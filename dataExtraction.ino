/*
    Functions here to parse data into useable variables



*/


// Variables

char callSign[] = {"SKY1"};




char rxCallSign[12];   //
char GPSlatitude[12];
char GPSlongitude[12];
char GPSaltitude[12];
char GPSspeed[12];
char packetChar[12];

char *dataArray[7] = {rxCallSign, packetChar, GPSlatitude, GPSlongitude, GPSaltitude, GPSspeed};



int packetID;                       // id number of transmitted packet.
int previousPacketID;                 // last received packet ID, can be used to compare for dropped packets.

char exampleString[] = {"SKY1,42,55.8990,-3.2543,183.4,0.5741"};


//
/*
   strtol()

  And if you really want to mess with floats strtof()

   Use strtok() to first break up the string at the comma delimiters.

   char * strtok ( char * str, const char * delimiters );


   // Example String to Extract: rxPacket

    SKY1,42,55.8990,-3.2543,183.4,0.5741
*/
//

int dataExtract() {

  char * pointer;

  Serial.println(exampleString);
  delay(1000);

  pointer = strtok(exampleString, ",");
  int i=0;
  while (pointer != NULL) {
        printf("%s\n", pointer);
    pointer = strtok(NULL, ",");
    i++;
  }
  return 0;

  delay(4000);
  for (int j=0;i < 6; j++){
  Serial.println(dataArray[j]);
  }
}
