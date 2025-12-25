SRC_ALL = $(wildcard *.cpp )
SRC = $(filter-out cli.cpp, $(SRC_ALL))
CFLAGS += -Wall -Wextra -std=c++17
OBJ = $(SRC:%.cpp=%.o)

paint: $(OBJ)
	$(CXX) $^ -o $@

cli: cli.o
	$(CXX) $^ -o $@

clean:
	$(RM) -rf $(OBJ) paint cli cli.o