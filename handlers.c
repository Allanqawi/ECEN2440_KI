/*
 * handlers.c
 *
 *  Created on: Sep 14, 2022
 *      Author: brenn
 */

//this file will contain all the handler functions

//this is an example of what handler function should look like
//it is used to process the interrupts sent from a button press to toggle an LED
/*
void PORT1_IRQHandler(void)
{
    if((P1->IFG & BIT1)==BIT1){
        counter++;          //increment global variable
        //When leaving ISR clear P1 flag to let the NVIC know that we are done with
the interrupt
        P1 -> IFG &= ~BIT1;
        //Toggle the RED LED
        P1->OUT ^= BIT0;
    }
    //Enable Interrupts
   __NVIC_EnableIRQ(PORT1_IRQn);
}
*/
