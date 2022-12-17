TARGET=solver

SRC=$(wildcard $(PWD)/*.c)

LINKS=-lm

RM=rm
CC=gcc

all: $(TARGET)

clear:
	${RM} ${TARGET}

$(TARGET): ${SRC}
	${CC} -o ${TARGET} ${SRC} ${LINKS}
