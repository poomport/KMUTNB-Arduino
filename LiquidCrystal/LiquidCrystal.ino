#include<LiquidCrystal.h>
int rs = 2;
int e = 3 ;
LiquidCrystal lcd(rs,e,8,9,10,11);
void setup() {
  
 lcd.begin(16,2);
 lcd.cursor();
 lcd.print("Hello , World!");

}

void loop() {


}
