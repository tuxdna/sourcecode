#LIBS=-lrpm -lrpmdb -lrpmio -lpopt
CFLAGS=`pkg-config rpm --cflags`
LIBS=`pkg-config rpm --libs`
all:
	cc $(CFLAGS) -o rpm1 rpm1.c  $(LIBS)
	cc $(CFLAGS) -o rpmexpand rpmexpand.c  $(LIBS)

tags:
	etags.ctags -a -e -f TAGS --tag-relative -R . /usr/include/rpm
