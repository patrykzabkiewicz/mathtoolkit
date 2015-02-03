hellomake:
	cxxtestgen --error-printer -o tests.cpp test*.h
	g++-4.9 -std=c++11 -I/Users/new/workspace/cxxtests/cxxtest -I/Users/new/workspace/boost_1_57_0 -o tests tests.cpp

clean:
	rm tests.cpp
	rm tests

run:
	./tests

