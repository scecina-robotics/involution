#include "main.h"
#include "scoop.h"

void scoopArmSet(int speed){
  motorSet(6, speed);
  motorSet(7,-speed);
}

void scoopGateSetRight(int speed){
  motorSet(9,-speed);
}

void scoopGateSetLeft(int speed) {
  motorSet(8, speed);
}
