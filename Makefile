CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -I./include -I./src
SRCS = Main.cpp
TARGET = exe/quadratic_solver

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p exe
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -rf exe *.o

run: $(TARGET)
	./$(TARGET)