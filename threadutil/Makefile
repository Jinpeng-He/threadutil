PROJECT_ROOT_DIR := ./

version = release

#PREFIX = arm-hisiv100nptl-linux-
CC = $(PREFIX)gcc
CXX = $(PREFIX)g++
AR = $(PREFIX)ar
STRIP = $(PREFIX)strip



INCLUDE_DIR := $(PROJECT_ROOT_DIR)include/
LIB_DIR := $(PROJECT_ROOT_DIR)lib/
BIN_DIR := $(PROJECT_ROOT_DIR)bin/

DEBUG_C_FLAG = -g

NODEBUG_C_FLAG = -o2

ifeq ($(version),release)
	CFLAGS = $(NODEBUG_C_FLAG) -Wall -Wno-strict-aliasing -Wno-unused-variable -Wno-deprecated -D_REENTRANT -DSIP_DEBUG -fPIC $(patsubst %, -I%, $(INCLUDE_DIR))
else
	CFLAGS = $(DEBUG_C_FLAG) -Wall -Wno-strict-aliasing -Wno-unused-variable -Wno-deprecated -D_REENTRANT -DSIP_DEBUG -fPIC $(patsubst %, -I%, $(INCLUDE_DIR))
endif

VPATH += src

SOURCES = $(foreach dir,$(VPATH),$(wildcard $(dir)/*))
C_SRCS   = $(filter %.c,$(SOURCES))
CPP_SRCS = $(filter %.cpp,$(SOURCES))
C_OBJS   = $(C_SRCS:%.c=%.o)
CPP_OBJS = $(CPP_SRCS:%.cpp=%.o)
OBJS = $(C_OBJS) $(CPP_OBJS)

LIB = libthreadpool.a

INCLUDE_DIR += $(PROJECT_ROOT_DIR)include/

all : $(LIB) 
$(LIB):$(OBJS)
	$(AR) r $@ $(OBJS)
	cp $@ $(LIB_DIR)

%.o:%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $^ -o $@

.PHONY:clean
clean:
	-rm $(OBJS) $(LIB) -rf

