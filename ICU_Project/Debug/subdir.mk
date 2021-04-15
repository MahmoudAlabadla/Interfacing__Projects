################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../Dio_Prog.c \
../LCD_Prog.c \
../PWM_FM_prog.c \
../T1_ICU_prog.c \
../main.c 

OBJS += \
./ADC_prog.o \
./Dio_Prog.o \
./LCD_Prog.o \
./PWM_FM_prog.o \
./T1_ICU_prog.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./Dio_Prog.d \
./LCD_Prog.d \
./PWM_FM_prog.d \
./T1_ICU_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


