







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





int i = 3;     // variable for line number to print to. Starts at 3, ends at 8


void setOLED() {                    // Writes Data & Text to Oled Screen Buffer



  sprintf(screenBuffer[0] , "%s", loraHeading );     // %s string of characters

  sprintf(screenBuffer[1] , "Rx Frq: %.3f MHz", rxFrequency);
  sprintf(screenBuffer[2] , "RSSI: %i", lastRSSI);

  sprintf(screenBuffer[i] , "%s", rxPacket);   // This just prints the entire RX packet. We need to add a function to extract the data from this packet.


  i++;
  if (i >= 8) {
    i = 3;
  }


}
