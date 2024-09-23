#include "core.h"

void scheduler()
{
	//bezpieczna kopia danych
	long aktualny_czas = sample_counter;

	//izolacja łańcucha tasków która ma zostać wykonana w kolejnym kroku
	run* next_task = (run*)first_task;
	while(first_task != 0 && first_task->time_to_run == aktualny_czas)
		first_task = first_task->next_obj;
	
	//uruchamianie zleconego zadania
	asm("sei\n");
	do
	{
		run* current_task = next_task;
		next_task = current_task->next_obj;

		skok_powtorz_zadanie:
		//wykonaj zadanie
		unsigned int czas_zadania = current_task->running();
		
		//sprawdzanie rezultatów zadania, czy ma zostać usunięte lub powtórnie wykonane po pewnym czasie
		if(czas_zadania == 0)
		{
			delete current_task;
		}
		else
		{
			long nowy_czas = current_task->time_to_run + czas_zadania;
			current_task->time_to_run = nowy_czas;
			
			//przed dodaniem do kolejki sprawdzić czy czas się nie zdeaktualizował
			asm("cli\n");
			if(nowy_czas <= sample_counter) // sprawdzanie czy zadanie się przedawniło
			{
				//ponowne wykonanie zadania gdy jego czas ponownego uruchomienia zdążył już upłynąć
				asm("sei\n");
				//next_task = current_task;
				//continue; // nie działa ponieważ sprawdzany będzie warunek który będzie zawsze negatywny
				goto skok_powtorz_zadanie;
			}

			//umiejscowienie zadania w kolejce
			if(first_task == 0 || first_task->time_to_run > current_task->time_to_run)
			{
				current_task->next_obj = (run*)first_task;
				first_task = current_task;
				asm("sei\n");
			}
			else
			{
				//wyszukiwanie miejsca dodania elementu, może to chwile zając dlatego przerwania zostają włączone
				asm("sei\n");
				asm("cli\n");
				run* t = (run*)first_task;
				while(t->next_obj != 0 && t->next_obj->time_to_run <= current_task->time_to_run)
					t = t->next_obj;

				//przed dodaniem do kolejki sprawdzić czy czas się nie zdeaktualizował
				//asm("cli\n");
				if(nowy_czas <= sample_counter) // sprawdzanie czy zadanie się przedawniło
				{
					//ponowne wykonanie zadania gdy jego czas ponownego uruchomienia zdążył już upłynąć
					asm("sei\n");
					//next_task = current_task;
					//continue; // nie działa ponieważ sprawdzany będzie warunek który będzie zawsze negatywny
					goto skok_powtorz_zadanie;
				}

				current_task->next_obj = t->next_obj;
				t->next_obj = current_task;
				asm("sei\n");
			}
		}
	} while (next_task != 0 && next_task->time_to_run == aktualny_czas);
}
