#include <windows.h>
int main(int argc, char *argv[])
{
    DWORD bytes = 0;
	char outbuf[0x400];

	unsigned long long inbuf1[2]  ={ 0x453545344ull,     0x120057ull };
	unsigned long long inbuf2[2] = { 0x853564544ull, 0x3C00120057ull };
    
	HANDLE ATKACPIhandle = CreateFile("\\\\.\\ATKACPI",
			GENERIC_READ|GENERIC_WRITE,
			FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
			0, NULL);

	if (ATKACPIhandle){ 
    DeviceIoControl(ATKACPIhandle, 0x22240C, inbuf1, 12, outbuf, sizeof(outbuf), &bytes, NULL);
    DeviceIoControl(ATKACPIhandle, 0x22240C, inbuf2, 16, outbuf, sizeof(outbuf), &bytes, NULL);
	CloseHandle(ATKACPIhandle);}
    return 0;
}
