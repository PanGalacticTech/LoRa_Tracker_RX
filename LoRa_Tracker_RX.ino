/*********
  Modified from the examples of the Arduino LoRa library
  More resources: https://randomnerdtutorials.com
*********/




/*

  Here’s the connections between the RFM95 LoRa transceiver module and the ESP32:


  ANA:          Antenna
  GND:          GND
  DIO3:         don’t connect
  DIO4:         don’t connect
  3.3V:         3.3V
  DIO0:         GPIO 2
  DIO1:         don’t connect
  DIO2:         don’t connect
  GND:          don’t connect
  DIO5:         don’t connect
  RESET:        GPIO 14
  NSS:          GPIO 5
  SCK:          GPIO 18
  MOSI:         GPIO 23
  MISO:         GPIO 19
  GND:          don’t connect






*/

#include <SPI.h>
#include <LoRa.h>



//define the pins used by the transceiver module
#define ss 5
#define rst 14
#define dio0 2


#include "globals.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ledObject.h>
#include <autoDelay.h>



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//#define OLED_ADDR   0x3C
//Adafruit_SSD1306 display(-1);

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Oled Pins


float rxFrequency = 434.500;     // Rx Frequency in MHz   (*E6)

long rxHz;                          // Rx Frequency in Hz

long MHz = 1000000;                    // conversion from Hz to MHz

unsigned long timeSinceRX;          // save the last time packet was received then once every minuite print time since last RX


////////////////////////////////////////////////////////////////////////////////////////////////
//ledObject Constructor

#define ledPin 26                         // Define LED pin. If undefined - defaults to pin 13.
#define initialState 0                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF

ledObject rxLED;                            // led object is going to be used to denote a transmitted message

autoDelay animationDelay;










void setup() {

  Serial.begin(115200);                        //initialize Serial Monitor

  rxLED.begin(ledPin, initialState);    // Begin ledObject library by passing the pin of an LED & the initialState
  Serial.println("Setting up OLED");

  OLEDsetupSimple();

  loraSetup();


  sprintf(screenBuffer[0] , "%s", loraHeading );     // Print the heading to the screen

  oledUpdate();                                   // Update OLED from buffers

}







int16_t lastRSSI;

char rxPacket[65];                  /// string to hold received packets


uint16_t packetSinceOn = 0;  // counts number of received packets since switch on

uint16_t rxPacketNumber = 0;  // counts number of received packets with no packet losses

uint16_t txPacketNumber;     // variable to hold the parsed packet ID number from the transmitter.

bool receivedPacket = false;



void loop() {

  loraParsePacket();

  if (receivedPacket) {
    dataExtract();
    setOLED();

  }
  timeSinceLast();                     // Debugging feature, prints to serial monitor if no packet RX within 1 minuite
  oledUpdate();
  rxLED.performBlink();
}
