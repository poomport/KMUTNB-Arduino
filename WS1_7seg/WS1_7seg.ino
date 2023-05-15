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
    
      digitalWrite(5, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(6, LOW);
      
  }
  //digitalWrite(6,HIGH); // off digit 1
  //digitalWrite(5,HIGH); // off digit 2
      
}

void loop() {
  /*
  for(int i=0;i<=9;i++){
    send7Seg(font[i]);  
    delay(1000);
  }
    */
      
      send7Seg(font[2]); 
      digitalWrite(5, LOW); // on digit
      delay(3); // หลอกตา
      digitalWrite(5, HIGH); // off digit
      
      send7Seg(font[1]); 
      digitalWrite(6, LOW); // on digit
      delay(3); // หลอกตา
      digitalWrite(6, HIGH); // off digit
     
}
