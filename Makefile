SRC:= src
ICL:= include
OBJ:= obj
BIN:= bin
EXE:= ${BIN}/tp

${BIN}/tp02: ${OBJ}/main.o ${OBJ}/QuickSortMedian.o ${OBJ}/QuickSortSelection.o  ${OBJ}/QuickSort.o ${OBJ}/QuickSort_NonRecursive.o
	c++ -g -pg -Wall ${OBJ}/*.o -o ${BIN}/tp02

${OBJ}/main.o: ${SRC}/main.cpp
	c++ -g -c ${SRC}/main.cpp -I ${ICL} -o ${OBJ}/main.o

${OBJ}/QuickSort.o: ${SRC}/QuickSort.cpp
	c++ -g -c ${SRC}/QuickSort.cpp -I ${ICL} -o ${OBJ}/QuickSort.o

${OBJ}/QuickSortMedian.o: ${SRC}/QuickSortMedian.cpp
	c++ -g -c ${SRC}/QuickSortMedian.cpp -I ${ICL} -o ${OBJ}/QuickSortMedian.o

${OBJ}/QuickSortSelection.o: ${SRC}/QuickSortSelection.cpp
	c++ -g -c ${SRC}/QuickSortSelection.cpp -I ${ICL} -o ${OBJ}/QuickSortSelection.o

${OBJ}/QuickSort_NonRecursive.o: ${SRC}/QuickSort_NonRecursive.cpp
	c++ -g -c ${SRC}/QuickSort_NonRecursive.cpp -I ${ICL} -o ${OBJ}/QuickSort_NonRecursive.o

clean:
	rm ${OBJ}/*.o ${BIN}/tp02