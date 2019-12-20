################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CharTrieNode.cpp \
../src/Dictionary.cpp \
../src/DictionaryWords.cpp \
../src/RandomSubstitutionCipher.cpp \
../src/WordStatistics.cpp 

OBJS += \
./src/CharTrieNode.o \
./src/Dictionary.o \
./src/DictionaryWords.o \
./src/RandomSubstitutionCipher.o \
./src/WordStatistics.o 

CPP_DEPS += \
./src/CharTrieNode.d \
./src/Dictionary.d \
./src/DictionaryWords.d \
./src/RandomSubstitutionCipher.d \
./src/WordStatistics.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


