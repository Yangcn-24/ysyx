#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->clk, 1, BTNC);
	nvboard_bind_pin( &top->rstn, 1, BTNU);
	nvboard_bind_pin( &top->in, 1, SW0);
	nvboard_bind_pin( &top->out, 1, LD4);
	nvboard_bind_pin( &top->o_state, 4, LD3, LD2, LD1, LD0);
}
