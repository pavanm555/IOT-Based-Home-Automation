# IOT-Based-Home-Automation

### Door Opener using Servo Motor 
#include <Servo.h>

Servo tap_servo;

int sensor_pin = 2;
int tap_servo_pin =9;
int val;

void setup(){
    pinMode(sensor_pin,INPUT);
    tap_servo.attach(tap_servo_pin);
}

void loop(){
    val = digitalRead(sensor_pin);
    if (val==0){
    tap_servo.write(0);
    }
    if (val==1){
    tap_servo.write(180);
    }
}

### Temp Sensor with Lcd Display (Air Conditioner)
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

### Smoke Detection
int buzzer = 5;
int ledgreen = 6;
int ledred = 7;

int sensorThreshold = 40;

void setup() 
{
  pinMode (ledred, OUTPUT);
  pinMode (ledgreen, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (A1, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  int sensorValue = analogRead(A1);
  Serial.print("SENSOR: ");
  Serial.println(sensorValue);
  
  if (sensorValue > sensorThreshold) 
  {
    digitalWrite (ledred, HIGH);
    digitalWrite (ledgreen, LOW);
    digitalWrite (buzzer, HIGH);
  }
  
  else
  {
    digitalWrite(ledred, LOW);
    digitalWrite (ledgreen, HIGH);
    digitalWrite (buzzer, LOW);
  }
  
  delay(100);
}

### Light Sensing
const int ledPin=13; //the code will flash the LED connected to pin 13
const int sensorPin= 0; //Sensor pin connects to analog pin A0

int level; //the variable that will hold the light level reading

const int threshold=500; //this represents the threshold voltage. If voltage is below 150, this triggers the LED to turn on

void setup() {
    pinMode (ledPin, OUTPUT); //sets digital pin 13 as output
    Serial.begin(9600); //sets the baud rate at 9600 so we can check the values the sensor is obtaining on the Serial Monitor
}

void loop(){
    level= analogRead(sensorPin); //the sensor takes readings from analog pin A0
    Serial.println(level);
    if (level < threshold){
        digitalWrite(ledPin, HIGH); //if the light level is below the threshold level, the LED turns on
    }
    else{ 
        digitalWrite(ledPin, LOW); //otherwise, if the light level is above the threshold level, the LED is off
    }
}
