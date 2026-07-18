CC ?= cc
POSIXLY_CORRECT ?= 1

animefetch: animefetch.c services/system_info_service.h
	$(CC) $(CFLAGS) -DPOSIXLY_CORRECT=$(POSIXLY_CORRECT) animefetch.c -o animefetch

clean:
	rm -f animefetch

.PHONY: clean
