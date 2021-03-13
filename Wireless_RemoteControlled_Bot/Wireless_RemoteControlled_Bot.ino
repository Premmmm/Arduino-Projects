const int lfm1=24;
const int lfm2=25;
const int rm1=0;
const int rm2=1;
void Forward()
{
  digitalWrite(lfm1,1);
  digitalWrite(lfm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0); 
  }
void Stop()
{
  digitalWrite(lfm1,1);
  digitalWrite(lfm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,1);
    
  }
void Backward()
{
  digitalWrite(lfm1,0);
  digitalWrite(lfm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1); 
  }

void Right()
{
  digitalWrite(lfm1,1);
  digitalWrite(lfm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1); 
  }  
void Left()
{
  digitalWrite(lfm1,0);
  digitalWrite(lfm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0); 
}
void setup() 
{
  Serial.begin(9600);
  pinMode(lfm1,OUTPUT);
  pinMode(lfm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() 
{
  while(!Serial.available());
  {
    Stop();
  
  }
  char c= Serial.read();
  Serial.println(c);
  
if(c=='A')
{
  analogWrite(12,255);
  analogWrite(13,255);
  Left();
}
else if(c=='W')
{
  analogWrite(12,255);
  analogWrite(13,255);
  Forward();
}
else if(c=='S')
{
  analogWrite(12,255);
  analogWrite(13,255);
  Backward();
}
else if(c=='D')
{
  analogWrite(12,255);
  analogWrite(13,255);
  Right();
}
else if(c=='a')
{
  analogWrite(12,155);
  analogWrite(13,155);
  Left();
}
else if(c=='w')
{
  analogWrite(12,155);
  analogWrite(13,155);
  Forward();
}
else if(c=='s')
{
  analogWrite(12,155);
  analogWrite(13,155);
  Backward();
}
else if(c=='d')
{
  analogWrite(12,155);
  analogWrite(13,155);
  Right();
}
else 
Stop();
}
