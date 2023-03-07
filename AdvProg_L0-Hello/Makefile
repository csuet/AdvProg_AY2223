all:
	g++ -std=c++17 -c hello.cpp
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 hello.o main.o -o main
	g++ -std=c++17 -c mainTest.cpp 
	g++ -std=c++17 hello.o mainTest.o -lcppunit -o mainTest 
run:
	chmod +x main
	./main
test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest
