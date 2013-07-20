################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/jensheidrich/Documents/Arduino/leOS/leOS.cpp 

OBJS += \
./leOS/leOS.o 

CPP_DEPS += \
./leOS/leOS.d 


# Each subdirectory must supply rules for building sources it contributes
leOS/leOS.o: /Users/jensheidrich/Documents/Arduino/leOS/leOS.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino" -I"/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard" -I"/Users/jensheidrich/Documents/ArduinoProjects/LoopingLeni" -I"/Users/jensheidrich/Documents/Arduino/LoopingLouie" -I"/Users/jensheidrich/Documents/Arduino/MatrixDriver" -I"/Users/jensheidrich/Documents/Arduino/TimerOne" -I"/Users/jensheidrich/Documents/Arduino/leOS2" -I"/Users/jensheidrich/Documents/Arduino/Looper" -I"/Users/jensheidrich/Documents/Arduino/leOS" -D__IN_ECLIPSE__=1 -DUSB_VID= -DUSB_PID= -DARDUINO=105 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


