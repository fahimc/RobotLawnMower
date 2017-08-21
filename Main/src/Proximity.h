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
