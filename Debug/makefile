################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf tinyara.bin tinyara_head.bin

# All of the sources participating in the build are defined here
-include sources.mk
-include examples/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pre-build main-build

# Main-build Target
main-build: Artik053-MotorSensing

# Tool invocations
Artik053-MotorSensing: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARTIK GCC C Linker'
	arm-none-eabi-ld  -T"/Users/macbook/install/ARTIK/SDK/A053/v1.2/common/scripts/flash.ld" -nostartfiles -nodefaultlibs -L"/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/libs" -L"/Users/macbook/install/ARTIK/toolchains/gcc-arm-none-eabi/v4.9-2015q3/lib/gcc/arm-none-eabi/4.9.3" --entry=__start "/Users/macbook/install/ARTIK/SDK/A053/v1.2/libsdk/typical/libs/arm_vectortab.o" -o "Artik053-MotorSensing" --start-group $(OBJS) $(USER_OBJS) $(LIBS) --end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) Artik053-MotorSensing
	-@echo ' '

pre-build:
	-@echo 'whether the tinyara.bin file is existed'
	-if [ ! -f tinyara.bin ] && [ -f ._main.o ];then rm ._main.o; fi
	-@echo ' '

post-build:
	-@echo 'add header and add tailer'
	-arm-none-eabi-objcopy -O binary ./"Artik053-MotorSensing" ./tinyara.bin;"/Users/macbook/install/ARTIK/SDK/A053/v1.2/common/tools/s5jchksum.py" tinyara.bin tinyara_head.bin;
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: main-build pre-build post-build

-include ../makefile.targets
