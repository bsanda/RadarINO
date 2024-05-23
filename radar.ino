
#include <DistanceSensor.h>
#include <ESP32Servo.h>
Servo myservo;
const int echoPin = 2;
const int trigPin = 4;
const int echoPin2 = 18;
const int trigPin2 = 19;
DistanceSensor sensor(trigPin, echoPin);
DistanceSensor sensor2(trigPin2, echoPin2);
bool buzz

  int d1;
int d2;


void setup() {
  myservo.attach(14, 400, 2400);
  Serial.begin(115200);
}

void loop() {
  for (int i = 1; i < 180; i++) {
    readSensors();
    Serial.print(i);
    Serial.print(",");
    Serial.print(d1);
    Serial.print(",");
    Serial.println(d2);
    myservo.write(i);
    delay(30);
  }
  for (int i = 180; i > 1; i--) {
    readSensors();
    Serial.print(i);
    Serial.print(",");
    Serial.print(d1);
    Serial.print(",");
    Serial.println(d2);
    myservo.write(i);
    delay(30);

    if (d1 <= 5 || d2 <= 5) {

    } else {
    }
  }

  void buzzerStart(int repeat) {
    for (byte i = 0; i < repeat; i++) {
      digitalWrite(buzzer, !digitalRead(buzzer));  // to switch buzzer ON and OFF alternatively
    }
  }

  void readSensors() {
    d1 = sensor.getCM();
    d2 = sensor2.getCM();
  }
