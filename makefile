CFLAGS =
CC     = cc -Wall -Wextra -O2 -std=gnu18 -I./inc ${CFLAGS}
OUT    = macsv
TEST   = ./bin/${OUT}_TEST
LIB    = ./bin/lib${OUT}.a

all: ${TEST}
	${TEST}

build: clean ${LIB}


clean:
	rm *.gz -f
	rm ./bin/* ./obj/* *.stack-dump -f

configure:
	mkdir -p ./bin/ ./obj/

# install:

# uninstall:


${TEST}: ./obj/main.o ./obj/acsv.o ./inc/acsv.h
	${CC} -o ${TEST} ./obj/*.o

${LIB}: ./obj/acsv.o
	ar rcs ${LIB} ./obj/acsv.o

./obj/main.o: ./inc/acsv.h ./src/main.c
	${CC} -o ./obj/main.o -c ./src/main.c

./obj/acsv.o: ./src/acsv.c ./inc/acsv.h
	${CC} -o ./obj/acsv.o -c ./src/acsv.c
