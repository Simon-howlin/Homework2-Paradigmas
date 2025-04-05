CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
BIN_DIR = bin

EJ1_SRC = Ejercicio1/main.cpp Ejercicio1/ejercicio1.cpp Ejercicio1/utils.cpp
# EJ2_SRC = Ejercicio2/main.cpp Ejercicio2/curso.cpp Ejercicio2/estudiante.cpp
EJ3_SRC = Ejercicio3/main.cpp Ejercicio3/numType.cpp
# EJ4_SRC = Ejercicio4/main.cpp

# all: $(BIN_DIR)/ej1 $(BIN_DIR)/ej2 $(BIN_DIR)/ej3 $(BIN_DIR)/ej4
all: $(BIN_DIR)/ej1 $(BIN_DIR)/ej3 

$(BIN_DIR)/ej1: $(EJ1_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

# $(BIN_DIR)/ej2: $(EJ2_SRC)
# 	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR)/ej3: $(EJ3_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

# $(BIN_DIR)/ej4: $(EJ4_SRC)
# 	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BIN_DIR)/ej1 $(BIN_DIR)/ej2 $(BIN_DIR)/ej3 $(BIN_DIR)/ej4