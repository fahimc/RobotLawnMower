void timer(unsigned long interval, void (*g)()){
  static unsigned long prev = 0;
  if (millis() - prev >= interval){
    g();
    prev = millis();
  }
}
