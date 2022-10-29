SRC:= src
ICL:= include
OBJ:= obj
BIN:= bin
EXE:= ${BIN}/tp

${BIN}/tp02: ${OBJ}/main.o ${OBJ}/QuickSortMedian.o
	c++ -g -pg -Wall ${OBJ}/*.o -o ${BIN}/tp02

${OBJ}/main.o: ${SRC}/main.cpp
	c++ -g -c ${SRC}/main.cpp -I ${ICL} -o ${OBJ}/main.o

${OBJ}/QuickSortMedian.o: ${SRC}/QuickSortMedian.cpp
	c++ -g -c ${SRC}/QuickSortMedian.cpp -I ${ICL} -o ${OBJ}/QuickSortMedian.o

clean:
	rm ${OBJ}/*.o ${BIN}/tp02