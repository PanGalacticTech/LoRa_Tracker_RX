/*
    Learning About Checksum Functions

  Implementing NMEA Checksum
  
*/





int checksum(const char *s) {
    int c = 0;

    while (*s)
        c ^= *s++;

    return c;
}


/*
int main()
{
    char mystring[] = "BNALF,1,1,0,,B,W,V,,220003,,0,0,VISUAL ALARM";

    printf("String: %s\nChecksum: 0x%02X\n", mystring, checksum(mystring));

    return 0;
}
    


*/














// Implementing a CRC8 Checksum (?)

//CRC8 - generates a checksum with a size of 8 bits (1byte)


//byte  CRC8(const byte *dataIn, byte dataLength) {                  // passed data string & data length

byte  CRC8(byte *dataIn, byte dataLength) {                  // passed data string & data length
  

  byte crc = 0x00;                                                    // initialise crc variable at zero

  while (dataLength--) {                                               // while datalength > 0 > decrem    // Does this mean (while dataLength -1) is > 0?  if so why not just write that?
    byte extract = *dataIn++;
    for (byte i = 8; i; i--) {

      byte sum = (crc ^ extract) & 0x01;                                                             //  CRC ( ^ bitwise XOR ) [dataByte] (& bitwise and) 0x01

      crc >>= 1;                                                                                          // crc bitshift right = 1 (I dont get it but okay)

      if (sum) {
        crc ^= 0x8C     ;                                                             // crc (^= compound bitwise xor) 0x8C
      }
      extract >>= 1;                                                            //    extract (bitshift right = 1) (still dont get it
    }
  }
  return crc;                                                                     // return crc   (guessing this returns a single byte crc check
}
