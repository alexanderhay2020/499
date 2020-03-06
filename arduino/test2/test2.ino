// Variable Declarations

int tricepPin = 10;
int tricepFan = 8;
int bicepPin = 11;
int bicepFan = 12;
float value = 1;  // 0 - 100
//int val = (value*255)/100; // 0 - 255
int val = 10;


void setup(){

  Serial.begin(9600);
  Serial.println("Initializing");
  pinMode(tricepFan, OUTPUT);
  pinMode(bicepFan, OUTPUT);
  digitalWrite(bicepFan, HIGH);
  delay(1000);
  digitalWrite(bicepFan, LOW);
  digitalWrite(tricepFan, HIGH);
  delay(1000);
  digitalWrite(tricepFan, LOW);

//  analogWrite(tricepPin, val); 
//  delay(5);

}
void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(tricepPin, HIGH);
//  Serial.println("flex");
//  delay(2000);
//  digitalWrite(tricepPin, LOW);
//  Serial.println("relax");
//  delay(5000);
//  

}
