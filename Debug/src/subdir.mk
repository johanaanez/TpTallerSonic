################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TpTallerSonic.cpp \
../src/capas.cpp \
../src/dimensiones.cpp \
../src/jcirculo.cpp \
../src/jconfiguracion.cpp \
../src/jentidades.cpp \
../src/jescenario.cpp \
../src/jescenarioJuego.cpp \
../src/jpruebas.cpp \
../src/jrectangulo.cpp \
../src/jventana.cpp \
../src/parseadorJson.cpp 

OBJS += \
./src/TpTallerSonic.o \
./src/capas.o \
./src/dimensiones.o \
./src/jcirculo.o \
./src/jconfiguracion.o \
./src/jentidades.o \
./src/jescenario.o \
./src/jescenarioJuego.o \
./src/jpruebas.o \
./src/jrectangulo.o \
./src/jventana.o \
./src/parseadorJson.o 

CPP_DEPS += \
./src/TpTallerSonic.d \
./src/capas.d \
./src/dimensiones.d \
./src/jcirculo.d \
./src/jconfiguracion.d \
./src/jentidades.d \
./src/jescenario.d \
./src/jescenarioJuego.d \
./src/jpruebas.d \
./src/jrectangulo.d \
./src/jventana.d \
./src/parseadorJson.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


