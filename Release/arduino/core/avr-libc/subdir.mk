################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/malloc.c \
/home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/realloc.c 

C_DEPS += \
./arduino/malloc.c.d \
./arduino/realloc.c.d 

AR_OBJ += \
./arduino/malloc.c.o \
./arduino/realloc.c.o 


# Each subdirectory must supply rules for building sources it contributes
arduino/malloc.c.o: /home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/malloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/home/user/eclipseArduino/workspace/LoopingLeni/LoopingLouie" -I"/home/user/eclipseArduino/workspace/LoopingLeni/MatrixDriver" -I"/home/user/eclipseArduino/workspace/LoopingLeni/QueueArray" -I"/home/user/eclipseArduino/workspace/LoopingLeni/timer" -I"/home/user/eclipseArduino/workspace/LoopingLeni/SimpleTimer" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -w
	@echo 'Finished building: $<'
	@echo ' '

arduino/realloc.c.o: /home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/realloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/home/user/eclipseArduino/workspace/LoopingLeni/LoopingLouie" -I"/home/user/eclipseArduino/workspace/LoopingLeni/MatrixDriver" -I"/home/user/eclipseArduino/workspace/LoopingLeni/QueueArray" -I"/home/user/eclipseArduino/workspace/LoopingLeni/timer" -I"/home/user/eclipseArduino/workspace/LoopingLeni/SimpleTimer" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -w
	@echo 'Finished building: $<'
	@echo ' '


