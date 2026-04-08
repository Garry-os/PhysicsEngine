include ../../config.mk

INCLUDE_PATH += -I $(TOP_DIR)/src -I $(TOP_DIR)/src/vendor/glad/include -I $(TOP_DIR)/src/vendor -I $(TOP_DIR)/src/vendor/stb_image

.PHONY: all engine

CPP_SOURCES := $(shell find . -name "*.cpp")
CPP_OBJECTS := $(patsubst %.cpp, $(BUILD_DIR)/engine/cpp/%.o, $(CPP_SOURCES))

C_SOURCES := $(shell find )

all: engine
engine: $(BUILD_DIR)/engine/libengine.a

$(BUILD_DIR)/engine/libengine.a: $(CPP_OBJECTS) $(C_OBJECTS) $(BUILD_DIR)/engine/c/glad.o $(BUILD_DIR)/engine/cpp/stb_image.o
	$(AR) rcs $@ $^

$(BUILD_DIR)/engine/cpp/%.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

## Compile glad
$(BUILD_DIR)/engine/c/glad.o: $(TOP_DIR)/src/vendor/glad/src/glad.c
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

## Compile stb_image
$(BUILD_DIR)/engine/cpp/stb_image.o: $(TOP_DIR)/src/vendor/stb_image/stb_image.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

-include $(CPP_OBJECTS:.o=.d)


