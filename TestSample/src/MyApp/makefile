CC			= g++
CFLAGS		= -O2 -MMD -Wall
LD			= g++
LDFLAGS		= -Wall

INCLUDES	= -I/usr/local/include -I../Common
SRCS		= ./MultiClass.cpp ./DivClass.cpp ./main.cpp
OBJDIR		= ./obj
LIBDIRS		= -L/usr/local/lib -L../../lib
LIBS		= -lCommon -lpthread
OUTDIR		= ../../bin
TARGET		= $(OUTDIR)/MyApp

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:%.cpp=%.o)))
DEPS		= $(OBJS:%.o=%.d)

all:		$(TARGET)

$(TARGET):	$(OBJS)
			mkdir -p $(OUTDIR)
			$(LD) $(LDFLAGS) $(LIBDIRS) -o $@ $^ $(LIBS)

$(OBJS): $(SRCS)
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $(filter %$(notdir $(@:%.o=%.cpp)), $(SRCS))

clean:
			rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)
