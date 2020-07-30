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
char checkSum[12];


char *dataArray[8] = {txCallSign, packetChar, GPSlatitude, GPSlongitude, GPSaltitude, GPSspeed, checkSum};


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

  atoi() // used to turn char into array

   // Example String to Extract: rxPacket

    SKY1,42,55.8990,-3.2543,183.4,0.5741
*/
//

int txCheckSum;
char checkSumChar;
char checkSumString[16];

int dataExtract() {

  int i = 0;                                                                            // variable used to count number of packets recieved

  if (receivedPacket) {

  //  byte checksum = CRC8(*rxPacket, sizeof(rxPacket));

    char * token;

    Serial.println(rxPacket);
    // delay(1000);

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




// Check Sum

  byte crc = 0x00;       
  
    for (int j = 0; j < (i - 1) ; j++) {

  byte sum = (crc ^ dataArray[j]) & 0x01; 

Serial.printf("Byte Sum: %i", sum)
Serial.println(" ");

checkSumString[j] =  char(sum);
      
for (int k = 0; k < sizeof(checkSumString[j]), k++){
 Serial.printf("checkSumString: %c", checkSumString[k]);
}

Serial.println(" ");

 // Serial.printf("CheckSum: %a", checksum[i]);    

    }

    /*
        // checksum
       int checksum = 0;                                                          // Reset checksum

        /*
            for (int j = 0; j < (i - 1) ; j++) {                           // for loop adds up received packets, i-1 as it need to ignore the final packet, the checksum

            //  txCheckSum = (txCheckSum + (uint32_t)dataArray[j]);
          checkSumChar = (checkSumChar + (char)dataArray[j]);

            }

    */
    /*
      for (int j = 0; j < (i - 1) ; j++) {
      Serial.println((int)dataArray[j]);
      //  Serial.println(char(dataArray[j]));

      checksum += (int)&dataArray[j];
      Serial.println(checksum);
      }

    */



    //   Serial.println(" ...");
    //    byte ls8b = lowByte(checksum);

 //   Serial.printf("CheckSum: %a", checksum);                           // At the moment just print the checksum and we can manually compare it to the printout from the next few lines
  //  Serial.println(" ");
    // Serial.printf("CheckSum ls8b: %i", ls8b);


    Serial.println(" ");
    Serial.println(" ");

    for (int j = 0; j < i; j++) {
      Serial.print(j);
      Serial.printf("|  %-15s %s", dataNames[j], dataArray[j]);
      Serial.println(" ");
    }

    Serial.println(" ");

  }
  receivedPacket = false;
  // return 0;

}
