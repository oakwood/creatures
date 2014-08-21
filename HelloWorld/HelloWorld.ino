#include "Quirkbot.h"

Sonar sonar;
Converter sonarConverter;
ServoMotor servo;

AnalogSensor sensor;
Converter sensorConverter;
Buzzer buzzer;

SerialMonitor monitor;

void start(){
  sonar.pin = 7;
  servo.pin = 2;
  sensor.pin = A0;
  buzzer.pin = 4;
  
  sonarConverter.set(0, 0.5, 0, 1);
  sensorConverter.set(0.2, 0.6, 1, 0);
  
  //servo.connect(sonarConverter);
  sonarConverter.connect(sonar);
  
  //buzzer.connect(sensorConverter);
  sensorConverter.connect(sensor);
  
  monitor.add(sonar);
  monitor.add(sonarConverter);
  monitor.add(sensor);
  monitor.add(sensorConverter);
}
