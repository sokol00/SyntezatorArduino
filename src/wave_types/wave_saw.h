#ifndef wave_saw_h
#define wave_saw_h

#include "../wave.h"



class wave_saw : public wave_null
{
public:
	int phase;
	int frequency;
	char volume;
	wave_saw();
	wave_saw(int, char);
	static void saw_func();
};



class stereo_wave_saw : public wave_null
{
public:
	int phase;
	int frequency;
	char volume_left;
	char volume_right;
	stereo_wave_saw();
	stereo_wave_saw(int, char, char);
	static void stereo_saw_func();
};



#endif
