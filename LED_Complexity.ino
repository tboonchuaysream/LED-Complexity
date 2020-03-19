/*
author @Tommy Boonchuaysream
This program allows a user to switch on the light by pressing the switch.
However, if it is already bright, the light will not turn on. It is done to conserve energy.
*/

int ledExternal = 12;
int ledInternal = 13;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the LED pin as outputs.
  pinMode(ledExternal, OUTPUT);
  pinMode(ledInternal, OUTPUT);
  // initialize the input pin as input
  pinMode(A0, INPUT);

}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  //print out light sensor value
  Serial.println(sensorValue);
  delay(1);        

  //check if the light value is below 1000
  //if it is, that means that it is dark
  if(sensorValue <= 1000){
    digitalWrite(ledExternal, HIGH);   
    digitalWrite(ledInternal, LOW);    
  } else {
      digitalWrite(ledExternal, LOW);    
      digitalWrite(ledInternal, HIGH);   
  }
}
