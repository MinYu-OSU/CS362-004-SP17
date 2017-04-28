CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittest: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o
		gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
		gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest:
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g
		gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

unittestresults:
		./unittest1 1 &> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./unittest2 1 >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./unittest3 1 >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./unittest4 1 >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest1 1 >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest2 1 >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest3 1 >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		./cardtest4 1 >> unittestresults.out
		gcov dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
