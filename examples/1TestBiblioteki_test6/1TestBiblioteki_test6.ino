
#include <Arduino_FreeRTOS.h>
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



class piano
{
public:
  TaskHandle_t TaskHandle;
  int frequency;
  int volume;

  static void play_piano(void *pvParameters)
  {
    piano* p = (piano*)pvParameters;
    auto* w = new wave_square(p->frequency, p->volume);
    addWave(w);
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = 1;
    
    for(int i = p->volume; i > 10; i = i*0.95)
    {
      w->volume = i/10;
      vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
    
    deleteWave(w);
    TaskHandle_t th = p->TaskHandle;
    delete p;
    vTaskDelete(th);
  }
  
  piano(int f)
  {
    frequency = f;
    volume = 50 * 10;
    xTaskCreate(piano::play_piano,// Task function
              "p",// Task name
              70,// Stack size 
              (void*)this,// Function paramaters
              1,// Priority
              &TaskHandle);// Handle
  }
};



void zagraj_melodie(void* v)
{
  TickType_t xLastWakeTime = xTaskGetTickCount();
  int const t = 25;
  bool w = false;
  while(1)
  {
    //deleteAllWave();
    //play_piano(hz(440));
    new piano(g4);
    vTaskDelayUntil(&xLastWakeTime, t);
    new piano(e4);
    vTaskDelayUntil(&xLastWakeTime, t);
    new piano(e4);
    vTaskDelayUntil(&xLastWakeTime, t);
    
    new piano(f4);
    vTaskDelayUntil(&xLastWakeTime, t);
    new piano(d4);
    vTaskDelayUntil(&xLastWakeTime, t);
    new piano(d4);
    vTaskDelayUntil(&xLastWakeTime, t);

    new piano(c4);
    vTaskDelayUntil(&xLastWakeTime, t/2);
    new piano(e4);
    vTaskDelayUntil(&xLastWakeTime, t/2);
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
    vTaskDelayUntil(&xLastWakeTime, t*2); 
  }  
}



void setup()
{
  testSetup();
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(12, HIGH);
  //digitalWrite(13, HIGH);
  Serial.begin(2000000);

  xTaskCreate(zagraj_melodie,// Task function
              "m", // Task name
              60,// Stack size 
              NULL,
              1,// Priority
              NULL);
}



/*
void loop()
{
  
}
*/
