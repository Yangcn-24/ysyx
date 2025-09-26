#include <nvboard.h>
#include "Vshift_reg.h"

void nvboard_bind_all_pins(Vshift_reg* top) {
	nvboard_bind_pin( &top->clk, 1, BTNC);
	nvboard_bind_pin( &top->rstn, 1, SW6);
	nvboard_bind_pin( &top->in, 1, SW4);
	nvboard_bind_pin( &top->load, 1, SW7);
	nvboard_bind_pin( &top->data, 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->R_L, 1, SW5);
	nvboard_bind_pin( &top->q, 4, LD3, LD2, LD1, LD0);
}
