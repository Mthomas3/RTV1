##
## Makefile for  in /home/mart_4/rendu/TestPiscine/Raytracer/parsing
##
## Made by Thomas Martins
## Login   <mart_4@epitech.net>
##
## Started on  Sat Feb 21 23:07:27 2015 Thomas Martins
## Last update Sun Mar 15 19:51:37 2015 Thomas Martins
##

SRC	= main.c \
	  src/basic/error.c \
	  src/basic/basic_func.c \
	  src/basic/my_putnbr.c \
	  src/basic/put_pixel.c \
	  src/calc_img/calc_image.c \
	  src/calc_img/put_image.c \
	  src/calc_ray/cone.c \
	  src/calc_ray/cylender.c \
	  src/calc_ray/eyes.c \
	  src/calc_ray/solve_quadric.c \
	  src/calc_ray/sphere.c \
	  src/light/light.c \
	  src/translation/rotate_x.c \
	  src/translation/rotate_y.c \
	  src/translation/rotate_z.c \
	  src/calc_ray/plan.c \
	  src/calc_ray/wall.c \
	  src/init/expose.c \
	  src/init/init_mlx.c \
	  src/init/key.c

OBJ	 = $(SRC:.c=.o)

NAME	= rtv1

RM	= rm -f

CC	= cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

%.o : %.c
	$(CC) $(INC) $(FLAGS) -o $@ -c $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
