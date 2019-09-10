CC = g++
DB = gdb
CFLAGS = -o
DFLAGS = -g
PROGNAME = main
PROGNAME2= GTUSet
PROGNAME3= GTUMap

all:
	$(CC) -std=c++11 -c $(PROGNAME).cpp $(PROGNAME2).cpp $(PROGNAME3).cpp 
	$(CC) $(PROGNAME).o $(PROGNAME2).o $(PROGNAME3).o  $(CFLAGS) $(PROGNAME)

debug:
	$(CC) $(DFLAGS) $(PROGNAME).cpp $(PROGNAME2).cpp $(PROGNAME3).cppp $(CFLAGS) $(PROGNAME)
	$(DB) ./$(PROGNAME)

run:
	./$(PROGNAME) 

clean:
	rm -f $(PROGNAME) *.o 
