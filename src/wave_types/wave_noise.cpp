#include "wave_noise.h"



wave_noise::wave_noise()
{
	wave_table = 0;
}

wave_noise::wave_noise(int f, char v)
{
	wave_table = (char*)wave_noise_table;
	phase = 0;
	frequency = f;
	volume = v;
}



stereo_wave_noise::stereo_wave_noise()
{
	wave_table = 0;
}

stereo_wave_noise::stereo_wave_noise(int f, char l, char r)
{
	wave_table = (char*)wave_noise_table;
	phase = 0;
	frequency = f;
	volume_left = l;
	volume_right = r;
}
