CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*.c)   # Find all .c files in the src folder
OBJ = $(SRC:.c=.o)          # Replace .c with .o to get the list of object files
TARGET = banking_app

all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lsqlite3

# Rule to compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
