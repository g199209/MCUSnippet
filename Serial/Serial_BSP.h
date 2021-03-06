/**
  **************************************************************
  * @file       Serial_BSP.h
  * @author	    高明飞
  * @version    V1.1
  * @date       2015-11-26
  *
  * @brief      串口数据发送抽象接口
  *
  * @details 
  * @verbatim
  * 本程序主要封装了一些常用的串口数据发送函数，便于不同项目中重复使用。
  * 需要配合底层HAL程序使用。
  *
  * 修改记录：
  * 2015-07-19 :
  *   - File Created.
  * 2015-09-12 :
  *   - Bug Fixed;
  *   - 添加UART_LEGACY宏定义.
  * 2015-09-26 :
  *   - 修改注释格式使其可以使用Doxygen.
  * 2015-11-23 :
  *   - 进一步修改注释格式。
  * 2015-11-26 :
  *   - 去掉内联函数inline（因为很多编译器对此的支持均有问题）
  * @endverbatim
  *
  * @note
  * 程序中未包含具体的底层实现方法，在使用时需要根据具体平台改写相关宏定义。
  ***************************************************************
  */
 
#ifndef UARTSENDDATA_H
#define UARTSENDDATA_H
 
/* C++ */
#ifdef __cplusplus  
extern "C" {
#endif

/** @addtogroup Serial
  * @brief      串口数据发送模块
  * @{
  */
  
/*--------------------此部分需要修改--------------------*/
/* 编译选项开关，部分编译器（如51）不支持va_list等，此时不实现printf() */
//#define UART_LEGACY

/* 如未定义uint8_t等基本数据类型，需要先定义 */
//#include "TypeDef.h"

/* HAL层提供的UART底层实现宏定义，此处以TMS320F28027为例，需要根据实际情况修改 */

/* HAL头文件 */
#include "System.h"
#include "UART.h"

/**
  * UART发送数据宏定义，一般发送数据都是向某个寄存器中写入一个8位数据。
  * 此处data即为要发送的8位（1 byte）数据。
  */
#define HAL_UART_SEND_UINT8(UARTdata) (SciaRegs.SCITXBUF = UARTdata)

/**
  * UART判断是否可以发送新数据宏定义。
  * 一般都存在一个寄存器可以用于判断此时TX Buffer是否可以接收新数据。
  * 可以发送数据时，宏的值应为非0值；
  * 当宏的值为0时，代表此时不能发送新数据。
  */
#define HAL_UART_TX_READY (SciaRegs.SCICTL2.bit.TXRDY)

/*--------------------此部分需要修改--------------------*/

void UARTSendChar(const char c);

void UARTSendByte(const uint8_t UARTdata);

void UARTSendWord(const uint16_t UARTdata);

void UARTSendDword(const uint32_t UARTdata);

void UARTSendUnsignASCII(uint32_t UARTdata, uint8_t base, uint8_t align);

void UARTSendSignASCII(int32_t UARTdata, uint8_t align);

void UARTSendString(const char * str);

void UARTSendByteArray(const uint8_t * UARTdata, const uint16_t num);

void UARTSendWordArray(const uint16_t * UARTdata, const uint16_t num);

void UARTSendDwordArray(const uint32_t * UARTdata, const uint16_t num);

#ifndef UART_LEGACY
void UARTprintf(const char *format, ...);
#endif

/**
  * @}
  */


/* C++ */
#ifdef __cplusplus  
}
#endif
 
#endif
 
