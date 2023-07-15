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
