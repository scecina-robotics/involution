
#include "api.h"

void LeftWheels(int speed){
  motorSet(1,speed/2);
  motorSet(2,speed/2);
}

void RightWheels(int speed) {
  motorSet (3,-speed/2);
  motorSet (4,-speed/2);
}
