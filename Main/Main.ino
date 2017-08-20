#include <AFMotor.h>
void timer(unsigned long interval, void (*g)()){
  static unsigned long prev = 0;
  if (millis() - prev >= interval){
    g();
    prev = millis();
  }
}
class Proximity {
  int OBJECT_DISTANCE = 15;
  unsigned long echoPin = 5;
  int triggerPin = 4; 
  unsigned long ultrasoundValue = 0;
  public:
  Proximity(long _triggerPin, long _echoPin){
    triggerPin = _triggerPin;
    echoPin = _echoPin;
  }
  void init(){
    Serial.begin(9600);
    pinMode(triggerPin,OUTPUT);
    pinMode(echoPin,INPUT);
  }
  boolean isObject(){
    digitalWrite(triggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin,LOW);
    pinMode(echoPin,INPUT);
    long distance=pulseIn(echoPin,HIGH)/ 58.138;
    boolean found = false;
    if(distance <= OBJECT_DISTANCE){
      found = true;
    }
    return found;
  }
};

class GrassCutter {
  AF_DCMotor* Cutter;
public:
  GrassCutter (int cutterPin){
    Cutter = new AF_DCMotor(cutterPin);
  }
  void init(){
    Cutter->setSpeed(200);
    Cutter->run(RELEASE);
  }
  void start(){
    Cutter->run(FORWARD);
  }
  void stop(){
    Cutter->run(RELEASE);
  }
};

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


int LEFT_WHEEL_PIN = 1;
int RIGHT_WHEEL_PIN = 2;
int CUTTER_PIN = 4;
RoverDriver roverDriver(1,2);
GrassCutter cutter(CUTTER_PIN);
Proximity proximity(A4,A5);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  roverDriver.init();
  cutter.init();
  proximity.init();
}

void loop() {
  roverDriver.forward();
  //timer(10000,end);
  //delay(1000);
  //roverDriver.turnLeft();
  //roverDriver.reverse();
  //delay(1000);
   //roverDriver.turnRight();
   //roverDriver.forward();
  //
  //cutter.start();
  boolean found = proximity.isObject();
  if(found)
  {
    roverDriver.stop();
    roverDriver.turnRight();
  }
  Serial.println(found);
  
}

void end(){
  roverDriver.stop();
  delay(1000);
}

