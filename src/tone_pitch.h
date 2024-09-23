#ifndef tone_pitch_h
#define tone_pitch_h
/*
#include <math.h>





//returns the converted frequency value to phase step in a sound unit
int hz(double hz);

//returns the converted key sound frequency to phase step in a sound unit
unsigned int keyboard(double key);

//konflikt nazw funkcji, naprawic
//returns the converted key sound and detune frequency to phase step in a sound unit
//unsigned int keyboard(double key, double cent);





//12-TET, in tune: a4=440hz
#define TUNE 440 //in hz
#define TONE_INTERVAL 2
#define NUMBER_OF_TONES 12
#define KEY_SHIFT 69 //midi number: 69 (a4 has a 69 key number), piano keyboard: 49 (a4=49)



//default 20khz = 62.5kHz * 8/25
#define NOMINATOR 8 //licznik
#define DENOMINATOR 25 //mianownik

#ifndef F_CPU
#define F_CPU 16000000
#endif

#define SAMPLE_RATE (1000000*256/F_CPU*NOMINATOR/DENOMINATOR)

*/

//12 equal temperament
//a=440hz

//#undef B0
//#undef B1

#define c0 hz(16.3515978313)
#define cs0 hz(17.3239144361)
#define d0 hz(18.3540479948)
#define ds0 hz(19.4454364826)
#define e0 hz(20.6017223071)
#define f0 hz(21.8267644646)
#define fs0 hz(23.1246514195)
#define g0 hz(24.4997147489)
#define gs0 hz(25.9565435987)
#define a0 hz(27.5)
#define as0 hz(29.1352350949)
#define b0 hz(30.8677063285)
#define h0 hz(30.8677063285)

#define c1 hz(32.7031956626)
#define cs1 hz(34.6478288721)
#define d1 hz(36.7080959897)
#define ds1 hz(38.8908729653)
#define e1 hz(41.20344446141)
#define f1 hz(43.6535289291)
#define fs1 hz(46.249302839)
#define g1 hz(48.9994294977)
#define gs1 hz(51.9130871975)
#define a1 hz(55)
#define as1 hz(58.2704701898)
#define b1 hz(61.735412657)
#define h1 hz(61.735412657)

#define c2 hz(65.4063913251)
#define cs2 hz(69.2956577442)
#define d2 hz(73.4161919794)
#define ds2 hz(77.7817459305)
#define e2 hz(82.4068892282)
#define f2 hz(87.3070578583)
#define fs2 hz(92.4986056779)
#define g2 hz(97.9988589954)
#define gs2 hz(103.823174395)
#define a2 hz(110)
#define as2 hz(116.5409403795)
#define b2 hz(123.470825314)
#define h2 hz(123.470825314)

#define c3 hz(130.8127826503)
#define cs3 hz(138.5913154884)
#define d3 hz(146.8323839587)
#define ds3 hz(155.563491861)
#define e3 hz(164.8137784564)
#define f3 hz(174.6141157165)
#define fs3 hz(184.9972113558)
#define g3 hz(195.9977179909)
#define gs3 hz(207.65234897)
#define a3 hz(220)
#define as3 hz(233.081880759)
#define b3 hz(246.9416506281)
#define h3 hz(246.9416506281)

#define c4 hz(261.6255653006)
#define cs4 hz(277.1826309769)
#define d4 hz(293.6647679174)
#define ds4 hz(311.1269837221)
#define e4 hz(329.6275569129)
#define f4 hz(349.228231433)
#define fs4 hz(369.9944227116)
#define g4 hz(391.9954359817)
#define	gs4 hz(415.3046975799)
#define	a4 hz(440)
#define as4 hz(466.1637615181)
#define b4 hz(493.8833012561)
#define h4 hz(493.8833012561)

#define c5 hz(523.2511306012)
#define cs5 hz(554.3652619537)
#define d5 hz(587.3295358348)
#define ds5 hz(622.2539674442)
#define e5 hz(659.2551138257)
#define f5 hz(698.456462866)
#define fs5 hz(739.9888454233)
#define g5 hz(783.9908719635)
#define gs5 hz(830.6093951599)
#define a5 hz(880)
#define as5 hz(932.3275230362)
#define b5 hz(987.7666025122)
#define h5 hz(987.7666025122)

#define c6 hz(1046.5022612024)
#define cs6 hz(1108.7305239075)
#define d6 hz(1174.6590716696)
#define ds6 hz(1244.5079348883)
#define e6 hz(1318.5102276515)
#define f6 hz(1396.912925732)
#define fs6 hz(1479.9776908465)
#define g6 hz(1567.981743927)
#define gs6 hz(1661.2187903198)
#define a6 hz(1760)
#define as6 hz(1864.6550460724)
#define b6 hz(1975.5332050245)
#define h6 hz(1975.5332050245)

#define c7 hz(2093.0045224048)
#define cs7 hz(2217.461047815)
#define d7 hz(2349.3181433393)
#define ds7 hz(2489.0158697766)
#define e7 hz(2637.020455303)
#define f7 hz(2793.825851464)
#define fs7 hz(2959.9553816931)
#define g7 hz(3135.963487854)
#define gs7 hz(3322.4375806396)
#define a7 hz(3520)
#define as7 hz(3729.3100921447)
#define b7 hz(3951.066410049)
#define h7 hz(3951.066410049)

#define c8 hz(4186.0090448096)
#define cs8 hz(4434.92209563)
#define d8 hz(4698.6362866785)
#define ds8 hz(4978.0317395533)
#define e8 hz(5247.0409106059)
#define f8 hz(5587.6517029281)
#define fs8 hz(5919.9107633862)
#define g8 hz(6271.926975708)
#define gs8 hz(6644.8751612791)
#define a8 hz(7040)
#define as8 hz(7458.6201842894)

#define b8 hz(7902.132820098)
#define h8 hz(7902.132820098)



#endif
