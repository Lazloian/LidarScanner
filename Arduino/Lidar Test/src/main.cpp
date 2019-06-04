#include <Arduino.h>
#include <Servo.h>
#include "Adafruit_VL53L0X.h"

Servo servo;
Adafruit_VL53L0X tof = Adafruit_VL53L0X();
bool right = true;
int angle = 100;

void setup()
{
  Serial.begin(9600);
  tof.begin();
  servo.attach(9);
  servo.write(angle);
}

void loop()
{
  VL53L0X_RangingMeasurementData_t distance;
  tof.rangingTest(&distance, false);
  Serial.println(distance.RangeMilliMeter);

  if (right)
  {
    if (servo.read() != 180)
    {
      angle += 5;
    }
    else
    {
      right = false;
    }
  }
  else
  {
    if (servo.read() != 0)
    {
      angle -= 5;
    }
    else
    {
      right = true;
    }
  }

  servo.write(0);
  delay(50);
}