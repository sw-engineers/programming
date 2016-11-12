CC = gcc
CXX = g++
CCFLAGS = -Wall -Wextra -O2
CXXFLAGS = -Wall -Wextra -O2 -std=c++11

TARGET = main
SRCS = main.c

OBJS := $(SRCS:.cpp=.o)
OBJS := $(OBJS:.c=.o)

.c.o:
	$(CC) $(CCFLAGS) -c -o $@ $<

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

clean:
	rm -f *.o $(TARGET)
