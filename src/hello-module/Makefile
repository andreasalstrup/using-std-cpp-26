.PHONY: run
run:
	./build/hello-module

.PHONY: build
build:
	cmake -B build -G Ninja \
      -DCMAKE_C_COMPILER=$(shell which clang) \
      -DCMAKE_CXX_COMPILER=$(shell which clang++) \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build
	ln -sf build/compile_commands.json compile_commands.json

.PHONY: clean
clean:
	rm -rf ./build
	rm -f compile_commands.json
