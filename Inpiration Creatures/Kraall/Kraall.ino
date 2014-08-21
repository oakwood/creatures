#include "Quirkbot.h"

ServoMotor servo;
Wave wave;
Converter converter;

void start(){

  servo.pin = 2;
  servo.control = 0.45;
  
  wave.duration = 0.7;
 
  converter.set(0,1, 0.07, 0.45);
  converter.connect(wave);
 
  servo.connect(converter); 
}
