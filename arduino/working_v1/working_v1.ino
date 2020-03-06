// Variable Declarations

int tricepPin = 10;
int tricepFan = 8;
int bicepPin = 11;
int bicepFan = 12;
float value = 1;  // 0 - 100
//int val = (value*255)/100; // 0 - 255
int val = 1;

void setup(){

  Serial.begin(9600);
  Serial.println("Initializing");
  pinMode(tricepPin, OUTPUT);
  pinMode(tricepFan, OUTPUT);
  pinMode(bicepPin, OUTPUT);
  pinMode(bicepFan, OUTPUT);
  
  Serial.println("Bicep Fan");
  digitalWrite(bicepFan, HIGH);
  delay(1000);
  digitalWrite(bicepFan, LOW);
  Serial.println("Tricep Fan");
  digitalWrite(tricepFan, HIGH);
  delay(1000);
  digitalWrite(tricepFan, LOW);
  
  analogWrite(tricepPin, val); 
  analogWrite(bicepPin, val); 
  delay(1000);
  Serial.println("Initialization Complete");

}

void loop(){

  Serial.println("flex");
  digitalWrite(tricepPin, HIGH);
  digitalWrite(tricepFan, LOW);
  digitalWrite(bicepPin, LOW);
  digitalWrite(bicepFan, HIGH);
  delay(5000);

  Serial.println("relax");
  digitalWrite(tricepPin, LOW);
  digitalWrite(tricepFan, HIGH);
  digitalWrite(bicepPin, HIGH);
  digitalWrite(bicepFan, LOW);
  delay(5000);

}
