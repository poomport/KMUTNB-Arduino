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
              
void send7Seg(int pat){
  int a   = 0b00000001;
  for(int i=7;i<=13;i++){
    digitalWrite(i,pat&a);
    a = a << 1;
  } 
}

void setup() {
  for(int i=5;i<=13;i++){
    pinMode(i,OUTPUT);
  }

  pinMode(2,INPUT);
  pinMode(3,INPUT);
      
}

int num = 5;

void loop() {
 /*
  if(digitalRead(2) == 0){ // check press switch 1
    delay(100);
      if(digitalRead(2) == 0){
      num--;
      delay(100);
    }
  }
  
  
    if(digitalRead(3) == 0){ // check press switch 2
    delay(100);
      if(digitalRead(3) == 0){
      num++;
      delay(100);
      } 
  }
    if(num > 5){
     num = 5;
    }
    if(num < 0){
     num = 0;
    } 
   */ 
    //เฉลยอาจารย์
    
     if(digitalRead(2) == 0){ // check press switch 1
    delay(100);
    while(digitalRead(2) == 0){}
     
      if(digitalRead(2) == 0){
      num--;
      delay(100);
    }
    num--;
  }
  
    
    if(digitalRead(3) == 0){ // check press switch 2
    delay(100);
    while(digitalRead(3) == 0){}
    
      if(digitalRead(3) == 0){
      num++;
      delay(100);
      } 
      num++;
    }
    if(num > 5){
     num = 5;
    }
    if(num < 0){
     num = 0;
    } 
  send7Seg(font[num]);
}
