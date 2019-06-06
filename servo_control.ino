// Reference:
// https://atceiling.blogspot.com/2017/03/arduino.html
// https://www.arduino.cc/en/Serial/Read
#include <Servo.h>

Servo servo;
int pos = 0;

int buf;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  if (Serial.available() > 0) {
    buf =  Serial.read();
    if (0 <= buf && buf <= 180) {
      pos = buf;
      servo.write(pos);
    }
    // It will print "123\r\n"
    Serial.println(pos);
  }
}
