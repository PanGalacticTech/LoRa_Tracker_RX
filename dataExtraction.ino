/*
    Functions here to parse data into useable variables



*/


// Variables

char rxCallSign[] = {"SKY1"};




char txCallSign[12];   //
char packetChar[8];
char GPSlatitude[16];
char GPSlongitude[16];
char GPSaltitude[12];
char GPSspeed[12];


char *dataArray[7] = {txCallSign, packetChar, GPSlatitude, GPSlongitude, GPSaltitude, GPSspeed};


char callsignName[] = {"Callsign: "};
char packetName[] = {"Packet ID: "};
char latitudeName[] = {"Latitude: "};
char longitudeName[] = {"Longitude: "};
char gpsAltitudeName[] = {"GPS Altitude:"};
char gpsSpeedName[] = {"Speed: "};

char *dataNames[] = {callsignName, packetName, latitudeName, longitudeName, gpsAltitudeName, gpsSpeedName};                //"Packet ID"


char callsignUnit[] = {" "};
char packetUnit[] = {" "};
char latitudeUnit[] = {" "};
char longitudeUnit[] = {" "};
char altitudeUnit[] = {"m"};
char speedUnit[] = {"m/s"};

char *dataUnits[] = {callsignUnit, packetUnit, latitudeUnit, longitudeUnit, altitudeUnit, speedUnit};



int packetID;                       // id number of transmitted packet.
int previousPacketID;                 // last received packet ID, can be used to compare for dropped packets.

char exampleString[] = {"SKY1,42,55.8990,-3.2543,183.4,0.5741"};


//
/*
   strtol()

  And if you really want to mess with floats strtof()

   Use strtok() to first break up the string at the comma delimiters.

   char * strtok ( char * str, const char * delimiters );


   // Example String to Extract: rxPacket

    SKY1,42,55.8990,-3.2543,183.4,0.5741
*/
//



int dataExtract() {

  if (receivedPacket) {

    char * token;

    Serial.println(rxPacket);
   // delay(1000);

    token = strtok(rxPacket, ",");
    int i = 0;

    while (token != NULL) {
      //   printf("%s\n", token);    // Just prints out data not needed
      dataArray[i] = token;
      token = strtok(NULL, ",");
      i++;
    }


    for (int j = 0; j < 6; j++) {
      Serial.printf("%-15s %s", dataNames[j], dataArray[j]);
      Serial.println(" ");
      Serial.println(" ");
    }

  }
  receivedPacket = false;
 // return 0;

}
