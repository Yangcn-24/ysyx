#include <nvboard.h>
#include <Vencode42.h>
 
static TOP_NAME dut;
 
void nvboard_bind_all_pins(TOP_NAME* encode42);
 
 
int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();
 
  while(1) {
    nvboard_update();
    dut.eval();}	
}
