CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = acadBuilding.o boardDisplay.o building.o coopFee.o dcTimsLine.o gameBoard.o gooseNesting.o goToTims.o gym.o main.o needlesHall.o osap.o owner.o player.o residence.o rollUpRim.o school.o SLC.o tile.o tuition.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
