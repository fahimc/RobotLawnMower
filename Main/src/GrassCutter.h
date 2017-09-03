class GrassCutter {
  int CutterPin;
public:
  GrassCutter (int cutterPin){
  CutterPin = cutterPin;
  }
  void init(){
    pinMode(2,OUTPUT);
  }
  void start(){
    digitalWrite(CutterPin,HIGH);
    //delay(1000);
  }
};
