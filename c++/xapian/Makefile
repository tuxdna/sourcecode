all: quickstartindex.o quickstartsearch.o
	c++  quickstartindex.o -o quickstartindex `xapian-config --libs`
	c++  quickstartsearch.o -o quickstartsearch `xapian-config --libs`

quickstartindex.o:
	c++  -c quickstartindex.cc `xapian-config --cxxflags`

quickstartsearch.o:
	c++  -c quickstartsearch.cc `xapian-config --cxxflags`


myindex:
	c++  `xapian-config --cxxflags --libs` myindex.cc -o myindex

clean:
	rm *.o *~
