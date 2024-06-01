CC=gcc
BIN=diskrit

all: diskrit

$(BIN): main.c tree.c
	$(CC) -o $@ $^

vis: $(BIN)
	$(BIN) | dot -Tpdf > vis.pdf

clean: 
	@echo Removing unwanted Files
	@del *.o *.exe *.gch