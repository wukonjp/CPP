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

all:		$(TARGET)

$(TARGET):	$(OBJS)
			mkdir -p $(OUTDIR)
			$(LD) $(LDFLAGS) $@ $^

#cppファイルのベース名を装飾する場合は接尾辞を使用すること（接頭辞ではパターンマッチで誤認する）
$(OBJS): $(SRCS)
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $(filter %$(notdir $(@:%.o=%.cpp)), $(SRCS))

clean:
			rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)
