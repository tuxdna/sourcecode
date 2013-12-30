#include <cstdlib>
#include <db_cxx.h>

int main() {

  u_int32_t env_flags = DB_CREATE |  // If the environment does not exist, create it.
    DB_INIT_MPOOL; // Initialize the in-memory cache.

  std::string envHome("tmp/testEnv");

  u_int32_t db_flags = DB_CREATE;   // If the database does not exist, create it.

  std::string dbName("mydb.db");
  DbEnv myEnv(0);
  Db *myDb;

  try {
    myEnv.open(envHome.c_str(), env_flags, 0);
    myDb = new Db(&myEnv, 0);
    myDb->open(NULL,
	       dbName.c_str(),
	       NULL,
	       DB_BTREE,
	       db_flags,
	       0);
  } catch(DbException &e) {
    std::cerr << "Error opening database environment: "
	      << envHome
	      << " and database "
	      << dbName << std::endl;
    std::cerr << e.what() << std::endl;
    exit( -1 );
  } catch(std::exception &e) {
    std::cerr << "Error opening database environment: "
	      << envHome
	      << " and database "
	      << dbName << std::endl;
    std::cerr << e.what() << std::endl;
    exit( -1 );
  }


  try {
    if (myDb != NULL) {
      myDb->close(0);
    }
    myEnv.close(0);

  } catch(DbException &e) {
    std::cerr << "Error closing database environment: "
              << envHome
              << " or database "
              << dbName << std::endl;
    std::cerr << e.what() << std::endl;
    exit( -1 );
  } catch(std::exception &e) {
    std::cerr << "Error closing database environment: "
              << envHome
              << " or database "
              << dbName << std::endl;
    std::cerr << e.what() << std::endl;
    exit( -1 );
  }
}
