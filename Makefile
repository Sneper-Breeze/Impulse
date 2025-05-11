TARGET = tape_sort
CXX = g++
SRCS_DIR = src/
OBJECTS_DIR = build/
CXXFLAGS = -g -O0
SRCS = $(wildcard $(SRCS_DIR)*.cpp)
#OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(patsubst $(SRCS_DIR)%.cpp, $(OBJECTS_DIR)%.o, $(SRCS))
#LIB =

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
$(OBJECTS_DIR)%.o: $(SRCS_DIR)%.cpp
	$(CC) $< -c -o $@
clean:
	rm -rf $(OBJECTS_DIR)*.o $(TARGET)