
NAME    = ex_c1
CC      = g++
CFLAGS  = -Wall -std=c++11 
SOURCES = main.cpp person.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $^ -o $(NAME) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o  $(NAME)
