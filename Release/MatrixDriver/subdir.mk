################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MatrixDriver/MatrixDriver.cpp 

OBJS += \
./MatrixDriver/MatrixDriver.o 

CPP_DEPS += \
./MatrixDriver/MatrixDriver.d 


# Each subdirectory must supply rules for building sources it contributes
MatrixDriver/%.o: ../MatrixDriver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino" -I"/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard" -I"/Users/jensheidrich/Documents/ArduinoProjects/LoopingLeni" -I"/Users/jensheidrich/Documents/ArduinoProjects/LoopingLeni/LoopingLouie" -I"/Users/jensheidrich/Documents/ArduinoProjects/LoopingLeni/MatrixDriver" -I"/Users/jensheidrich/Documents/ArduinoProjects/LoopingLeni/QueueArray" -I"/Users/jensheidrich/Documents/ArduinoProjects/LoopingLeni/SimpleTimer" -D__IN_ECLIPSE__=1 -DUSB_VID= -DUSB_PID= -DARDUINO=105 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


