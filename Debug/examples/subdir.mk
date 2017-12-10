################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../examples/adc_test.c \
../examples/gpio_buttons.c \
../examples/gpio_ledonoff.c \
../examples/gpio_loopback.c \
../examples/gpio_starterled.c \
../examples/i2c_mpu9250.c \
../examples/i2c_tcs34725.c \
../examples/pwm_buzzer.c \
../examples/pwm_led.c \
../examples/spi_k6ds3.c \
../examples/spi_lis3lv02qd.c \
../examples/uart_loopback.c 

OBJS += \
./examples/adc_test.o \
./examples/gpio_buttons.o \
./examples/gpio_ledonoff.o \
./examples/gpio_loopback.o \
./examples/gpio_starterled.o \
./examples/i2c_mpu9250.o \
./examples/i2c_tcs34725.o \
./examples/pwm_buzzer.o \
./examples/pwm_led.o \
./examples/spi_k6ds3.o \
./examples/spi_lis3lv02qd.o \
./examples/uart_loopback.o 

C_DEPS += \
./examples/adc_test.d \
./examples/gpio_buttons.d \
./examples/gpio_ledonoff.d \
./examples/gpio_loopback.d \
./examples/gpio_starterled.d \
./examples/i2c_mpu9250.d \
./examples/i2c_tcs34725.d \
./examples/pwm_buzzer.d \
./examples/pwm_led.d \
./examples/spi_k6ds3.d \
./examples/spi_lis3lv02qd.d \
./examples/uart_loopback.d 


# Each subdirectory must supply rules for building sources it contributes
examples/%.o: ../examples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARTIK GCC C Compiler'
	arm-none-eabi-gcc  -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/include/apps" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/framework_include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/apps_include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/apps_include/netutils" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/base" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/connectivity" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/systemio" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/wifi" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/lwm2m" -O0 -ffunction-sections -fdata-sections -fno-builtin -fno-strict-aliasing -fno-strength-reduce -fomit-frame-pointer -Wstrict-prototypes -Wshadow -Wno-implicit-function-declaration -Wno-unused-function -Wno-unused-but-set-variable -DAPP_STACKSIZE=18432 -DAPP_PRIORITY=100 -mcpu=cortex-r4 -mfpu=vfpv3 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


