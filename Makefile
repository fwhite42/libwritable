NAME	:= writable
METHODS	:=			\
	realloc			\
	realloc_and_free	\
	writeone		\
	writemany		\
	writestr

MK	:= ../mk
include	$(MK)/ar.mk
include	$(MK)/targets.mk

all: library

clean:
	$(RM) $(OBJECTS)

fclean: clean

re: fclean all
