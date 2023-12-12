#--STARNDARD--
NAME		= cub3D
CFLAGS		= -I/mlx_linux -Imlx_linux -O3 -Lmlx_linux -lmlx_Linux -L/mlx_linux -Imlx_linux -lXext -lX11 -lm -lz
VPATH		= $(addprefix $(SRC_D)/, $(DIRS))

#--LIBFT--
LIB		= $(addprefix $(LPATH)/, libft.a)
LPATH	= ./Libft

#--DIRS--
SRC_D		= ./src
DIRS		= . init system utils msg
OBJ_D		= ./objects
INCLUDE_D	= ./include
LIB_INC_D	= $(LPATH)/Include

#--FILES--
SRC 		= $(INI) $(SYS) $(UTI) $(MSG)
INI			= init.c
SYS			= main.c
UTI			= utils.c
MSG			= msg.c
HEADERS		= ./include/cub3D.h #./mlx_linux/mlx.h ./mlx_linux/mlx_int.h
INCLUDE		= -I $(INCLUDE_D) -I $(LIB_INC_D)

#--OBJECTS--
OBJ			= $(SRC:%.c=$(OBJ_D)/%.o)

#--COLORS--
WHITE	=	\e[00m
GREEN	=	\e[32m
RED		=	\e[91m
YELLOW	=	\e[033m
BLUE	=	\e[34m

#--PROGRESSION--
NUMBER_OF_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)

$(NAME): $(LIB) $(OBJ) $(OBJ_D) $(HEADERS)
	@echo "$(BLUE)Compiling $(WHITE)cub3D"
	@cc $(OBJ) $(CFLAGS) $(INCLUDE) -lreadline $(LIB) -o $@
	@echo "$(GREEN)Compiled $(WHITE)cub3D"

$(LIB):
	@echo "$(BLUE)Compiling $(WHITE)Libft"
	@$(MAKE)	-C $(LPATH) --no-print-directory

$(OBJ_D)/%.o: %.c Makefile | $(OBJ_D)
	@cc -c $(CFLAGS) $< -o $@
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

$(OBJ_D):
	@mkdir -p $@

clean:
	@echo "$(BLUE)Removing $(WHITE)Minishell objects"
	@rm -rf $(OBJ_D)
	@$(MAKE)	clean -C $(LPATH) --no-print-directory

fclean: clean
	@echo "$(BLUE)Removing $(WHITE)$(NAME)"
	@rm -rf $(NAME)
	@$(MAKE)	fclean -C $(LPATH) --no-print-directory

re: fclean all