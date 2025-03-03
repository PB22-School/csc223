default:
	make test

clean:
	rm -rf build

test:
	make clean
	mkdir build
	g++ -std=c++11 src/VisualHanoi.cpp src/main.cpp -lncursesw -o build/main
	./build/main