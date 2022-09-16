#include "msp.h"
#include "gpio.h"
#include "handlers.h"


//below is an example for how to configure interrupts in main

/*
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    //Temporarily disable interrupts to configure P1.0
    __disable_irq();                //Disables all interrupts
    __NVIC_DisableIRQ(PORT1_IRQn);  //Disables just the one for PORT1 in the NVIC
    //1. Configure Peripheral and Peripheral Interrupt
    //2. Configure NVIC for Peripheral Interrupt
    //3. Write ISR Handler
    // GPIO P1 Definition
    //BUTTON
    P1-> SEL0 &= ~BIT1; //Configuring GPIO function
    P1-> SEL1 &= ~BIT1;
    //Pull up Resistor -> Push button will be a LLH
    //DIR = 0, REN = 1, OUT = 1
    P1-> DIR &= ~BIT1;
    P1-> REN |= BIT1;
    P1-> OUT |= BIT1;
    //Clear the flag
    P1->IFG &= ~BIT1;
    //INTERRUPT: Low to high transition, rising edge, set IES to 0
    P1-> IES &= ~BIT1;
    //Enable the interrupt within the peripheral
    P1-> IE |= BIT1;
    //P1 RED LED Configuration P1.0
    P1-> SEL0 &= ~BIT0;
    P1-> SEL1 &= ~BIT0;
    P1-> DIR |= BIT0;
    //Clear the flag
    P1->IFG &= ~BIT1;
    //  NVIC Configuration
    //HAL - Hardware Abstraction Layer, core_cm4.h syntax for NVIC
    //Set priority for the IRQn P1, 35, Priority sets order of precendence for interrupts
    //This is a 3-bit number between 0 and 7, 0 being the lowest and 7 being the highest
    //NVIC->IP[PORT1_IRQn] |= 0x04;
    __NVIC_EnableIRQ(PORT1_IRQn);
    //35  0000 0000 0000 0000 0000 0000 0000 1000
    //Enable Interrupts
    __enable_irq();
    //Set the flag
    P1->IFG |= BIT1;
    while(1)
    {
        printf("counter: %u\n", counter);
    }
}
*/

void main(void){
//nasser allanqawi
}

