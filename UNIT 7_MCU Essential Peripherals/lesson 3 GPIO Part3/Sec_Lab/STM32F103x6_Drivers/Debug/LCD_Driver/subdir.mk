################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_Driver/LCD_Programme.c 

OBJS += \
./LCD_Driver/LCD_Programme.o 

C_DEPS += \
./LCD_Driver/LCD_Programme.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_Driver/LCD_Programme.o: ../LCD_Driver/LCD_Programme.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Embedded Systems/Keroles projects/STM32F103x6_Drivers/KEYPAD_Driver" -I../Inc -I"D:/Embedded Systems/Keroles projects/STM32F103x6_Drivers/Stm32_F103C6_Drivers/inc" -I"D:/Embedded Systems/Keroles projects/STM32F103x6_Drivers/LCD_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD_Driver/LCD_Programme.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

