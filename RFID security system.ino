#include <Servo.h>

Servo doorServo;

void setup() {
  Serial.begin(9600);
  doorServo.attach(D4);
}

void loop() {
  int cardNumber = random(1, 5);
  int validCards[] = {2, 3};
  bool isValidCard = false;
  for (int i = 0; i < sizeof(validCards) / sizeof(validCards[0]); i++) {
    if (cardNumber == validCards[i]) {
      isValidCard = true;
      break;
    }
  }
  Serial.print("Scanned RFID Card: ");
  Serial.println(cardNumber);
  if (isValidCard) {
    Serial.println("Valid Card");
    Serial.println("Simulating servo movement: Opening door");
  } else {
    Serial.println("Invalid Card");
  }
  delay(2000); 
}
