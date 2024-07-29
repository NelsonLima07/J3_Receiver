################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/usr/J3_PT2258.c \
../Core/Src/usr/J3_tReceiver.c \
../Core/Src/usr/main_J3_Receiver.c \
../Core/Src/usr/tEncoder.c 

OBJS += \
./Core/Src/usr/J3_PT2258.o \
./Core/Src/usr/J3_tReceiver.o \
./Core/Src/usr/main_J3_Receiver.o \
./Core/Src/usr/tEncoder.o 

C_DEPS += \
./Core/Src/usr/J3_PT2258.d \
./Core/Src/usr/J3_tReceiver.d \
./Core/Src/usr/main_J3_Receiver.d \
./Core/Src/usr/tEncoder.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/usr/%.o Core/Src/usr/%.su Core/Src/usr/%.cyclo: ../Core/Src/usr/%.c Core/Src/usr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-usr

clean-Core-2f-Src-2f-usr:
	-$(RM) ./Core/Src/usr/J3_PT2258.cyclo ./Core/Src/usr/J3_PT2258.d ./Core/Src/usr/J3_PT2258.o ./Core/Src/usr/J3_PT2258.su ./Core/Src/usr/J3_tReceiver.cyclo ./Core/Src/usr/J3_tReceiver.d ./Core/Src/usr/J3_tReceiver.o ./Core/Src/usr/J3_tReceiver.su ./Core/Src/usr/main_J3_Receiver.cyclo ./Core/Src/usr/main_J3_Receiver.d ./Core/Src/usr/main_J3_Receiver.o ./Core/Src/usr/main_J3_Receiver.su ./Core/Src/usr/tEncoder.cyclo ./Core/Src/usr/tEncoder.d ./Core/Src/usr/tEncoder.o ./Core/Src/usr/tEncoder.su

.PHONY: clean-Core-2f-Src-2f-usr

