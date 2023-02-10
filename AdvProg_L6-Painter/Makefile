LIBFLAGS = -lSDL2 -lSDL2_image
all:
	g++ -std=c++17 -c utils.cpp $(LIBFLAGS)
	g++ -std=c++17 -c painter.cpp $(LIBFLAGS)
	g++ -std=c++17 -c main.cpp $(LIBFLAGS)
	g++ -std=c++17 utils.o  painter.o main.o -o main $(LIBFLAGS)
	g++ -std=c++17 -c painterTest.cpp $(LIBFLAGS)
	g++ -std=c++17 utils.o  painter.o painterTest.o  -lcppunit -o painterTest $(LIBFLAGS)
run:
	chmod +x main
	./main

test:
	chmod +x guessitTest
	./guessitTest

clean:
	rm -rf *.o main painterTest
