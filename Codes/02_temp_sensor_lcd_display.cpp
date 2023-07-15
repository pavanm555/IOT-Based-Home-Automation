#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int tempin = A0; // the output pin of TMP36
int cel;
int led = 6;
int tempmin = 30;
int relay = 7;
void setup() {
  pinMode(tempin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  cel = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); 
  Serial.print(cel);
  Serial.println();
  if (tempmin < cel) {
    lcd.setCursor(0, 1);// move cursor to next line
    lcd.print("Relay Status:");
    lcd.print("ON"); // display the temperature
    digitalWrite(relay, LOW);
    digitalWrite(led, HIGH);
  }
  else {
    lcd.setCursor(0, 1);// move cursor to next line
    lcd.print("Relay Status:");
    lcd.print("OFF"); // display the temperature
    digitalWrite(relay, HIGH);
    digitalWrite(led, LOW);
  }
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.print(cel); // display the temperature
  lcd.print("C ");
  delay(3000);
  lcd.clear();

}

