NAME = 	libasm.a
NAME_BONUS = libasm_bonus.a

NASM = 	nasm -f elf64

SRC = 	src/mandatory/ft_read.s \
		src/mandatory/ft_strcmp.s \
		src/mandatory/ft_strcpy.s \
		src/mandatory/ft_strdup.s \
		src/mandatory/ft_strlen.s \
		src/mandatory/ft_write.s

BONUS_SRC =	src/bonus/ft_list_push_front_bonus.s \
			src/bonus/ft_list_size_bonus.s \

OFILES = $(SRC:.s=.o)
BONUS_OFILES = $(BONUS_SRC:.s=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OFILES)
	ar -rcs $@ $^
	@gcc main.c libasm.a -I ./header/mandatory -z noexecstack -o main

$(NAME_BONUS): $(BONUS_OFILES)
	ar -rcs $@ $^
	@gcc main_bonus.c libasm_bonus.a -I ./header/mandatory -I ./header/bonus -z noexecstack -o main_bonus

%.o: %.s
	$(NASM) $< -o $@

clean:
	rm -f $(OFILES)
	rm -f $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)
	rm -f main
	rm -f libasm.a
	rm -f main_bonus
	rm -f libasm_bonus.a

re: fclean $(NAME)

.PHONY: all clean fclean re