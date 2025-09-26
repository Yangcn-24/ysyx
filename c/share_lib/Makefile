lib_srcs:=$(shell find src -name *.c)
lib_objs:=$(patsubst src/%.c,objs/%.o,$(lib_srcs))
so_objs :=$(filter-out objs/main.o,$(lib_objs))

include_dirs:=include
library_libs:=lib
linking_libs:=ddd
I_options:=$(include_dirs:%=-I%)
l_options:=$(linking_libs:%=-l%)
L_options:=$(library_libs:%=-L%)
r_options:=$(library_libs:%=-Wl,-rpath=%)
linking_options:=$(l_options) $(L_options) $(r_options)
compile_options:=-g -O3 -w -fPIC $(I_options)

lib/libddd.so:$(so_objs)
	@mkdir -p $(dir $@)
	@gcc -shared $^ -o $@
objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@gcc -c $^ -o $@ $(compile_options)
compile:$(lib_objs)
dynamic:lib/libddd.so
bin/main:objs/main.o
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(linking_options)
run:bin/main compile dynamic
	@./$^
debug:
	@echo $(so_objs)
clean:
	@rm -rf objs bin
.PHONY:debug compile dynamic clean
