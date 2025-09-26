lib_srcs:=$(filter-out src/main.c,$(shell find src -name *.c))
lib_objs:=$(patsubst src/%.c,objs/%.o,$(lib_srcs))
include_paths:=./include
library_paths:=./lib
linking_libs :=xxx
l_options:=-l$(linking_libs)
L_options:=-L$(library_paths)
I_options:=$(include_paths:%=-I%)
compile_flags:= -g -O3 $(I_options)
linking_flags:= $(l_options) $(L_options)
#==========編譯靜態庫==========
objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@gcc -c  $^ -o $@ $(compile_flags)
lib/libxxx.a:$(lib_objs)
	@mkdir -p $(dir $@)
	@ar -r $@ $^ 
static_lib:lib/libxxx.a
#==========鏈接靜態庫==========
objs/main.o/src/main.c:
	@mkdir -p $(dir $@)
	@gcc -c  $^ -o $@ $(compile_flags)
bin/main:objs/main.o
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(linking_flags)
run   :bin/main
	@./$<
debug :
	@echo $(lib_objs)
clean :
	rm -rf objs
	rm -rf bin
.PHONY:compile debug clean
