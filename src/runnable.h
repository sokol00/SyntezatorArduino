#ifndef runnable_h
#define runnable_h



class run
{
public:
	//funkcja będzie mieć za zadanie zwrócić czas do ponownego uruchomienia tej funkcji
	//jeżeli zostanie zwrócone 0 to obiekt zostanie usunięty (zadanie zostało wykonane)
	virtual unsigned int running();

	run* next_obj;
	long time_to_run;

	//konstruktor doda obiekt do listy zadań
	run();
	virtual ~run();
	void start_running();
};



extern volatile long sample_counter;
extern volatile run* first_task;



#endif
