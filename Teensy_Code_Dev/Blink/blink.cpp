#define GPIO(n) 0x401B8000+(n-1)*0x4000 // For GPIO[1,4]
#define GPIO_DR(n) GPIO(n) // GPIO Data Register
#define GPIO_GDIR(n) GPIO(n)+0x4 // GPIO Direction Register
#define GPIO_PSR(n) GPIO(n)+0x8 // GPIO Pad Status Register

#define REGISTER(address) (*((volatile uint32_t*) (address)))


int main() {
    // Setup LED for output mode
    REGISTER(GPIO_GDIR(2)) &= ~(0x1 << 3); // Clear pin 3 (sets pin as output)

    while(1) {
        // Set GPIO2-3
        REGISTER(GPIO_DR(2)) |= (0x1 << 3);

        // Assume 600MHz CPU Speed
        for(uint32_t i = 0; i < 200000000; i++) __asm__("nop");

        // Clear GPIO2-3
        REGISTER(GPIO_DR(2)) &= ~(0x1 << 3);
        
        // Assume 600MHz CPU Speed
        for(uint32_t i = 0; i < 200000000; i++) __asm__("nop");
    }
}