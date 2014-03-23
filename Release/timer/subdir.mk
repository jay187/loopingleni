################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../timer/Event.cpp \
../timer/Timer.cpp 

CPP_DEPS += \
./timer/Event.cpp.d \
./timer/Timer.cpp.d 

LINK_OBJ += \
./timer/Event.cpp.o \
./timer/Timer.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
timer/Event.cpp.o: ../timer/Event.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/home/user/eclipseArduino/workspace/LoopingLeni/LoopingLouie" -I"/home/user/eclipseArduino/workspace/LoopingLeni/MatrixDriver" -I"/home/user/eclipseArduino/workspace/LoopingLeni/QueueArray" -I"/home/user/eclipseArduino/workspace/LoopingLeni/timer" -I"/home/user/eclipseArduino/workspace/LoopingLeni/SimpleTimer" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -w
	@echo 'Finished building: $<'
	@echo ' '

timer/Timer.cpp.o: ../timer/Timer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/user/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/home/user/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/home/user/eclipseArduino/workspace/LoopingLeni/LoopingLouie" -I"/home/user/eclipseArduino/workspace/LoopingLeni/MatrixDriver" -I"/home/user/eclipseArduino/workspace/LoopingLeni/QueueArray" -I"/home/user/eclipseArduino/workspace/LoopingLeni/timer" -I"/home/user/eclipseArduino/workspace/LoopingLeni/SimpleTimer" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -w
	@echo 'Finished building: $<'
	@echo ' '


