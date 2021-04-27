#pragma once

#ifndef IMPORT_DLL
#define EXT_API __declspec(dllexport)
#else
#define EXT_API __declspec(dllimport)
#endif

namespace CLI
{

EXT_API void CallNET5();

}
