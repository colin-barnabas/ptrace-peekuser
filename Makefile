##
# PTRACE_PEEKUSER demo
#
# @file
# @version 0.1


CFLAGS = -ggdb3 -Wall
LIBS   = -lm
CC     = $(shell which clang)


.PHONY: all
all: run clean

ptrace_peekuser: ptrace_peekuser.c
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

.PHONY: run
run: ptrace_peekuser
	./ptrace_peekuser

.PHONY: clean
clean: ptrace_peekuser
	rm $<


# end
