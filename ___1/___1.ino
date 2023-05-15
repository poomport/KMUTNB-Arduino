// ข้อ 1
int font[6] = {
               0x3F, // 0
               0x06, // 1
               0x5B, // 2
               0x77, // A
               0x7F, // 8 = B
               0x00  // off
              };

void send7Seg_MultiDigit(int pat,int digit){


  digitalWrite(3,HIGH); // Turn off Digit 1
  digitalWrite(4,HIGH); // Turn off Digit 2
  
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
            
            digitalWrite(3,HIGH); // Turn off Digit 1
            digitalWrite(4,LOW);  // Turn off Digit 2
            digitalWrite(5,HIGH); // Turn off Digit 3
            digitalWrite(6,HIGH); // Turn off Digit 4
            
            break; 
    
      } // End Switch
       
     delay(1);
   
}
void setup() {
     
  for(int i=3;i<=14;i++){
    pinMode(i,OUTPUT); 
  }

  pinMode(15,INPUT); // Switch1

}

void click1(){
  send7Seg_MultiDigit(font[3],1);
  send7Seg_MultiDigit(font[1],2);
}

void click2(){
  send7Seg_MultiDigit(font[4],1);
  send7Seg_MultiDigit(font[2],2);
}

int Roundc = digitalRead(15);
bool state = true;

void loop() {
    state =! state;
   
    click1();
    
    state =! state;
    click2();
    
}
