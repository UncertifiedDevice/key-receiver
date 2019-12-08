#include <Wire.h>

void setup()
{
  Wire.begin(1);
  Wire.onReceive(receiveCharacter);

  Serial.begin(9600);
}

void loop()
{
  delay(50);
}

void receiveCharacter(int n)
{
  while(1 < Wire.available())
  {
    Wire.read();
  }

  //display(Wire.read());
  Serial.println(Wire.read());
}
