all: compile link

compile:
	g++ -Isrc/include -c coding/*.cpp

link:
	g++ *.o -o SNAKE -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32