#ifndef asmSynth_h
#define asmSynth_h

#include "wave.h"
#include "core.h"
#include "runnable.h"



extern volatile char czas;
extern volatile wave_null* first_wave;
extern volatile long sample_counter;
extern volatile run* first_task;




void addWave(wave_null*);
void pushBackWave(wave_null*);
wave_null* getPrevious(wave_null*); 
void deleteWave(wave_null*);
void deleteAllWave(void);




#endif
