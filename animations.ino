





//
int animationFrame = 0;

void waitingAnimation() {

  if (packetSinceOn < 1) {                                          // This section runs an animation on boot up while waiting for first packet
    // Do some Animation
    if (animationDelay.delayScript(500)) {
      animationFrame++;
      if (animationFrame >= 4) {
        animationFrame = 0;
        sprintf(screenBuffer[4], "%22s", lineWipe);
        wipeOLED();
      }

      if (animationFrame == 0) {
        sprintf(screenBuffer[4], "Waiting For Packet");
      } else if (animationFrame == 1) {
        sprintf(screenBuffer[4], "Waiting For Packet.");
      } else if (animationFrame == 2) {
        sprintf(screenBuffer[4], "Waiting For Packet..");
      }   else if (animationFrame == 3) {
        sprintf(screenBuffer[4], "Waiting For Packet...");
      }
    }

  }


  if (minsSinceRX > 0) {

    // if it has been longer than 1 minute since reading a packet

    if (animationDelay.delayScript(500)) {
      animationFrame++;

      if (animationFrame >= 4) {
        animationFrame = 0;
        wipeOLED();
        // sprintf(screenBuffer[4], "%22s", lineWipe);
      }

      sprintf(screenBuffer[3], "Minutes Since Rx %i", minsSinceRX);
      if (animationFrame == 0) {
        sprintf(screenBuffer[4], "Waiting For Packet");
      } else if (animationFrame == 1) {
        sprintf(screenBuffer[4], "Waiting For Packet.");
      } else if (animationFrame == 2) {
        sprintf(screenBuffer[4], "Waiting For Packet..");
      }   else if (animationFrame == 3) {
        sprintf(screenBuffer[4], "Waiting For Packet...");
      }
    }
  }
}
