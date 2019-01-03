/*
Example for Tamper2 Click

    Date          : Nov 2017.
    Author        : MikroE Team

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

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


sbit TAMPER_OFF_STATE_Direction at TRISB.B8;
sbit TAMPER_ON_STATE_Direction at TRISE.B8;

uint8_t getAN()
{
     return PORTB.B8;
}
uint8_t getINT()
{
     return PORTE.B8;
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
     AD1PCFG = 0xFFFF;
     TAMPER_OFF_STATE_Direction = 1;
     TAMPER_ON_STATE_Direction = 1;
     UART2_Init(9600);
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
        UART2_Write_text("Tamper 2 click is in ON state.");
		UART2_Write(13);
		UART2_Write(10);
		
    }
    if(tamper2_getOffState())
    {
       UART2_Write_text("Tamper 2 click is in OFF state.");
	   UART2_Write(13);
	   UART2_Write(10);
		
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
