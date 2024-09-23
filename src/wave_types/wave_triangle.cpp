#include "wave_triangle.h"



wave_triangle::wave_triangle()
{
	asm_func = triangle_func;
}

wave_triangle::wave_triangle(int f, char v)
{
	asm_func = triangle_func;
	phase = 1 << 14;
	frequency = f;
	volume = v;
}

void wave_triangle::triangle_func()
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

		"sbrs r17, 7\n"
		"com r17\n"
		"lsl r17\n"
		"subi r17, 127\n"

		"mulsu r17, r20\n"
		"add r25, r1\n"
	);
	RETURN_WAVE;
}



stereo_wave_triangle::stereo_wave_triangle()
{
	asm_func = stereo_triangle_func;
}

stereo_wave_triangle::stereo_wave_triangle(int f, char l, char r)
{
	asm_func = stereo_triangle_func;
	phase = 1 << 14;
	frequency = f;
	volume_left = l;
	volume_right = r;
}

void stereo_wave_triangle::stereo_triangle_func()
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

		"sbrs r17, 7\n"
		"com r17\n"
		"lsl r17\n"
		"subi r17, 127\n"

		"mulsu r17, r20\n"
		"add r24, r1\n"
		"mulsu r17, r21\n"
		"add r23, r1\n"
	);
	RETURN_WAVE;
}
