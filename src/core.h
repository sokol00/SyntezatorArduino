#ifndef core_h
#define core_h

#include "asmSynth.h"



extern "C"
{
	void nastepny_dzwiek();
	void zakoncz_obliczenia();

	void testSetup(); //na testy, usunąć

	void scheduler() __attribute__ ((/*naked, */used));
}



#endif
