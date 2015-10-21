CC ?= gcc
CFLAGS_common ?= -O2 -g -Wall -std=gnu99
PERF_FLAGS = stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,cs,branch-misses

EXEC = phonebook_orig phonebook_opt
all: $(EXEC)

SRCS_common = main.c

phonebook_orig: $(SRCS_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_opt: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

run: $(EXEC)
	watch -d -t ./phonebook_orig
	watch -d -t ./phonebook_opt
perf_record:
	perf record -F 12500 -e cache-misses ./phonebook_orig && perf report
	perf record -F 12500 -e cache-misses ./phonebook_opt && perf report
perf_opt:
	perf $(PERF_FLAGS) ./phonebook_opt
perf_orig:
	perf $(PERF_FLAGS) ./phonebook_orig
clean:
	$(RM) $(EXEC) *.o perf.*
