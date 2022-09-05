#include <ddp22_libs.h>
#include <gpio.h>
#include <int.h>


void ISR_GPIO (void)
{
    // According to DS reading the IRG status reg
    // in order to clear the interrupt flag
    uint32_t value = get_gpio_irq_status();
    bm_printf("\nFrom an IRQ!\n");
}

int main() 
{
    // GPIO 0 is E1 on board, just for a reference for VCC
    set_gpio_pin_value(0, 1);

    // Set GPIO 1 to trigger on rising edge 
    set_gpio_pin_irq_type(1, GPIO_IRQ_RISE);
    set_gpio_pin_irq_en(1, 1);

    // Enable general interrupt functionality 
    int_enable();

    // Do nothing and wait for interrupt 
    while(1)
    {
    }

    bm_quit_app();
    return 0;
}

