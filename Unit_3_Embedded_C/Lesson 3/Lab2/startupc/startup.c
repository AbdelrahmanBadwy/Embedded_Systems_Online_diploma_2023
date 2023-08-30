// Comment: This code is a startup code.
//Eng.Abdelrahman_ElBadawy
//30/8/2023
// It defines exception vectors, initializes data and bss sections, and jumps to the main function.

// Comment: Header file for fixed-size integer types.
#include <stdint.h>

// Comment: External declaration of the main function.
extern int main(void);

// Comment: External declarations of addresses from the linker script.
extern uint32_t _E_text;
extern uint32_t _S_Data;
extern uint32_t _E_Data;
extern uint32_t _S_Bss;
extern uint32_t _E_Bss;
extern uint32_t stack_top;

// Comment: Declaration of default and reset handlers.
void Default_Handler();
void Rest_Handler(void);

// Comment: Definition of weak exception handlers, which can be overridden.
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

// Comment: Vector table containing the initial addresses of exception handlers.
uint32_t Vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t) &stack_top,           // Initial stack pointer value
    (uint32_t) &Rest_Handler,        // Reset handler address
    (uint32_t) &NMI_Handler,         // NMI handler address
    (uint32_t) &H_Fault_Handler,     // Hard Fault handler address
    (uint32_t) &MM_Fault_Handler,    // Memory Management Fault handler address
    (uint32_t) &Bus_Fault,           // Bus Fault handler address
    (uint32_t) &Usage_Fault_Handler, // Usage Fault handler address
};

// Comment: Default handler that just jumps to the reset handler.
void Default_Handler() {
    Rest_Handler();
}

// Comment: Reset handler that initializes data and bss sections, then jumps to the main function.
void Rest_Handler(void) {
    uint32_t i;

    // Comment: Calculate the size of the data section.
    uint32_t data_size = (uint8_t*)&_E_Data - (uint8_t*)&_S_Data;
    uint8_t *p_src = (uint8_t*)&_E_text; // Source data location
    uint8_t *p_des = (uint8_t*)&_S_Data; // Destination data location

    // Comment: Copy data section from flash to RAM.
    for (i = 0; i < data_size; ++i) {
        *((uint8_t*)p_des++) = *((uint8_t*)p_src++);
    }

    // Comment: Calculate the size of the bss section.
    uint32_t bss_size = (uint8_t*)&_E_Bss - (uint8_t*)&_S_Bss;
    p_des = (uint8_t*)&_S_Bss; // BSS section location

    // Comment: Initialize the bss section with zeros.
    for (i = 0; i < bss_size; ++i) {
        *((uint8_t*)p_des++) = (uint8_t)0;
    }

    // Comment: Jump to the main function.
    main();
}
