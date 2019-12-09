#include <Wire.h>

// r is row and c is collum.

#define r5 1
#define r3 2
#define r8 3
#define r1 4
#define r4 5
#define SIX 6
#define c7 7
#define r2 8
#define NINE 9
#define c1 10
#define c2 11
#define c6 12
#define c3 13
#define c4 A1
#define FIFTEEN A2
#define SIXTEEN A3

char cols[4] = {c1,c2,c3,c4};
char rows[3] = {r1,r2,r3};

void setup() {
  Wire.begin(1);
  Wire.onReceive(receiveCharacter);

  Serial.begin(9600);
  
  pinMode(r5, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r8, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(SIX, OUTPUT);
  pinMode(c7, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(NINE, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c6, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(FIFTEEN, OUTPUT);
  pinMode(SIXTEEN, OUTPUT);


  digitalWrite(c7, HIGH);
  digitalWrite(c6, HIGH); 
  digitalWrite(FIFTEEN, HIGH);
}

int letters[27][12] = 
          {{{0,0,0,0,0,0,0,0,0,0,0,0}},
           {{0,1,0,1,0,1,1,1,1,1,0,1}},
           {{1,1,1,1,1,0,1,0,1,1,1,0}},
           {{0,1,1,1,0,0,1,0,0,0,1,1}},
           {{1,1,0,1,0,1,1,0,1,1,1,0}},
           {{1,1,1,1,1,0,1,0,0,1,1,1}},
           {{1,1,1,1,1,0,1,0,0,1,0,0}},
           {{0,1,1,1,0,0,1,0,1,0,1,1}},
           {{1,0,1,1,1,1,1,0,1,1,0,1}},
           {{1,1,1,0,1,0,0,1,0,1,1,1}},
           {{1,1,1,0,0,1,1,0,1,0,1,0}},
           {{1,0,1,1,1,0,1,0,1,1,0,1}},
           {{1,0,0,1,0,0,1,0,0,1,1,1}},
           {{1,1,1,1,1,1,1,0,1,1,0,1}},
           {{1,1,0,1,0,1,1,0,1,1,0,1}},
           {{0,1,0,1,0,1,1,0,1,0,1,0}},
           {{1,1,1,1,0,1,1,1,1,1,0,0}},
           {{0,1,0,1,0,1,1,1,1,0,1,1}},
           {{1,1,0,1,0,1,1,1,0,1,0,1}},
           {{1,1,1,1,1,0,0,0,1,1,1,1}},
           {{1,1,1,0,1,0,0,1,0,0,1,0}},
           {{1,0,1,1,0,1,1,0,1,0,1,0}},
           {{1,0,1,1,0,1,1,1,0,1,0,0}},
           {{1,0,1,1,0,1,1,1,1,1,1,1}},
           {{1,0,1,0,1,0,1,0,1,1,0,1}},
           {{1,0,1,1,0,1,0,1,0,0,1,0}},
           {{1,1,1,0,1,1,1,0,0,1,1,1}}};

void displayy(int indexOfLetter)
{
  for(int i = 0; i < 12; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      digitalWrite(rows[j], letters[indexOfLetter][i]);
      i++;
    }

    digitalWrite(cols[i/3], HIGH);
    delay(12);
    digitalWrite(cols[i/3], LOW);
  }
}

char currentChar = 0;

void receiveCharacter(int n)
{
  while(1 < Wire.available())
  {
    Wire.read();
  }

  currentChar = Wire.read();
  Serial.println((int)currentChar);
}

void loop()
{
  displayy(currentChar);
}
