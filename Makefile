CXX = g++
CXXFLAGS = -I.

%:
	$(CXX) $(CXXFLAGS) -o $@ recipes/$@.cpp
	./$@

