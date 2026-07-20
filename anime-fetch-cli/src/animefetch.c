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

#ifdef __unix__
	if (getOsType() == MacOS) {
		system("kitty +icat ~/.anime-fetch/images/os-tan/mac/system-tan.png");
	}

	if (getOsType() == Linux) {
		system("kitty +icat ~/.anime-fetch/images/os-tan/linux/arch-1-tan.png");
	}

	if (getOsType() == BSD) {
		system("kitty +icat ~/.anime-fetch/images/os-tan/bsd/free-bsd-tan.png");
	}

	if (getOsType() == Unix) {
		system("kitty +icat ~/.anime-fetch/images/os-tan/others/solaris-tan.png");
	}

	if (getOsType() == Other) {
		system("kitty +icat ~/.anime-fetch/images/os-tan/windows/windows7-tan.png");
	}
#elif WIN32
	system("chafa %HOMEDRIVE%%HOMEPATH%\\.anime-fetch\\images\\os-tan\\windows\\windows11-tan.png");
#endif

	return 0;
}
