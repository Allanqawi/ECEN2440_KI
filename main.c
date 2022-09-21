#include "msp.h"
#include "gpio.h"
#include "handlers.h"
#include <stdlib.h>

void main(void)
{
    // button at 1.1 to reset
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    //Winner LED setup
    P2->DIR |= BIT4; //sets pins as outputs
    P5->DIR |= BIT6;
    P6->DIR |= BIT6;
    P2->OUT &= ~BIT4; //turns off winner LEDS
    P5->OUT &= ~BIT6;
    P6->OUT &= ~BIT6;
    //Temporarily disable interrupts to configure P1.0
    __disable_irq();                //Disables all interrupts
    __NVIC_DisableIRQ(PORT1_IRQn);  //Disables just the one for PORT1 in the NVIC
    __NVIC_DisableIRQ(PORT2_IRQn);  // disables port 2 interrupt
    //1. Configure Peripheral and Peripheral Interrupt
    //2. Configure NVIC for Peripheral Interrupt
    //3. Write ISR Handler
    // GPIO P1 Definition
    //BUTTON 1.1 and 3 external buttons 2.5,2.6,2.7
    P1-> SEL0 &= ~BIT1; //Configuring GPIO function
    P1-> SEL1 &= ~BIT1;
    P2-> SEL0 &= ~BIT5; //Configuring GPIO function
    P2-> SEL1 &= ~BIT5;
    P2-> SEL0 &= ~BIT6; //Configuring GPIO function
    P2-> SEL1 &= ~BIT6;
    P2-> SEL0 &= ~BIT7; //Configuring GPIO function
    P2-> SEL1 &= ~BIT7;
    //Pull up Resistor -> Push button will be a LLH
    //DIR = 0, REN = 1, OUT = 1
    P1-> DIR &= ~BIT1;
    P1-> REN |= BIT1;
    P1-> OUT |= BIT1;
    P2-> DIR &= ~BIT5;
    P2-> REN |= BIT5;
    P2-> OUT |= BIT5;
    P2-> DIR &= ~BIT6;
    P2-> REN |= BIT6;
    P2-> OUT |= BIT6;
    P2-> DIR &= ~BIT7;
    P2-> REN |= BIT7;
    P2-> OUT |= BIT7;

    //Clear the flag
    P1->IFG &= ~BIT1;
    P2->IFG &= ~BIT5;
    P2->IFG &= ~BIT6;
    P2->IFG &= ~BIT7;
    //INTERRUPT: Low to high transition, rising edge, set IES to 0
    P1-> IES &= ~BIT1;
    P2-> IES &= ~BIT5;
    P2-> IES &= ~BIT6;
    P2-> IES &= ~BIT7;
    //Enable the interrupt within the peripheral
    P1-> IE |= BIT1;
    P2-> IE |= BIT5;
    P2-> IE |= BIT6;
    P2-> IE |= BIT7;
    //Clear the flag
    P1->IFG &= ~BIT1;
    P2->IFG &= ~BIT5;
    P2->IFG &= ~BIT6;
    P2->IFG &= ~BIT7;
    //  NVIC Configuration
    //HAL - Hardware Abstraction Layer, core_cm4.h syntax for NVIC
    //Set priority for the IRQn P1, 35, Priority sets order of precendence for interrupts
    //This is a 3-bit number between 0 and 7, 0 being the lowest and 7 being the highest
    //NVIC->IP[PORT1_IRQn] |= 0x04;
    __NVIC_EnableIRQ(PORT1_IRQn);
    __NVIC_EnableIRQ(PORT2_IRQn);
    //35  0000 0000 0000 0000 0000 0000 0000 1000
    //Enable Interrupts
    __enable_irq();
    //Set the flag
    //P1->IFG |= BIT1;
    while(1);
}
