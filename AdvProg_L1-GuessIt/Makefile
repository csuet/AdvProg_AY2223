
all:
	g++ -std=c++17 -c guessit.cpp
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 guessit.o main.o -o main
	g++ -std=c++17 -c guessitTest.cpp
	g++ -std=c++17 guessit.o guessitTest.o -lcppunit -o guessitTest
run:
	chmod +x main
	./main
test:
	chmod +x guessitTest
	./guessitTest
clean:
	rm -rf *.o guessit guessitTest