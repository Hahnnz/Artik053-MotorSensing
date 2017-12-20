################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../._main.c \
../ModuleShifting-api.c \
../sensorbd_main.c 

OBJS += \
./._main.o \
./ModuleShifting-api.o \
./sensorbd_main.o 

C_DEPS += \
./._main.d \
./ModuleShifting-api.d \
./sensorbd_main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARTIK GCC C Compiler'
	arm-none-eabi-gcc  -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/include/apps" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/framework_include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/apps_include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/apps_include/netutils" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/base" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/connectivity" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/systemio" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/wifi" -I"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/artik-sdk_include/lwm2m" -O0 -ffunction-sections -fdata-sections -fno-builtin -fno-strict-aliasing -fno-strength-reduce -fomit-frame-pointer -Wstrict-prototypes -Wshadow -Wno-implicit-function-declaration -Wno-unused-function -Wno-unused-but-set-variable -DAPP_STACKSIZE=18432 -DAPP_PRIORITY=100 -mcpu=cortex-r4 -mfpu=vfpv3 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


