
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vencode42.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vencode42* top;

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
    printf("en=%d,x=%d,y=%d\n",top->en,top->x,top->y);
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new Vencode42;  // 更改为 Vmux41
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("encode42.vcd");
}

void sim_exit() {
    step_and_dump_wave();
    tfp->close();
    delete top;
    delete tfp;
    delete contextp;
}

int main() {
    sim_init();

    // 初始化所有输入
    top->en = 0;
    top->x = 0b0000; step_and_dump_wave();

    top->x = 0b0001; step_and_dump_wave();
    

    top->x = 0b0010; step_and_dump_wave();


    top->x = 0b0100; step_and_dump_wave();
    
    
    top->x = 0b1000; step_and_dump_wave();
    
	
    top->en = 1 ;
    top->x = 0b0000; step_and_dump_wave();

    top->x = 0b0001; step_and_dump_wave();
    

    top->x = 0b0010; step_and_dump_wave();


    top->x = 0b0100; step_and_dump_wave();
    
    
    top->x = 0b1000; step_and_dump_wave();
    
    top->en = 0;step_and_dump_wave();
    sim_exit();
    return 0;
}
