IDIR=include
CC=clang++

ODIR=obj
SRCDIR=src
TESTDIR=tests/

all: libmean.a main test

libmean.a: $(ODIR)/Intal.o $(ODIR)/get_time.o
	ar rcs libintal.a $(ODIR)/Intal.o $(ODIR)/get_time.o

main:	$(ODIR)/main.o $(ODIR)/Intal.o $(ODIR)/get_time.o
		$(CC) -o main $(ODIR)/main.o $(ODIR)/Intal.o $(ODIR)/get_time.o

test:	$(ODIR)/test.o
	$(CC) -o test $(ODIR)/test.o -L. -static -lintal
	
$(ODIR)/test.o: $(TESTDIR)/test.cpp
	$(CC) -w -o $(ODIR)/test.o -c $(TESTDIR)test.cpp -std=c++11

$(ODIR)/main.o:	main.cpp
	$(CC) -w -o $(ODIR)/main.o -c main.cpp

$(ODIR)/Intal.o:	$(SRCDIR)/Intal.cpp $(IDIR)/Intal.h
	$(CC) -w -o $(ODIR)/Intal.o -c $(SRCDIR)/Intal.cpp
	
$(ODIR)/get_time.o:	$(SRCDIR)/get_time.cpp $(IDIR)/get_time.h
	$(CC) -w -o $(ODIR)/get_time.o -c $(SRCDIR)/get_time.cpp


clean:
	rm -f $(ODIR)/*.o
	rm main test
