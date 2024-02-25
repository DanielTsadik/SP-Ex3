CC = gcc
CFLAGS = -Wall
AR = ar  

all: StrList 

StrList: Main.o libStrList.a
	$(CC) $(CFLAGS) -o $@ $^

libStrList.a: StrList.o
	$(AR) -rcs $@ $^

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean all  

clean:  
	rm -f *.o *.a StrList