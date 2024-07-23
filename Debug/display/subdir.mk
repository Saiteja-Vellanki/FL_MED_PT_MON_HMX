################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../display/display.c \
../display/gfx.c 

OBJS += \
./display/display.o \
./display/gfx.o 

C_DEPS += \
./display/display.d \
./display/gfx.d 


# Each subdirectory must supply rules for building sources it contributes
display/%.o display/%.su display/%.cyclo: ../display/%.c display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F410Rx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/display" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/error" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/Fw_release" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/Fw_version" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/ioexpansion" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/led" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/motor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/temp_sensor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/App" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/display" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/ioexpansion" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/led" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/error" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/Fw_release" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/temp_sensor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/buttons" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/RTC" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/pwm" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-display

clean-display:
	-$(RM) ./display/display.cyclo ./display/display.d ./display/display.o ./display/display.su ./display/gfx.cyclo ./display/gfx.d ./display/gfx.o ./display/gfx.su

.PHONY: clean-display

