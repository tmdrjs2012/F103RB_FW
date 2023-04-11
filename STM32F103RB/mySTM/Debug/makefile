################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/lib/STM32F1xx_HAL_Driver/Src/Legacy/subdir.mk
-include src/lib/STM32F1xx_HAL_Driver/Src/subdir.mk
-include src/lib/FreeRTOS/Source/portable/MemMang/subdir.mk
-include src/lib/FreeRTOS/Source/portable/GCC/ARM_CM3/subdir.mk
-include src/lib/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include src/lib/FreeRTOS/Source/subdir.mk
-include src/hw/core/subdir.mk
-include src/hw/subdir.mk
-include src/common/subdir.mk
-include src/bsp/startup/subdir.mk
-include src/bsp/cmsis/subdir.mk
-include src/bsp/subdir.mk
-include src/app/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := mySTM
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
mySTM.elf \

MAP_FILES += \
mySTM.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
mySTM.list \


# All Target
all: main-build

# Main-build Target
main-build: mySTM.elf secondary-outputs

# Tool invocations
mySTM.elf mySTM.map: $(OBJS) $(USER_OBJS) /home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/ldscript/STM32F103XB_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "mySTM.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"/home/encanto/MY_PROJECT/STM32/STMF1/STM32F103RB/mySTM/src/bsp/ldscript/STM32F103XB_FLASH.ld" --specs=nosys.specs -Wl,-Map="mySTM.map" -Wl,--gc-sections -static -u_printf_float --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

mySTM.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "mySTM.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout mySTM.elf mySTM.list mySTM.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
