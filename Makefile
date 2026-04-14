include config.mk

export TOP_DIR := $(CURDIR)

## Detect all projects
PROJECTS_DIRS := $(wildcard projects/*/)
PROJECTS 	  := $(notdir $(patsubst %/, %, $(PROJECTS_DIRS)))

.PHONY: all engine projects clean $(PROJECTS)
all: engine projects

engine:
	@ $(MAKE) -C src/Engine BUILD_DIR=$(abspath build)

## Compile projects
projects: $(PROJECTS)
$(PROJECTS):
	@ $(MAKE) -C projects/$@ BUILD_DIR=$(abspath build)

clean:
	rm -rf build


