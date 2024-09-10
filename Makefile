CXX = g++
CXXFLAGS = -I.

%:
	mkdir -p build
	$(CXX) $(CXXFLAGS) -o build/$@ recipes/$@.cpp
	./build/$@

clean:
	rm -rf build
