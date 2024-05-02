NAME		= cub3D
CFLAGS      = -Wall -Wextra -Werror -g
LFLAGS      = -lmlx -lXext -lX11 -lm -lz

VPATH		= $(addprefix $(SRC_D)/, $(DIRS))
MAPA 		= map_pdf.cub
LIB			= $(addprefix $(LPATH)/, libft.a)
LPATH		= ./Libft
SRC_D		= ./src
DIRS		= . map init raycast system utils msg
OBJ_D		= ./objects
INCLUDE_D	= ./include
LIB_INC_D	= $(LPATH)/Include
SRC 		= $(INI) $(MAP) $(RAY) $(SYS) $(UTI) $(MSG)

INI			= init.c
MAP			= draw_map.c player.c square.c parser.c
RAY			= raycast.c raycast_second.c r_utils.c
SYS			= hooks.c main.c
UTI			= utils.c map_reader.c
MSG			= msg.c
HEADERS		= ./include/cub3D.h

INCLUDE		= -I $(INCLUDE_D) -I $(LIB_INC_D)
OBJ			= $(SRC:%.c=$(OBJ_D)/%.o)

WHITE	=	\e[00m
GREEN	=	\e[32m
RED		=	\e[91m
YELLOW	=	\e[033m
BLUE	=	\e[34m

NUMBER_OF_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)

r: $(NAME)
	./$(NAME) $(MAPA)

v: $(NAME)
	valgrind --track-origins=yes ./$(NAME) $(MAPA)

$(NAME): $(LIB) $(OBJ) $(OBJ_D) $(HEADERS)
	@echo "$(BLUE)Compiling $(WHITE)$(NAME)"
	@$(CC) $(OBJ) $(LFLAGS) $(INCLUDE) $(LIB) -o $@
	@echo "$(GREEN)Compiled $(WHITE)$(NAME)"

$(LIB):
	@echo "$(BLUE)Compiling $(WHITE)Libft"
	@$(MAKE) -C $(LPATH) --no-print-directory

$(OBJ_D)/%.o: %.c Makefile | $(OBJ_D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

$(OBJ_D):
	@mkdir -p $@

clean:
	@echo "$(BLUE)Removing $(WHITE)Cub3D objects"
	@rm -rf $(OBJ_D)
	@$(MAKE)	clean -C $(LPATH) --no-print-directory

fclean: clean
	@echo "$(BLUE)Removing $(WHITE)$(NAME)"
	@rm -rf $(NAME)
	@$(MAKE)	fclean -C $(LPATH) --no-print-directory

re: fclean all
