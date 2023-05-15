#include<LiquidCrystal.h>
int rs = 2;
int e = 3 ;
LiquidCrystal lcd(rs,e,8,9,10,11);
void setup() {
  

  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.cursor();
  pinMode(14,INPUT);
  pinMode(15,INPUT);
 lcd.print("NUMBER : 100 ");

}
int NUMBER = 100;
void loop() {

  if(digitalRead(14) == 0){ 
    delay(20);
      if(digitalRead(14) == 0){
      NUMBER++;
     if(NUMBER > 198){
     NUMBER = 199;
     }
      lcd.setCursor(9,0);  
      lcd.print(NUMBER);
          delay(300);

      
  }
}
  if(digitalRead(15) == 0){ 
    delay(20);
      if(digitalRead(15) == 0){
        NUMBER--;
      if(NUMBER <= 100){
     NUMBER = 100;
      }
      lcd.setCursor(9,0);
      lcd.print(NUMBER);
          delay(300);
      }
 }
}
