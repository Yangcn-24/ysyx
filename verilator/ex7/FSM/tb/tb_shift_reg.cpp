#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vshift_reg.h"//更改为V+module_name.h

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vshift_reg* top;//更改为V+module_name

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
    //printf("a=%d,b=%d,f=%d,co=%d,overflow=%d\n",top->a,top->b,top->f,top->co,top->overflow);
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new Vshift_reg;  // 更改为V+module_name
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("shift_reg4.vcd");
    top->clk=0;
    top->rstn = 0;
    top->in = 0;
    top->load = 1;
    top->data = 0b1010;
    top->R_L = 0;
    top->ena = 1;
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
    for (int i = 0; i < 100; i++) {  // 减少仿真周期数
        if(i==10){
        	top->rstn=1;
        }
        if(i==40){
        	top->rstn=0;
        }
        if(i==20){
        	top->load=0;
        }
        top->clk = !top->clk;       // 翻转时钟
        step_and_dump_wave();
    }
    sim_exit();
    return 0;
}
