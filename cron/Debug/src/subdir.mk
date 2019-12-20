################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cron.cpp \
../src/CronEntry.cpp \
../src/Schedule.cpp \
../src/start.cpp 

OBJS += \
./src/Cron.o \
./src/CronEntry.o \
./src/Schedule.o \
./src/start.o 

CPP_DEPS += \
./src/Cron.d \
./src/CronEntry.d \
./src/Schedule.d \
./src/start.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


