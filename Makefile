# Dossier contenant les fichiers .cpp
SRC_DIR := src
INCLUDE_DIR := include

# Tous les fichiers .cpp dans src/
SRCS := $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:.cpp=.o)

# Nom de l'exécutable
TARGET := mon_programme

# Commandes
CXX := g++
CXXFLAGS := -Wall -I$(INCLUDE_DIR) -std=c++17

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

.PHONY: all clean
