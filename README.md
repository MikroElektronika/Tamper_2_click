![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Tamper2 Click

- **CIC Prefix**  : TAMPER2
- **Author**      : MikroE Team

---

### Software Support

We provide a library for the Tamper2 Click on our [LibStock](http://libstock.mikroe.com/projects/view/2223/tamper-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).


Key functions :

- ``` uint8_t tamper2_getOffState(); ```  - Function detects if the switch is in OFF state.
- ``` uint8_t tamper2_getOnState();```  - Function detects if the switch is in ON state.


**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO pins used for tamper 2 and UART module used for data logging
- Application Initialization - Initializes Tamper 2 click GPIO pins
- Application Task - Check the state of both GPIO pins and reports current state by logging information to UART


```.c
void applicationTask()
{
    if(tamper2_getOnState())
    {
        UART1_Write_text("Tamper 2 click is in ON state.");
		UART1_Write(13);
		UART1_Write(10);
		
    }
    if(tamper2_getOffState())
    {
       UART1_Write_text("Tamper 2 click is in OFF state.");
	   UART1_Write(13);
	   UART1_Write(10);
		
    }
    Delay_ms(200);
}
```
The full application code, and ready to use projects can be found on our 
[LibStock](http://libstock.mikroe.com/projects/view/2223/tamper-2-click) page.

Other mikroE Libraries used in the example:

- UART
- GPIO

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
