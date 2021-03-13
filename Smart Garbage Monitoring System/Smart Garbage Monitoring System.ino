#include<WiFi.h>
#include<IOXhop_FirebaseESP32.h>
#include "DHT.h"

#define FIREBASE_HOST "clean-experts.firebaseio.com" 
#define FIREBASE_AUTH "5HcgxcOZvUIQvRmTcEGIoMCQ3d9OuRDYPtTUpEuG"
#define DHTPIN 15
#define DHTTYPE DHT11
const char* wifiname="OnePlus 6T P";
const char* wifipass="........";

double marginT = 26.00;
double marginH = 15.00;
double cel;
double hum;
double cel1 =0;
double hum1=0;
int countT=0;
int countH=0;
int tr=2;
int ec=4;
float duration, d;


DHT dht(DHTPIN, DHTTYPE);


void readsens()
{

  digitalWrite(tr,LOW);
  delayMicroseconds(3);
  digitalWrite(tr,HIGH);
  delayMicroseconds(6); 
  duration = pulseIn(ec, HIGH);
  d = duration*(0.034/2); 
  
 }

void setup()
{
  Serial.begin(9600);
  pinMode(tr,OUTPUT);
  pinMode(ec,INPUT);
  Serial.println();

  Serial.print("Connecting to: " );
  Serial.print(wifiname);
  WiFi.begin(wifiname, wifipass);

while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("wifi connected");
Serial.println(wifiname);

dht.begin();
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.setFloat("VAN/VAN1/GPS&SPEED/LATITUDE",0);
Firebase.setFloat("VAN/VAN1/GPS&SPEED/LONGITUDE",0);
Firebase.setFloat("VAN/VAN1/GPS&SPEED/SPEED",0);
Firebase.setFloat("DUSTBIN/DUSTBIN1/DHT_CEL/Dustbin",1);
Firebase.setFloat("DUSTBIN/DUSTBIN1/DHT_CEL",0);
Firebase.setFloat("DUSTBIN/DUSTBIN1/DHT_HUM",0);

}

void loop()
{
  readsens();
  Serial.println("Length: ");
  Serial.print(d); 
  Serial.println("");
  if(d<=7)
  {
  Firebase.setFloat("DUSTBIN/DUSTBIN1/Dist",d);
  }  
  cel =dht.readTemperature();
  if(cel==cel1)
  {
  countT=countT+1;
  }
  else
  {
    countT=0;
  
  }
  cel1=cel; 
  Serial.println("TEMPERATURE: ");
  Serial.print(cel);
  Serial.println("");
  if(countT>=2 && (cel1==marginT || cel1==25 || cel1==24 ||  cel1==27))
  {
  Firebase.setFloat("DUSTBIN/DUSTBIN1/DHT_CEL",cel);
  }
  hum = dht.readHumidity();
   if(hum==hum1)
  {
  countH=countH+1;
  }
  else
  {
    countH=0;
  }
  hum1=hum;
  Serial.println("HUMIDITY:  ");
  Serial.print(hum);
  Serial.println("");
  if(countT>=2 && (hum1==15 || hum1==14 || hum1==16 ||  hum1==17))
  {
   Firebase.setFloat("DUSTBIN/DUSTBIN1/DHT_HUM",hum);
  }
  
  delay(3500);
}
