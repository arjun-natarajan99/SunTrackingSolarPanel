#include <Servo.h>

Servo servo;
int b1;
int b2;
int b3;
int b4;
int pos;
int diff;
int sum1;
int sum2;

void setup() {
servo.attach(9);
Serial.begin(9600);
pos = 180;
}

void loop() {
b1 = analogRead(1);
b2 = analogRead(2);
b3 = analogRead(3);
b4 = analogRead(4);
sum1 = b1 + b2;
sum2 = b3 + b4;
Serial.print("1 brightness = ");
Serial.print(b1);
Serial.print (" ");
Serial.print("2 brightness = ");
Serial.print(b2);
Serial.print (" ");
Serial.print("3 brightness = ");
Serial.print(b3);
Serial.print (" ");
Serial.print ("4 brightness = ");
Serial.print(b4); 
Serial.print (" "); 
diff = sum1 - sum2;
Serial.print("difference = ");
Serial.print(diff);
Serial.print (" ");
Serial.print("sum1 = ");
Serial.print(sum1);
Serial.print (" ");
Serial.print("sum2 = ");
Serial.print(sum2);
Serial.print (" ");

if (diff >  50)  {
  pos = pos - 5;
}
if (diff < -50) {
  pos = pos + 5;
}
if (pos > 180) {
  pos = 180;
}
else if (pos < 0) {
  pos = 0;
}
servo.write(pos);
Serial.println(pos);
delay(500);
} 
