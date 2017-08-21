#include <AFMotor.h>
#include "src/util/Timer.h"
#include "src/RoverDriver.h"
#include "src/GrassCutter.h"
#include "src/Proximity.h"
#include "src/LawnMower.h"

LawnMower lawnMower;

void setup() {
 lawnMower.setup();
}

void loop() {
  lawnMower.loop();
}


