all:
	g++ -std=c++17 -c main_simpleai.cpp
	g++ -std=c++17 -c util.cpp
	g++ -std=c++17 -c simpleai.cpp
	g++ -std=c++17 util.o main_simpleai.o simpleai.o -o main_simpleai
	g++ -std=c++17 -c mainTest.cpp
	g++ -std=c++17 mainTest.o simpleai.o util.o -lcppunit -o mainTest 
run:
	chmod +x main
	./main
test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest main_simpleai
