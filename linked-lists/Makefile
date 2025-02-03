CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_lists: build/LinkedList.o build/test_lists.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test clean

test: build/test_lists
	./build/test_lists

clean:
	rm -rf build