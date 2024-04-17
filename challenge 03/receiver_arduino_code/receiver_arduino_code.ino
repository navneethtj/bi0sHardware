#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 


void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
}

void loop() {
  if (Serial.available() > 0) { 
    String receivedData = Serial.readStringUntil('\n'); 
    Serial.print("Received: ");
    Serial.println(receivedData);

    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print(receivedData); 
  }
}
