/*




*/





void loraSetup() {

  // delay(400);
  rxHz = rxFrequency * MHz;    // Translate frequency in MHz to Hz
  delay(400);

  while (!Serial);

  Serial.println("SkyTracker LoRa Receiver");

  delay(300);

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  delay(300);


  /*
    if (!LoRa.begin(rxHz)) {
      //while (!LoRa.begin(rxHz)){
      //   delay(1000);
      Serial.println("Starting LoRa failed!");
      delay(5000);
      Serial.print("...");
      delay(1000);
      Serial.println("Restarting");
      ESP.restart();
      // while (1);
    }

  */

  int resetTrigger = 0;

  while (!LoRa.begin(rxHz)) {

    Serial.println("Attempting to find LoRa Module... ");

    delay(1000);

    resetTrigger++;

    if (resetTrigger >= 20) {
      Serial.println("Restarting");
      delay(1000);
      ESP.restart();
    }



  }

  Serial.println("LoRa Module Detected");
  Serial.printf("Rx Frequency: %i Hz", rxHz);
  Serial.println(" ");






}
