NAME = CollisionDetected
#backup files
zipName = $(NAME)_backup/$(shell date +%F-%H-%M-%S).zip

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
RM = rm -f
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system 

all: $(OBJ)
	g++  $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	-$(RM) *.o

fclean:	clean
	-$(RM) $(NAME)

re: fclean all

tar: fclean
	zip -r zipName ../CollisionDetected

debug:fclean $(OBJ)
	g++ $(OBJ) -o $(NAME) $(CFLAGS) -ggbd

