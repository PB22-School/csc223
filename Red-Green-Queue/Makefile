default:
	make test

test:
	make clean
	mkdir build
	g++ src/main.cpp src/RGThings.cpp -std=c++11 -o build/main
	./build/main

clean:
	rm -rf build