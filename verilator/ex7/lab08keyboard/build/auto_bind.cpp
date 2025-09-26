#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->rst, 1, BTNU);
	nvboard_bind_pin( &top->ps2_clk, 1, PS2_CLK);
	nvboard_bind_pin( &top->ps2_data, 1, PS2_DAT);
	nvboard_bind_pin( &top->seg1, 8, SEG0A, SEG0B, SEG0C, SEG0A, SEG0D, SEG0E, SEG0F, DEC0P);
	nvboard_bind_pin( &top->seg2, 8, SEG1A, SEG1B, SEG1C, SEG1A, SEG1D, SEG1E, SEG1F, DEC1P);
	nvboard_bind_pin( &top->seg3, 8, SEG2A, SEG2B, SEG2C, SEG2A, SEG2D, SEG2E, SEG2F, DEC2P);
	nvboard_bind_pin( &top->seg4, 8, SEG3A, SEG3B, SEG3C, SEG3A, SEG3D, SEG3E, SEG3F, DEC3P);
	nvboard_bind_pin( &top->seg5, 8, SEG4A, SEG4B, SEG4C, SEG4A, SEG4D, SEG4E, SEG4F, DEC4P);
	nvboard_bind_pin( &top->seg6, 8, SEG5A, SEG5B, SEG5C, SEG5A, SEG5D, SEG5E, SEG5F, DEC5P);
	nvboard_bind_pin( &top->seg7, 8, SEG6A, SEG6B, SEG6C, SEG6A, SEG6D, SEG6E, SEG6F, DEC6P);
	nvboard_bind_pin( &top->seg8, 8, SEG7A, SEG7B, SEG7C, SEG7A, SEG7D, SEG7E, SEG7F, DEC7P);
}
