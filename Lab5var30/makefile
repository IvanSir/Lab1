CC = gcc
TARGET = laba5.exe


.PHONY: all run clean build

all: $(TARGET)

clean:
	@rm -rf $(TARGET) *.o *.i *.s *.gch *.out *.exe

build: $(TARGET)

Lab5var30.o: Lab5var30.c
			$(CC) -c Lab5var30.c


$(TARGET): Lab5var30.o
			$(CC) -o $(TARGET) Lab5var30.o


run:
	$(TARGET)