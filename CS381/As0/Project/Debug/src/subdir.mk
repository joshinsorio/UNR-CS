################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BaseApplication.cpp \
../src/TutorialApplication.cpp 

CPP_DEPS += \
./src/BaseApplication.d \
./src/TutorialApplication.d 

OBJS += \
./src/BaseApplication.o \
./src/TutorialApplication.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/student/eclipse-workspace/Project/inc" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/BaseApplication.d ./src/BaseApplication.o ./src/TutorialApplication.d ./src/TutorialApplication.o

.PHONY: clean-src

