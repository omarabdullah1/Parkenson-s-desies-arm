#include <Servo.h>
Servo ServoAUp, ServoBUp, ServoCUp, ServoDUp, ServoEUp, ServoADwn, ServoBDwn, ServoCDwn, ServoDDwn, ServoEDwn;
const int flex1 = A4, flex2 = A3, flex3 = A2, flex4 = A1, flex5 = A0;
int flex1position = 0, flex2position = 0, flex3position = 0, flex4position = 0, flex5position = 0;
int servoAposition = 0, servoBposition = 0, servoCposition = 0, servoDposition = 0, servoEposition = 0;
void setup() {
  Serial.begin(9600);
  ServoAUp.attach(2);
  ServoBUp.attach(3);
  ServoCUp.attach(4);
  ServoDUp.attach(5);
  ServoEUp.attach(6);
  ServoADwn.attach(7);
  ServoBDwn.attach(8);
  ServoCDwn.attach(9);
  ServoDDwn.attach(10);
  ServoEDwn.attach(11);
}
//744:856,740:855,755:900,735:800,750:830

void loop() {

  flex1position = analogRead(flex1);
  flex2position = analogRead(flex2);
  flex3position = analogRead(flex3);
  flex4position = analogRead(flex4);
  flex5position = analogRead(flex5);

  servoAposition = map(flex1position, 744, 856, 0, 180);
  servoBposition = map(flex2position, 740, 855, 0, 180);
  servoCposition = map(flex3position, 755, 900, 0, 180);
  servoDposition = map(flex4position, 735, 800, 0, 180);
  servoEposition = map(flex5position, 750, 830, 0, 180);


  servoAposition = constrain(servoAposition, 0, 180);
  servoBposition = constrain(servoBposition, 0, 180);
  servoCposition = constrain(servoCposition, 0, 180);
  servoDposition = constrain(servoDposition, 0, 180);
  servoEposition = constrain(servoEposition, 0, 180);

  ServoAUp.write(servoAposition);
  ServoADwn.write(servoAposition);

  ServoBUp.write(servoBposition);
  ServoBDwn.write(servoBposition);

  ServoCUp.write(servoCposition);
  ServoCDwn.write(servoCposition);

  ServoDUp.write(servoDposition);
  ServoDDwn.write(servoDposition);

  ServoEUp.write(servoEposition);
  ServoEDwn.write(servoEposition);

  Serial.print(flex1position);
  Serial.print(",");
  Serial.print(flex2position);
  Serial.print(",");
  Serial.print(flex3position);
  Serial.print(",");
  Serial.print(flex4position);
  Serial.print(",");
  Serial.println(flex5position);
  // myServo.write(servoposition);
  // Serial.println("sensor");
  // Serial.println(flexposition);
  // Serial.println("myservo");
  // Serial.println(servoposition);
  delay(80);
}

// #include <Servo.h>
// Servo myServo;
// Servo myServo2;
// const int flexPin = A0;
// int currentFlexposition;
// int lastFlexposition;
// int servoposition;
// int servoposition2;
// void setup() {
// Serial.begin(9600);
// myServo.attach(11);
// myServo2.attach(10);
// }
// void loop() {
// currentFlexposition=analogRead(flexPin);

//   if(currentFlexposition>lastFlexposition){
//   //inc
//    Serial.println("inc");
//     servoposition=map(currentFlexposition, 730, 900, 0, 180);
// servoposition=constrain(servoposition, 0, 180);
// myServo.write(servoposition);
// Serial.println("sensor");
// Serial.println(currentFlexposition);
// Serial.println("myservo");
// Serial.println(servoposition);
//   }
//   else if(lastFlexposition>currentFlexposition){
//     //inc
//        Serial.println("dec");
// servoposition2=map(lastFlexposition, 730, 900, 0, 180);
// servoposition2=constrain(servoposition2, 0, 180);
// myServo2.write(servoposition2);
//   }

// //Serial.println("sensor");
// //Serial.println(lastFlexposition);
// //Serial.println("myservo");
// //Serial.println(servoposition2);
// //  }

// lastFlexposition=currentFlexposition;
// delay(80);
// }
