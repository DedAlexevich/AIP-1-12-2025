SRC = $(wildcard *.cpp )
CFLAGS += -Wall -Wextra -std=c++11
OBJ = $(SRC:%.cpp=%.o)
paint: $(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) -rf $(OBJ)