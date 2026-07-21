#include "services/system_info_service.h"

#include <stdio.h>
#include <stdlib.h>

#if defined(__SPECTRUM__)
#include <arch/zx.h>
#endif

int main(void)
{

#if defined(__SPECTRUM__)
	zx_cls(PAPER_WHITE);
#endif
	puts(getOperatingSystemInfo());
	puts(getKernelName());
	puts(getMemoryInfo());
	puts(getCpuInfo());
	puts(getSystemUptime());
	return 0;
}
