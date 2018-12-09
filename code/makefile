LDFLAGS = -g -Wall --std=c++11 -Wno-sign-compare

src = $(wildcard *.cpp)
target = $(patsubst %.cpp, %, ${src})
target2 = $(patsubst %, %.dSYM, ${target})

.PHONY: all clean

all: ${target}

%:%.o
	${CC} ${LDFLAGS} -o $@

clean:
	rm -f ${target}
	rm -rf ${target2}
