int r = 3;
int g = 5;
int b = 6;

void setup() {
 pinMode(r,OUTPUT);
 pinMode(g,OUTPUT);
 pinMode(b,OUTPUT);

 
 Serial.begin(9600);
 

}

void ShowRGB(int red,int green,int blue){
  red = map(50,0,255,255,0); // 0-255 -> 255-0
  green = map(155,0,255,255,0); // 0-255 -> 255-0
  blue = map(70,0,255,255,0); // 0-255 -> 255-0
  analogWrite(r,red);
  analogWrite(g,green);
  analogWrite(b,blue);
}

void loop() { 
  
 ShowRGB(100,255,255);

 // Serial.println(red,DEC);
  //Serial.println(green,DEC);
  //Serial.println(blue,DEC);
}
