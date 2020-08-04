/*
      NMEA Standards:


      Lets make this program function more akin to regonised standards for marine communications



*/





/*
     Serial Configuration: Data Link Layer:
     Typical Baud Rate:  4800
     Data Bits:          8
     Parity:             None
     Stop Bits:          1
     Handshake           None

     There is a variation of the standard called NMEA-0183HS that specifies a baud rate of 38,400. This is in general use by AIS (Automatic Identification System) devices.
     - Interesting as this could allow a vehicle to be tracked by other infrastructure




*/




/*


    ASCII      Hex      Dec    Use
    <CR>       0x0d     13     Carriage return
    <LF>       0x0a     10     Line feed, end delimiter
     !         0x21     33     Start of encapsulation sentence delimiter
     $         0x24     36     Start delimiter
               0x2a     42     Checksum delimiter
     ,         0x2c     44     Field delimiter
     \         0x5c     92     TAG block delimiter
     ^         0x5e     94     Code delimiter for HEX representation of ISO/IEC 8859-1 (ASCII) characters
     ~         0x7e     126    Reserved

  Messages have a maximum length of 82 characters, including the $ or ! starting character and the ending <LF>



  The start character for each message can be either a $ (For conventional field delimited messages) or ! (for messages that have special encapsulation in them)

  The next five characters identify the talker (two characters) and the type of message (three characters).

  All data fields that follow are comma-delimited.

  Where data is unavailable, the corresponding field remains blank (it contains no character before the next delimiter – see Sample file section below).
  The first character that immediately follows the last data field character is an asterisk, but it is only included if a checksum is supplied.
  The asterisk is immediately followed by a checksum represented as a two-digit hexadecimal number.

  The checksum is the bitwise exclusive OR of ASCII codes of all characters between the $ and *, not inclusive.

  According to the official specification, the checksum is optional for most data sentences, but is compulsory for RMA, RMB, and RMC (among others).

  <CR><LF> ends the message.


  As an example, a waypoint arrival alarm has the form:

    $GPAAM,A,A,0.10,N,WPTNME*32



*/


/*   // USEFUL NOTES & TAKEAWAY

      Using the concept of NMEA standards but with my own implementation for this particular sketch

      Sample Message:

           $SKY01,011,52.3456,-3.2342

          [$][CallSign],[PacketType],[GPS.latitude],[GPS.longitude],[GPS.altitude]
  Bytes     1     5           3             4(float)    4(float)


*/


/*


  C implementation of checksum generation
  The checksum at the end of each sentence is the XOR of all of the bytes in the sentence,
  excluding the initial dollar sign.
  The following C code generates a checksum for the string entered as "mystring"
  and prints it to the output stream. In the example, a sentence from the sample file is used.



  #include <stdio.h>

  int checksum(const char *s) {
  int c = 0;

  while (*s)
     c ^= *s++;

  return c;
  }

  int main()
  {
  char mystring[] = "BNALF,1,1,0,,B,W,V,,220003,,0,0,VISUAL ALARM";

  printf("String: %s\nChecksum: 0x%02X\n", mystring, checksum(mystring));

  return 0;
  }



*/
