#include "Quirkbot.h"

ServoMotor servo1;
ServoMotor servo2;
Converter converter1;
Converter converter2;
AnalogSensor sensor1;
AnalogSensor sensor2;
Led led;
Wave wave;

Converter ledConverter;
Maximum maximum;
Multiplication multiplication;

SerialMonitor monitor;

void start(){
  // Attach to the correct pins
  servo1.pin = 2;
  servo2.pin = 4;
  
  sensor1.pin = A0;
  sensor2.pin = A1;
  
  led.pin = 5;
 

  // Connections: sensor > converter > servo
  servo1.connect(converter1);
  converter1.connect(sensor1);

  servo2.connect(converter2);
  converter2.connect(sensor2);

  // Convert the correct values
  converter1.set(0.5, 0, 0.7, 0.47);
  converter2.set(0.5, 0, 0.3, 0.50);
  
  maximum.set(sensor1, sensor2);
  ledConverter.set(0.15, 0.5, 0, 1);
  multiplication.set(wave, ledConverter);
  ledConverter.connect(maximum);
  led.connect(multiplication);

  // Monitor values via serial
  monitor.add(sensor1);
  monitor.add(converter1);
  monitor.add(sensor2);
  monitor.add(converter2);
  monitor.add(maximum);
  monitor.add(ledConverter);
  
}
