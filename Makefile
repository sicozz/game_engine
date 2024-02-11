ifeq ($(OS),Windows_NT)
    # Windows
    RM := del /Q
    RMDIR := rmdir /S /Q
    MKDIR := mkdir
    TARGET_EXTENSION := .exe
else
    # Unix-like (Linux, macOS)
    RM := rm -f
    RMDIR := rm -rf
    MKDIR := mkdir -p
    TARGET_EXTENSION :=
endif

TARGET = game.exe
CC = g++
INCLUDE_DIR = external/include
LIB_DIR = external/lib
CFLAGS = -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -std=c++20
DBG_FLAGS = -g

SRCS_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRCS_DIR)/*.cpp)
OBJS = $(patsubst $(SRCS_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all debug clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
ifeq ($(OS),Windows_NT)
	if not exist $(@D) $(MKDIR) $(@D)
else
	$(MKDIR) $(@D)
endif
	$(CC) -c $< -o $@ $(CFLAGS)

debug: CFLAGS += $(DBG_FLAGS)
debug: $(TARGET)

clean:
	$(RM) $(TARGET) $(BUILD_DIR)\*.
	$(RMDIR) $(BUILD_DIR)