
PROG = project

TESTING = testing.cpp
# Fichiers sources (NE PAS METTRE les .h ni les .o seulement les .cpp)
SOURCES = film.cpp  photo.cpp media.cpp video.cpp  \
		mediaStorage.cpp mediaGroup.cpp \
		tcpserver.cpp cppsocket.cpp \

MAIN = main.cpp

HEADERS = ${SOURCES:%.cpp=%.h}

OBJETS = ${SOURCES:%.cpp=%.o}
#~ OBJETS += ${MAIN:%.cpp=%.o}

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g # -O0 --coverage
LDFLAGS = -pthread


######################################################################
# 																	 #
#    Regles de construction/destruction des .o et de l'executable    #
# 																	 #
######################################################################

all: ${PROG}

run: ${PROG}
	./${PROG}

${PROG}: ${MAIN} ${OBJETS} 
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} $^
	
testing: ${TESTING} ${OBJETS} 
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} $^
	./$@

${OBJETS}: %.o: %.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -c -o $@ $<
	
clean:
	$(RM) ${OBJETS} ${PROG}



