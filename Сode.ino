//Подкючение
// Драйвер мотора | ARDUINO |
//    IN1         |   D8    |
//    IN2         |   D9    | 
//    IN3         |   D10   |
//    IN4         |   D11   |
//    -           |   GND   |
//    +           |   +5    |
#include <Stepper.h>//Подключаем библиотеку
#define STEPS 70 //Шагов за 360 градусов
Stepper stepper(STEPS, 8, 9, 10, 11); //Пины подключения
int previous = 0;
void setup() { //Цикл setup выполняется 1 раз при запуске arduino
  stepper.setSpeed(100);//Скорость оборотов в минуту
}
void loop() {
  int val = analogRead(0);
  stepper.step(val - previous);
  previous = val;
}
