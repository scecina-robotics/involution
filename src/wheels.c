
#include "api.h"

void LeftWheels(int speed){
  motorSet(1,speed);
  motorSet(2,speed);
}

void RightWheels(int speed) {
  motorSet (3, speed);
  motorSet (4,speed);
}
