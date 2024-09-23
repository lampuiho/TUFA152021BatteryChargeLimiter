#include <windows.h>
int main(int argc, char *argv[])
{
    
    long num;

	if (argc > 1) {
		char *p;
		errno = 0;
		long conv = strtol(argv[1], &p, 10);
		if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
			//printf("Input is not a number");
			return 1;
		} else {
			num = conv;
		}
	} else {
		num = 0x3C;
	}

    //WMI method IDs, argument byte length, IIA0, PCI0.SBRG.EC0.SRSC (IIA1)
	const unsigned long DSTS[3] = { 0x53545344, 0x4, 0x120057 };
	const unsigned long DEVS[4] = { 0x53564544, 0x8, 0x120057, num };
    const unsigned long ATK_ACPI_WMIFUNCTION = 0x22240c; //see IOCTL Decoder

    DWORD bytes = 0;
	char outbuf[0x400];
    
	HANDLE ATKACPIhandle = CreateFile("\\\\.\\ATKACPI",
			GENERIC_READ|GENERIC_WRITE,
			FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
			0, NULL);

	if (ATKACPIhandle){ 
    DeviceIoControl(ATKACPIhandle, ATK_ACPI_WMIFUNCTION, DSTS, sizeof(DSTS), outbuf, sizeof(outbuf), &bytes, NULL);
    DeviceIoControl(ATKACPIhandle, ATK_ACPI_WMIFUNCTION, DEVS, sizeof(DEVS), outbuf, sizeof(outbuf), &bytes, NULL);
	CloseHandle(ATKACPIhandle);}
    return 0;
}
