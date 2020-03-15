// Variable Declarations
int musclePin = 0;
int tricepPin = 10;
int bicepFan = 12;

int fanPin = 0;
int bicepPin = 11;
int tricepFan = 8;

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

int flex(int musclePin, int fanPin){
  digitalWrite(musclePin, HIGH);
  digitalWrite(fanPin, HIGH);
}

int relax(int musclePin, int fanPin){
  digitalWrite(musclePin, LOW);
  digitalWrite(fanPin, LOW);
}

void loop(){

  Serial.println("flexion");
  flex(tricepPin, bicepFan);
  relax(bicepPin, tricepFan);
  delay(5000);

  Serial.println("extension");
  flex(bicepPin, tricepFan);
  relax(tricepPin, bicepFan);
  delay(5000);
}
