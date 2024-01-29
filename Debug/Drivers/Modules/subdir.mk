################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Modules/button_driver.c \
../Drivers/Modules/led_driver.c 

OBJS += \
./Drivers/Modules/button_driver.o \
./Drivers/Modules/led_driver.o 

C_DEPS += \
./Drivers/Modules/button_driver.d \
./Drivers/Modules/led_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Modules/%.o Drivers/Modules/%.su Drivers/Modules/%.cyclo: ../Drivers/Modules/%.c Drivers/Modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/Modules -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Modules

clean-Drivers-2f-Modules:
	-$(RM) ./Drivers/Modules/button_driver.cyclo ./Drivers/Modules/button_driver.d ./Drivers/Modules/button_driver.o ./Drivers/Modules/button_driver.su ./Drivers/Modules/led_driver.cyclo ./Drivers/Modules/led_driver.d ./Drivers/Modules/led_driver.o ./Drivers/Modules/led_driver.su

.PHONY: clean-Drivers-2f-Modules

