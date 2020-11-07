################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
h743Loader.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
h743Loader.list \

OBJCOPY_BIN += \
h743Loader.bin \


# All Target
all:
	+@make --no-print-directory main-build && make --no-print-directory post-build

# Main-build Target
main-build: h743Loader.elf secondary-outputs

# Tool invocations
h743Loader.elf: $(OBJS) $(USER_OBJS) C:\Users\deive\Documents\workspace_cubeide\h743Loader\STM32H743IITX_FLASH.ld
	arm-none-eabi-gcc -o "h743Loader.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\deive\Documents\workspace_cubeide\h743Loader\STM32H743IITX_FLASH.ld" -Wl,-Map="h743Loader.map" -static -Wl,-cref,-u,Reset_Handler, --entry=Init --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

h743Loader.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "h743Loader.list"
	@echo 'Finished building: $@'
	@echo ' '

h743Loader.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "h743Loader.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	cmd.exe /C copy/Y  "h743Loader.elf" "..\QSPI_flashloader_CSP.stldr"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
