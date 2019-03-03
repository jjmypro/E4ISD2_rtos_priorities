################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mkl25z4.c 

OBJS += \
./startup/startup_mkl25z4.o 

C_DEPS += \
./startup/startup_mkl25z4.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\board" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\source" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\freertos" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\drivers" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\utilities" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\startup" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


