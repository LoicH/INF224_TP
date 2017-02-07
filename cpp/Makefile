
PROG = project

# Fichiers sources (NE PAS METTRE les .h ni les .o seulement les .cpp)
SOURCES = main.cpp

HEADERS = media.h film.h photo.h video.h

OBJETS = ${SOURCES:%.cpp=%.o}

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g # -O0 --coverage
LDFLAGS =

# Exemple: LDLIBS = -L/usr/local/qt/lib -lqt
LDLIBS =


##########################################
# Regles de construction/destruction des .o et de l'executable
#

all: ${PROG}

run: ${PROG}
	./${PROG}

${PROG}:  ${OBJETS} ${HEADERS}
	${CXX} -o $@ ${CXXFLAGS} ${OBJETS}

${OBJETS}: %.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $^
	
clean:
	$(RM) ${OBJETS} ${PROG}



