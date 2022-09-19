/*
 * gpio.c
 *
 *  Created on: Aug 29, 2022
 *      Author: brenn
 */
#include "msp.h"
#include "gpio.h"

#define LED1 BIT0 //(0000 0000 0000 0001)
#define LED2 BIT1 //(0000 0000 0000 0010)
#define LED3 BIT2 //(0000 0000 0000 0100)
#define S1 BIT1 //(0000 0000 0000 0010)
#define S4 BIT4

//example for toggling LED
/*
void gpio_toggle_red_led(){
    volatile uint32_t i;
    P1->DIR |= BIT0;

    P1->OUT ^= BIT0;
    for(i = 200000; i > 0; i--);
}
*/

void count_down(void){
/*
 * count_down circuit
 *
 * created September 19, 2022
 * Author: Dakota Augenstein
 *
 * This Driver is intended to turn on 3 LEDS that are green yellow and red
 * it will start by turning them all on and will then turn them off similarly to a drag strips lights
 */

    //int LED_finished = 0; //could be used as an indicator to see if the driver has finsihed

    P6->DIR |= BIT7;
    P2->DIR |= BIT3;
    P5->DIR |= BIT1; //sets pins as outputs

    P6->OUT |= BIT7;
    P2->OUT |= BIT3;
    P5->OUT |= BIT1; //turns all leds on

    int i = 0;
    for(i = 0; i < 30000; i++);
    i = 0; //delay

    P5->OUT ^= BIT1;
    for(i = 0; i < 30000; i++);
    i = 0; //turns off red

    P2->OUT ^= BIT3;
    for(i = 0; i < 30000; i++);
    i = 0; //turns off yellow

    P6->OUT ^= BIT7;
    for(i = 0; i < 30000; i++);
    i = 0; //turns off green

    //LED_finished = 1;
}
