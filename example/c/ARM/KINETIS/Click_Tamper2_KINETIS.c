/*
Example for Tamper2 Click

    Date          : Nov 2017.
    Author        : MikroE Team

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v5.1.0.0

---
Description :

The application is composed of three sections :

- System Initialization - GPIO and UART initialization 
- Application Initialization - Sends HAL pointers
- Application Task - Detects whether the state of switch on Tamper 2 click is ON or OFF.

Additional Functions :

-   
-

*/

#include "Click_Tamper2_types.h"


uint8_t getAN()
{
     return PTB_PDIR.B2;
}
uint8_t getINT()
{
     return PTB_PDIR.B13;
}

typedef void    (*T_hal_gpioSetFp)(uint8_t);
typedef uint8_t (*T_hal_gpioGetFp)();

typedef struct
{
    T_hal_gpioSetFp      gpioSet[ 12 ];
    T_hal_gpioGetFp      gpioGet[ 12 ];

}T_hal_gpioObj;

const T_hal_gpioObj GPIO_BUS =
{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { &getAN, 0, 0, 0, 0, 0, 0, &getINT, 0, 0, 0, 0 }
};
void systemInit()
{
     GPIO_Digital_Input(&PTB_PDIR, _GPIO_PINMASK_2);
     GPIO_Digital_Input(&PTB_PDIR, _GPIO_PINMASK_13);
     UART0_Init(9600);
     Delay_ms( 100 );
}

void applicationInit()
{
     tamper2_gpioDriverInit( (T_TAMPER2_P)&GPIO_BUS );
}

void applicationTask()
{
    if(tamper2_getOnState())
    {
        UART0_Write_text("Tamper 2 click is in ON state.");
		UART0_Write(13);
		UART0_Write(10);
		
    }
    if(tamper2_getOffState())
    {
       UART0_Write_text("Tamper 2 click is in OFF state.");
	   UART0_Write(13);
	   UART0_Write(10);
		
    }
    Delay_ms(200);
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
