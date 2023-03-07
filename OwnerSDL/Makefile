LIBFLAGS = -lSDL2
all:
	g++ -std=c++17 -c src/main.cpp $(LIBFLAGS)
	g++ -std=c++17 build/main.o -o buildmain $(LIBFLAGS)
run:
	cd build
	chmod +x main
	./main
	cd ..
test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest
