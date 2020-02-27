  // Variable Declarations
  
  int tricepPin = 10;
  int bicepPin = 11;
  int potPin = A2;
  
  int pot = 0;

void setup(){

  Serial.begin(9600);
  pinMode(tricepPin, OUTPUT);
  pinMode(bicepPin, OUTPUT);
  pinMode(potPin, INPUT);    
}

void loop(){
  
  pot = analogRead(potPin);
  analogWrite(tricepPin, (pot/4)+1); 
  analogWrite(bicepPin, 256-(pot/4)); 
  Serial.println("Bicep: " + String(256-(pot/4)) + ", Tricep: " + String((pot/4)+1));
//  Serial.println(
}
