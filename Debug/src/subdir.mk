################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TpTallerSonic.cpp \
../src/capas.cpp \
../src/circulo.cpp \
../src/dimensiones.cpp \
../src/jconfiguracion.cpp \
../src/jentidades.cpp \
../src/jescenario.cpp \
../src/jventana.cpp \
../src/rectangulo.cpp 

OBJS += \
./src/TpTallerSonic.o \
./src/capas.o \
./src/circulo.o \
./src/dimensiones.o \
./src/jconfiguracion.o \
./src/jentidades.o \
./src/jescenario.o \
./src/jventana.o \
./src/rectangulo.o 

CPP_DEPS += \
./src/TpTallerSonic.d \
./src/capas.d \
./src/circulo.d \
./src/dimensiones.d \
./src/jconfiguracion.d \
./src/jentidades.d \
./src/jescenario.d \
./src/jventana.d \
./src/rectangulo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


