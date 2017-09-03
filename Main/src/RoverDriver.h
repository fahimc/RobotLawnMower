class RoverDriver {
   AF_DCMotor* LeftBackWheel;
   AF_DCMotor* RightBackWheel;
   AF_DCMotor* RightFrontWheel;
   AF_DCMotor* LeftFrontWheel;
   int SPEED = 255;
   int TURN_DELAY = 2000;
  public:
  RoverDriver(int leftBackWheelPin,int rightBackWheelPin,int leftFrontWheelPin,int rightFrontWheelPin){
    LeftBackWheel = new AF_DCMotor(leftBackWheelPin);
    RightBackWheel = new AF_DCMotor(rightBackWheelPin);

    LeftFrontWheel = new AF_DCMotor(leftFrontWheelPin);
    RightFrontWheel = new AF_DCMotor(rightFrontWheelPin);
  }
 void init(){
    LeftBackWheel->setSpeed(SPEED);
    RightBackWheel->setSpeed(SPEED);

    LeftFrontWheel->setSpeed(SPEED);
    RightFrontWheel->setSpeed(SPEED);

    stop();
  }
  void forward(){
    LeftBackWheel->run(FORWARD);
    RightBackWheel->run(FORWARD);
    LeftFrontWheel->run(FORWARD);
    RightFrontWheel->run(FORWARD);
  }
  void reverse(){
    LeftBackWheel->run(BACKWARD);
    RightBackWheel->run(BACKWARD);
    LeftFrontWheel->run(BACKWARD);
    RightFrontWheel->run(BACKWARD);
  }
  void turnLeft(){
    LeftBackWheel->run(BACKWARD);
    RightBackWheel->run(FORWARD);
    LeftFrontWheel->run(BACKWARD);
    RightFrontWheel->run(FORWARD);
    delay(TURN_DELAY);
  }
  void turnRight(){
    LeftBackWheel->run(RELEASE);
    LeftFrontWheel->run(RELEASE);
    
    RightBackWheel->run(BACKWARD);
    RightFrontWheel->run(BACKWARD);
    delay(TURN_DELAY);
  }
  void stop(){
    LeftBackWheel->run(RELEASE);
    RightBackWheel->run(RELEASE);
    LeftFrontWheel->run(RELEASE);
    RightFrontWheel->run(RELEASE);
  }
};
