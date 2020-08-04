/*
    Functions here to parse data into useable variables



*/




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

bool checksumValid;


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




    // Convert chechsum to an int

    txCheckSum = atoi(checkSumChar);



    rxCheckSum = nmeaChecksum(rxPacket);                                  // run the rest of the rxPacket through NMEA checksum function to generate the checksum

    if (verboseSerial) {
      Serial.println(" ");
      Serial.print("rxPacket: ");
    }

    Serial.print(rxPacket);                                        // This prints out the entire recieved string


    if (verboseSerial) {
      Serial.println(" ");
      Serial.printf("Tx CheckSum: %i  ", txCheckSum);
      Serial.printf("  Rx CheckSum: %i", rxCheckSum);
      Serial.println(" ");
    }

    if (txCheckSum == rxCheckSum) {                  // If the checksums are equal
      checksumValid = true;
      Serial.println(",1");                                   // prints an extra data byte - 1 for valid checksum
      if (verboseSerial) {
        Serial.println("Checksum Valid!");
        Serial.println(" ");
      }

    } else {
      checksumValid = false;
      Serial.println(",0");                                        //prints an extra databyte - 0 for invalid checksum
      if (verboseSerial) {
        Serial.println("CHECKSUM INVALID");
        Serial.println(" ");
      }

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

    if (verboseSerial) {
      Serial.printf("Received %i Data Points.", i);
      Serial.println(" ");



      for (int j = 0; j < i; j++) {
        Serial.print(j);
        Serial.printf("|  %-15s %s %s", dataNames[j], dataArray[j], dataUnits[j] );
        Serial.println(" ");
      }
    }

    comparePacketNumbers();                                             // Checks for sequential TX packet numbers

    if (verboseSerial) {
      Serial.println("----------------------------------------------- ");     // End of RecievedPacket
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
    }
  }
  receivedPacket = false;
  // return 0;

}
