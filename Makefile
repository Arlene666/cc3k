CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = cc3k
OBJECTS = main.o grid.o cell.o object.o player.o item.o enemy.o enemyImpl.o \
shade.o drow.o vampire.o goblin.o troll.o potion.o gold.o rh.o ba.o bd.o ph.o \
wa.o wd.o human.o merchant.o dragon.o dwarf.o orcs.o halfling.o elf.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
