################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/croutine.c \
../freertos/event_groups.c \
../freertos/fsl_tickless_lptmr.c \
../freertos/fsl_tickless_systick.c \
../freertos/heap_4.c \
../freertos/list.c \
../freertos/port.c \
../freertos/queue.c \
../freertos/tasks.c \
../freertos/timers.c 

OBJS += \
./freertos/croutine.o \
./freertos/event_groups.o \
./freertos/fsl_tickless_lptmr.o \
./freertos/fsl_tickless_systick.o \
./freertos/heap_4.o \
./freertos/list.o \
./freertos/port.o \
./freertos/queue.o \
./freertos/tasks.o \
./freertos/timers.o 

C_DEPS += \
./freertos/croutine.d \
./freertos/event_groups.d \
./freertos/fsl_tickless_lptmr.d \
./freertos/fsl_tickless_systick.d \
./freertos/heap_4.d \
./freertos/list.d \
./freertos/port.d \
./freertos/queue.d \
./freertos/tasks.d \
./freertos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/%.o: ../freertos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\board" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\source" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\freertos" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\drivers" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\utilities" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\startup" -I"C:\Users\Jesper\Documents\MCUXpressoIDE_10.0.2_411\workspace\E4ISD2_rtos_priorities\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


