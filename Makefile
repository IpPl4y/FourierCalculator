CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = program
OBJS = main.o FourierCalculator.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp FourierCalculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

FourierCalculator.o: FourierCalculator.cpp FourierCalculator.h
	$(CXX) $(CXXFLAGS) -c FourierCalculator.cpp

clean:
	rm -f $(TARGET) $(OBJS)
