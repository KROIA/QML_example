#pragma once
#include "QML_example_global.h"

/// USER_SECTION_START 1

/// USER_SECTION_END

// Debugging
#ifdef NDEBUG
	#define QML_CONSOLE(msg)
	#define QML_CONSOLE_FUNCTION(msg)
#else
	#include <iostream>

	#define QML_DEBUG
	#define QML_CONSOLE_STREAM std::cout

	#define QML_CONSOLE(msg) QML_CONSOLE_STREAM << msg;
	#define QML_CONSOLE_FUNCTION(msg) QML_CONSOLE_STREAM << __PRETTY_FUNCTION__ << " " << msg;
#endif

/// USER_SECTION_START 2

/// USER_SECTION_END

#ifdef QML_PROFILING
	#include "easy/profiler.h"
	#include <easy/arbitrary_value.h> // EASY_VALUE, EASY_ARRAY are defined here

	#define QML_PROFILING_BLOCK_C(text, color) EASY_BLOCK(text, color)
	#define QML_PROFILING_NONSCOPED_BLOCK_C(text, color) EASY_NONSCOPED_BLOCK(text, color)
	#define QML_PROFILING_END_BLOCK EASY_END_BLOCK
	#define QML_PROFILING_FUNCTION_C(color) EASY_FUNCTION(color)
	#define QML_PROFILING_BLOCK(text, colorStage) QML_PROFILING_BLOCK_C(text,profiler::colors::  colorStage)
	#define QML_PROFILING_NONSCOPED_BLOCK(text, colorStage) QML_PROFILING_NONSCOPED_BLOCK_C(text,profiler::colors::  colorStage)
	#define QML_PROFILING_FUNCTION(colorStage) QML_PROFILING_FUNCTION_C(profiler::colors:: colorStage)
	#define QML_PROFILING_THREAD(name) EASY_THREAD(name)

	#define QML_PROFILING_VALUE(name, value) EASY_VALUE(name, value)
	#define QML_PROFILING_TEXT(name, value) EASY_TEXT(name, value)

#else
	#define QML_PROFILING_BLOCK_C(text, color)
	#define QML_PROFILING_NONSCOPED_BLOCK_C(text, color)
	#define QML_PROFILING_END_BLOCK
	#define QML_PROFILING_FUNCTION_C(color)
	#define QML_PROFILING_BLOCK(text, colorStage)
	#define QML_PROFILING_NONSCOPED_BLOCK(text, colorStage)
	#define QML_PROFILING_FUNCTION(colorStage)
	#define QML_PROFILING_THREAD(name)

	#define QML_PROFILING_VALUE(name, value)
	#define QML_PROFILING_TEXT(name, value)
#endif

// Special expantion tecniques are required to combine the color name
#define CONCAT_SYMBOLS_IMPL(x, y) x##y
#define CONCAT_SYMBOLS(x, y) CONCAT_SYMBOLS_IMPL(x, y)



// Different color stages
#define QML_COLOR_STAGE_1 50
#define QML_COLOR_STAGE_2 100
#define QML_COLOR_STAGE_3 200
#define QML_COLOR_STAGE_4 300
#define QML_COLOR_STAGE_5 400
#define QML_COLOR_STAGE_6 500
#define QML_COLOR_STAGE_7 600
#define QML_COLOR_STAGE_8 700
#define QML_COLOR_STAGE_9 800
#define QML_COLOR_STAGE_10 900
#define QML_COLOR_STAGE_11 A100 
#define QML_COLOR_STAGE_12 A200 
#define QML_COLOR_STAGE_13 A400 
#define QML_COLOR_STAGE_14 A700 

namespace QML_example
{
	class QML_EXAMPLE_EXPORT Profiler
	{
	public:
		// Implementation defined in LibraryName_info.cpp to save files.
		static void start();
		static void stop();
		static void stop(const char* profilerOutputFile);
	};
}


// General
#define QML_GENERAL_PROFILING_COLORBASE Cyan
#define QML_GENERAL_PROFILING_BLOCK_C(text, color) QML_PROFILING_BLOCK_C(text, color)
#define QML_GENERAL_PROFILING_NONSCOPED_BLOCK_C(text, color) QML_PROFILING_NONSCOPED_BLOCK_C(text, color)
#define QML_GENERAL_PROFILING_END_BLOCK QML_PROFILING_END_BLOCK;
#define QML_GENERAL_PROFILING_FUNCTION_C(color) QML_PROFILING_FUNCTION_C(color)
#define QML_GENERAL_PROFILING_BLOCK(text, colorStage) QML_PROFILING_BLOCK(text, CONCAT_SYMBOLS(QML_GENERAL_PROFILING_COLORBASE, colorStage))
#define QML_GENERAL_PROFILING_NONSCOPED_BLOCK(text, colorStage) QML_PROFILING_NONSCOPED_BLOCK(text, CONCAT_SYMBOLS(QML_GENERAL_PROFILING_COLORBASE, colorStage))
#define QML_GENERAL_PROFILING_FUNCTION(colorStage) QML_PROFILING_FUNCTION(CONCAT_SYMBOLS(QML_GENERAL_PROFILING_COLORBASE, colorStage))
#define QML_GENERAL_PROFILING_VALUE(name, value) QML_PROFILING_VALUE(name, value)
#define QML_GENERAL_PROFILING_TEXT(name, value) QML_PROFILING_TEXT(name, value)


/// USER_SECTION_START 3

/// USER_SECTION_END