CC			= g++
CFLAGS		= -O2 -MMD -Wall
LD			= ar
LDFLAGS		= rcs

INCLUDES	= -I/usr/local/include
SRCS		= ./ComA/AddClass.cpp ./ComB/SubClass.cpp
OBJDIR		= ./obj
OUTDIR		= ../../lib
TARGET		= $(OUTDIR)/libCommon.a

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:%.cpp=%.o)))
DEPS		= $(OBJS:%.o=%.d)

#ソースリストからターゲットオブジェクトとマッチするソースを取得する関数
GetSrc		= $(strip $(foreach src, $(SRCS),							\
					$(if $(filter $(@F:%.o=%.cpp), $(notdir $(src))),	\
						$(src)											\
					)													\
				))

all:		$(TARGET)

$(TARGET):	$(OBJS)
			mkdir -p $(OUTDIR)
			$(LD) $(LDFLAGS) $@ $^

$(OBJS):	$(SRCS)
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $(call GetSrc)

clean:
			rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)
