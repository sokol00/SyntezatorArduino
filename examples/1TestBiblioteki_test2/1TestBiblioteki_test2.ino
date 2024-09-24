#include <1TestBiblioteki.h>


//do pracy wymagany jest mostek-H (najlepiej l298n)
//podłączenie ardunio:
//D3 -> in2
//D9 -> in4
//D10 -> in3
//D11 -> in1
//następnie wyjście mostka zostaje podłączone do głośników




void test1(int freq);
void test2();
void test3(int freq);

#define SAMPLE_RATE 20000
int hz(int h)
{
  long a = 65536;
  a = a * h;
  a = a / SAMPLE_RATE;
  return a;
}



void setup()
{
  //inicjalizacja
  testSetup();
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  Serial.begin(115200);
}

void loop()
{
  //test czy dziala
  digitalWrite(13, HIGH);
  addWave(new wave_square(1442, 100));
  delay(1000);
  deleteAllWave();
  digitalWrite(13, LOW);
  delay(3000);

  //wiele dźwięków
  unsigned char v = 50;
  addWave(new wave_triangle(fs1, v+v));
  addWave(new wave_triangle(fs2, v));
  delay(800);
  addWave(new wave_triangle(cs3, v));
  delay(50);
  addWave(new wave_triangle(fs3, v));
  delay(50);
  addWave(new wave_triangle(as3, v));
  delay(50);
  addWave(new wave_triangle(cs4, v));
  delay(50);
  delay(300);
  for(int i = v; i > 0; i--)
  {
    for(wave_null* w = first_wave; w->next_wave != nullptr; w = w->next_wave)
    {
      wave_square* s = w;
      s->volume = i;
    }
    delay(125);
  }
  deleteAllWave();
  delay(3000);
  
  
  //test 1
  test1(g4);
  test1(e4);
  test1(e4);
  test1(f4);
  test1(d4);
  test1(d4);
  test1(c4);
  test1(e4);
  test1(g4);
  delay(3000);

  //test 2
  for(int i = 0; i < 7; i++)
  {
    test2();
    delay(350);
  }
  delay(3000);
  
  //test 3
  test3(c5);
  delay(3000);
}





void test1(int freq)
{
  auto* w = new wave_square(freq, 127);
  addWave(w);
  for(int i = 60; i > 0; i--)
  {
    w->volume = i;
    delay(8);
  }
  deleteWave(w);
}

void test2()
{
  auto* w = new wave_sin(0, 255);
  w->phase = 1<<13;
  addWave(w);
  for(int i = 300; i >= 50; i = i - 10)
  {
    int f = hz(i);
    //int v = 150 + i;
    
    cli();
    w->frequency = f;
    //w->volume = v;
    sei();
    
    delay(1);
  }
  for(int i = 255; i > 5; i = i - 5)
  {
    w->volume = i;
    delay(1);
  }
  deleteWave(w);
}

void test3(int freq)
{
  int a = 0;
  bool k = true;

  auto* w = new stereo_wave_triangle(freq, 200, 200);
  addWave(w);

  for(int i = 0; i < 4000; i++)
  {
    if(a >= 100) k = false;
    if(a <= -100) k = true;
    if(k == true) a++;
    if(k == false) a--;

    int l = 150 + a;
    int r = 150 - a;
    int f = freq + a;
    
    cli();
    w->volume_left = l;
    w->volume_right = r;
    w->frequency = f;
    sei();
    
    delay(1);
  }
  deleteWave(w);
}
