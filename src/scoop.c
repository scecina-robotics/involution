#include "main.h"
#include "scoop.h"

void scoopArmSet(int speed){
  motorSet(6, speed);
  motorSet(7,-speed);
}

void scoopGateSet(int speed){
  motorSet(8, speed);
  motorSet(9,-speed);
}
