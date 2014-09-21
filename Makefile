# Project sources
SRCS = 	main.c gpio.c clocks.c iir_filter.c dpll.c pwm.c exti.c interrupts.c \
	   	handlers.c 

# all the files will be generated with this name (main.elf, main.bin, main.hex, etc)

PROJ_NAME=ind_heater_stm32f303
MCU=STM32F303xC
OUTPATH=build

###################################################

# Check for valid float argument
# NOTE that you have to run make clean after
# changing these as hardfloat and softfloat are not
# binary compatible
ifneq ($(FLOAT_TYPE), hard)
ifneq ($(FLOAT_TYPE), soft)
override FLOAT_TYPE = hard
#override FLOAT_TYPE = soft
endif
endif

###################################################

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
SIZE=arm-none-eabi-size

CFLAGS  = -std=gnu99 -Wall -O1 -Tstm32_flash.ld -D$(MCU) \
		  -Wl,-Map=$(OUTPATH)/main.map -ggdb -g3
CFLAGS += -mlittle-endian -mthumb -mthumb-interwork -nostartfiles \
		  -mcpu=cortex-m4

ifeq ($(FLOAT_TYPE), hard)
CFLAGS += -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
#CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
else
CFLAGS += -msoft-float
endif

###################################################

vpath %.c src
vpath %.a lib

ROOT=$(shell pwd)

#CFLAGS += -Iinc -Ilib -Ilib/inc 
#CFLAGS += -Ilib/inc/core -Ilib/inc/peripherals

# add startup file to build
SRCS += src/startup_stm32f30x.s

# Libraries to use
#LIBS = -Llib -lstm32f3 -lm

OBJS = $(SRCS:.c=.o)

###################################################

#.PHONY: lib proj
.PHONY: proj

#all: lib proj
all: proj
	$(SIZE) $(OUTPATH)/$(PROJ_NAME).elf

lib:
	$(MAKE) -C lib FLOAT_TYPE=$(FLOAT_TYPE)

proj: 	$(OUTPATH)/$(PROJ_NAME).elf

$(OUTPATH)/$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
	$(OBJCOPY) -O ihex $(OUTPATH)/$(PROJ_NAME).elf $(OUTPATH)/$(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(OUTPATH)/$(PROJ_NAME).elf $(OUTPATH)/$(PROJ_NAME).bin

clean:
	rm -f *.o
	rm -f $(OUTPATH)/$(PROJ_NAME).elf
	rm -f $(OUTPATH)/$(PROJ_NAME).hex
	rm -f $(OUTPATH)/$(PROJ_NAME).bin
	$(MAKE) clean -C lib
