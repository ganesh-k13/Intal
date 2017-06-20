IDIR=include
CC=g++

ODIR=obj
SRCDIR=src

test:	$(ODIR)/test.o $(ODIR)/Intal.o $(ODIR)/get_time.o
		$(CC) -o test $(ODIR)/test.o $(ODIR)/Intal.o $(ODIR)/get_time.o

$(ODIR)/test.o:	test.cpp
	$(CC) -w -o $(ODIR)/test.o -c test.cpp

$(ODIR)/Intal.o:	$(SRCDIR)/Intal.cpp $(IDIR)/Intal.h
	$(CC) -w -o $(ODIR)/Intal.o -c $(SRCDIR)/Intal.cpp
	
$(ODIR)/get_time.o:	$(SRCDIR)/get_time.cpp $(IDIR)/get_time.h
	$(CC) -w -o $(ODIR)/get_time.o -c $(SRCDIR)/get_time.cpp

clean:
	rm -f $(ODIR)/*.o
	rm test
