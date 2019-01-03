/*
Example for Tamper2 Click

    Date          : Nov 2017.
    Author        : MikroE Team

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.2.1.0

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
     return GPIO_PIN9_bit;
}
uint8_t getINT()
{
     return GPIO_PIN3_bit;
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
     GPIO_Digital_Input( &GPIO_PORT_00_07, _GPIO_PINMASK_3 );
     GPIO_Digital_Input( &GPIO_PORT_08_15, _GPIO_PINMASK_1 );
     UART1_Init(9600);
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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
