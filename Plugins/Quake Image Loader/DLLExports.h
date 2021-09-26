#pragma once
#include <string>
#include "../../Source/Libraries/PluginSDK/GMFSDK.h"
#include "../../Source/Libraries/PluginSDK/TextureInfo.h"
#include "../../Source/Libraries/PluginSDK/MemReader.h"
#include "../../Source/Libraries/PluginSDK/MemWriter.h"
#include "../../Source/Libraries/PluginSDK/Utilities.h"

using namespace GMFSDK;

#ifdef _WIN32
	#define DLLExport __declspec( dllexport )
#else
	#define DLLExport
#endif

struct Context
{
	void* mem;
	MemWriter* writer;
};

extern "C"
{
	DLLExport BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved);
	DLLExport Context* CreateContext();
	DLLExport void* LoadTexture(void*, void* data, uint64_t size, wchar_t* cpath, uint64_t& returnsize);
	DLLExport int GetPluginInfo(unsigned char* cs, int maxsize);
	DLLExport void FreeContext(void*);
}