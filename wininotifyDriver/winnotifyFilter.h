#pragma once
#include <fltKernel.h>

typedef struct _WINNOTIFY_GLOBAL_DATA {
	PFLT_FILTER filter;
}WINNOTIFY_GLOBAL_DATA, *PWINNOTIFY_GLOBAL_DATA;

WINNOTIFY_GLOBAL_DATA GlobalData;