class Proximity {
  int OBJECT_DISTANCE = 30;
  unsigned long echoPin = 5;
  int leftTriggerPin = 4; 
  unsigned long leftUltrasoundValue = 0;
  int centerTriggerPin = 4; 
  unsigned long centerUltrasoundValue = 0;
  int rightTriggerPin = 4; 
  unsigned long rightUltrasoundValue = 0;
  public:
  Proximity(long _leftTriggerPin, long _leftUltrasoundValue, long _centerTriggerPin, long _centerUltrasoundValue,long _rightTriggerPin, long _rightUltrasoundValue){
    leftTriggerPin = _leftTriggerPin;
    leftUltrasoundValue = _leftUltrasoundValue;
    centerTriggerPin = _centerTriggerPin;
    centerUltrasoundValue = _centerUltrasoundValue;
    rightTriggerPin = _rightTriggerPin;
    rightUltrasoundValue = _rightUltrasoundValue;
  }
  void init(){
    setPinMode(leftTriggerPin,leftUltrasoundValue);
    setPinMode(centerTriggerPin,centerUltrasoundValue);
    setPinMode(rightTriggerPin,rightUltrasoundValue);
  }
  void setPinMode(long triggerPin,long ultraSound){
    pinMode(triggerPin,OUTPUT);
    pinMode(ultraSound,INPUT);
  }
  boolean isObstacle(){
    boolean found = isObject(leftTriggerPin,leftUltrasoundValue);
    if(!found)found = isObject(centerTriggerPin,centerUltrasoundValue); 
    if(!found)found = isObject(rightTriggerPin,rightUltrasoundValue); 

    return found;
  }
  boolean isObject(long triggerPin,long echoPin){
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
