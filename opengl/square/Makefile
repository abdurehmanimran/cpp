NAME := square
SRC_DIR := src
SRC_FILES:= $(wildcard ${SRC_DIR}/*)
INCLUDE_DIR:= include/
BINARY := bin/${NAME}

COMPILER := g++
INCLUDE_FLAGS := -I${INCLUDE_DIR}
LINKING_FLAGS := -lglfw

build ${BINARY}: $(SRC_FILES)
	mkdir bin/ -p
	${COMPILER} $(SRC_FILES) $(INCLUDE_FLAGS) $(LINKING_FLAGS) -o ${BINARY} -g -fsanitize=address

run: ${BINARY}
	${BINARY}

