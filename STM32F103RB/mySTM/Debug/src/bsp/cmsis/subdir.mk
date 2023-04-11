################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/cmsis/system_stm32f1xx.c 

OBJS += \
./src/bsp/cmsis/system_stm32f1xx.o 

C_DEPS += \
./src/bsp/cmsis/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/cmsis/%.o src/bsp/cmsis/%.su: ../src/bsp/cmsis/%.c src/bsp/cmsis/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis/Include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/STM32F1xx_HAL_Driver/Inc" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/app" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/common" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/hw" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/CMSIS_RTOS" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/portable/GCC/ARM_CM3" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-bsp-2f-cmsis

clean-src-2f-bsp-2f-cmsis:
	-$(RM) ./src/bsp/cmsis/system_stm32f1xx.d ./src/bsp/cmsis/system_stm32f1xx.o ./src/bsp/cmsis/system_stm32f1xx.su

.PHONY: clean-src-2f-bsp-2f-cmsis

