CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(shell find src -name *.c)
OBJECTS=$(patsubst src/%.c,objs/%.o,$(SOURCES))
TEST_SRC=$(shell find tests -name *_tests.c)
TESTS=$(patsubst tests/%.c,bin/%,$(TEST_SRC))
#static(.a)
TARGET=build/libex29.a
#dynamic(.so)
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))
# The Target tests
all:$(SO_TARGET)

debug:
	@echo $(SO_TARGET)


build/%.so:$(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) -shared $^ -o $@
objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ -fPIC

$(TARGET): CFLAGS += -fPIC
$(TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@


$(TESTS): tests/%.c
	@mkdir -p $(dir $@)
	$(CC) Wall -g -DNDEBUG -$< -ldl -o $@


# The Unit Tests
.PHONY: tests build 
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS) objs
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true
