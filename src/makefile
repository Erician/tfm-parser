.PHONY: clean 
GFPARSER = ../obj/tmfp
PRODUCTS = $(GFPARSER)
default: $(PRODUCTS)

OBJDIR = ../obj

include tfm/makefile
include display/makefile

include utils/makefile
include logging/makefile

#unittest makefile
include unittest/makefile
include unittest/tfm/makefile
include unittest/display/makefile

include unittest/utils/makefile 
include unittest/logging/makefile 


# OBJS can deal with either .cc or .c 
OBJS += $(OBJDIR)/tfmp_tfm_data_header.o $(OBJDIR)/tfmp_tfm_data_charinfo.o 
OBJS += $(OBJDIR)/tfmp_tfm_data.o $(OBJDIR)/tfmp_tfm_header.o 
OBJS += $(OBJDIR)/tfmp_tfm_data_param.o $(OBJDIR)/tfmp_tfm_data_ligkern.o 
OBJS += $(OBJDIR)/tfmp_tfm_data_exten.o $(OBJDIR)/tfmp_tfm_data_fixword_array.o
OBJS += $(OBJDIR)/tfmp_tfm.o $(OBJDIR)/tfmp_tfmutil.o
OBJS += $(OBJDIR)/tfmp_display_board.o $(OBJDIR)/tfmp_display.o
OBJS += $(OBJDIR)/stringutil.o  
OBJS += $(OBJDIR)/config.o $(OBJDIR)/logging.o 
OBJS += $(OBJDIR)/tfmp_main.o

JUNK = *~ $(OBJDIR)/*.o $(OBJDIR)/*.a $(OBJDIR)/*_ut

# Define the tools we are going to use
CC= g++
LD = g++

CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare -std=c++11 -I.

LIBS = -lm -lc -lpthread

$(OBJDIR)/tfmp_main.o: tfmp_main.cc
	$(CC) $(CFLAGS) -c -o $@ $<

$(PRODUCTS): $(OBJS)     
	$(LD) -o $@  $^  $(LIBS)
	cp $(PRODUCTS) ./


#unittest,using googletest:https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
#this make no sense, and just test googletest

ut-run-all: ut-display-tfmp-display-board ut-tfm-tfmp-tfm-header \
			ut-tfm-tfmp-tfmutil \
			ut-utils-stringutil \
			ut-logging-logging ut-logging-config

ut-display-tfmp-display-board: $(OBJDIR)/tfmp_display_board_ut
	./$(OBJDIR)/tfmp_display_board_ut

ut-tfm-tfmp-tfm-header: $(OBJDIR)/tfmp_tfm_header_ut
	./$(OBJDIR)/tfmp_tfm_header_ut

ut-tfm-tfmp-tfm-data-header: $(OBJDIR)/tfmp_tfm_data_header_ut
	./$(OBJDIR)/tfmp_tfm_data_header_ut

ut-tfm-tfmp-tfm-data-charinfo: $(OBJDIR)/tfmp_tfm_data_charinfo_ut
	./$(OBJDIR)/tfmp_tfm_data_charinfo_ut

ut-tfm-tfmp-tfmutil: $(OBJDIR)/tfmp_tfmutil_ut
	./$(OBJDIR)/tfmp_tfmutil_ut

ut-utils-stringutil: $(OBJDIR)/stringutil_ut
	./$(OBJDIR)/stringutil_ut

ut-logging-logging: $(OBJDIR)/logging_ut 
	./$(OBJDIR)/logging_ut

ut-logging-config: $(OBJDIR)/config_ut
	./$(OBJDIR)/config_ut

clean:
	@rm -f $(JUNK) $(PRODUCTS) ./tfmp ../logs/log.txt 


