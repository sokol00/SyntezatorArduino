#include "wave_saw.h"



wave_saw::wave_saw()
{
	asm_func = saw_func;
}

wave_saw::wave_saw(int f, char v)
{
	asm_func = saw_func;
	phase = 0;
	frequency = f;
	volume = v;
}

void wave_saw::saw_func()
{
	asm
	(
		"ldd r16, Y+4\n"
		"ldd r17, Y+5\n"
		"ldd r18, Y+6\n"
		"ldd r19, Y+7\n"
		"ldd r20, Y+8\n"

		"add r16, r18\n"
		"adc r17, r19\n"
		"std Y+4, r16\n"
		"std Y+5, r17\n"

		"mulsu r17, r20\n"
		"add r25, r1\n"
	);
	RETURN_WAVE;
}



stereo_wave_saw::stereo_wave_saw()
{
	asm_func = stereo_saw_func;
}

stereo_wave_saw::stereo_wave_saw(int f, char l, char r)
{
	asm_func = stereo_saw_func;
	phase = 0;
	frequency = f;
	volume_left = l;
	volume_right = r;
}

void stereo_wave_saw::stereo_saw_func()
{
	asm
	(
		"ldd r16, Y+4\n"
		"ldd r17, Y+5\n"
		"ldd r18, Y+6\n"
		"ldd r19, Y+7\n"
		"ldd r20, Y+8\n"
		"ldd r21, Y+9\n"

		"add r16, r18\n"
		"adc r17, r19\n"
		"std Y+5, r17\n"
		"std Y+4, r16\n"

		"mulsu r17, r20\n"
		"add r24, r1\n"
		"mulsu r17, r21\n"
		"add r23, r1\n"
	);
	RETURN_WAVE;
}
