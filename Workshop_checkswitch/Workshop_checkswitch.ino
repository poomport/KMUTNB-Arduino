void setup() {
  
pinMode(15,INPUT); // Switch 1
pinMode(16,INPUT); // Switch 2

Serial.begin(9600);
}

void loop() {
  int val1;
  int val2;

  val1 = digitalRead(15); // Switch 1 //A1
  Serial.println("Switch1 : ");
  Serial.println(val1);
  delay(100);
  
  val2 = digitalRead(16); // Switch 2 //A2
  Serial.println("Switch2 : ");
  Serial.println(val2);
  delay(100);
}
