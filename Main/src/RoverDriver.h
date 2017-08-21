class RoverDriver {
   AF_DCMotor* LeftWheel;
   AF_DCMotor* RightWheel;
  public:
  RoverDriver(int leftWheelPin,int rightWheelPin){
    LeftWheel = new AF_DCMotor(leftWheelPin);
    RightWheel = new AF_DCMotor(rightWheelPin);
  }
 void init(){
    LeftWheel->setSpeed(200);
    RightWheel->setSpeed(200);

    LeftWheel->run(RELEASE);
    RightWheel->run(RELEASE);
  }
  void forward(){
    LeftWheel->run(FORWARD);
    RightWheel->run(FORWARD);
  }
  void reverse(){
    LeftWheel->run(BACKWARD);
    RightWheel->run(BACKWARD);
  }
  void turnLeft(){
    LeftWheel->run(BACKWARD);
    RightWheel->run(FORWARD);
    delay(500);
  }
  void turnRight(){
    LeftWheel->run(FORWARD);
    RightWheel->run(BACKWARD);
    delay(500);
  }
  void stop(){
    LeftWheel->run(RELEASE);
    RightWheel->run(RELEASE);
  }
};
