include $(TOP_DIR)/config.mk

ENGINE_LIB := $(BUILD_DIR)/engine/libengine.a

CPP_SRC := $(shell find . -name "*.cpp")
CPP_OBJ := $(patsubst %.cpp, $(BUILD_DIR)/$(APP_NAME)/cpp/%.o, $(CPP_SRC))

INCLUDE_PATH += -I $(TOP_DIR)/src/

.PHONY: all app

all: app
app: $(BUILD_DIR)/$(APP_NAME)/$(APP_NAME)
$(BUILD_DIR)/$(APP_NAME)/$(APP_NAME): $(CPP_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^ $(ENGINE_LIB)

$(BUILD_DIR)/$(APP_NAME)/cpp/%.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

-include $(CPP_OBJ:.o=.d) $(C_OBJECTS:.o=.d)

