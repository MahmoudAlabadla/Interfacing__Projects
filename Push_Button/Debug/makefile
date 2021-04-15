################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Push_Button.lss \

FLASH_IMAGE += \
Push_Button.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Push_Button.elf secondary-outputs

# Tool invocations
Push_Button.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Push_Button.map -mmcu=atmega32 -o "Push_Button.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Push_Button.lss: Push_Button.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Push_Button.elf  >"Push_Button.lss"
	@echo 'Finished building: $@'
	@echo ' '

Push_Button.hex: Push_Button.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Push_Button.elf  "Push_Button.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Push_Button.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Push_Button.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Push_Button.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
