#include<LiquidCrystal.h>  //LCD Library
LiquidCrystal lcd(2,3,4,5,6,7);  //Declare LCD pins rs, enable, d4,d5,d6,d7 in Microcontroller

const int l1=24;
const int l2=25;
const int r1=0;
const int r2=1;

const int e1=13;
const int e2=14;
const int w1=15;
const int w2=16;

const int en1=26;
const int en2=27;

void Forward()
{
   digitalWrite(l1,1);
   digitalWrite(l2,0);
   digitalWrite(r1,1);
   digitalWrite(r2,0);
}

void Stop()
{
   digitalWrite(l1,0);
   digitalWrite(l2,0);
   digitalWrite(r1,0);
   digitalWrite(r2,0);

   digitalWrite(e1,0);
   digitalWrite(e2,0);
   digitalWrite(w1,0);
   digitalWrite(w2,0);
}

void Reverse()
{
   digitalWrite(l1,0);
   digitalWrite(l2,1);
   digitalWrite(r1,0);
   digitalWrite(r2,1);
}

void Right()
{
   digitalWrite(l1,1);
   digitalWrite(l2,0);
   digitalWrite(r2,1);
}

void Left()
{
   digitalWrite(l1,0);
   digitalWrite(l2,1);
   digitalWrite(r1,1);
   digitalWrite(r2,0);
}

void ElbowUp()
{
   digitalWrite(e1,1);
   digitalWrite(e2,0);
}

void ElbowDown()
{
   digitalWrite(e1,0);
   digitalWrite(e2,1);
}

void WristUp()
{
   digitalWrite(w1,1);
   digitalWrite(w2,0);
}   

void WristDown()
{
   digitalWrite(w1,0);
   digitalWrite(w2,1);
}

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(w1,OUTPUT);
 pinMode(w2,OUTPUT);
 pinMode(e1,OUTPUT);
 pinMode(e2,OUTPUT);
 pinMode(w1,OUTPUT);
 pinMode(w2,OUTPUT);

 pinMode(en1,OUTPUT);
 pinMode(en2,OUTPUT);

 lcd.begin(16,2);
 lcd.print("Hi Appu");
// delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.clear();

 while(!Serial.available())
 {
  lcd.clear();
  lcd.print("Velai Seiyala");
  //delay(50);

  Stop();
 }
 char c=Serial.read();

 Serial.println(c);
 lcd.print(c);
 //delay(50);

 if(c=='a')
  {
   analogWrite(en1,255);
   Left();
   delay(40);
   Stop();
   delay(5);
  }
 if(c=='d')
  {
analogWrite(en1,255);
Right();
   delay(40);
   Stop();
   delay(5);
  }
 if(c=='w')
  {
analogWrite(en1,255);
Forward();
   delay(40);   
   Stop();
   delay(5);
  }
 if(c=='s')
  {
analogWrite(en1,255);
   Reverse();
   delay(40);
   Stop();
   delay(5);
  }
 if(c=='A')
  {
  analogWrite(en1,255);
   Left();
  }
 if(c=='D')
  {
   analogWrite(en1,255);
   Right();
  }
 if(c=='W')
  {
   analogWrite(en1,255);
   Forward();
  }
 if(c=='S')
  {
   analogWrite(en1,255);
   Reverse();
  }
 if(c=='o')     //Wrist Up(Open)
  WristUp();     
 if(c=='p')     //Wrist Down(Close)
  WristDown();
 if(c=='k')     //Elbow Up
  ElbowUp();
 if(c=='l')     //Elbow Down
  ElbowDown();
}
