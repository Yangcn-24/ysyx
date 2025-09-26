#include <nvboard.h>
#include "Vencode42.h"

void nvboard_bind_all_pins(Vencode42* top) {
	nvboard_bind_pin( &top->en, 1, SW0);
	nvboard_bind_pin( &top->x, 4, SW4, SW3, SW2, SW1);
	nvboard_bind_pin( &top->y, 2, LD1, LD0);
}
