// Variable Declarations

int tricepPin = 11;
int bicepPin = 10;
int tricepFan = 8;
int bicepFan = 12;
float value = 1;  // 0 - 100
//int val = (value*255)/100; // 0 - 255
int val =45;


void setup(){

  Serial.begin(9600);
  Serial.println("Initializing");
  pinMode(tricepFan, OUTPUT);
  pinMode(bicepFan, OUTPUT);
  analogWrite(tricepPin, val); 
  analogWrite(bicepPin, val); 
//  delay(5);

}
void loop() {

}
