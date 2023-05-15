#include "Timer.h"
Timer t;
int sec = 24;
int IDEvery;
int font[] = {
    0x3F,//0
    0x06,//1
    0x5B,//2
    0x4F,//3
    0x66,//4
    0x6D,//5
    0x7D,//6
    0x07,//7
    0x7F,//8
    0x6F,//9
    0x00//off
};
int disBuf[4];
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 500;           // interval at which to blink (milliseconds)

void send7Seg_Multigit(int pat, int digit){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  
  int a = 0b00000001;
  for(int i=7;i<=13;i++){
  digitalWrite(i,pat&a);
  a = a<< 1;
  }
  switch (digit){
    case 1:
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 2:
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      break;
    case 3:
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      break;
    case 4:
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      break;
  }
  delay(1);
}
void ScanX(int num){
  if(num < 1000){
    disBuf[0] = 10;
  }else{
    disBuf[0] = num / 1000;
  }
  if(num < 100){
    disBuf[1] = 10;
  }else{
    disBuf[1] = num / 100;
  }
  if(num < 10){
    disBuf[2] = 10;
  }else{
    disBuf[2] = (num / 10)%10;
  }
  disBuf[3] = num%10;
  send7Seg_Multigit(font[disBuf[0]],1);
  send7Seg_Multigit(font[disBuf[1]],2);
  send7Seg_Multigit(font[disBuf[2]],3);
  send7Seg_Multigit(font[disBuf[3]],4);
}
void ISR_Timer(){
  sec--;
  if(sec < 0){
      sec = 24;
    } 
}
void ISR_StopTime(){
  t.stop(IDEvery);
  attachInterrupt(digitalPinToInterrupt(3),ISR_PlayTime,FALLING);
}

void ISR_PlayTime(){
  IDEvery = t.every(1000,ISR_Timer);
  detachInterrupt(digitalPinToInterrupt(3));

}
void setup() {
  for(int i=4;i<=13;i++){
    pinMode(i, OUTPUT);
  }
pinMode(2,INPUT);
pinMode(3,INPUT);
IDEvery = t.every(1000,ISR_Timer);
attachInterrupt(digitalPinToInterrupt(2),ISR_StopTime,FALLING);
//attachInterrupt(digitalPinToInterrupt(3),ISR_PlayTime,FALLING);

}

void loop() {
  t.update();
  ScanX(sec);

}
