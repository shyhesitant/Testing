#include <ddp22_libs.h>
#include <gpio.h>
#include <int.h>


int main() 
{
	int value = 0;
	int dir = 0;
	set_gpio_pin_value(0, 1); // E1 on board, a reference to VCC

	dir =  get_gpio_pin_direction(1); // J1 on board
	bm_printf("\nPIN DIR IS: %d\n", dir);

	set_gpio_pin_direction(1, DIR_OUT);  // DIR_OUT == 1
	dir =  get_gpio_pin_direction(1); // Make sure the pin dir actually changed
	bm_printf("\nPIN DIR IS: %d\n", dir);

	while(1)
	{
		// Periodically read and print pin 0's value
		for (volatile int i=0;i<10000;i++) {}
		value = get_gpio_pin_value(1);
		bm_printf("\nPIN VALUE IS: %d\n", value);
	}
  bm_quit_app();
  return 0;
}

