//#include "core.h"



.extern czas
.extern first_wave
//.extern run_runnable
//definicje tymczasowe, będą docelowo w pliku konfiguracyjnym, usunąć później
//domyślnie 20khz = 8/25
#define licznik 8
#define mianownik 25



//.global TIMER2_OVF_vect
.global __vector_9
.global wave_end_func

//TIMER2_OVF_vect:
__vector_9:
push r24
in r24, 0x3F //SREG
push r24

//liczenie czasu
lds r24, (czas)
subi r24, licznik
brcs generuj_dzw		//sprawdzić czy warunek poprawny, także dla większych liczb i co gdy mianownik > licznik

sts (czas), r24
pop r24
out 0x3F, r24 //SREG
pop r24
reti

generuj_dzw:
//aktualizacja czasu
subi r24, -mianownik
sts (czas), r24
sei


//generowanie próbki dźwięku:
//przygotowywanie zasobów
push r31
push r30
push r29
push r28
push r27
push r26
push r25
//push r24
push r23
push r22
push r21
push r20
push r19
push r18
push r17
push r16
push r1
push r0

clr r23
clr r24
clr r25

//ładowanie pierwszego wskaźnika obiektu do rejestru
lds r26, (first_wave)
lds r27, (first_wave+1)
movw r28, r26

//ładowanie wskaźnika funkcji do obsługi obiektu
ldd r30, Y+0
ldd r31, Y+1

//wykonywanie obliczeń dźwięku
ijmp

zakoncz_obliczenia:
wave_end_func:
add r23, r25
add r24, r25

//dalsze obliczenia



//wystawienie wyniku na io
cli
clr r0
sbrs r24, 7 //lewy kanał
rjmp 1f

com r24 // fala ujemna
lsl r24
sts 0x8A, r24
sts 0x88, r0
rjmp 2f

1:
lsl r24 // fala dodatnia
sts 0x88, r24
sts 0x8A, r0

2:

sbrs r23, 7 //prawy kanał
rjmp 1f

com r23 //fala ujemna
lsl r23
sts 0xB4, r23
sts 0xB3, r0
rjmp 2f

1: // fala dodatnia
lsl r23
sts 0xB3, r23
sts 0xB4, r0

2:



//liczenie czasu, próbki dźwięku
lds r16, (sample_counter)
inc r16
sts (sample_counter), r16
brne sprawdzanie
lds r17, (sample_counter + 1)
inc r17
sts (sample_counter + 1), r17
brne sprawdzanie
lds r18, (sample_counter + 2)
inc r18
sts (sample_counter + 2), r18
brne sprawdzanie
lds r19, (sample_counter + 3)
inc r19
sts (sample_counter + 3), r19

//sprawdz czy jest teraz zadanie do wykonania:
//sprawdz czy first_task jest null (0)
sprawdzanie:
lds r28, (first_task)
lds r29, (first_task + 1)
sbiw r28, 0
brne sprawdz_czas



powrot_z_przerwania:
pop r0
pop r1
pop r16
pop r17
pop r18
pop r19
pop r20
pop r21
pop r22
pop r23
//pop r24
pop r25
pop r26
pop r27
pop r28
pop r29
pop r30
pop r31

pop r24
out 0x3F, r24 //SREG
pop r24
reti

sprawdz_czas:
ldd r20, Y+4
cp r16, r20
brne powrot_z_przerwania
lds r17, (sample_counter + 1)
ldd r21, Y+5
cp r17, r21
brne powrot_z_przerwania
lds r18, (sample_counter + 2)
ldd r22, Y+6
cp r18, r22
brne powrot_z_przerwania
lds r19, (sample_counter + 3)
ldd r23, Y+7
cp r19, r23
brne powrot_z_przerwania


//gdy jest zadanie do wykonania to go wykonaj:
push r2
push r3
push r4
push r5
push r6
push r7
push r8
push r9
push r10
push r11
push r12
push r13
push r14
push r15
clr r1

//funkcja cpp opsługująca wywoływanie zadań
rcall scheduler //poprawić na call gdy kompilator przeniesie tą funkcję w dalsze miejsce (ale raczej nie powinien)

pop r15
pop r14
pop r13
pop r12
pop r11
pop r10
pop r9
pop r8
pop r7
pop r6
pop r5
pop r4
pop r3
pop r2

pop r0
pop r1
pop r16
pop r17
pop r18
pop r19
pop r20
pop r21
pop r22
pop r23
//pop r24
pop r25
pop r26
pop r27
pop r28
pop r29
pop r30
pop r31

pop r24
out 0x3F, r24 //SREG
pop r24
reti













//tymczasowe, usunąć
#define timer2
#define timer1
.global testSetup
testSetup:
cli
ldi r25, 131
out 0x23, r25//GTCCR
#ifdef timer0
	ldi r25, 1
	out 0x25, r25//TCCR0B
	ldi r25, 163
	out 0x24, r25//TCCR0A
	clr r25
	out 0x26, r25//TCNT0
	//ldi r25, 1
	//sts 0x6E, r25//TIMSK0
#endif
#ifdef timer1
	ldi r25, 9
	sts 0x81, r25//TCCR1B
	ldi r25, 161
	sts 0x80, r25//TCCR1A
	clr r25
	sts 0x85, r25//TCNT1H
	sts 0x84, r25//TCNT1L
	//ldi r25, 1
	//sts 0x6F, r25//TIMSK1
#endif
#ifdef timer2
	ldi r25, 1
	sts 0xB1, r25//TCCR2B
	ldi r25, 163
	sts 0xB0, r25//TCCR2A
	clr r25
	sts 0xB2, r25//TCNT2
	ldi r25, 1
	sts 0x70, r25//TIMSK2
#endif
clr r25
out 0x23, r25//GTCCR

//na testy, ustawienie pinów 3, 9, 10, 11
sbi 0x04, 3
sbi 0x04, 2
sbi 0x04, 1
sbi 0x0A, 3
sei
ret
