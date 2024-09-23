#ifndef wave_h
#define wave_h



//template, use for class inheritance
class wave_null
{
public:
	void (*asm_func)();
	wave_null* next_wave;
};





//do not use, used only to mark the end of a list
class wave_end : public wave_null
{
public:
	wave_end();
};

extern "C" {void wave_end_func();}

static wave_end obj_wave_end;
#define LAST_WAVE (&obj_wave_end)

//ładowanie wskaźnika do kolejnego obiektu i wykonanie programu obiektu
#define RETURN_WAVE \
asm \
( \
	"ldd r26, Y+2\n" \
	"ldd r27, Y+3\n" \
	"movw r28, r26\n" \
	"ldd r30, Y+0\n" \
	"ldd r31, Y+1\n" \
	"ijmp\n" \
)
//X = Y->next_obj;
//Y = X;
//Z = Y->func();
//run Z->func();


#endif
