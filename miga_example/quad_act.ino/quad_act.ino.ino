// Initial Variable Declarations

int tricep1 = 9;
int bicep1 = 10;
//int migaPin3 = 5;
//int migaPin4 = 9;
int tricepFan = 2;
int bicepFan = 7;
int potPin = A2;
int pot = 0;


typedef struct {
  int fanPin;
  int actPin;
} Muscle;


void setup() {

  // Begin serial communication
  Serial.begin(9600);
  
  // Pin setup
  Serial.println("Initializing Pins");
  pinMode(potPin, INPUT);
  pinMode(tricep1, OUTPUT);
  pinMode(bicep1, OUTPUT);
//  pinMode(migaPin3, OUTPUT);
//  pinMode(migaPin4, OUTPUT);
  pinMode(bicepFan, OUTPUT);
  pinMode(bicepFan, OUTPUT);
  
  // Initialize Actuators
  Serial.println("Initializing Actuators");
  analogWrite(tricep1, 1023); 
  analogWrite(bicep1, 1023); 
//  analogWrite(migaPin3, 1023); 
//  analogWrite(migaPin4, 1023);
  delay(2000);

  analogWrite(tricep1, 0); 
  analogWrite(bicep1, 0); 
//  analogWrite(migaPin3, 0); 
//  analogWrite(migaPin4, 0);
  
  // Initialize fans
  Serial.println("Initializing Fans");
  digitalWrite(tricepFan, HIGH);
  digitalWrite(bicepFan, HIGH);
  delay(2000);
  
  digitalWrite(tricepFan, LOW);
  digitalWrite(bicepFan, LOW);

  Serial.println("Initialization Complete");

  Muscle tricep;
}



//void flex(Muscle){
//  analogWrite(Muscle.actPin, 1024);
//  
//}
//
//
//void relax(Muscle){
//  analogWrite(Muscle.actPin, 0);
//  digitalWrite(Muscle.fanPin, HIGH);
//  delay(1000);
//  digitalWrite(Muscle.fanPin, LOW);
//}


void loop() {
  pot = analogRead(potPin);
  analogWrite(tricep1, pot); 
  analogWrite(bicep1, pot); 
//  analogWrite(migaPin3, pot); 
//  analogWrite(migaPin4, pot); 
  Serial.println(pot);
}
