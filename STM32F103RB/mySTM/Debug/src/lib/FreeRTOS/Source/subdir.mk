################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/FreeRTOS/Source/croutine.c \
../src/lib/FreeRTOS/Source/event_groups.c \
../src/lib/FreeRTOS/Source/list.c \
../src/lib/FreeRTOS/Source/queue.c \
../src/lib/FreeRTOS/Source/stream_buffer.c \
../src/lib/FreeRTOS/Source/tasks.c \
../src/lib/FreeRTOS/Source/timers.c 

OBJS += \
./src/lib/FreeRTOS/Source/croutine.o \
./src/lib/FreeRTOS/Source/event_groups.o \
./src/lib/FreeRTOS/Source/list.o \
./src/lib/FreeRTOS/Source/queue.o \
./src/lib/FreeRTOS/Source/stream_buffer.o \
./src/lib/FreeRTOS/Source/tasks.o \
./src/lib/FreeRTOS/Source/timers.o 

C_DEPS += \
./src/lib/FreeRTOS/Source/croutine.d \
./src/lib/FreeRTOS/Source/event_groups.d \
./src/lib/FreeRTOS/Source/list.d \
./src/lib/FreeRTOS/Source/queue.d \
./src/lib/FreeRTOS/Source/stream_buffer.d \
./src/lib/FreeRTOS/Source/tasks.d \
./src/lib/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/FreeRTOS/Source/%.o src/lib/FreeRTOS/Source/%.su: ../src/lib/FreeRTOS/Source/%.c src/lib/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/cmsis/Include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/STM32F1xx_HAL_Driver/Inc" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/app" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/common" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/hw" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/CMSIS_RTOS" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/include" -I"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/lib/FreeRTOS/Source/portable/GCC/ARM_CM3" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-lib-2f-FreeRTOS-2f-Source

clean-src-2f-lib-2f-FreeRTOS-2f-Source:
	-$(RM) ./src/lib/FreeRTOS/Source/croutine.d ./src/lib/FreeRTOS/Source/croutine.o ./src/lib/FreeRTOS/Source/croutine.su ./src/lib/FreeRTOS/Source/event_groups.d ./src/lib/FreeRTOS/Source/event_groups.o ./src/lib/FreeRTOS/Source/event_groups.su ./src/lib/FreeRTOS/Source/list.d ./src/lib/FreeRTOS/Source/list.o ./src/lib/FreeRTOS/Source/list.su ./src/lib/FreeRTOS/Source/queue.d ./src/lib/FreeRTOS/Source/queue.o ./src/lib/FreeRTOS/Source/queue.su ./src/lib/FreeRTOS/Source/stream_buffer.d ./src/lib/FreeRTOS/Source/stream_buffer.o ./src/lib/FreeRTOS/Source/stream_buffer.su ./src/lib/FreeRTOS/Source/tasks.d ./src/lib/FreeRTOS/Source/tasks.o ./src/lib/FreeRTOS/Source/tasks.su ./src/lib/FreeRTOS/Source/timers.d ./src/lib/FreeRTOS/Source/timers.o ./src/lib/FreeRTOS/Source/timers.su

.PHONY: clean-src-2f-lib-2f-FreeRTOS-2f-Source

