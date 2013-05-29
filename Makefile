CC=gcc
TARGET=calculator
all: $(TARGET)

$(TARGET): main.o $(TARGET).o
	$(CC) main.o $(TARGET).o -o $(TARGET) -lreadline

main.o: main.c
	$(CC) -c main.c

$(TARGET).o: $(TARGET).c
	$(CC) -c $(TARGET).c

clean:
	rm -rf *.o hello
install: 
	cp $(TARGET) /usr/bin
uninstall:
	/bin/rm -f /usr/bin/$(TARGET) 
