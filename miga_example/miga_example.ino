// Initial Variable Declarations
int motorPin = 8;       // motor control
int potPin = A2;         // analog input
int val = 0;            // serial reading
int potBuffer = 10;     // pot reading buffer
int reps = 0;           // cycles completed
long startTime = 0;     // starting time value
long time = 0;          // current time
int dist = 150;         // desired travel distance (Calibrated)
int initPot = 0;        // initial pot value
int thresh = 0;         // pot value threshold


void setup() {
  // Pin setup
  pinMode(motorPin, OUTPUT);
  pinMode(potPin, INPUT);

  // Begin serial communication
  Serial.begin(9600);

}

void loop() {
  // Initialization
  initPot = analogRead(potPin);
  thresh = initPot + dist;
  startTime = millis();

  // Power Acutator
  digitalWrite(motorPin, HIGH);

  // Wait unit threshold is reached
  while (val < thresh){
    val = analogRead(potPin);
    time = millis() - startTime;
  }

  // Stop Actuator
  digitalWrite(motorPin, LOW);

  // Wait until actuator reaches initial position (+ buffer)
  while (val > (initPot + potBuffer)){
    val = analogRead(potPin);
  }

  // Increment Cycles
  reps = reps + 1;

  // Print reps completed and actuation time
  Serial.print(reps);Serial.print(" ");Serial.println(time);

}
