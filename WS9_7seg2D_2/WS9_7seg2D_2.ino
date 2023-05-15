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

void setup() {
  for(int i=3;i<=14;i++){
    pinMode(i,OUTPUT); 
  }

  pinMode(15,INPUT); // Switch1
  pinMode(16,INPUT); // Switch2
      
}


void loop() {
  send7Seg_MultiDigit(font[2],3);
  send7Seg_MultiDigit(font[5],4);
}
