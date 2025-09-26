CFLAGS ?= -Wall -g  # ?= 表示如果未定义则使用默认值

# 默认目标
all: ex20

# 显式规则
ex20: ex20.c
	$(CC) $(CFLAGS) ex20.c -o ex20

# 清理生成的文件
clean:
	rm -f ex20