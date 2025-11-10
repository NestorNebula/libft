ROOT = ..

NAME = do_tests

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = include

LIB_INCLUDE_DIR = $(ROOT)

LIB_DIR = $(ROOT)

SRC_DIR = src

LIB = ft

SRC = $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isalnum.c \
	  $(SRC_DIR)/ft_isascii.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_strlen.c \
	  $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_memcpy.c \
	  $(SRC_DIR)/ft_memmove.c $(SRC_DIR)/ft_strlcpy.c $(SRC_DIR)/ft_strlcat.c \
	  $(SRC_DIR)/ft_toupper.c $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_strchr.c \
	  $(SRC_DIR)/ft_strrchr.c $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_memchr.c \
	  $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_atoi.c \
	  $(SRC_DIR)/ft_calloc.c $(SRC_DIR)/ft_strdup.c $(SRC_DIR)/ft_substr.c \
	  $(SRC_DIR)/ft_strjoin.c $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_split.c \
	  $(SRC_DIR)/ft_itoa.c $(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_striteri.c \
	  $(SRC_DIR)/ft_putchar_fd.c $(SRC_DIR)/ft_putstr_fd.c \
	  $(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = $(SRC_DIR)/ft_lstnew.c $(SRC_DIR)/ft_lstadd_front.c \
			$(SRC_DIR)/ft_lstsize.c $(SRC_DIR)/ft_lstlast.c \
			$(SRC_DIR)/ft_lstadd_back.c $(SRC_DIR)/ft_lstdelone.c \
			$(SRC_DIR)/ft_lstclear.c $(SRC_DIR)/ft_lstiter.c \
			$(SRC_DIR)/ft_lstmap.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CRITERION = # Path to criterion library 

CRITERION_INCLUDE = $(CRITERION)/include

LDLIBS = -l$(LIB) -lcriterion -lbsd

LDFLAGS = -Wl,-rpath,$(CRITERION)/lib

all: $(NAME)

%.o: %.c $(LIB_DIR)/lib$(LIB).a
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDE_DIR) -I$(LIB_INCLUDE_DIR) \
	-I$(CRITERION_INCLUDE)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -L$(CRITERION)/lib $(LDLIBS) $(LDFLAGS)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $^ -L$(LIB_DIR) -L$(CRITERION)/lib \
	$(LDLIBS) $(LDFLAGS)
