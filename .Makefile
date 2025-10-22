NAME = 	libasm.a

NASM = 	nasm -f elf64

SRC = 	src/ft_read.s \
		src/ft_strcmp.s \
		src/ft_strcpy.s \
		src/ft_strdup.s \
		src/ft_strlen.s \
		src/ft_write.s

OFILES = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar -rcs $@ $^
	ranlib $@

%.o: %.s
	$(NASM) $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re