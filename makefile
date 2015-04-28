# Declartation of variables
CC 			= g++
CSTD		= -std=c++14
CFLAGS 	= -g -W

# File names
EXEC 		= composerdb
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXEC)
	@echo -e "\nSuccessfully built" $<

# Main target - linking objects
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)


# To obtain object files - compiling source
%.o: %.cpp
	$(CC) -c $(CSTD) $(CFLAGS) $< -o $@

# To remove generated files
clean:
	rm -rf $(OBJECTS) $(EXEC).exe