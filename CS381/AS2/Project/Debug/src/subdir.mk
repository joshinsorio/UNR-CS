################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BaseApplication.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/as2.cpp 

CPP_DEPS += \
./src/BaseApplication.d \
./src/Entity381.d \
./src/EntityMgr.d \
./src/as2.d 

OBJS += \
./src/BaseApplication.o \
./src/Entity381.o \
./src/EntityMgr.o \
./src/as2.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/student/eclipse-workspace/Project/inc" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/BaseApplication.d ./src/BaseApplication.o ./src/Entity381.d ./src/Entity381.o ./src/EntityMgr.d ./src/EntityMgr.o ./src/as2.d ./src/as2.o

.PHONY: clean-src
