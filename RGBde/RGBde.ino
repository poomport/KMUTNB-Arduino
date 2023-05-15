int r = 3;
int g = 5;
int b = 6;   

 void ShowRGB(int red,int green ,int blue){
   red = map (red,0,255,255,0);
   green = map(green,0,255,255,0);
   blue = map(blue,0,255,255,0);
  analogWrite(r,red);
  analogWrite(g,green);
  analogWrite(b,blue);
 }
void setup(){
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);

Serial.begin(9600);
   
}
void loop(){
 ShowRGB(0,139,139);
 delay(500);
 ShowRGB(25,25,112);
 delay(500);
 ShowRGB(75,0,130);
 delay(500);
 ShowRGB(199,21,133);
 delay(500);
 ShowRGB(139,69,19);
 delay(500);
 ShowRGB(188,143,143);
 delay(500);
 ShowRGB(112,128,144);
 delay(500);
 ShowRGB(255,182,193);
 delay(500);
 ShowRGB(105,105,105);
 delay(500);
 ShowRGB(220,20,60);
 delay(500);

}
