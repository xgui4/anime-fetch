#include "services/system_info_service.h"

#include <stdio.h>
#include <stdlib.h>

#if defined(__SPECTRUM__)
#include <arch/zx.h>
#endif

int main(int argc, char *argv[])
{

#if defined(__SPECTRUM__)
	zx_cls(PAPER_WHITE);
#endif
	system("kitty +icat /home/xgui4/.anime-fetch/images/os-tan/linux/arch-1-tan.png"); 
	puts(getOperatingSystemInfo());
	puts(getKernelName());
	puts(getMemoryInfo());
	puts(getCpuInfo());
	puts(getSystemUptime());
	return 0;
}
