#include <fltKernel.h>
#include "winnotifyFilter.h"

DRIVER_INITIALIZE DriverEntry;

NTSTATUS winnotifyInstanceSetup(
	_In_ PCFLT_RELATED_OBJECTS FltObjects,
	_In_ FLT_INSTANCE_SETUP_FLAGS Flags,
	_In_ DEVICE_TYPE volumeType,
	_In_ FLT_FILESYSTEM_TYPE VolumeFsType
);

CONST FLT_REGISTRATION FilterRegistration = {
	sizeof(FLT_REGISTRATION),
	FLT_REGISTRATION_VERSION,
	0,

	NULL,						// Context registartion
	NULL,						// Operation Callbacks

	NULL,						// Unload routine

	winnotifyInstanceSetup,		// Instance Setup
	NULL,						// Query tear down
	NULL,						// Teardown start
	NULL,						// Teardown completed

	NULL,						// Generate file name
	NULL,						// Name normalizer
	NULL,						// Normalizer context clean up
	NULL,						// Transaction notification callback
	NULL,						// Extended name normalizer callback
	NULL						// Section notification callback
};

#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT, DriverEntry)
#pragma alloc_text(PAGE, winnotifyInstanceSetup)
#endif

NTSTATUS winnotifyInstanceSetup(
	_In_ PCFLT_RELATED_OBJECTS FltObjects,
	_In_ FLT_INSTANCE_SETUP_FLAGS Flags,
	_In_ DEVICE_TYPE volumeType,
	_In_ FLT_FILESYSTEM_TYPE VolumeFsType
) {
	NTSTATUS status = STATUS_SUCCESS;

	// Not using these parameters for as of now
	UNREFERENCED_PARAMETER(FltObjects);
	UNREFERENCED_PARAMETER(Flags);
	UNREFERENCED_PARAMETER(volumeType);

	PAGED_CODE();

	// Avoiding network file systems
	if (VolumeFsType == FILE_DEVICE_NETWORK_FILE_SYSTEM)
		return STATUS_FLT_DO_NOT_ATTACH;

	return status;
}

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