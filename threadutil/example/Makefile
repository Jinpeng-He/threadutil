#CROSS_COMPILE ?= arm-hisiv100nptl-linux-


VPATH = .
SOURCES = $(foreach dir,$(VPATH),$(wildcard $(dir)/*))
C_SRCS   = $(filter %.c,$(SOURCES))
CPP_SRCS = $(filter %.cpp,$(SOURCES))
C_OBJS   = $(C_SRCS:%.c=%.o)
CPP_OBJS = $(CPP_SRCS:%.cpp=%.o)
OBJS = $(C_OBJS) $(CPP_OBJS)

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar
STRIP = $(CROSS_COMPILE)strip



CFLAGS = -Wall -O2
CFLAGS += -I../include
CFLAGS += -DDDNSDEBUG #-g
CFLAGS += -L../lib -lthreadpool
CFLAGS += -Wall -Wno-strict-aliasing -Wno-unused-variable -Wno-deprecated -D_REENTRANT -DSIP_DEBUG -fPIC -pthread $(patsubst %, -I%, $(INCLUDE_DIR))

TARGET = threadpool_demo

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $^ > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(TARGET): $(OBJS)
	$(CXX) $^ $(CFLAGS) -o $@
	cp $@ ../bin/
	rm -rf $@
	
.PHONY : clean
clean :
	rm -f *.o *.bak $(TARGET) ../bin/$(TARGET)

