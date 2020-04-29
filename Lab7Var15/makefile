CC = gcc
TARGET = laba7.exe


.PHONY: all run clean build

all: $(TARGET)

clean:
	@rm -rf $(TARGET) *.o *.i *.s *.gch *.out *.exe

build: $(TARGET)

Lab7var15.o: Lab7var15.c
			$(CC) -c Lab7var15.c


$(TARGET): Lab7var15.o
			$(CC) -o $(TARGET) Lab7var15.o


run:
	$(TARGET)