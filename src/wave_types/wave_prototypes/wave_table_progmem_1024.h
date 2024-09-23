#ifndef wave_table_progmem_1024_h
#define wave_table_progmem_1024_h

#include "../../wave.h"



class wave_table_progmem_1024 : public wave_null
{
public:
	int phase;
	int frequency;
	char volume;
	char* wave_table;
	wave_table_progmem_1024();
	static void table_progmem_1024_func();
};



class stereo_wave_table_progmem_1024 : public wave_null
{
public:
	int phase;
	int frequency;
	char volume_left;
	char volume_right;
	char* wave_table;
	stereo_wave_table_progmem_1024();
	static void stereo_table_progmem_1024_func();
};



#endif
