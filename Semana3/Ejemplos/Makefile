# Compilador
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic

# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
else
    EXEEXT :=
endif

# Todos los archivos .cpp del directorio actual
SRCS := $(wildcard *.cpp)

# Nombres de ejecutables (mismo nombre que el .cpp, extensión según OS)
TARGETS := $(SRCS:%.cpp=%$(EXEEXT))

# Regla por defecto
all: $(TARGETS)

# Regla genérica cpp -> ejecutable
%$(EXEEXT): %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Limpiar ejecutables
# clean:
#       rm -f $(TARGETS)

# ------------------------------------------------------------
# AddressSanitizer
ASAN_FLAGS := -fsanitize=address -g

asan: CXXFLAGS += $(ASAN_FLAGS)
asan: clean all

# Limpiar ejecutables
clean:
	rm -f $(TARGETS)