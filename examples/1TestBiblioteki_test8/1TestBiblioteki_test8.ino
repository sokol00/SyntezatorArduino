#include <1TestBiblioteki.h>


//20000hz = 62500/25*8
#define licznik 8
#define mianownik 25
#define SAMPLE_RATE (62500/mianownik*licznik)
int hz(int h)
{
  long a = 65536;
  a = a * h;
  a = a / SAMPLE_RATE;
  return a;
}


class piano : public run
{
public:
  int frequency;
  int volume;
  wave_square* w;
  piano(int);
  ~piano();
  unsigned int running() override;
};

piano::piano(int freq)
{
  w = new wave_square(freq, 80);
  addWave(w);
  start_running();
}

piano::~piano()
{
  deleteWave(w);
}

unsigned int piano::running()
{
  w->volume *= 0.95;
  if(w->volume < 1)
    return 0; // zakończ zadanie
  return 600; // uruchom tą funkcję za 600 ticków (600t = 30ms dla próbkowania 20kHz)
}


void setup()
{
  testSetup();
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(12, HIGH);
  //digitalWrite(13, HIGH);
  //Serial.begin(2000000);
}

void loop()
{
  int const t = 400;
  bool w = false;
  while(1)
  {
    new piano(g4);
    delay(t);
    new piano(e4);
    delay(t);
    new piano(e4);
    delay(t);
    
    new piano(f4);
    delay(t);
    new piano(d4);
    delay(t);
    new piano(d4);
    delay(t);

    new piano(c4);
    delay(t/2);
    new piano(e4);
    delay(t/2);
    if(w == false)
    {
      w = true;
      new piano(g4);
    }
    else
    {
      w = false;
      new piano(c4);
    }
    delay(t*2);
  }
}
