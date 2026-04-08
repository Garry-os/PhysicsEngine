include config.mk

export TOP_DIR := $(CURDIR)

## Detect all projects
PROJECTS_DIRS := $(wildcard projects/*/)
PROJECTS 	  := $(notdir $(PROJECTS_DIRS))

.PHONY: all engine projects clean
all: engine projects

engine:
	@ $(MAKE) -C src/Engine BUILD_DIR=$(abspath build)

## Compile projects
projects:
	@ for project in $(PROJECTS); do \
		$(MAKE) -C projects/$$project BUILD_DIR=$(abspath build); \
	done

clean:
	rm -rf build

-include $(CPP_OBJECTS:.o=.d) $(C_OBJECTS:.o=.d)


