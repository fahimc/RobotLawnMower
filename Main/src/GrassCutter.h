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
