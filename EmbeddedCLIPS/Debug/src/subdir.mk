################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EmbeddedCLIPS.cpp \
../src/myFuncDummy.cpp 

OBJS += \
./src/EmbeddedCLIPS.o \
./src/myFuncDummy.o 

CPP_DEPS += \
./src/EmbeddedCLIPS.d \
./src/myFuncDummy.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/sidd/dev/cpp/workspace/CLIPS/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


