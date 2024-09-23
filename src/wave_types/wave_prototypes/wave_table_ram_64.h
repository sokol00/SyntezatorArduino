#ifndef wave_table_ram_64_h
#define wave_table_ram_64_h

#include "../../wave.h"



class wave_table_ram_64 : public wave_null
{
public:
	int phase;
	int frequency;
	char volume;
	char* wave_table;
	wave_table_ram_64();
	static void table_ram_64_func();
};



class stereo_wave_table_ram_64 : public wave_null
{
public:
	int phase;
	int frequency;
	char volume_left;
	char volume_right;
	char* wave_table;
	stereo_wave_table_ram_64();
	static void stereo_table_ram_64_func();
};



#endif
