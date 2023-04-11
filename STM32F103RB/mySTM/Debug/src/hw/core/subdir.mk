################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/core/adc.c \
../src/hw/core/cmd.c \
../src/hw/core/flash.c \
../src/hw/core/gpio.c \
../src/hw/core/pwm.c \
../src/hw/core/uart.c 

OBJS += \
./src/hw/core/adc.o \
./src/hw/core/cmd.o \
./src/hw/core/flash.o \
./src/hw/core/gpio.o \
./src/hw/core/pwm.o \
./src/hw/core/uart.o 

C_DEPS += \
./src/hw/core/adc.d \
./src/hw/core/cmd.d \
./src/hw/core/flash.d \
./src/hw/core/gpio.d \
./src/hw/core/pwm.d \
./src/hw/core/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/core/%.o src/hw/core/%.su: ../src/hw/core/%.c src/hw/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis/Include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/STM32F1xx_HAL_Driver/Inc" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/app" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/common" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/hw" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/CMSIS_RTOS" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/portable/GCC/ARM_CM3" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-hw-2f-core

clean-src-2f-hw-2f-core:
	-$(RM) ./src/hw/core/adc.d ./src/hw/core/adc.o ./src/hw/core/adc.su ./src/hw/core/cmd.d ./src/hw/core/cmd.o ./src/hw/core/cmd.su ./src/hw/core/flash.d ./src/hw/core/flash.o ./src/hw/core/flash.su ./src/hw/core/gpio.d ./src/hw/core/gpio.o ./src/hw/core/gpio.su ./src/hw/core/pwm.d ./src/hw/core/pwm.o ./src/hw/core/pwm.su ./src/hw/core/uart.d ./src/hw/core/uart.o ./src/hw/core/uart.su

.PHONY: clean-src-2f-hw-2f-core

