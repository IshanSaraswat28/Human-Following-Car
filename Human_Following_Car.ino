#include <HCSR04.h>

UltraSonicDistanceSensor hc(6,7);//initialisation class HCSR04 (trig pin , echo pin)
UltraSonicDistanceSensor hc2(8,9);
UltraSonicDistanceSensor hc3(11,12);

int m1a = 2;
int m1b = 3;
int m2a = 4;
int m2b = 5;
void setup()
{ 
  Serial.begin(9600); 
  pinMode(m1a, OUTPUT);  
  pinMode(m1b, OUTPUT);  
  pinMode(m2a, OUTPUT);  
  pinMode(m2b, OUTPUT);  
  }

void loop()
{ 
  int vll=hc.measureDistanceCm();
  int vll2=hc2.measureDistanceCm();
  int vll3=hc3.measureDistanceCm();
  Serial.print("Distance Sensor 1: ");
  Serial.print(vll);
  Serial.print(" cm   ");

  Serial.print("Distance Sensor 2: ");
  Serial.print(vll2);
  Serial.print(" cm   ");

  Serial.print("Distance Sensor 3: ");
  Serial.println(vll3);

  if(vll<60 & vll>25)
  {
    gobackleft();
  }
  else if(vll2<35 & vll2>10)
  {
    goback();
  }
  else if(vll2<60 & vll2>40)
  {
    goforward();
  }
  else if(vll3<60 & vll3>25)
  {
    gobackright();
  }
   else
   {
    stopc();
   }
   delay(1000);

  }//return curent distance in serial

  void stopc()
  {
      Serial.println("stop");
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW); 
  }

  void goback()
  {
      Serial.println("back");
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW); 
  }
 void goforward()
  {
      Serial.println("forward");
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
  }
 void gobackleft()
  {
     Serial.println("left");
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW); 
  }
void gobackright()
  {
     Serial.println("right");
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    
  }
