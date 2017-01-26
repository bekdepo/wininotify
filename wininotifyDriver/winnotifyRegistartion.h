#pragma once
#include <fltKernel.h>

// User Includes
#include "winnotifyFilter.h"
#include "winnotifyInstance.h"

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
