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

