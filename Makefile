TARGET=solver

VALUES_DEFINITIONS=entry.c
OUTPUTS=output.c
INPUTS=input.c
SRC=main.c solve.c ${VALUES_DEFINITIONS} ${INPUTS} ${OUTPUTS}

LINKS=-lm

RM=rm
CC=gcc

all: $(TARGET)

clear:
	${RM} ${TARGET}

$(TARGET): ${SRC}
	${CC} -o ${TARGET} ${SRC} ${LINKS}

output: ${OUTPUTS}
	${CC} -o table_output ${OUTPUTS}

input: ${INPUTS}
	${CC} -o table_input ${INPUTS}