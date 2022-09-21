#include "msp.h"
#include "handlers.h"
#include "gpio.h"
volatile uint16_t counter = 0, p1=0, p2=0,p3=0;
/*
 * handlers.c
 *
 *  Created on: Sep 14, 2022
 *      Author: brenn
 */

//this file will contain all the handler functions

// interrupt to start sequence of lights
void PORT1_IRQHandler(void){
    if((P1->IFG & BIT1)==BIT1){
        __disable_irq(); //disable interrupts so that you can't press button b4 play has started
        P2->OUT &= ~BIT4; //turns off winner LEDS
        P5->OUT &= ~BIT6;
        P6->OUT &= ~BIT6;
        //counter++; //from interrupts demo
        count_down(); //calls driver that runs the count down LEDS
        //P1->DIR |= BIT0; //interrupt check
        //P1->OUT |= BIT0;
        P1->IFG &= ~BIT1; // clear flag
        __enable_irq(); //enable interrupts so that the winner can be determined
    }
    __NVIC_EnableIRQ(PORT1_IRQn);
}
// interrupt to recognize winner
void PORT2_IRQHandler(void){
    __disable_irq();
    if((P2->IFG & BIT5)==BIT5){
        P5->OUT &= ~BIT6; P2->OUT &= ~BIT4; P6->OUT &=  ~BIT6;
        //__disable_irq(); //maybe needed to stop program from detecting multiple button presses
        //P5->DIR |= BIT6; //Declared in main hopefully unneeded here
        P5->OUT |= BIT6; //turns on LED
        //p1++; // first player wins
        P2->IFG &= ~BIT5; // clear flag
    }
    if((P2->IFG & BIT6)==BIT6){
        P5->OUT &= ~BIT6; P2->OUT &= ~BIT4; P6->OUT &=  ~BIT6;
        //__disable_irq(); //from above
        //P2->DIR |= BIT4; //Declared in main hopefully unneeded here
        P2->OUT |= BIT4; //turns on LED
        //p2++; // second player wins
        P2->IFG &= ~BIT6; // clear flag
    }
    if((P2->IFG & BIT7)==BIT7){
        P5->OUT &= ~BIT6; P2->OUT &= ~BIT4; P6->OUT &=  ~BIT6;
        //__disable_irq(); //from above
        //P6->DIR |= BIT6; //Declared in main hopefully unneeded here
        P6->OUT |= BIT6; //turns on LED
        //p3++; // third player wins
        P2->IFG &= ~BIT7; // clear flag
    }
    __enable_irq(); //needed if we turn of irq in if statements
    __NVIC_EnableIRQ(PORT2_IRQn);
}
