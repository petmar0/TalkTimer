/*
  A timer for your talks. This is designed for the LilyTiny and a Vibe Board.
  A button is attached to pin 0 and VCC, while the Vibe Board is attached to pin 1 and GND.
  CC2014 Pete Marchetto, petmar@gmail.com
  Standard beerware license applies.
*/

int buzz1=10;  //Time until first alert in minutes
int buzz2=14;  //Time until second alert in minutes
unsigned long t0=0;  //Timekeeping variable for button press time
unsigned long t1=0;  //Timekeeping variable for current time
unsigned long dt=0;  //Timekeeping variable for difference of t1-t0

void setup() {
  pinMode(0, INPUT);  //Set button pin to 0
  pinMode(1, OUTPUT);  //Set Vibe pin to 1
}

void loop() {
  if(digitalRead(0)==HIGH){  //If the button is pressed:
    t0=millis();  //set the time in t0 at which this happened,
    digitalWrite(1, HIGH);  //send pin 1 high
    delay(200);  //for 200 msec,
    digitalWrite(1, LOW);  //then low
    delay(200);  //for 200 msec,
    digitalWrite(1, HIGH);  //then high again,
    delay(500);  //this time for 500 msec,
    digitalWrite(1, LOW);  //then turn it off
  }
  t1=millis();  //Take the current time into t1
  dt=t1-t0;  //Get the difference of t1 and t0
  dt/=60000;  //Convert msec to minutes
  if(dt==buzz1){  //If the first alert time has elapsed:
    digitalWrite(1, HIGH);  //send pin 1 high
    delay(500);  //for 500 msec,
    digitalWrite(1, LOW);  //then turn it off
  }
  else if(dt==buzz2){  //If the second alert time has elapsed:
    digitalWrite(1, HIGH);  //send pin 1 high
    delay(500);  //for 500 msec,
    digitalWrite(1, LOW);  //then low
    delay(500);  //for 500 msec,
    digitalWrite(1, HIGH);  //then high again
    delay(500);  //for 500 msec,
    digitalWrite(1, LOW);  //then turn it off
  }
}
