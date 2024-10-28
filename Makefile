CC = gcc
CFLAGS = -Wall -I"C:/MinGW/sqlite3" -Iinclude  # Add -Iinclude to specify the header file directory
LDFLAGS = -L"C:/MinGW/sqlite3" -lsqlite3
SRC = $(wildcard src/*.c)   # Find all .c files in the src folder
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))  # Convert src/*.c to build/*.o
TARGET = build/financier.exe  # Place the executable in the build directory

# Default target to build the executable
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJ)
	@if not exist build mkdir build
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Rule to compile .c files into .o files under the build/ directory
build/%.o: src/%.c
	@if not exist build mkdir build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	@if exist build\*.o del /Q build\*.o
	@if exist build\$(notdir $(TARGET)) del /Q build\$(notdir $(TARGET))

# New 'run' target that builds and then runs the executable
run: all
	$(TARGET)
