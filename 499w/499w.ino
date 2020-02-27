// Initial Variable Declarations

int potPin = A2;
int pot = 0;

typedef struct {
  int fanPin;
  int actPin;
} Muscle;

void flex(Muscle);
void relax(Muscle);

void setup() {

  // Begin serial communication
  Serial.begin(9600);

  Muscle tricep;
  tricep.actPin = 9;
  tricep.fanPin = 2;
  pinMode(tricep.actPin, OUTPUT);
  pinMode(tricep.fanPin, OUTPUT);

  Muscle bicep;
  bicep.actPin = 10;
  bicep.fanPin = 7;
  pinMode(bicep.actPin, OUTPUT);
  pinMode(bicep.fanPin, OUTPUT);

  Serial.println("Initializing Pins");
  pinMode(potPin, INPUT);

  // Initialize Actuators
  Serial.println("Initializing Actuators");
  flex(tricep);
  delay(1000);
  relax(tricep);
  delay(1000);
  flex(bicep);
  delay(1000);
  relax(bicep);
  Serial.println("Initialization Complete");
}

void flex(Muscle m){
  analogWrite(m.actPin, 1023);
}


void relax(Muscle m){
 analogWrite(m.actPin, 0);
 digitalWrite(m.fanPin, HIGH);
 delay(4000);
 digitalWrite(m.fanPin, LOW);
}


void loop(){

}
