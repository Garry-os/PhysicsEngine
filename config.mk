CXX = g++
UNAME_S = $(shell uname -s)

INCLUDE_PATH = 

CXXFLAGS = -Wall -Wextra -O2 -std=c++20 -MMD -MP $(INCLUDE_PATH)
CFLAGS = -Wall -Wextra -O2 -std=c11 -MMD -MP $(INCLUDE_PATH)

ifeq ($(UNAME_S), Darwin)
	CXXFLAGS += -I /opt/homebrew/include
	CFLAGS += -I /opt/homebrew/include

	LDFLAGS = -L/opt/homebrew/lib -lglfw -framework OpenGL \
			  -framework Cocoa -framework IOKit -framework CoreVideo \
			  -Wl,-rpath,/opt/homebrew/lib
else
	LDFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
endif

CC = gcc
LD = g++
AR = ar


