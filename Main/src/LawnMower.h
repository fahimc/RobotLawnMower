class LawnMower {
  int LEFT_WHEEL_PIN = 1;
  int RIGHT_WHEEL_PIN = 2;
  int CUTTER_PIN = 4;
  RoverDriver* roverDriver;
  GrassCutter* cutter;
  Proximity* proximity;

  public:
  LawnMower(){
    roverDriver = new RoverDriver(1,2);
    cutter = new GrassCutter(CUTTER_PIN);
    proximity = new Proximity(A4,A5);
  }
  void setup(){
    Serial.begin(9600);           // set up Serial library at 9600 bps
    Serial.println("Motor test!");
    roverDriver->init();
    cutter->init();
    proximity->init();
  }
  void loop(){
    roverDriver->forward();
    checkObsticale();
  }
  void checkObsticale(){
    boolean found = proximity->isObject();
    if(found)
    {
      roverDriver->stop();
      roverDriver->turnRight();
    }
  }
};

