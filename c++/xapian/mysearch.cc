#include <xapian.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  // Simplest possible options parsing: we just require two or more
  // parameters.
  if (argc < 3) {
    cout << "usage: " << argv[0] <<
      " <path to database> <search terms>" << endl;
    exit(1);
  }

  // Catch any Xapian::Error exceptions thrown
  try {
    // Make the database
    Xapian::Database db(argv[1]);

    // Start an enquire session
    Xapian::Enquire enquire(db);

    // Build the query object
    Xapian::Query query(Xapian::Query::OP_OR, argv + 2, argv + argc);
    cout << "Performing query `" << query.get_description() << "'" << endl;

    // Give the query object to the enquire session
    enquire.set_query(query);

    // Get the top 10 results of the query
    Xapian::MSet matches = enquire.get_mset(0, 10);

    // Display the results
    cout << matches.size() << " results found" << endl;

    for (Xapian::MSetIterator i = matches.begin();
	 i != matches.end();
	 ++i) {
      Xapian::Document doc = i.get_document();
      cout << "Document ID " << *i << "\t" <<
	i.get_percent() << "% [" <<
	doc.get_data() << "]" << endl;
    }
  } catch(const Xapian::Error &error) {
    cout << "Exception: "  << error.get_msg() << endl;
  }
}

