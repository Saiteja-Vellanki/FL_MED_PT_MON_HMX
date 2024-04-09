################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fw_release/fw_release.c 

OBJS += \
./Fw_release/fw_release.o 

C_DEPS += \
./Fw_release/fw_release.d 


# Each subdirectory must supply rules for building sources it contributes
Fw_release/%.o Fw_release/%.su Fw_release/%.cyclo: ../Fw_release/%.c Fw_release/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F410Rx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/buttons" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/display" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/error" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/Fw_release" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/Fw_version" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/ioexpansion" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/led" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/motor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_STEM-001/temp_sensor" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/App" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/display" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/ioexpansion" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/led" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/error" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/Fw_release" -I"C:/Users/saive/STM32CubeIDE/workspace_1.11.0/FL_MED_PT_MON_HMX/temp_sensor" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Fw_release

clean-Fw_release:
	-$(RM) ./Fw_release/fw_release.cyclo ./Fw_release/fw_release.d ./Fw_release/fw_release.o ./Fw_release/fw_release.su

.PHONY: clean-Fw_release

