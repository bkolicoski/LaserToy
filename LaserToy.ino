#include <Servo.h>

Servo servo1;
Servo servo2;

int pos1 = 0;
int pos2 = 0;

int limit1a = 100;
int limit1b = 180;
int limit2a = 110;
int limit2b = 160;

void setup() {
  servo1.attach(9);
  servo2.attach(11);

  servo1.write(limit1a);
  servo2.write(limit2b);
  delay(200);

  for(int a = 0; a < 3; a++){
    for(int i = limit1a; i < limit1b; i++){
      servo1.write(i);
      delay(15);
    }
    for(int i = limit2b; i >= limit2a; i--){
      servo2.write(i);
      delay(15);
    }
    for(int i = limit1b; i >= limit1a; i--){
      servo1.write(i);
      delay(15);
    }
    for(int i = limit2a; i < limit2b; i++){
      servo2.write(i);
      delay(15);
    }
  }
}

void loop() {

  pos1 = random(limit1a, limit1b);
  pos2 = random(limit2a, limit2b);

  servo1.write(pos1);
  delay(500);
  servo2.write(pos2);

  delay(500);
}
