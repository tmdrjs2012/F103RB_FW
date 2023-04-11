################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./src/lib/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./src/lib/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/FreeRTOS/Source/CMSIS_RTOS/%.o src/lib/FreeRTOS/Source/CMSIS_RTOS/%.su: ../src/lib/FreeRTOS/Source/CMSIS_RTOS/%.c src/lib/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis/Include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/STM32F1xx_HAL_Driver/Inc" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/app" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/common" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/hw" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/CMSIS_RTOS" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/portable/GCC/ARM_CM3" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-lib-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS

clean-src-2f-lib-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS:
	-$(RM) ./src/lib/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d ./src/lib/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o ./src/lib/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.su

.PHONY: clean-src-2f-lib-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS

