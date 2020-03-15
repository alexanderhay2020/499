
// Define muscle command
typedef struct {
  int fanPin;
  int actPin;
} Muscle;


void flex(Muscle);
void relax(Muscle);

void setup() {

  // Begin serial communication
  Serial.begin(9600);

  // Begin pin initialization
  Serial.println("Initializing Pins");
  Muscle tricep;
  tricep.actPin = 9;                        // tricep actuator
  tricep.fanPin = 2;                        // bicep fan
  pinMode(tricep.actPin, OUTPUT);
  pinMode(tricep.fanPin, OUTPUT);

  Muscle bicep;
  bicep.actPin = 10;                        // bicep actuator
  bicep.fanPin = 7;                         // tricep fan
  pinMode(bicep.actPin, OUTPUT);
  pinMode(bicep.fanPin, OUTPUT);

  // Initialize Actuators
  // Serial.println("Initializing Actuators");
  // flex(tricep);
  // delay(1000);
  // relax(tricep);
  // delay(1000);
  // flex(bicep);
  // delay(1000);
  // relax(bicep);
  Serial.println("Initialization Complete");
}

void flex(Muscle m){
  analogWrite(m.actPin, 1023);
  digitalWrtie(m.fanPin, HIGH)
}

void relax(Muscle m){
 analogWrite(m.actPin, 0);
 digitalWrite(m.fanPin, LOW);
}


void loop(){
  flex(tricep);
  relax(bicep);
  delay(5000);
  relax(tricep);
  flex(bicep);
}
