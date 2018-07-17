/*
*
*
*
*\

penjelasan code PaulStoffregen/TimerOne

timer pada proram Paul Stoffregen dapat digunakan pada mikrokontroller AT-Tiny, AVR, dan non AVR mikrokontroller
Code terdapat beberapa fungsi umum untuk konfigurasi pwm dan pemanggilan pwm pada AT-Tiny
diantaranya adalah:
1. initilize()
2. setPeriod()
3. start()
4. stop()
5. restart()
6. resume()
7. attachInterrupt()
8. detachInterrupt()

- Fungsi Initialize ketika dipanggil akan memberikan periode default = 1000000, 
- Fungsi setPeriod adalah untuk menset periode timer dengan menyimpan nilai dari counting timer pada
beberapa register. dalam librarynya Paul mendefinisikan resolusi timer untuk AT-Tiny85
sebesar 256 (8 bit), dimana nilai cycle = microseconds * ratio, dimana ratio = (F_CPU)/ ( 1000000 ). Pada 
codenya, pwmperiod ditentukan dari nilai cycle, misal, jika nilai cycle < resolusi timer, maka pwm periode
cycle, jika cycle < resolusi timer * 2, maka pwm periode = cycle/2 dst. nilai perhitungan pwm periode akhirnya 
akan disimpan pada register OCR1A dan OCR1C, register yang sudah disediakan pada clockSelectBits akan disimpan
pada TCCR1. Batas setting period timer adalah 1 hingga 16384UL* resolusi timer.
- fungsi start, untuk memulai timer dengan memberikan nilai 0 pada register TCCR1, dan TCNT1, dan dilanjutkan 
dengan memberikan nilai pada TCCR1
- fungsi stop, memberikan nilai register TCCR1 sesuai dengan nilai pada register CTC1
- fungsi restart, menjalankan fungsi start kembali
- fungsi resume, memberikan nilai pada register TCCR1
- fungsi attachInterrupt, memanggil fungsi callback interrrupt, dan memberikan nilai pada regiter TIMSK
- fugnsi detachInterrupt, melakukan bitwise and operator pada register TIMSK

pada mikrokontroller AVR terdapat beberapa fungsi yaitu:
1. initilize()
2. setPeriod()
3. start()
4. stop()
5. restart()
6. resume()
7. attachInterrupt()
8. detachInterrupt()
9. setPwmDuty()
10. pwm()
11. disablePwm()

- pada fungsi yang diperuntukkan untuk mikrokontroller AVR memiliki kemiripan dengan fungsi2 yang dimiliki AT-Tiny85,
hanya terdapat perbedaan pada nama register, besar resolusi timer.
- terdapat fungsi tambahan yaitu setPwmDuty, digunakan  untuk mensetting duty cycle pada pwm, dengan memberikan beberapa
parameter berupa pin yang akan digunakan dan besar duty cycle.
- pin yang digunakan berafiliasi dengan 3 timer pin yaitu TIMER1_A_Pin, TIMER1_B_Pin, dan TIMER1_C_Pin.
- duty cycle didapatkan dengan menggeser 10 bit right-shift pada nilai duty yang telah diberikan.
- fungsi pwm untuk mensetting pin sesuai dengan timer peripheral yang dimiliki, dan mensetting pin menjadi pin output
- disble pwm digunakan untuk memberhentikan fungsi pwm.

Pada mikrokontroller selain dari AT-Tiny dan AVR memiliki fungsi yang hampir sama, hanya menggunakan alamat tergister yang berbeda
Untuk code AT-Tyni belum disempurnakan karena blm terdapat PWM output

sample code

/**********************
*/

#include "TimerOne.h"
TimerOne Timer1;

int main {

Timer1.initilize();
Timer1.setPeriod(500000);
Timer1.setPwmDuty(PIN_1, 50);
Timer1.start();

return 0;
}

