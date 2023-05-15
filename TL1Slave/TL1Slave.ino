//Slave
#include <SoftwareSerial.h>
const byte rxPin = 2;
const byte txPin = 3;
// Set up a new SoftwareSerial Object
SoftwareSerial mySerial (rxPin,txPin);
void setup() {
 mySerial.begin(9600); // SoftwareSeial
 Serial.begin(9600); 
 pinMode(13,OUTPUT);
}
char Buffer[5];
int index = 0;
bool mesfinish = false;
void loop() {
 mesfinish = false;
 if(mySerial.available() > 0){
 char data = mySerial.read();
 //Serial.println(data);
 if(data == ':'){
  Buffer[0] = data;
 }
 else if(data != '#'){
  index++;
  Buffer[index] = data;
 }
 else if(data == '#'){
  index++;
  Buffer[3] = data;
  Buffer[4] ='\0';
 
  mesfinish = true;
 }
 }
 
 if(mesfinish){
  if(Buffer[1] == 'L'){
  digitalWrite(13,Buffer[2]-48);}
  Serial.println(Buffer);
 }

}
