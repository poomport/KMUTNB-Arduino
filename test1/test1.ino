int font[3] = {
               0x77, // A
               0x7c,   // b
               0x39 // C
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
  pinMode(16,INPUT); // Switch1
  
  send7Seg_MultiDigit(font[2],1);
  send7Seg_MultiDigit(font[2],2);
}

int r1;
void click1(){ //AA
    r1 = digitalRead(15);
    send7Seg_MultiDigit(font[0],1);
    send7Seg_MultiDigit(font[0],2);
}
int r2;
void click2(){ //bb
  r2 = digitalRead(16);
  send7Seg_MultiDigit(font[1],1);
  send7Seg_MultiDigit(font[1],2);
}

bool state = 0;
void loop() {  




  state =! state;
  if(digitalRead(15)==0){
  if(state == false){
  click1();
  }}
  if(digitalRead(16)==0){
  if(state == false){
  click2();
  }}
  
    
}
