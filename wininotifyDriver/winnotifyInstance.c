#include "winnotifyInstance.h"

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