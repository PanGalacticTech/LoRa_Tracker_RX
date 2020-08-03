



int minsSinceRX;


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


char loraHeading[23] = {"LoRa Rx"}; //
