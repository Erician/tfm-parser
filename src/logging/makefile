LOGGINGDIR := logging

$(OBJDIR)/config.o: $(LOGGINGDIR)/config.cc
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/logging.o: $(LOGGINGDIR)/logging.cc $(LOGGINGDIR)/logging.ini ../logs
	$(CC) $(CFLAGS) -c -o $@ $<

../logs: 
	mkdir ../logs

