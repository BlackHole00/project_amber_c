#pragma once

#define ae_inline static inline

#if defined(_MSC_VER)
  //  Microsoft 
  #define ae_export __declspec(dllexport)
  #define ae_import __declspec(dllimport)
#elif (defined(__GNUC__) || defined(__CLANGC__))
	//  GCC
  #define ae_export __attribute__((visibility("default")))
  #define ae_import
#else
	#error Unsupported platform
#endif

