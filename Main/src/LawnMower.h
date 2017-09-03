class LawnMower {
  int LEFT_WHEEL_PIN = 1;
  int RIGHT_WHEEL_PIN = 2;
  int CUTTER_PIN = A0;
  RoverDriver* roverDriver;
  GrassCutter* cutter;
  Proximity* proximity;

  public:
  LawnMower(){
    roverDriver = new RoverDriver(1,2,4,3);
    cutter = new GrassCutter(CUTTER_PIN);
    proximity = new Proximity(A0,A1,A2,A3,A4,A5);
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
    cutter->start();
    checkObsticale();
  }
  void checkObsticale(){
    boolean found = proximity->isObstacle();
    if(found)
    {
      roverDriver->stop();
      roverDriver->turnRight();
    }
  }
};

