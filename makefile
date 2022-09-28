CXX      :=
CXXFLAGS := -Wall -Wextra -Wno-unused-parameter -Wno-volatile -Wno-unused-but-set-variable -std=c++20 -g
LDFLAGS  :=
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
SRC_DIR  := source
INCL     :=
TARGET   := program
SRC      := $(wildcard source/*.cpp)
EXT      :=

ifeq ($(OS),Windows_NT)
    CXX += x86_64-w64-mingw32-g++
    INCL += -Iinclude/glfw-3.3.2/include -Iinclude/glew-2.2.0/include -Iinclude/
    LDFLAGS += -Linclude/glfw-3.3.2/lib -Linclude/glew-2.2.0/lib -Linclude/lib -static-libgcc -static-libstdc++ -lglfw3 -lglew32 -lglu32 -lopengl32 -lgdi32 -luser32 -static -lwinpthread
    EXT += .exe
else
    CXX += g++
    LDFLAGS += -lstdc++ -lm `pkg-config --libs glfw3 glew`
    EXT += .out
endif

OBJECTS  := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.d,$(SRC))

.PHONY: all debug release windows clean info

all: $(APP_DIR)/$(TARGET)$(EXT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCL) -c $< -MD -o $@

$(APP_DIR)/$(TARGET)$(EXT): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET)$(EXT) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

windows: CXX := x86_64-w64-mingw32-g++
windows: INCL := -Iinclude/glfw-3.3.2/include -Iinclude/glew-2.2.0/include -Iinclude/
windows: LDFLAGS := -Linclude/glfw-3.3.2/lib -Linclude/glew-2.2.0/lib -Linclude/lib -static-libgcc -static-libstdc++ -lglfw3 -lglew32 -lglu32 -lopengl32 -lgdi32 -luser32 -static -lwinpthread
windows: EXT := .exe
windows: all

clean:
	@rm -f $(OBJECTS)
	@rm -f $(DEPENDENCIES)
	@echo "Cleanup complete!"

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
