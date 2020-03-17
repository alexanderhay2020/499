void setup() {
  // put your setup code here, to run once:

  int pin = 10;
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  analogWrite(pin, 10); //1023 max


}

void loop() {
  // put your main code here, to run repeatedly:

}
