  #include <Adafruit_NeoPixel.h>
  #ifdef __AVR__
  #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
  #endif

  // Which pin on the Arduino is connected to the NeoPixels?
  // On a Trinket or Gemma we suggest changing this to 1:
  #define LED_PIN    6

  // How many NeoPixels are attached to the Arduino?
  #define LED_COUNT 24

  Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

  uint32_t white = strip.Color(246, 231, 210);

  int sensor_pin = A0;
  int current_sensor_value;
  int previous_sensor_value;
  int brightness_value;

void setup() {

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  current_sensor_value = analogRead(sensor_pin);

  if (current_sensor_value - previous_sensor_value > 5 ) {
      brightness_value = current_sensor_value;
      //strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
      Serial.print("POS CHANGE");
      Serial.println(current_sensor_value);
      previous_sensor_value = current_sensor_value;
      delay(50);
  } else {
    if (previous_sensor_value - current_sensor_value > 5 ) {
      brightness_value = current_sensor_value;
      //strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
      Serial.print("NEG CHANGE");
      Serial.println(current_sensor_value);
      previous_sensor_value = current_sensor_value;
      delay(50);
    } else {
         Serial.println(current_sensor_value);
         delay(50);
  }
  }


  }

 
  //strip.fill(white);
 // strip.show();













