DEBUG = FALSE

BLD_FILE ?= .buildver                                                          

# Initiate BLD_FILE if not exists                                              
buildver_create := $(shell if ! test -f $(BLD_FILE); then echo 0 > $(BLD_FILE); fi)

# Prepare callable function. This function updates BLD_FILE
buildver = $(shell echo $$(($$(cat $(BLD_FILE)) + 1)) > $(BLD_FILE))

VER = buildver

GCC = nspire-gcc
AS  = nspire-as
GXX = nspire-g++
LD  = nspire-ld
GENZEHN = genzehn

EXE = nespire_mod_$(shell cat $(BLD_FILE))


GCCFLAGS = -Wall -W -marm
LDFLAGS =
ZEHNFLAGS = --name "$(EXE)"

ifeq ($(DEBUG),FALSE)
	GCCFLAGS += -Os
else
	GCCFLAGS += -O0 -g
endif

OBJS = $(patsubst %.c, %.o, $(shell find . -name \*.c))
OBJS += $(patsubst %.cpp, %.o, $(shell find . -name \*.cpp))
OBJS += $(patsubst %.S, %.o, $(shell find . -name \*.S))
DISTDIR = builds


all:$(DISTDIR)/$(EXE).tns

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $< -o $@

%.o: %.cpp
	$(GXX) $(GCCFLAGS) -c $< -o $@
	
%.o: %.S
	$(AS) -c $< -o $@

$(DISTDIR)/$(EXE).elf: $(OBJS)
	mkdir -p $(DISTDIR)
	$(LD) $^ -o $@ $(LDFLAGS)

$(DISTDIR)/$(EXE).tns: $(DISTDIR)/$(EXE).elf
	$(GENZEHN) --input $^ --output $@.zehn $(ZEHNFLAGS)
	$(call buildver)
	make-prg $@.zehn $@
	rm $@.zehn

clean:
	rm -f $(OBJS) 
