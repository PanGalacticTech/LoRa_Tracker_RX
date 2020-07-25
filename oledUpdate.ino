

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


char loraHeading[23] = {"LoRa Receiver"}; //







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

  sprintf(screenBuffer[i] , "%s", rxPacket);


  i++;
  if (i >= 8) {
    i = 3;
  }


}
