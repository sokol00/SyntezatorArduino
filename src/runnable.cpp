#include "runnable.h"



run::run() : next_obj(0), time_to_run(0)
{
	//przeniesiono do funkcji start_running,
	//aby umożliwić uruchomienie konstruktora zanim obiekt zostanie dodany do listy
	/*
	//dodanie na początek kolejki wykonanie zadania
	asm("cli\n");
	next_obj = (run*)first_task;
	time_to_run = sample_counter + 1;
	first_task = this;
	asm("sei\n");
	*/
}

run::~run()
{
	//usuwanie z kolejki priorytetowej tego zadania
	asm("cli\n");
	if(this == first_task)
	{
		first_task = next_obj;
		asm("sei\n");
	}
	else
	{
		run* t = (run*)first_task;
		asm("sei\n");
		//wyszukiwanie poprzedniego elementu z listy
		while(t != 0 && t->next_obj != this)
			t = t->next_obj;
		//usuwanie tego elementu z listy
		if(t != 0)
			t->next_obj = this->next_obj;
	}
}

unsigned int run::running()
{
	//return 0;
	//prawdopodobnie konstruktor klasy pochodnej nie został jeszcze uruchomiony aby wywołać właściwą funkcję
	return 1;
}

void run::start_running()
{
	//dodanie zadania na początek kolejki
	asm("cli\n");
	next_obj = (run*)first_task;
	time_to_run = sample_counter + 1;
	first_task = this;
	asm("sei\n");
	//istnieje opcja aby pierwsze wywołanie running zostało wywołane po pewnym czasie
	//w takim przypadku konieczne będzie umiejscowienie zadania wewnątrz kolejki
	//aby zachować spójność tej struktury danych
}
