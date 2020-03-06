int incomingByte = 0; // for incoming serial data
char arr[100];
String str;
int i = 0,j=0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial.println("echo: ");
  
  while (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    arr[i] = char(incomingByte);
    i++;
  }
  i = 0;
  for(j=0;j<i;j++){
    Serial.println(String(arr[j])); 
  }
}


void loop() {
}
