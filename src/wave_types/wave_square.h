#ifndef wave_square_h
#define wave_square_h

#include "../wave.h"



class wave_square : public wave_null
{
public:
	int phase;
	int frequency;
	char volume;
	wave_square();
	wave_square(int, unsigned char);
	static void square_func();
};



class stereo_wave_square : public wave_null
{
public:
	int phase;
	int frequency;
	char volume_left;
	char volume_right;
	stereo_wave_square();
	stereo_wave_square(int, char, char);
	static void stereo_square_func();
};



#endif
