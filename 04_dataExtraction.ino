/*
    Functions here to parse data into useable variables



*/


// Variables

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


char callsignName[] = {"Callsign: "};
char packetName[] = {"Packet ID: "};
char latitudeName[] = {"Latitude: "};
char longitudeName[] = {"Longitude: "};
char gpsAltitudeName[] = {"GPS Altitude:"};
char gpsSpeedName[] = {"Speed: "};
char gpsHeadingName[] = {"Heading: "};
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


//
/*
   strtol()

  And if you really want to mess with floats strtof()

   Use strtok() to first break up the string at the comma delimiters.

   char * strtok ( char * str, const char * delimiters );

  atoi() // used to turn char into array

   // Example String to Extract: rxPacket

    SKY1,42,55.8990,-3.2543,183.4,0.5741
*/
//

int txCheckSum;
int rxCheckSum;

char *checkSumChar;



// Function to extract useable data from the recieved string


int dataExtract() {

  int i = 0;                                                                            // variable used to count number of packets recieved

  if (receivedPacket) {

    //  Serial.println(rxPacket);


    char * checkSumToken;

    // Seperate the string at the * and extract the checksum value as a char

    checkSumToken = strtok(rxPacket, "*");                                                  // Unpick the checksum data

    while (checkSumToken != NULL) {

      checkSumChar = checkSumToken;

      checkSumToken = strtok(NULL, "*");

    }

    Serial.println(" ");
    Serial.print("rxPacket: ");
    Serial.println(rxPacket);
  //  Serial.println(" ");

 //   Serial.print("txCheckSum (char): ");
 //   Serial.println(checkSumChar);
    Serial.println(" ");



    // Convert chechsum to an int

    txCheckSum = atoi(checkSumChar);

    Serial.printf("Tx CheckSum: %i  ", txCheckSum);

    rxCheckSum = nmeaChecksum(rxPacket);                                  // run the rest of the rxPacket through NMEA checksum function to generate the checksum

    Serial.printf("  Rx CheckSum: %i", rxCheckSum);

    Serial.println(" ");

    if (txCheckSum == rxCheckSum) {                  // If the checksums are equal

      Serial.println(" ");
      Serial.println("Checksum Valid!");

      Serial.println(" ");
    }




    char * token;

    token = strtok(rxPacket, ",");




    while (token != NULL) {
      //   printf("%s\n", token);    // Just prints out data not needed
      dataArray[i] = token;

      //token = strtok(NULL, ",");
      token = strtok(NULL, ",");
      i++;
    }

    Serial.printf("Received %i Data Points.", i);
    Serial.println(" ");



    for (int j = 0; j < i; j++) {
      Serial.print(j);
      Serial.printf("|  %-15s %s %s", dataNames[j], dataArray[j], dataUnits[j] );
      Serial.println(" ");
    }


    comparePacketNumbers();

    Serial.println("----------------------------------------------- ");     // End of RecievedPacket
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");

  }
  receivedPacket = false;
  // return 0;

}
