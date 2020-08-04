







void oledUpdate() {                                               // Function that checks the contents of the OLED screen buffer, against the
  // last data written. If the content is different, the display is written too

  for (int i = 0; i < 8; i++) {
    if (strcmp(screenBuffer[i], PscreenBuffer[i]) != 0) {   // Compare contents of old buffer and new buffer line by line
      strcpy(PscreenBuffer[i],  screenBuffer[i]);            // if a difference is found new buffer is copied into previous buffer
      screenUpdate = true;                                    // Flag to write to screen set to true
    }
  }

  for (int i = 0; i < 8; i++) {                                     // Sets text colours   // Could also add function to change fonts based on another int array

    if (lineColours[i] != PlineColours[i]) {
      screenUpdate = true;
      PlineColours[i] = lineColours[i];                            // checks if line colours have changed and sets screen to update if it has.
    }
    display.setTextColor(lineColours[i], !lineColours[i]);
    display.setCursor(0, (i * 8));
    display.print(screenBuffer[i]);
  }

  if (screenUpdate == true) {

    display.display();
    //   Serial.print("Oled Updated");
    screenUpdate = false;
  }
}







void setOLED() {                    // Writes Data & Text to Oled Screen Buffer

  // Heading

  // sprintf(screenBuffer[0] , "%-10s  RSSI: %i", loraHeading, lastRSSI);     // %s string of characters

  sprintf(screenBuffer[0] , "%-9s %.3f MHz", loraHeading, rxFrequency);

  sprintf(screenBuffer[1], "%-s %-6s %s 0%s", dataNames[0], dataArray[0], dataNames[1], dataArray[1]);

  // Checksum
  if (checksumValid) {
    sprintf(screenBuffer[2], "%-4i   Checksum Valid", rxPacketNumber);
  } else {
    sprintf(screenBuffer[2], "     INVALID CHECKSUM");
  }

  // Data
  sprintf(screenBuffer[3], "%-13s %6s", dataNames[2], dataArray[2]);     // Latitude

  sprintf(screenBuffer[3], "%-13s %6s", dataNames[2], dataArray[2]);     // Latitude
  sprintf(screenBuffer[4], "%-13s %6s", dataNames[3], dataArray[3]);     // Longitude
  sprintf(screenBuffer[5], "%-14s %6s", dataNames[4], dataArray[4]);      // Altitude

  sprintf(screenBuffer[6], "%-14s %6s", dataNames[5], dataArray[5]);       // Speed
  sprintf(screenBuffer[7], "%-14s %6s", dataNames[6], dataArray[6]);       // Heading
  // sprintf(screenBuffer[8], "%-s %s", dataNames[5], dataArray[5]);

}


void wipeOLED() {

  // sprintf(screenBuffer[0], "%22s", lineWipe);     // %s string of characters   // This line commented because we always want the header to print
  //  sprintf(screenBuffer[1], "%22s", lineWipe);                                     // Including the frequency
  sprintf(screenBuffer[2], "%22s", lineWipe);
  sprintf(screenBuffer[3], "%22s", lineWipe);
  sprintf(screenBuffer[4], "%22s", lineWipe);
  sprintf(screenBuffer[5], "%22s", lineWipe);
  sprintf(screenBuffer[6], "%22s", lineWipe);
  sprintf(screenBuffer[7], "%22s", lineWipe);

  display.clearDisplay();


}
