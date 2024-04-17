#include <Servo.h>
#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#define OLED_RESET 4
#define SCREEN_WIDTH 128 //  display width in pixels
#define SCREEN_HEIGHT 64 // display height in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};
byte rowPins[ROWS] = {2, 3, 4, 5}; // Connecting r1,r2,r3,r4
byte colPins[COLS] = {6, 7, 8, 9}; // Connecting c1,c2,c3,c4
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //creating object

#define SERVO_PIN 10
Servo servo;

const String correctPin = "12345678";

String enteredPin = ""; 
boolean doorLocked = true;

void setup() {
  // Initialising display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);

  // Initialize servo
  servo.attach(SERVO_PIN);
  servo.write(0); 
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '#') { // Check if entered PIN is complete
      if (enteredPin == correctPin) {
        unlockDoor();
      } else {
        enteredPin = ""; // Reseting the entered PIN
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Invalid PIN!");
        display.display();
        delay(2000);
        display.clearDisplay();
      }
    } else {
      enteredPin += key; // Adding keypad input to entered pin
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Enter PIN:");
      for (int i = 1; i <= enteredPin.length(); i++) {
        display.print("*"); // show digits
      }
      display.display();
    }
  }
}

void unlockDoor() {
  servo.write(90); 
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Dool UnLOCKED");
  display.display();
  delay(5000); // Wait for 5 seconds

  servo.write(0); // Rotating the servo back to locked position
  enteredPin = ""; // Resetting the entered PIN
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Dool LOCKED");
  display.display();
  delay(2000);
  display.clearDisplay();
}

