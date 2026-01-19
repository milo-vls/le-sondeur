CC = clang
CFLAGS = -Wall -Wextra -g -O0

LIBS = -lraylib -lm -lpthread -ldl -lrt -lX11

SRC = \
    main_sondeur.c \
    game_states.c \
    game_objects.c \
    asset/sprite.c \
    basic-menu/basic_menu.c \
    basic-menu/title_screen.c \
    utils-and-ds/linked_list.c \
    player-controller/player-controller.c

OBJ = $(SRC:.c=.o)

INC = \
    -I . \

program: $(OBJ)
	$(CC) $(OBJ) -o program $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) program
