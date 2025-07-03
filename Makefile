CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
SRC = main.cpp src/aes.cpp src/file_utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = aes_cli

all: $(TARGET)

$(TARGET): main.o src/aes.o src/file_utils.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp include/aes.h include/file_utils.h
	$(CXX) $(CXXFLAGS) -c main.cpp

src/aes.o: src/aes.cpp include/aes.h
	$(CXX) $(CXXFLAGS) -c src/aes.cpp -o src/aes.o

src/file_utils.o: src/file_utils.cpp include/file_utils.h
	$(CXX) $(CXXFLAGS) -c src/file_utils.cpp -o src/file_utils.o

clean:
	rm -f *.o src/*.o $(TARGET)
