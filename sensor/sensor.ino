/* moisture_sensor
 * 
 * This program checks the analog input (pin A0) coming from a moisture sensor
 * and switch on a LED placed on the digital pin 13 if the read data is below a
 * certain threshold. The default value of the threshold is 800, but it can be
 * changed in the source code if you really need to.
 *
 */

static int SENSOR_PIN = A0;           // sensor pin number
static int LED_PIN = 13;              // LED pin number
static int threshold = 800;           // threshold for activating the LED

static long SPEED=9600;               // speed of serial data's transmission
static long interval_30m=1800000;     // interval of 30 minutes in milliseconds
static long interval_300ms=300;         // interval of 2 seconds
static long interval_2s=2000;         // interval of 5 seconds


static char message[]="Feed me!";     // message to print on the monitor
/*static char message2[]="You can change the threshold. The current value is: ";*/

int reading;                          // analog sensor reading
int led_state;                        // current led state

void setup()
{
    pinMode(LED_PIN, OUTPUT);         // set the digital pin as output
    Serial.begin(SPEED);              // start sending and receiving serial data
}


void flash(){
   digitalWrite(LED_PIN, HIGH);       // turn on the LED
   delay(interval_300ms);              // wait one second
   digitalWrite(LED_PIN, LOW);        // turn off the LED
}

void loop()
{
  
  reading = analogRead(SENSOR_PIN);   // get the sensor reading 
  led_state = digitalRead(LED_PIN);   // get the current LED state
  
  if (reading<=threshold){
    flash();
    Serial.println(message);          // print the message to the monitor
    delay(interval_2s);               // wait for 5 seconds
  }
  else{
    digitalWrite(LED_PIN, LOW);       // turn off the LED
    delay(interval_30m);
  }
  
  /* TODO: allow the user changing the threshold value*/
  
}
