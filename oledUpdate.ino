







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



  sprintf(screenBuffer[0] , "%-s  %s", loraHeading, txCallSign);     // %s string of characters

  sprintf(screenBuffer[1] , "Rx Frq: %.3f MHz", rxFrequency);
  sprintf(screenBuffer[2] , "RSSI: %i", lastRSSI);

  // sprintf(screenBuffer[3] , "%s", rxPacket);


  sprintf(screenBuffer[3], "%10-s %s", dataNames[0], dataArray[0]);
  sprintf(screenBuffer[4], "%10-s %s", dataNames[1], dataArray[1]);
  sprintf(screenBuffer[5], "%10-s %s", dataNames[2], dataArray[2]);
  sprintf(screenBuffer[6], "%10-s %s", dataNames[3], dataArray[3]);
  sprintf(screenBuffer[7], "%10-s %s", dataNames[4], dataArray[4]);
 // sprintf(screenBuffer[8], "%-s %s", dataNames[5], dataArray[5]);



}
