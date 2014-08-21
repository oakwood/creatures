#include "Quirkbot.h"

ServoMotor servo;
Sonar sonar;
Led led;
Buzzer buzzer;

Converter detector;

Wave turn;
Converter turnDuration;

Randomizer voiceSurce;
Multiplication voice;



SerialMonitor monitor;


void start(){
  servo.pin = 2;
  sonar.pin = 7;
  led.pin = 5;
  buzzer.pin = 4;
  
  detector.set(0.4, 0.41, 1.0, 0); 
  turnDuration.set(1,0, 100, 5);  
  voice.set(voiceSurce, detector);
  
  detector.connect(sonar); 
  turnDuration.connect(detector);
  turn.duration.connect(turnDuration);
  servo.connect(turn);
  buzzer.connect(voice);
  led.connect(voice);
  
  monitor.add(sonar);
  monitor.add(detector);  
}
