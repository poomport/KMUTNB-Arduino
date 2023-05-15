int font[11] = {
               0x3F, // 0
               0x06, // 1
               0x5B, // 2
               0x4F, // 3
               0x66, // 4
               0x6D, // 5
               0x7D, // 6
               0x07, // 7
               0x7F, // 8
               0x6F, // 9
               0x00  // off
              };
int disBuf[3]; //{ค่าD1,ค่าD2,ค่าD3}

void send7Seg_MultiDigit(int pat,int digit){
  
  digitalWrite(3,HIGH); // Turn off Digit 1
  digitalWrite(4,HIGH); // Turn off Digit 2
  digitalWrite(5,HIGH); // Turn off Digit 3
  digitalWrite(6,HIGH); // Turn off Digit 4
  
  int a   = 0b00000001;
  for(int i=7;i<=14;i++){
    digitalWrite(i,pat&a);
    a = a << 1;
  }
   switch(digit){
      case 1:
            digitalWrite(3,LOW);  // Turn off Digit 1
            digitalWrite(4,HIGH); // Turn off Digit 2
            digitalWrite(5,HIGH); // Turn off Digit 3
            digitalWrite(6,HIGH); // Turn off Digit 4
            break;
      case 2:
            /*
            digitalWrite(3,HIGH); // Turn off Digit 1
            digitalWrite(4,LOW);  // Turn off Digit 2
            digitalWrite(5,HIGH); // Turn off Digit 3
            digitalWrite(6,HIGH); // Turn off Digit 4
            break; */
     
            for(int i=3;i<=6;i++){
              if(i==4){
                digitalWrite(i,0); // Turn on Digit 2
              }
              else{
                digitalWrite(i,1);
              }
            }  
              break;   
      case 3:
            digitalWrite(3,HIGH); // Turn off Digit 1
            digitalWrite(4,HIGH); // Turn off Digit 2
            digitalWrite(5,LOW);  // Turn off Digit 3
            digitalWrite(6,HIGH); // Turn off Digit 4
            break;
      case 4:
            digitalWrite(3,HIGH); // Turn off Digit 1
            digitalWrite(4,HIGH); // Turn off Digit 2
            digitalWrite(5,HIGH); // Turn off Digit 3
            digitalWrite(6,LOW);  // Turn off Digit 4
            break;
      } // End Switch
       
     delay(1);
   
}

void ScanX(int num){
  if(num<100){
    disBuf[0] =10; // font[10] = 0x00 // Turn off Segment หลัก1xx
  }
  else{
    disBuf[0] = num/100;
  }
  
  if(num<10){
    disBuf[1] =10; // font[10] = 0x00 // Turn off Segment หลัก1x
  }
  else{
    disBuf[1] = num/10%10;
  }
  disBuf[2] = num%10; // ค่าของหลักสิบ
  
  send7Seg_MultiDigit(font[disBuf[0]],1);
  send7Seg_MultiDigit(font[disBuf[1]],2);
  send7Seg_MultiDigit(font[disBuf[2]],3);
  
}

void setup() {
  for(int i=3;i<=14;i++){
    pinMode(i,OUTPUT); 
  }

  pinMode(15,INPUT); // Switch1
  pinMode(16,INPUT); // Switch2
      
}
int num = 180;
unsigned long previousMillis = 0; 
unsigned long currentMillis = 0;       
const long interval = 1000; 
bool state = true; // true = play , false = pause

void loop() {

    unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if(state == true){
      num--;
    }
    else if(state == false){
       // Blink Led
        send7Seg_MultiDigit(font[10],1);
        send7Seg_MultiDigit(font[10],2);
        send7Seg_MultiDigit(font[10],3);
        delay(500);
        ScanX(num);
    }
  }
  if(digitalRead(15) == 0){
    delay(20);
    while(digitalRead(15) == 0){
    ScanX(num);
    }
    state = !state; // tongle true <-> false
  }
 ScanX(num);
}
