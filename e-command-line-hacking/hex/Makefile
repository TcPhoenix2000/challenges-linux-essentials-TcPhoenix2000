# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall -std=c++2a
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Linker flags
# LDFLAGS=

# Libraries
# LIBS=

# Name of app
APPNAME=hex
BINARY=${APPNAME}
SRCDIR=src
BUILDDIR=bin
INSTALLDIR=/opt/${APPNAME}
PATHDIR=/usr/local/bin

OBJS := $(patsubst %.cpp,%.o,$(shell find ${SRCDIR} -name '*.cpp'))

all: makebuildir ${BINARY}

${BINARY}: ${OBJS}
	${CC} ${LDFLAGS} -o ${BUILDDIR}/$@ ${OBJS} ${LIBS}

%.o : %.cpp
	${CC} ${CFLAGS} $< -o $@

clean:
	rm -rf ${BUILDDIR}
	rm -f ${OBJS}

# Really basic install - needs improvement
install:
	mkdir -p ${INSTALLDIR}
	cp ${BUILDDIR}/${BINARY} ${INSTALLDIR}
	ln -sf ${INSTALLDIR}/${BINARY} ${PATHDIR}/${APPNAME}

makebuildir:
	mkdir -p ${BUILDDIR}