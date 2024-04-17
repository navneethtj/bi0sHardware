// code for transmitter arduino,
void setup() {
  Serial.begin(9600); 
}

void loop() {
  static int number = 0; 
  Serial.println(number);
  number++;

  delay(1000); 
}
