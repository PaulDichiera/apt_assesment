# set variables for compiler and flags
CC = g++
CFLAGS = -Wall -Werror -std=c++14 -O

# set files variables
SOURCES = main.cpp ward.cpp patient.cpp patientRegister.cpp
OBJECTS = main.o ward.o patient.o patientRegister.o
TARGET = build

# default rule 
all: $(TARGET)

# linking executables
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# compiling source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# clean
.PHONEY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)