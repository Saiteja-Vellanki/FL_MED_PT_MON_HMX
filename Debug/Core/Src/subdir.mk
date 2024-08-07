################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Usart.c \
../Core/Src/dma.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/main.c \
../Core/Src/spi.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/Usart.o \
./Core/Src/dma.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/main.o \
./Core/Src/spi.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/Usart.d \
./Core/Src/dma.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/main.d \
./Core/Src/spi.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F410Rx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/display" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/error" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/Fw_release" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/Fw_version" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/ioexpansion" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/led" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/motor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/temp_sensor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/App" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/display" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/ioexpansion" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/led" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/error" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/Fw_release" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/temp_sensor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/buttons" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/RTC" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/pwm" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Usart.cyclo ./Core/Src/Usart.d ./Core/Src/Usart.o ./Core/Src/Usart.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/spi.cyclo ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

