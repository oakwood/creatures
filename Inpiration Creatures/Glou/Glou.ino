#include "Quirkbot.h"

RGBLed led;
ServoMotor servo;
Sonar sonar;

Converter sonarConverter;
Randomizer randomizer;
Converter scaledRandomizer;
Multiplication distanceMap;
Addition movement;

Converter hue;

SerialMonitor monitor;

void start(){

  led.pinR = 3;
  led.pinG = 5;
  led.pinB = 6;
  servo.pin = 2;
  sonar.pin = 7;
  
  hue.set(0,0.7, 0.1,0.0);
  hue.connect(sonar);
  led.hue.connect(hue);
  led.luminosity = 1.0;
  
  sonarConverter.set(0.1, 0.4, 1.0, 0);
  sonarConverter.connect(sonar);
  
  scaledRandomizer.set(0,1, -0.03, 0.05);
  scaledRandomizer.connect(randomizer);
  
  distanceMap.operand = sonarConverter;
  distanceMap.connect(scaledRandomizer);
  
  movement.operand = 0.5;
  movement.connect(distanceMap);

  servo.connect(movement);

}
