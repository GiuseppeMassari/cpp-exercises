
NAME    = exercise
CC      = g++
CFLAGS  = -Wall -std=c++11
LDFLAGS = -pthread
SOURCES = main.cpp person.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $(NAME) $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS) 

clean:
	rm *.o  $(NAME)
