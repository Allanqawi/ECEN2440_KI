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
        __disable_irq();
        counter++;
        //count_down();
        P1->DIR |= BIT0;
        P1->OUT |= BIT0;
        P1->IFG &= ~BIT1; // clear flag
        __enable_irq();
    }
    __NVIC_EnableIRQ(PORT1_IRQn);
}
// interrupt to recognize winner
void PORT2_IRQHandler(void){
    if((P2->IFG & BIT5)==BIT5){
        p1++; // first player wins
        P2->IFG &= ~BIT5; // clear flag
    }
    if((P2->IFG & BIT6)==BIT6){
            p2++; // second player wins
            P2->IFG &= ~BIT6; // clear flag
    }
    if((P2->IFG & BIT7)==BIT7){
            p3++; // third player wins
            P2->IFG &= ~BIT7; // clear flag
    }
    __NVIC_EnableIRQ(PORT2_IRQn);
}
