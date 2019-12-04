
NAME    = exercise
CC      = g++
CFLAGS  = -Wall -std=c++11 -g 
LDFLAGS = -pthread
SOURCES = main.cpp pay_parking.cpp parking.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $(NAME) $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm *.o  $(NAME)
