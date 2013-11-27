/*
 *This program turns on and turns off a LED,
  writing the SOS message in Morse code.
  Each SOS is separated from the other
  by 30 seconds.
*/

static int ledPin=13;

void setup(){
  pinMode(ledPin, OUTPUT);        // set the digital pin as output
}

void ledSOS(){
  int i = 0;
  for (i=0; i<3; i++){            // letter S, made by 3 dots
    digitalWrite(ledPin, HIGH);   // turns on the LED
    delay(250);                   // wait
    digitalWrite(ledPin, LOW);    // turns off the LED
    delay(250);
  }
  delay(1500);
  i = 0;
  for (i=0; i<3; i++){            // letter O, made by 3 dashes
    digitalWrite(ledPin, HIGH); 
    delay(900); 
    digitalWrite(ledPin, LOW); 
    delay(250);
  }
  delay(1500);
  i = 0;
  for (i=0; i<3; i++){            // letter S, made by 3 dots
    digitalWrite(ledPin, HIGH); 
    delay(250); 
    digitalWrite(ledPin, LOW); 
    delay(250);
  }
}

void loop(){                      // loop the instructions
  ledSOS();
  delay(30000);                   // wait 30 seconds
}

