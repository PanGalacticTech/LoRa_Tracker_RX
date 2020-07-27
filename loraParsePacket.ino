

void loraParsePacket() {

  // try to parse packet
  int packetSize = LoRa.parsePacket();

  if (packetSize) {                                     // if packet size > 0, then a packet has been recived

    packetSinceOn++;

    Serial.printf("%i Received packet | ", packetSinceOn);

    char rxBuffer[64];
    int j = 0;                                                  // variable to advancing char array

    while (LoRa.available()) {
      // Serial.print((char)LoRa.read());                   // Simple old method

      rxBuffer[j] = (char(LoRa.read()));                    // better new method saves recieved packet as a char string
      Serial.print(rxBuffer[j]);
      j++;                                                    // Advance array pointer
    }

    rxBuffer[j] = '\n';   // Terminate the rxBuffer string


    lastRSSI = LoRa.packetRssi();                              // Save the RSSI of last recieved packet

    rxPacketNumber++;
    // print RSSI of packet
    Serial.printf(" | with RSSI: %i   chain number: %i", lastRSSI, rxPacketNumber );
    Serial.println(" ");

    wipePacket();

    strcpy(rxPacket,  rxBuffer);    // copy the rxBuffer into the packet array


    // Function here updated the values printed to the OLED. going to be done elsewhere now.

  }

}
