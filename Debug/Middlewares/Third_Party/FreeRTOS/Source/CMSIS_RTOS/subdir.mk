################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Core/Inc" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/Drivers/CMSIS/Include" -I"/home/julian/Documents/famaf/micro/stm32/projects/RTOS_DHT_ESP8266/BSP/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


