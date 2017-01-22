#include <fltKernel.h>
#include "winnotifyRegistartion.h"

DRIVER_INITIALIZE DriverEntry;

#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT, DriverEntry)
#pragma alloc_text(PAGE, winnotifyInstanceSetup)
#endif

NTSTATUS DriverEntry( PDRIVER_OBJECT pDriverObject,
					  PUNICODE_STRING pRegistryPath ) 
{
	NTSTATUS status = STATUS_SUCCESS;

	UNREFERENCED_PARAMETER(pRegistryPath);

	// Initlizing the global data
	RtlZeroMemory(&GlobalData, sizeof(GlobalData));
	
	// Registering the filter driver
	status = FltRegisterFilter(pDriverObject,
				&FilterRegistration,
				&GlobalData.filter);

	return status;
}