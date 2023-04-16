CC			= g++
CFLAGS		= -O2 -MMD -Wall
LD			= g++
LDFLAGS		= -Wall

INCLUDES	= -I/usr/local/include -I../../../Common
SRCS		= ./DivClass_Test.cpp ../../DivClass.cpp ../Stub/MultiClass_Stub.cpp
OBJDIR		= ./obj
LIBDIRS		= -L/usr/local/lib -L../../../../lib
#依存関係の解決にはライブラリの順番を適切に記述する必要がある
LIBS		= -lCommon -lgtest_main -lgtest -lpthread
OUTDIR		= ./
TARGET		= $(OUTDIR)/UnitTes_DivClass

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:%.cpp=%.o)))
DEPS		= $(OBJS:%.o=%.d)

all:		$(TARGET)

#依存関係の解決にはobjファイルの後にライブラリを記述する必要がある
$(TARGET):	$(OBJS)
			mkdir -p $(OUTDIR)
			$(LD) $(LDFLAGS) $(LIBDIRS) -o $@ $^ $(LIBS)

#cppファイルのベース名を装飾する場合は接尾辞を使用すること（接頭辞ではパターンマッチで誤認する）
$(OBJS): $(SRCS)
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $(filter %$(notdir $(@:%.o=%.cpp)), $(SRCS))

clean:
			rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)
