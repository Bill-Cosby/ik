CC=g++
CFLAGS=-std=c++11 -Iinclude -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

ik: main.o basicObjects.o bodyStructure.o node.o quaternion.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: src/%.cpp
	$(CC) $(CFLAGS) $^ -c -o $@

clean:
	rm *.o
	rm ik
