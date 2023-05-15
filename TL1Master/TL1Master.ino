//Master
#include <SoftwareSerial.h>
const byte rxPin = 2;
const byte txPin = 3;
// Set up a new SoftwareSerial Object
SoftwareSerial mySerial (rxPin,txPin);
void setup() {
 mySerial.begin(9600);
 //mySerial.print("L123");

}

void loop() {
 mySerial.print(":L1#");
 delay(1000);
 mySerial.print(":L0#");
 delay(1000);
}
