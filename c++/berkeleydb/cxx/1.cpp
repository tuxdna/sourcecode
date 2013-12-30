#include <db_cxx.h>
#include <iostream>
#include <cstring>

using namespace std;
/* 
 * Function called to handle any database error messages
 * issued by DB. 
 */
void
my_error_handler(const DbEnv *dbenv, const char *error_prefix,
		 const char *msg)
{
  /* 
   * Put your code to handle the error prefix and error
   * message here. Note that one or both of these parameters
   * may be NULL depending on how the error message is issued
   * and how the DB handle is configured.
   */
} 


int main() {
  Db db(NULL, 0);
  u_int32_t oFlags = DB_CREATE | DB_EXCL;

  std::string dbFileName("my_db.db");

  
  // Open the database
  try {
    db.open(NULL,                // Transaction pointer 
            dbFileName.c_str(),          // Database file name 
            NULL,                // Optional logical database name
            DB_BTREE,            // Database access method
            DB_CREATE | DB_EXCL,              // Open flags
            0);                  // File mode (using defaults)

  } catch(DbException &e) {
    
    db.open(NULL,                // Transaction pointer 
            dbFileName.c_str(),          // Database file name 
            NULL,                // Optional logical database name
            DB_BTREE,            // Database access method
            0,              // Open flags
            0);                  // File mode (using defaults)

  }


  float money = 122.45;
  char description[] = "Grocery bill.";
  
  cout << "key: " << money << endl;
  cout << "data: " << description << endl;
  cout << "storing into the database now... " << endl;
  
  Dbt key(&money, sizeof(float));
  Dbt data(description, strlen(description)+1); 
  
  int ret = db.put(NULL, &key, &data, DB_NOOVERWRITE);
  if (ret == DB_KEYEXIST) {
    db.err(ret, "Put failed because key %f already exists", money);
  }
  

  
  


  // close the database
  try {
    db.close(0);
  } catch(DbException &e) {
    db.err(e.get_errno(), "Database open failed %s", 
	   dbFileName.c_str());
    throw e;
  } catch(std::exception &e) {
    db.errx("Error closing database: %s", e.what());
    throw e;
  } 

}
