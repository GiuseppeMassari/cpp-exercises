
NAME    = exercise
CC      = g++
CFLAGS  = -Wall -std=c++14 # std14 is for make_unique
SOURCES = main.cpp person.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $(NAME) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o  $(NAME)
