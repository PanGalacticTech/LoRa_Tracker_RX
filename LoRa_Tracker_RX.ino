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

void setup() {

  Serial.begin(115200);                        //initialize Serial Monitor

  Serial.println("Setting up OLED");
  OLEDsetupSimple();

  rxHz = rxFrequency * MHz;




  while (!Serial);

  Serial.println("LoRa Receiver");

  delay(300);

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  delay(300);

  if (!LoRa.begin(rxHz)) {
    //while (!LoRa.begin(rxHz)){
    //   delay(1000);
    Serial.println("Starting LoRa failed!");
    delay(5000);
    Serial.print("...");
    delay(1000);
    Serial.println("Restarting");
    ESP.restart();
    // while (1);
  }

  Serial.printf("Rx Frequency: %i Hz", rxHz);
  Serial.println(" ");

  sprintf(screenBuffer[0] , "%s", loraHeading );     // %s string of characters
  oledUpdate();

}


int16_t lastRSSI;

char rxPacket[64];


uint16_t packetSinceOn = 0;  // counts number of received packets since switch on

uint16_t rxPacketNumber = 0;  // counts number of received packets with no packet losses

uint16_t txPacketNumber;     // variable to hold the parsed packet ID number from the transmitter.



void loop() {

  dataExtract();




  // setOLED();



  //  oledUpdate();

}



void wipePacket() {

  /*  // IF ABOVE STCOPY does not terminate correctly, use something like this
       if (characterInput == '\n')
     {
         theString[counter] = '\0';  // terminate input string


    OR

         size_t len = strlen(myString)
         memset (myString, 0,len);


  */

  int stringLength;

  stringLength = sizeof(rxPacket);

  // Serial.println(stringLength);

  for (int i = 0; i < stringLength; i++) {
    rxPacket[i] = '\n';
  }

}
