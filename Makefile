CC=g++

build: main.cpp justify.cpp
	$(CC) main.cpp -o justify

clean: 
	rm -f justify
