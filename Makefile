CXX = g++
CXXFLAGS = -O0 -Wall -g -std=c++17
OBJECTS = control.o game.o main.o snake.o tview.o view.o
TARGET =snake

all: ${TARGET}

${TARGET}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -o ${TARGET} ${OBJECTS}

control.o: control.cc
	${CXX} ${CXXFLAGS} -c -o control.o control.cc

game.o: game.cc
	${CXX} ${CXXFLAGS} -c -o game.o game.cc

main.o: main.cc
	${CXX} ${CXXFLAGS} -c -o main.o main.cc

snake.o: snake.cc
	${CXX} ${CXXFLAGS} -c -o snake.o snake.cc

tview.o: tview.cc
	${CXX} ${CXXFLAGS} -c -o tview.o tview.cc

view.o: view.cc
	${CXX} ${CXXFLAGS} -c -o view.o view.cc

run:
	./${TARGET}

clean:
	${RM} ${OBJECTS} ${TARGET}

