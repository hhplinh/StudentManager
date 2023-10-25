SHELL = powershell.exe

CXXFLAGS = -std=c++20

INC_DIRS = \
	"./SFML/include" \
	"./headers" \
	"."
LIB_DIRS = "./SFML/lib"

LDLIBS = -lsfml-graphics -lsfml-network -lsfml-window -lsfml-main -lsfml-system

BIN = StudentManager

BUILD_DIR = ./release
JUNK_DIR = $(BUILD_DIR)/junk

CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(CPP_FILES:%.cpp=$(JUNK_DIR)/%.o)
DEP_FILES = $(OBJ_FILES:%.o=%.d)

all: pre-build $(BUILD_DIR)/$(BIN)

pre-build:
	-mkdir "$(JUNK_DIR)"

$(BUILD_DIR)/$(BIN): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(^:%="%") -o $@ $(LIB_DIRS:%=-L%) $(LDLIBS)

$(JUNK_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@ $(INC_DIRS:%=-I%)

-include $(DEP_FILES)

clean:
	-rm -force "$(BUILD_DIR)/*.exe"
	-rm -force "$(JUNK_DIR)/*.o"
	-rm -force "$(JUNK_DIR)/*.d"

rebuild: clean all
