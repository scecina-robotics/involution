#include "api.h"
#include "main.h"
#include "wheels.h"
#include "trough.h"
#include "scoop.h"
#include "autocode.h"
#include "ref_time.h"

void autocode(){
  // this should turn it 90 degrees
  LeftWheels(-MtrSpeed());
  RightWheels(MtrSpeed());

  delay(NinetyDegreeTurn());
   //Wait
  LeftWheels(MtrSpeed());
  RightWheels(MtrSpeed());

  delay (5000);

  LeftWheels(0);
  RightWheels(0);

}
