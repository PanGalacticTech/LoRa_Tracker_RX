

bool verboseSerial = true;    // enables Verbose serial output for debugging. Else just prints data.

int minsSinceRX;





int16_t lastRSSI;

char rxPacket[65];                  /// string to hold received packets


uint16_t packetSinceOn = 0;  // counts number of received packets since switch on

uint16_t rxPacketNumber = 0;  // counts number of received packets with no packet losses

uint16_t txPacketNumber;     // variable to hold the parsed packet ID number from the transmitter.

bool receivedPacket = false;


// Data Variables



char rxCallSign[] = {"SKY1"};




char txCallSign[5];   //0
char packetChar[4];    //1
char GPSlatitude[16];   //2
char GPSlongitude[16]; //3
char GPSaltitude[12];   //4
char GPSspeed[12];      //5
char GPSheading[12];    //6
char checkSum[16];        //7


char *dataArray[] = {txCallSign, packetChar, GPSlatitude, GPSlongitude, GPSaltitude, GPSspeed, GPSheading, checkSum};


char callsignName[] = {"Call:"};
char packetName[] = {"ID:"};
char latitudeName[] = {"Lat: "};
char longitudeName[] = {"Long: "};
char gpsAltitudeName[] = {"Alt:"};
char gpsSpeedName[] = {"Speed: "};
char gpsHeadingName[] = {"Head: "};
char checksumName[] = {"CheckSum: "};

char *dataNames[] = {callsignName, packetName, latitudeName, longitudeName, gpsAltitudeName, gpsSpeedName, gpsHeadingName, checksumName};                //"Packet ID"


char callsignUnit[] = {" "};
char packetUnit[] = {" "};
char latitudeUnit[] = {" "};
char longitudeUnit[] = {" "};
char altitudeUnit[] = {"m"};
char speedUnit[] = {"m/s"};
char degreesUnit[] = {"Degrees"};
char checksumUnit[] = {" "};

char *dataUnits[] = {callsignUnit, packetUnit, latitudeUnit, longitudeUnit, altitudeUnit, speedUnit, degreesUnit };



int packetID;                       // id number of transmitted packet.
int previousPacketID;                 // last received packet ID, can be used to compare for dropped packets.

char exampleString[] = {"SKY1,42,55.8990,-3.2543,183.4,0.5741"};


// OLED Variables & Screen Buffers


bool screenUpdate = false;

uint8_t lineColours[8] = {1, 1, 1, 1, 1, 1, 1, 1};   // used to control line highlighting effect. 1 = Black Background, 0 = White Background Passed to oledUpdate

uint8_t PlineColours[8];   // Previous line colour

//############################## Empty Screen Buffers #########################################################
char oledLine0[23] = {"                     "}; //
char oledLine1[23] = {"                     "}; //
char oledLine2[23] = {"                     "}; //
char oledLine3[23] = {"                     "}; //
char oledLine4[23] = {"                     "}; //
char oledLine5[23] = {"                     "}; //
char oledLine6[23] = {"                     "}; //
char oledLine7[23] = {"                     "}; //

char *screenBuffer[9] = {oledLine0, oledLine1, oledLine2 , oledLine3, oledLine4, oledLine5, oledLine6, oledLine7};



// Previous Screen Buffers;
char PoledLine0[23];
char PoledLine1[23];
char PoledLine2[23];
char PoledLine3[23];
char PoledLine4[23];
char PoledLine5[23];
char PoledLine6[23];
char PoledLine7[23];

char *PscreenBuffer[9] = {PoledLine0, PoledLine1, PoledLine2 , PoledLine3, PoledLine4, PoledLine5, PoledLine6, PoledLine7};

//############################## Empty Screen Buffers #########################################################



// Text Strings


char lineWipe[23] = {"                     "};  // used to wipe old messages line by line


char loraHeading[23] = {"LoRa Rx"}; //
