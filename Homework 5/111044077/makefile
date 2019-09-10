CC = g++
DB = gdb
CFLAGS = -o
DFLAGS = -g
PROGNAME = main
PROGNAME2= ConnectFourAbstract
PROGNAME3= Cell
PROGNAME4= ConnectFourDiag
PROGNAME5= ConnectFourPlus
PROGNAME6= ConnectFourPlusUndo
all:
	$(CC) -std=c++11 -c $(PROGNAME).cpp $(PROGNAME2).cpp $(PROGNAME3).cpp $(PROGNAME4).cpp $(PROGNAME5).cpp $(PROGNAME6).cpp
	$(CC) $(PROGNAME).o $(PROGNAME2).o $(PROGNAME3).o $(PROGNAME4).o $(PROGNAME5).o $(PROGNAME6).o $(CFLAGS) $(PROGNAME)

debug:
	$(CC) $(DFLAGS) $(PROGNAME).cpp $(PROGNAME2).cpp $(PROGNAME3).cpp $(PROGNAME4).cpp $(PROGNAME5).cpp $(PROGNAME6).cpp $(CFLAGS) $(PROGNAME)
	$(DB) ./$(PROGNAME)

run:
	./$(PROGNAME) 

clean:
	rm -f $(PROGNAME) *.o 
