CXX = g++
CXXFLAGS = -O0 -Wall -g -std=c++17
OBJECTS = control.o game.o view.o main.o
TARGET =snake

all: ${TARGET}

${TARGET}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -o ${TARGET} ${OBJECTS}

run:
	./${TARGET}

clean:
	${RM} ${OBJECTS} ${TARGET}

