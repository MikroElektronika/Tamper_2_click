#include "Click_Tamper2_types.h"

#ifdef  ENABLE_SPI
const uint32_t _TAMPER2_SPI_CFG[ 3 ] = 
{ 
	1000000, 
	_SPI_MASTER, 
	_SPI_8_BIT | 
	_SPI_CLK_IDLE_HIGH |
	_SPI_SECOND_CLK_EDGE_TRANSITION 
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _TAMPER2_I2C_CFG[ 1 ] = 
{ 
	_I2C_BITRATE_STANDARD_MODE 
};
#endif

#ifdef ENABLE_UART
const uint32_t _TAMPER2_UART_CFG[ 6 ] = 
{
	9600, 
	9600, 
	_UART_8_BIT_DATA, 
	_UART_NOPARITY,
    _UART_ONE_STOPBIT, 
    _UART_HIGH_SPEED
};
#endif
