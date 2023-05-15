void setup() {
  
pinMode(0,INPUT); // Switch 1
pinMode(1,INPUT); // Switch 2

Serial.begin(300);
}

void loop() {
  int val1;
  int val2;
  /*
  val1 = digitalRead(2); // Switch 1
  Serial.println(val1);
  delay(100);
  /*
  val2 = digitalRead(3); // Switch 2
  Serial.println(val2);
  delay(100);*/
  
  val1 = digitalRead(0); // Switch 1
  Serial.println("Ratchapoom Huabiam Ratchapoom Huabiam Ratchapoom Huabiam");
  delay(100);
  
}
