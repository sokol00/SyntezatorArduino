#include "wave_table_ram_256.h"



wave_table_ram_256::wave_table_ram_256()
{
	asm_func = table_ram_256_func;
}

void wave_table_ram_256::table_ram_256_func()
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

		"ldd r26, Y+9\n"
		"ldd r27, Y+10\n"
		"clr r0\n"
		"add r26, r17\n"
		"adc r27, r0\n"
		"ld r22, X\n"

		"mulsu r22, r20\n"
		"add r25, r1\n"
	);
	RETURN_WAVE;
}



stereo_wave_table_ram_256::stereo_wave_table_ram_256()
{
	asm_func = stereo_table_ram_256_func;
}

void stereo_wave_table_ram_256::stereo_table_ram_256_func()
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

		"ldd r26, Y+10\n"
		"ldd r27, Y+11\n"
		"clr r0\n"
		"add r26, r17\n"
		"adc r27, r0\n"
		"ld r22, X\n"

		"mulsu r22, r20\n"
		"add r24, r1\n"
		"mulsu r22, r21\n"
		"add r23, r1\n"
	);
	RETURN_WAVE;
}
