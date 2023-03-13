################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/TSS/TSS_Freemaster.c \
../Sources/TSS/TSS_Sensor.c \
../Sources/TSS/TSS_SensorGPIO.c \
../Sources/TSS/TSS_SensorTSI.c \
../Sources/TSS/TSS_SensorTSIL.c \
../Sources/TSS/TSS_SystemSetupData.c 

OBJS += \
./Sources/TSS/TSS_Freemaster.o \
./Sources/TSS/TSS_Sensor.o \
./Sources/TSS/TSS_SensorGPIO.o \
./Sources/TSS/TSS_SensorTSI.o \
./Sources/TSS/TSS_SensorTSIL.o \
./Sources/TSS/TSS_SystemSetupData.o 

C_DEPS += \
./Sources/TSS/TSS_Freemaster.d \
./Sources/TSS/TSS_Sensor.d \
./Sources/TSS/TSS_SensorGPIO.d \
./Sources/TSS/TSS_SensorTSI.d \
./Sources/TSS/TSS_SensorTSIL.d \
./Sources/TSS/TSS_SystemSetupData.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/TSS/%.o: ../Sources/TSS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/traja/miniproject/MPWS/Static_Code/PDD" -I"C:/Users/traja/miniproject/MPWS/Static_Code/IO_Map" -I"C:/Users/traja/miniproject/MPWS/Sources" -I"C:/Users/traja/miniproject/MPWS/Generated_Code" -I"C:/Users/traja/miniproject/MPWS/Sources/TSS" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


