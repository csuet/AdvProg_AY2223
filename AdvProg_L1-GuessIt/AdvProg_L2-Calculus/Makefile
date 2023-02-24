
all:
	g++ -std=c++17 -c calculus.cpp
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 calculus.o main.o -o main
	g++ -std=c++17 -c calculusTest.cpp
	g++ -std=c++17 calculus.o calculusTest.o -lcppunit -o calculusTest
run:
	chmod +x main
	./main
test:
	chmod +x calculusTest
	./calculusTest
clean:
	rm -rf *.o calculus calculusTest