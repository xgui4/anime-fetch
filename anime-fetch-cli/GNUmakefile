CC ?= cc
POSIXLY_CORRECT ?= 1

animefetch: src/animefetch.c src/services/system_info_service.h
	$(CC) $(CFLAGS) -DPOSIXLY_CORRECT=$(POSIXLY_CORRECT) src/animefetch.c -o src/anime-fetch

clean:
	rm -f animefetch

.PHONY: clean
