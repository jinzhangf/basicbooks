CFLAGS = -g -Wall -Werror --std=c++11 -g -Wno-sign-compare
LDFLAGS = -lpthread

src = $(wildcard *.cpp)
target = $(patsubst %.cpp, %, ${src})

.PHONY: all clean

%.o:%.cpp
	$(CC) ${CFLAGS} -c -o $@
%:%.o
	$(CC) ${LDFLAGS} -o $@

all: ${target}

clean:
	rm -f ${target}
