#include <HCSR04.h>

#define TRIG 10
#define ECHO 9

#define BUZZER 12

HCSR04 sensor(TRIG, ECHO);

void setup() {
  
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  
  int sensorDist = sensor.dist();

  Serial.print("Distance from Sensor: ");
  Serial.print(sensorDist);
  Serial.println(" cm");

  if (sensorDist > 25 && sensorDist <= 50)
    tone(BUZZER, 349);
  else if (sensorDist > 10 && sensorDist <= 25)
    tone(BUZZER, 455);
  else if (sensorDist > 0 && sensorDist <= 10)
    tone(BUZZER, 587);
  else
    noTone(BUZZER);

  delay(100);
}
