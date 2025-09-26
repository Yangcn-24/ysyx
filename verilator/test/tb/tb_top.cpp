
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"//更改为V+module_name.h

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vtop* top;//更改为V+module_name

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
    printf("a=%d,b=%d,f=%d,co=%d,overflow=%d\n",top->a,top->b,top->f,top->co,top->overflow);
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new Vtop;  // 更改为V+module_name
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("decode24.vcd");
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
    top->mode = 0;
    top->a = 0; top->b = 0; 
    step_and_dump_wave();
	
    top->mode = 0 ;
    top->a = 0b0100; top->b = 0b0110; 
    step_and_dump_wave();
	
    top->a = 0b0010; top->b = 0b0010; 
    step_and_dump_wave();
    
    top->a = 0b0110; top->b = 0b0111; 
    step_and_dump_wave();
    
    top->mode = 1 ;
    top->a = 0b1100; top->b = 0b0100; //-4-4
    step_and_dump_wave();
    
    top->a = 0b0011; top->b = 0b0100; //3-4
    step_and_dump_wave();
    
    top->a = 0b1100; top->b = 0b0101; //-4-5
    step_and_dump_wave();
    
    top->a = 0b0101; top->b = 0b0100; //5-4
    step_and_dump_wave();
    
    step_and_dump_wave();
    sim_exit();
    return 0;
}
