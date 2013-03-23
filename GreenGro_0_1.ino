
#include "U8glib.h"
U8GLIB_ST7920_128X64 u8g(2, 11,7 , U8G_PIN_NONE);     // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17

#include <SPI.h>
#include <Ethernet.h>
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,222,181);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(8181);

#include <SD.h>

#include <Wire.h>
#include <ArduinoNunchuk.h>

#include "DHT.h"
#define DHTPIN 5     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 8
#define TEMPERATURE_PRECISION 9

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// arrays to hold device addresses
DeviceAddress ThermometerA, ThermometerB;


void draw(void) {
  digitalWrite(13, HIGH); 
  // graphic commands to redraw the complete screen should be placed here  
  //u8g.setFont(u8g_font_unifont);
   u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 4, 40, "GreenGro");
   u8g.setPrintPos(100, 60);
   u8g.setFont(u8g_font_unifont);
  int a1=analogRead(1);
  u8g.print(a1/10);
  
  u8g.drawBox(5,62,a1,2);
}

void setup(void) {
  
  
    u8g.setColorIndex(1);         // pixel on
    int a1= 0; //test
     pinMode(13, OUTPUT);  
  
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    
    draw();
  } while( u8g.nextPage() );
         
  
  // rebuild the picture after some delay
  delay(150);
  digitalWrite(13, LOW);
}
