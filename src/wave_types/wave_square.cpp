#include "wave_square.h"



wave_square::wave_square()
{
	asm_func = square_func;
}

wave_square::wave_square(int f, unsigned char v)
{
	asm_func = square_func;
	phase = 0;
	frequency = f;
	volume = v >> 1;
}

void wave_square::square_func()
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

		"sbrc r17, 7\n"
		"neg r20\n"
		"add r25, r20\n"
	);
	RETURN_WAVE;
}



stereo_wave_square::stereo_wave_square()
{
	asm_func = stereo_square_func;
}

stereo_wave_square::stereo_wave_square(int f, char l, char r)
{
	asm_func = stereo_square_func;
	phase = 0;
	frequency = f;
	volume_left = l >> 1;
	volume_right = r >> 1;
}

void stereo_wave_square::stereo_square_func()
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

		"brpl 1f\n"
		"neg r20\n"
		"neg r21\n"
	"1:""add r24, r20\n"
		"add r23, r21\n"
	);
	RETURN_WAVE;
}
