MODULE_NAME:=top
.PHONY:all sim clean
all:sim
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc --exe --build ./csrc/$(MODULE_NAME).cpp ./vsrc/$(MODULE_NAME).v --trace
	./obj_dir/V$(MODULE_NAME)
clean:
	rm ./obj_dir/*
	rm ./*.vcd
