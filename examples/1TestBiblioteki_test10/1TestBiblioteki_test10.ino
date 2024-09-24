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
  wave_square* w;
  piano(int, unsigned char volume = 30);
  ~piano();
  unsigned int running() override;
};

piano::piano(int freq, unsigned char volume)
{
  w = new wave_square(freq, volume);
  addWave(w);
  start_running();
}

piano::~piano()
{
  deleteWave(w);
}

unsigned int piano::running()
{
  w->volume -= 1;
  if(w->volume < 1)
    return 0;
  return ((int)(255 - w->volume))*2;
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
  unsigned char const mv = 80;
  bool w = false;
  while(1)
  {
    new piano(c2);
    new piano(c3);
    new piano(g4, mv);
    delay(t);
    new piano(e3);
    new piano(g3);
    new piano(e4, mv);
    delay(t);
    new piano(e3);
    new piano(g3);
    new piano(e4, mv);
    delay(t);
    
    new piano(g1);
    new piano(g2);
    new piano(f4, mv);
    delay(t);
    new piano(h2);
    new piano(d3);
    new piano(d4, mv);
    delay(t);
    new piano(h2);
    new piano(d3);
    new piano(d4, mv);
    delay(t);

    new piano(c2);
    new piano(c3);
    new piano(c4, mv);
    delay(t/2);
    new piano(e4, mv);
    delay(t/2);
    new piano(e3);
    new piano(g3);
    if(w == false)
    {
      w = true;
      new piano(g4, mv);
    }
    else
    {
      w = false;
      new piano(c4, mv);
    }
    delay(t);
    new piano(e3);
    new piano(g3);
    delay(t);
  }
}
