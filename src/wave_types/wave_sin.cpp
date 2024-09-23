#include "wave_sin.h"



wave_sin::wave_sin()
{
	wave_table = 0;
}

wave_sin::wave_sin(int f, char v)
{
	wave_table = (char*)wave_sin_table;
	phase = 0;
	frequency = f;
	volume = v;
}



stereo_wave_sin::stereo_wave_sin()
{
	wave_table = 0;
}

stereo_wave_sin::stereo_wave_sin(int f, char l, char r)
{
	wave_table = (char*)wave_sin_table;
	phase = 0;
	frequency = f;
	volume_left = l;
	volume_right = r;
}
