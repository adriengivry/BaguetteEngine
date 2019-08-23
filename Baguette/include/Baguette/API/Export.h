#pragma once

#pragma warning(disable : 4251)
#pragma warning(disable : 4275)

#ifdef BAGUETTE_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif // BAGUETTE_EXPORT
