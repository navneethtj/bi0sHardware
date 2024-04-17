const int shift = 3; 

void setup() 
{
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) 
  {
    char incomingByte = Serial.read(); 
    char decodedChar = decodeCaesar(incomingByte, shift);
    Serial.print(decodedChar );
  }
}

char decodeCaesar(char input, int shift) 
{
  if (isalpha(input)) 
  { 
    char base = islower(input) ? 'a' : 'A'; 
    return (input - base + 26 - shift) % 26 + base; // Caesar Cipher decryption
  } 
  else 
  {
    return input; 
  }
}
