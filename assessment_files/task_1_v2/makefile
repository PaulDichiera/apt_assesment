# compiler and flags 
CC = g++
CFLAGS = -Wall -Werror -std=c++14 -O

# files
SOURCES = main.cpp Patient.cpp LinkedList.cpp PatientRegister.cpp Ward.cpp
OBJECTS = main.o Patient.o LinkedList.o PatientRegister.o Ward.o
TARGET = build

# default rule 
all: $(TARGET)

#linking executabled
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

#compiling source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# clean
.PHONEY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)