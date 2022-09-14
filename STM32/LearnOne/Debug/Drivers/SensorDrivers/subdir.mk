################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SensorDrivers/SFM3300.c 

OBJS += \
./Drivers/SensorDrivers/SFM3300.o 

C_DEPS += \
./Drivers/SensorDrivers/SFM3300.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SensorDrivers/%.o Drivers/SensorDrivers/%.su: ../Drivers/SensorDrivers/%.c Drivers/SensorDrivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F302x8 -c -I../Core/Inc -I../Drivers/SensorDrivers -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-SensorDrivers

clean-Drivers-2f-SensorDrivers:
	-$(RM) ./Drivers/SensorDrivers/SFM3300.d ./Drivers/SensorDrivers/SFM3300.o ./Drivers/SensorDrivers/SFM3300.su

.PHONY: clean-Drivers-2f-SensorDrivers

