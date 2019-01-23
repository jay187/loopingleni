################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include timer/subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
-include SimpleTimer/subdir.mk
-include MatrixDriver/subdir.mk
-include LoopingLouie/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/user/eclipseArduino/workspace/LoopingLeni/Release/arduino.ar \

ELF += \
LoopingLeni.elf \

EEP += \
LoopingLeni.eep \

FLASH_IMAGE += \
LoopingLeni.hex \


# All Target
all: LoopingLeni

# Tool invocations
LoopingLeni: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-size" -A "/home/user/eclipseArduino/workspace/LoopingLeni/Release/LoopingLeni.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/user/eclipseArduino/workspace/LoopingLeni/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-ar" rcs "/home/user/eclipseArduino/workspace/LoopingLeni/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

LoopingLeni.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "/home/user/eclipseArduino/workspace/LoopingLeni/Release/LoopingLeni.elf"   $(LINK_OBJ) $(AR)  "/home/user/eclipseArduino/workspace/LoopingLeni/Release/arduino.ar" "-L/home/user/eclipseArduino/workspace/LoopingLeni/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

LoopingLeni.eep: $(ELF)
	@echo 'Create eeprom image'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "/home/user/eclipseArduino/workspace/LoopingLeni/Release/LoopingLeni.elf" "/home/user/eclipseArduino/workspace/LoopingLeni/Release/LoopingLeni.eep"
	@echo 'Finished building: $@'
	@echo ' '

LoopingLeni.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "/home/user/eclipseArduino/workspace/LoopingLeni/Release/LoopingLeni.elf" "/home/user/eclipseArduino/workspace/LoopingLeni/Release/LoopingLeni.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ELF)$(ASM_DEPS)$(CC_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) LoopingLeni
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
