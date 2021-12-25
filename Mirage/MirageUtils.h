#pragma once


#ifdef MIRAGE_WINDOWS
	#ifdef MIRAGE_LIB
		#define MIRAGE_API __declspec(dllexport)
	#else
		#define MIRAGE_API __declspec(dllimport)
	#endif
#else
	#define MIRAGE_API
#endif


#ifdef MIRAGE_DEBUG
	#define MIRAGE_LOG(x) std::cout<<x<<std::endl;
#else
	#define MIRAGE_LOG(x)
#endif