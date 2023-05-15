unsigned long previousMillis = 0; 
unsigned long currentMillis = 0;       
const long interval = 1000;    

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
                 
int Count = 0; 

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
}

 
void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Count++;
    send7Seg(font[Count]);
    if(Count == 9){
      Count = 0;
    } 
  } 
}
