CC = g++
DB = gdb
CFLAGS = -o
DFLAGS = -g
PROGNAME = main

all:
	$(CC) -c $(PROGNAME).cpp 
	$(CC) $(PROGNAME).o $(CFLAGS) $(PROGNAME)

debug:
	$(CC) $(DFLAGS) $(PROGNAME).cpp $(CFLAGS) $(PROGNAME)
	$(DB) ./$(PROGNAME)

run:
	./$(PROGNAME)

clean:
	rm -f $(PROGNAME) *.o 
