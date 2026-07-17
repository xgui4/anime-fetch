enum OS_TYPE { Windows, Linux, BSD, Unix, MacOS, Other };

#if POSIXLY_CORRECT
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

char memory2[50];
#endif

static enum OS_TYPE getOsType(void)
{
#ifdef _WIN32
	return Windows;
#elif __linux__
	return Linux;
#elif __FreeBSD__
	return BSD;
#elif __NetBSD__
	return BSD;
#elif __OpenBSD__
	return BSD;
#elif __DragonflyBSD__
	return BSD;
#elif __APPLE__
	return MacOS;
#elif __unix__
	return Unix;
#else
	return Other;
#endif
}

static char* getOperatingSystemInfo(void)
{
#ifdef _WIN32
	return "OS : Windows";
#elif __GLIBC__ && __linux__
	return "OS : GNU/Linux";
#elif __GNU__
	return "OS : GNU";
#elif __linux__
	return "OS : Unknown/Linux";
#elif __FreeBSD__
	return "OS : FreeBSD";
#elif __NetBSD__
	return "OS : NetBSD";
#elif __OpenBSD__
	return "OS : OpenBSD";
#elif __DragonflyBSD__
	return "OS : DragonflyBSD";
#elif __APPLE__
	return "OS : MacOS";
#elif __unix__
	return "OS : UNIX";
#else
	return "OS : Unknown";
#endif
}

static char* getKernelName(void)
{
#ifdef _WIN32
	return "Kernel : NT";
#elif __linux__
	return "Kernel : Linux";
#elif __GNU__
	return "Kernel : Hurd";
#elif __FreeBSD__
	return "Kernel : FreeBSD";
#elif __NetBSD__
	return "Kernel : NetBSD";
#elif __OpenBSD__
	return "Kernel : OpenBSD";
#elif __DragonflyBSD__
	return "Kernel : DragonflyBSD";
#elif __APPLE__
	return "Kernel : Darwin";
#elif __unix__
	return "Kernel : UNIX";
#else
	return "Kernel : Unknown";
#endif
}

static char* getCpuInfo(void)
{
#ifdef __x86_64__
	return "CPU : x86_64";
#elif __i386__
	return "CPU : x86";
#elif __Z80__
	return "CPU : z80";
#elif __CC65__
	return "CPU : 6502";
#elif __CC65__
	return "CPU : 6502";
#elif __m68k__
	return "M68K";
#else
	return "CPU : Unknown";
#endif
}

static char* getMemoryInfo(void)
{
#ifdef __SPECTRUM__
	return "Memory : 0.000048GB";
#elif __C64__
	return "Memory : 0.000064GB";
#elif POSIXLY_CORRECT
	long page_size = sysconf(_SC_PAGESIZE);
	long num_pages = sysconf(_SC_PHYS_PAGES);
	double total_ram_gb;
	double total_ram_bytes;

	if (page_size == -1 || num_pages == -1) {
		return "Memory : Unknown";
	}

	memset(memory2, 0, 50 * sizeof(memory2[0]));

	total_ram_bytes = (double)num_pages* page_size;

	total_ram_gb = total_ram_bytes / (1024.0 * 1024.0 * 1024.0);

	snprintf(memory2, sizeof(memory2), "Memory : %.2fGB", total_ram_gb);

	return memory2;
#endif
}

static char* getSystemUptime(void)
{
#if POSIXLY_CORRECT
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == -1) {
		return "Uptime : Unknown";
	}

	long uptime_seconds = ts.tv_sec;

	memset(memory2, 0, 50 * sizeof(memory2[0]));

	snprintf(memory2, sizeof(memory2), "Uptime : %ld seconds", uptime_seconds);

	return memory2;
#else
	return "Uptime : Unknown";
#endif
}
