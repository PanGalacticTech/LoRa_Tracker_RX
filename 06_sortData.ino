/*
 *   Fucnctions here to sort and use the data
 * 
 * 
 * 
 */


int lastPacketNumber =  0;

void comparePacketNumbers(){


int receivedPacketNumber = atoi(dataArray[1]); // This holds the number of the last received data packet

if (receivedPacketNumber == (lastPacketNumber+1)){
 rxPacketNumber++;       
} else {
  rxPacketNumber = 0;  
}
 Serial.printf(" | chain number: %i",  rxPacketNumber );
 Serial.println(" ");
lastPacketNumber = receivedPacketNumber;
}





unsigned long minuteMillis = 60000;


void timeSinceLast(){              // Prints a message to serial monitor once a minute if packet has not been received in a while

unsigned long currentTime = millis();

currentTime = currentTime - timeSinceRX;  // I dont like reusing variables like this but oh well

if (currentTime >= minuteMillis){    // if a minuite has passed without RX


minsSinceRX++;
 Serial.printf("%i Minutes Since Last Packet", minsSinceRX);
 Serial.println(" ");



timeSinceRX = millis();      // again reuseing variable so its name doesnt make sense but it does work and saves some memory

  
}


  
}
