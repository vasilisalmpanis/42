#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
PINK = \033[95m
END=\033[0m
CFLAGS+=-O2
CFLAGS+= -w

all: $(NOM)

$(NOM): space $(OBJ)
	@ar -rs $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "$(PINK)mlx completed\n$(END)"

%.o: %.c
		${CXX} ${CXXFLAGS} -c $< -o $@
space:
		@echo ""

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
