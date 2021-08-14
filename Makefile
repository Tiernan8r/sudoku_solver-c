TARGET=solver

SRC=main.c solve.c entry.c input.c output.c

LINKS=-lm

RM=rm
CC=gcc

all: $(TARGET)

clear:
	${RM} ${TARGET}

$(TARGET): ${SRC}
	${CC} -o ${TARGET} ${SRC} ${LINKS}
