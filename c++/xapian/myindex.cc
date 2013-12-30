/* quickstartindex.cc: Simplest possible indexer
 *
 * ----START-LICENCE----
 * Copyright 1999,2000,2001 BrightStation PLC
 * Copyright 2003,2004 Olly Betts
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#include <xapian.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

typedef struct {
  string name;
  int id;
} doc;

int main(int argc, char **argv)
{
  // Simplest possible options parsing: we just require three or more
  // parameters.
  if(argc < 2) {
    cout << "usage: " << argv[0] <<
      " <path to database>" << endl;
    exit(1);
  }

  // Catch any Xapian::Error exceptions thrown
  try {
    // Make the database
    Xapian::WritableDatabase database(argv[1], Xapian::DB_CREATE_OR_OPEN);

    doc documents[] = {
      {"zero", 0},
      {"one", 1},
      {"two", 2},
      {"three", 3},
      {"four", 4},
      {"five", 5},
      {"six", 6},
      {"seven", 7},
      {"eight", 8},
      {"nine", 9},
      {"ten", 10},
      {"eleven", 11},
      {"twelve", 12},
      {"thirteen", 13},
      {"forteen", 14},
      {"fifteen", 15},
      {"sixteen", 16},
      {"seventeen", 17},
      {"eighteen", 18},
      {"nineteen", 19},
      {"twenty", 20},
    };

    int size =  sizeof(documents) / sizeof(documents[0]);
    for( int i = 0; i < size; i++ ) {
      doc *d = &documents[i];
      // Make the document
      Xapian::Document	newdocument;

      // Put the data in the document
      newdocument.set_data(d->name);

      // Put the terms into the document
      /*
	id:0
	name:zero
       */
      Xapian::TermGenerator tg;
      tg.set_document(newdocument);

      // id
      stringstream ss;
      ss << d->id;
      tg.index_text(ss.str(), 1, "XID");
      tg.index_text(d->name, 1, "XNAME");

       // Add the document to the database
       database.add_document(newdocument);
    }
  } catch(const Xapian::Error &error) {
    cout << "Exception: "  << error.get_msg() << endl;
  }
}

