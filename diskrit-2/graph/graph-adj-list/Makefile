CC=gcc
BIN=diskrit

all: diskrit

%.o: %.c %.h
	$(CC) -c $^

$(BIN): main.o graph.o
	$(CC) -o $@ $^

vis: $(BIN)
	$(BIN) | dot -Tpdf > vis.pdf

clean: 
	@echo Removing unwanted Files
	@del *.o *.exe *.gch