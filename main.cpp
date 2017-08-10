#include <windows.h>
#include <winioctl.h>
#include <stdio.h>




int main(int argc, char *argv[])
{
	BOOL bResult;                            // generic results flag

	HANDLE hDevice;               // handle to the drive to be examined
	BOOL bResult;                 // results flag
	DWORD junk;                   // discard results

	hDevice = CreateFile(L"\\\\.\\COM"),  // drive to open
		0,                // no access to the drive
		FILE_SHARE_READ | // share mode
		FILE_SHARE_WRITE,
		NULL,             // default security attributes
		OPEN_EXISTING,    // disposition
		0,                // file attributes
		NULL);            // do not copy file attributes

	if (hDevice == INVALID_HANDLE_VALUE) // cannot open the drive
	{
		printf("CreateFile() failed!\n");
		return (FALSE);
	}

	bResult = DeviceIoControl(hDevice,  // device to be queried
		DRV2605_MODE_INTTRIG,  // operation to perform
		NULL, 0, // no input buffer
		, sizeof(),     // output buffer
		&junk,                 // # bytes returned
		(LPOVERLAPPED)NULL);  // synchronous I/O

	CloseHandle(hDevice);

	return ((int)bResult);
}