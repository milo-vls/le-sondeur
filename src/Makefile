#compilateur linux
CC = clang
CFLAGS = -Wall -Wextra -g -O0
LIBS = -lraylib -lm -lpthread -ldl -lrt -lX11
#compilateur windows
CC_WIN = x86_64-w64-mingw32-gcc
CFLAGS_WIN = -Wall -Wextra -O2 -std=c99 -static
LIBS_WIN = -lraylib -lopengl32 -lgdi32 -lwinmm




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

windows:
	$(CC_WIN) $(SRC) $(INC) -o game.exe $(CFLAGS_WIN) $(LIBS_WIN)

clean:
	rm -f $(OBJ) program game.exe
