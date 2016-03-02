#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "usbdrv.h"
#include <util/delay.h>

#define USB_LED_OFF 0
#define USB_LED_ON  1
#define LED_PIN PD3


USB_PUBLIC uchar usbFunctionSetup(uchar data[8]) {
	usbRequest_t *rq = (void *)data; // cast data to correct type
        
    switch(rq->bRequest) { // custom command is in the bRequest field
    case USB_LED_ON:
        PORTD &=~_BV(LED_PIN); // turn LED on 输出低点电平
        return 0;
    case USB_LED_OFF: 
        PORTD |= _BV(LED_PIN); // turn LED off
        return 0;
    }

    return 0; // should not get here

}

int main(void) {
    uchar i;
	DDRD|=_BV(LED_PIN);
    wdt_enable(WDTO_1S); // enable 1s watchdog timer

    usbInit();
        
    usbDeviceDisconnect(); // enforce re-enumeration
    for(i = 0; i<250; i++) { // wait 500 ms
        wdt_reset(); // keep the watchdog happy
        _delay_ms(2);
    }
    usbDeviceConnect();
        
    sei(); // Enable interrupts after re-enumeration
        
    while(1) {
        wdt_reset(); // keep the watchdog happy
        usbPoll();
		
		//PORTD &=~_BV(LED_PIN); // turn LED on 输出低点电平
		//_delay_ms(2000);
		//PORTD |= _BV(LED_PIN); // turn LED off
		//_delay_ms(2000);
    }
        
    return 0;
}
