#include "asmSynth.h"



volatile char czas = 0;
volatile wave_null* first_wave = LAST_WAVE;
volatile long sample_counter = 0;
volatile run* first_task = 0;



void addWave(wave_null* w)
{
	w->next_wave = (wave_null*)first_wave;
	first_wave = w;
}

void pushBackWave(wave_null* w)
{
	w->next_wave = LAST_WAVE;
	getPrevious(LAST_WAVE)->next_wave = w;
}

wave_null* getPrevious(wave_null* w)
{
	wave_null* p = (wave_null*)first_wave;
	while(p->next_wave != w && p->next_wave != LAST_WAVE)
		p = p->next_wave;
	return p;
}

void deleteWave(wave_null* w)
{
	if (w == first_wave)
		first_wave = w->next_wave;
	else
		getPrevious(w)->next_wave = w->next_wave;
	delete w;
}

void deleteAllWave()
{
	wave_null* w = (wave_null*)first_wave;
	first_wave = LAST_WAVE;
	while(w != LAST_WAVE) // || w != nullptr
	{
		wave_null* n = w->next_wave;
		delete w;
		w = n;
	}
}
