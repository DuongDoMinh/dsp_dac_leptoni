/**
  ******************************************************************************
  * @file    Leptoni DAC Display
  * @author  ds.DUONG
  * @version V1.1.1
  * @date    09-June-2018
  * @brief  Control Display - DAC - USB Audio
  ******************************************************************************
  * 
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"
#include "stm8l15x_conf.h"
#include "stm8l15x_lcd16x2.h"
#include "stdio.h"
#include "delay.h"
#include "msg_dsp_leptoni.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define vol_pot		GPIO_Pin_6 //DAC output pin
#define gpio_vol_pot		GPIOB
#define mute_out	GPIO_Pin_7 //mute output pin
#define gpio_mute_out		GPIOB
#define in_sel_0	GPIO_Pin_2 //select input0 output pin
#define gpio_in_sel_0		GPIOB
#define in_sel_1	GPIO_Pin_3 //select input1 output pin
#define gpio_in_sel_1		GPIOB
#define usb_f0          GPIO_Pin_2 //usb_f0 input pin
#define gpio_usb_f0		GPIOA
#define usb_f1          GPIO_Pin_3 //usb_f1 input pin
#define gpio_usb_f1		GPIOA
#define usb_f2          GPIO_Pin_4 //usb_f2 input pin
#define gpio_usb_f2		GPIOA
#define usb_f3          GPIO_Pin_5 //usb_f3 input pin
#define gpio_usb_f3		GPIOA
#define usb_mute        GPIO_Pin_6 //usb_mute input pin
#define gpio_usb_mute		GPIOA
#define usb_plug        GPIO_Pin_6 //usb_plug input pin
#define gpio_usb_plug		GPIOC
#define dsd_on          GPIO_Pin_0 //dsd_on input pin
#define gpio_dsd_on		GPIOB
#define dsd_64_128      GPIO_Pin_1 //dsd_64_128 input pin
#define gpio_dsd_64_128		GPIOB
//------select switch----
#define sw_up_vol      GPIO_Pin_5 //switch up volume input pin
#define gpio_sw_up_vol		GPIOC
#define sw_down_vol    GPIO_Pin_4 //switch down volume input pin
#define gpio_sw_down_vol        GPIOC
#define sw_vol_off      GPIO_Pin_3 //switch volume off input pin
#define gpio_sw_vol_off		GPIOC
#define sw_vol_ctr    GPIO_Pin_2 //switch volume control input pin
#define gpio_sw_vol_ctr        GIOC
#define sw_sel_up      GPIO_Pin_5 //switch select up input pin
#define gpio_sw_sel_up		GPIOB
#define sw_sel_down      GPIO_Pin_4 //switch select down input pin
#define gpio_sw_sel_down	GPIOB
//-----------------------       

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char m[35]; //LCD string variable
short s_f_usb_plug = 0; //usb plugged flag
short s_f_usb_mute = 0; //usb mute flag
short s_f_usb_f0 = 0; //usb f0 flag
short s_f_usb_f1 = 0; //usb f1 flag
short s_f_usb_f2 = 0; //usb f2 flag
short s_f_usb_f3 = 0; //usb f3 flag
short s_f_dsd_on = 0; //dsd on flag
short s_f_dsd_64_128 = 0; //dsd 64 or 128 flag
short s_f_mute_out = 0; //mute out flag
short s_f_in_sel_0 = 0; //in select 0 flag
short s_f_in_sel_1 = 0; //in select 1 flag
short s_f_sw_up_vol = 0; //sw_up_vol flag
short s_f_sw_down_vol = 0; //sw_down_vol flag
short s_f_sw_vol_off = 0; //sw_vol_off flag
short s_f_sw_vol_ctr = 0; //sw_vol_ctr flag
short s_f_sw_sel_up = 0; //sw_sel_up flag
short s_f_sw_sel_down = 0; //sw_sel_down flag

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
void main(void)
{
  GPIO_DeInit(GPIOD); //init port D
  //GPIO_DeInit(GPIOC);
  //GPIO_DeInit(GPIOB);
  init_LCD();
  //init_i2c();
  
  sprintf(&m[0],"Leptoni DAC");
  wr_str(&m[0]);
  gotoxy(1,1);
  sprintf(&m[0],"Badila Team");
  wr_str(&m[0]);
  

  while (1)
  {
    //_delay_ms(100); //waiting 1 second    
    //s_f_sw_up_vol = GPIO_ReadInputDataBit(gpio_sw_up_vol, sw_up_vol); //read value sw_up_vol
    if (GPIO_ReadInputDataBit(gpio_sw_up_vol, sw_up_vol)==0) {while(GPIO_ReadInputDataBit(gpio_sw_up_vol, sw_up_vol)==0);    }
    //s_f_sw_down_vol = GPIO_ReadInputDataBit(gpio_sw_down_vol, sw_down_vol); //read value sw_up_vol
    if (GPIO_ReadInputDataBit(gpio_sw_down_vol, sw_down_vol)==0) {while(GPIO_ReadInputDataBit(gpio_sw_down_vol, sw_down_vol)==0);}
  }
}

//------------------------------------------------------------------------------
//----Function subs-------------------------------------------------------------

//------------------------------------------------------------------------------
void Delay(uint32_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
