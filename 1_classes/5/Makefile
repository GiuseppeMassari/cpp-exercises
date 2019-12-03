
NAME    = exercise
CC      = g++
CFLAGS  = -Wall -std=c++11 -g
SOURCES = main.cpp pay_parking.cpp parking.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $(NAME) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o  $(NAME)
