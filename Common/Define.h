#pragma once

#ifdef WideRenderer_Exporting
#define WideRendererAPI __declspec(dllexport)
#else
#define WideRendererAPI __declspec(dllimport)
#endif

#ifdef Platform_Exporting
#define PlatformAPI __declspec(dllexport)
#else
#define PlatformAPI __declspec(dllimport)
#endif
