# Compiler
CC = gcc

# Compiler flags
CFLAGS = -IHeader_Files

# Source files
SOURCES = Functions/Input.c Functions/entab.c Functions/detab.c main.c

# Output executable
OUTPUT = run

# Default target
all: $(OUTPUT)

# Linking
$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT)

# Clean up
clean:
	rm -f $(OUTPUT)
