################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CCodeGenerator.cpp \
../src/InputParser.cpp \
../src/LTMonitorLibGenerator.cpp 

OBJS += \
./src/CCodeGenerator.o \
./src/InputParser.o \
./src/LTMonitorLibGenerator.o 

CPP_DEPS += \
./src/CCodeGenerator.d \
./src/InputParser.d \
./src/LTMonitorLibGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


