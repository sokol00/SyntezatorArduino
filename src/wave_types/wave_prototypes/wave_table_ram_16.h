#ifndef wave_table_ram_16_h
#define wave_table_ram_16_h

#include "../../wave.h"



class wave_table_ram_16 : public wave_null
{
public:
	int phase;
	int frequency;
	char volume;
	char* wave_table;
	wave_table_ram_16();
	static void table_ram_16_func();
};



class stereo_wave_table_ram_16 : public wave_null
{
public:
	int phase;
	int frequency;
	char volume_left;
	char volume_right;
	char* wave_table;
	stereo_wave_table_ram_16();
	static void stereo_table_ram_16_func();
};



#endif
