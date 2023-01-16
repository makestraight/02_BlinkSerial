/*
  LED Blink controlled by Serial Communication
  p for pause
  r for resume

  based on Arduino Examples "Blink"

  Date: 16 Jan 2023
  Author: Yen-Chen Chang @ makestraight
*/

// indicator of blink
bool blink = true;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    char incomingByte = Serial.read();

    if('p' == incomingByte){
      blink = false;
    }
    else if('r' == incomingByte){
      blink = true;
    }

    // print the blink status on the serial monitor
    if(blink){
      Serial.println("Blink: On");
    }else{
      Serial.println("Blink: Off");
    }
  }

  if(blink){
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(1000);                      // wait for a second
  }
}
