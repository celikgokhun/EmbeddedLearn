################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SFM3300Driver/SFM3300.c 

OBJS += \
./Drivers/SFM3300Driver/SFM3300.o 

C_DEPS += \
./Drivers/SFM3300Driver/SFM3300.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SFM3300Driver/%.o Drivers/SFM3300Driver/%.su: ../Drivers/SFM3300Driver/%.c Drivers/SFM3300Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/SFM3300Driver -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-SFM3300Driver

clean-Drivers-2f-SFM3300Driver:
	-$(RM) ./Drivers/SFM3300Driver/SFM3300.d ./Drivers/SFM3300Driver/SFM3300.o ./Drivers/SFM3300Driver/SFM3300.su

.PHONY: clean-Drivers-2f-SFM3300Driver
