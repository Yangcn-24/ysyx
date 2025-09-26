#include <nvboard.h>
#include <Vdecode24.h>
 
static TOP_NAME dut;
 
void nvboard_bind_all_pins(TOP_NAME* decode24);
 
 
int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();
 
  while(1) {
    nvboard_update();
    dut.eval();}	
}
