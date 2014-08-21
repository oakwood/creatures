#include "Quirkbot.h"

ServoMotor servo;
Sonar sonar;
Converter converter;
SerialMonitor monitor;
Wave wave;

void start(){
  servo.pin = 4;
  sonar.pin = 7;
  
  converter.set(0.1, 0.5, 0.3, 0.85);
  
  wave.duration = 5;
  converter.connect(sonar);
  servo.connect(converter);
  
  
  monitor.add(sonar);
  monitor.add(converter);
}
