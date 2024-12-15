CC = g++

CFLAGS = -g -MMD

SRCS =	src/main.cpp \
	src/Entity.cpp \
	src/Herbivore.cpp \
	src/Plant.cpp \
	src/Map.cpp \
	src/tools.cpp

OBJ_DIR = obj

OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

DEPS = $(OBJS:.o=.d)	

NAME = environnement

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/src
	mkdir -p $(OBJ_DIR)/include
	$(CC) -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) 

all: $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re