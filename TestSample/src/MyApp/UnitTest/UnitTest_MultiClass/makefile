CC			= g++
CFLAGS		= -O2 -MMD -Wall
LD			= g++
LDFLAGS		= -Wall

INCLUDES	= -I/usr/local/include -I../../../Common
SRCS		= ./MultiClass_Test.cpp ../../MultiClass.cpp
OBJDIR		= ./obj
LIBDIRS		= -L/usr/local/lib -L../../../../lib
LIBS		= -lCommon -lgtest_main -lgtest -lpthread
OUTDIR		= ./
TARGET		= $(OUTDIR)/UnitTes_MultiClass

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
			$(LD) $(LDFLAGS) $(LIBDIRS) -o $@ $^ $(LIBS)

$(OBJS): $(SRCS)
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $(call GetSrc)

clean:
			rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)
