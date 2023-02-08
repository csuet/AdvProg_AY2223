LIBFLAGS = -lSDL2 -lSDL2_image
INCLUDE_DIR = -ISDL2\SDL2-2.26.2\i686-w64-mingw32\include\SDL2 -ISDL2\SDL2_image-2.6.2\i686-w64-mingw32\include\SDL2
LIB_DIR = -LSDL2\SDL2-2.26.2\i686-w64-mingw32\lib -LSDL2\SDL2_image-2.6.2\i686-w64-mingw32\lib
all:
	g++ -std=c++17 -c utils.cpp $(LIBFLAGS) $(INCLUDE_DIR) $(LIB_DIR)
	g++ -std=c++17 -c painter.cpp $(LIBFLAGS) $(INCLUDE_DIR) $(LIB_DIR)
	g++ -std=c++17 -c main.cpp $(LIBFLAGS) $(INCLUDE_DIR) $(LIB_DIR)
	g++ -std=c++17 utils.o  painter.o main.o -o main $(LIBFLAGS) $(INCLUDE_DIR) $(LIB_DIR)
	g++ -std=c++17 -c painterTest.cpp $(LIBFLAGS) $(INCLUDE_DIR) $(LIB_DIR)
	g++ -std=c++17 utils.o  painter.o painterTest.o  -lcppunit -o painterTest $(LIBFLAGS) $(INCLUDE_DIR) $(LIB_DIR)
run:
	chmod +x main
	./main

test:
	chmod +x painterTest
	./painterTest

clean:
	rm -rf *.o main painterTest
