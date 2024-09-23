//plik mógłby mieć rozszerzenie .c (brak obiektów)
#include "tone_pitch.h"

/*

int hz(double hz)
{
	return hz*65536*SAMPLE_RATE/1000000;
}

unsigned int keyboard(double key)
{
	key=hz(TUNE*pow(TONE_INTERVAL, ((key-KEY_SHIFT)/NUMBER_OF_TONES)));
	return key;
}

unsigned int keyboard(double key, double cent)
{
	key=keyboard(key+cent/100);
	return key;
}
*/
