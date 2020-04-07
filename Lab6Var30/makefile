QWER = lab6.exe

COMP = gcc

.PHONY: all build clean run

all: $(QWER)	 

clean:
		del *.o
build: $(QWER)

$(QWER): lab6.o
		$(COMP) -o $(QWER) lab6.o 
lab6.o: lab6.c
		@$(COMP) -c lab6.c

run: 
	$(QWER)