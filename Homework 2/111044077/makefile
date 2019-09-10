CC = g++
DB = gdb
CFLAGS = -o
DFLAGS = -g
PROGNAME = main

all:
	$(CC) -std=c++11 -c $(PROGNAME).cpp 
	$(CC) $(PROGNAME).o $(CFLAGS) $(PROGNAME)

debug:
	$(CC) $(DFLAGS) $(PROGNAME).cpp $(CFLAGS) $(PROGNAME)
	$(DB) ./$(PROGNAME)

run:
	./$(PROGNAME)

clean:
	rm -f $(PROGNAME) *.o 
