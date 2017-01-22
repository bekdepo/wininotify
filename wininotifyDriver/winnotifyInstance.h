#pragma once
#include <fltKernel.h>

NTSTATUS winnotifyInstanceSetup(
	_In_ PCFLT_RELATED_OBJECTS FltObjects,
	_In_ FLT_INSTANCE_SETUP_FLAGS Flags,
	_In_ DEVICE_TYPE volumeType,
	_In_ FLT_FILESYSTEM_TYPE VolumeFsType
);