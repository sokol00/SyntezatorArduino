#ifndef wave_triangle_h
#define wave_triangle_h

#include "../wave.h"



class wave_triangle : public wave_null
{
public:
	int phase;
	int frequency;
	char volume;
	wave_triangle();
	wave_triangle(int, char);
	static void triangle_func();
};



class stereo_wave_triangle : public wave_null
{
public:
	int phase;
	int frequency;
	char volume_left;
	char volume_right;
	stereo_wave_triangle();
	stereo_wave_triangle(int, char, char);
	static void stereo_triangle_func();
};



#endif
