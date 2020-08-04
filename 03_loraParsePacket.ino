

void loraParsePacket() {




  // try to parse packet
  int packetSize = LoRa.parsePacket();





  if (packetSize) {                                     // if packet size > 0, then a packet has been recived

    packetSinceOn++;                                             // increments variable for total received packets since switch on


    if (verboseSerial) {
      Serial.printf("%i Received packet | ", packetSinceOn);
    }

    rxLED.callBlink();

    receivedPacket = true;

    timeSinceRX = millis();          // Used for timing the program
    minsSinceRX = 0;                // Used for UI Purposes

    char rxBuffer[64];
    int j = 0;                                                  // variable to advancing char array





    while (LoRa.available()) {
      //   Serial.print((char)LoRa.read());                   // Simple old method
      rxBuffer[j] = (char(LoRa.read()));                    // better new method saves recieved packet as a char string
      if (verboseSerial) {
        Serial.print(rxBuffer[j]);                                // Prints out the received string
      }
      j++;                                                    // Advance array pointer
    }

    //   rxBuffer[j] = '\n';   // Terminate the rxBuffer string


    lastRSSI = LoRa.packetRssi();                              // Save the RSSI of last recieved packet


    if (verboseSerial) {
      Serial.printf(" | with RSSI: %i", lastRSSI);
      Serial.println(" ");
    }

    wipePacket();

    strcpy(rxPacket,  rxBuffer);    // copy the rxBuffer into the packet array

    //    Serial.println(rxPacket);   // Uncomment for debugging. Prints rxPacket including checksum



  }

}




// Function to "clean" data packet ready for next message

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
