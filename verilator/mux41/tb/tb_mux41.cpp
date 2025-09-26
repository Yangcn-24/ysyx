
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vmux41.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vmux41* top;

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
    printf("X0=%d,X1=%d,X3=%d,X4=%d,Y=%d,F=%d\n",top->X0,top->X1,top->X2,top->X3,top->Y,top->F);
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new Vmux41;  // 更改为 Vmux41
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("dump.vcd");
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
    top->Y = 0;
    top->X0 = 0; top->X1 = 0; top->X2 = 0; top->X3 = 0;
    step_and_dump_wave();

    // 测试用例1: Y=00 (选择X0)
    top->Y = 0;
    top->X0 = 1; step_and_dump_wave();  // F应输出1
    top->X0 = 0; step_and_dump_wave();  // F应输出0

    // 测试用例2: Y=01 (选择X1)
    top->Y = 1;
    top->X1 = 2; step_and_dump_wave();  // F应输出2
    top->X1 = 3; step_and_dump_wave();  // F应输出3

    // 测试用例3: Y=10 (选择X2)
    top->Y = 2;
    top->X2 = 1; step_and_dump_wave();  // F应输出1
    top->X2 = 0; step_and_dump_wave();  // F应输出0

    // 测试用例4: Y=11 (选择X3)
    top->Y = 3;
    top->X3 = 3; step_and_dump_wave();  // F应输出3
    top->X3 = 2; step_and_dump_wave();  // F应输出2

    // 边界测试: 所有输入同时变化
    top->Y = 0;
    top->X0 = 3; top->X1 = 2; top->X2 = 1; top->X3 = 0;
    step_and_dump_wave();  // F应输出3 (X0)

    top->Y = 1;
    step_and_dump_wave();  // F应输出2 (X1)

    top->Y = 2;
    step_and_dump_wave();  // F应输出1 (X2)

    top->Y = 3;
    step_and_dump_wave();  // F应输出0 (X3)

    sim_exit();
    return 0;
}
