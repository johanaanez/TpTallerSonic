################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TpTallerSonic.cpp \
../src/jasonentidades.cpp \
../src/jconfiguracion.cpp \
../src/jventana.cpp 

OBJS += \
./src/TpTallerSonic.o \
./src/jasonentidades.o \
./src/jconfiguracion.o \
./src/jventana.o 

CPP_DEPS += \
./src/TpTallerSonic.d \
./src/jasonentidades.d \
./src/jconfiguracion.d \
./src/jventana.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


