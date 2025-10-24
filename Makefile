NAME = 	libasm.a

NASM = 	nasm -f elf64

SRC = 	src/mandatory/ft_read.s \
		src/mandatory/ft_strcmp.s \
		src/mandatory/ft_strcpy.s \
		src/mandatory/ft_strdup.s \
		src/mandatory/ft_strlen.s \
		src/mandatory/ft_write.s

OFILES = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar -rcs $@ $^
	@gcc main.c libasm.a -I ./header/mandatory -o main

%.o: %.s
	$(NASM) $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)
	@rm -f main

re: fclean $(NAME)

.PHONY: all clean fclean re