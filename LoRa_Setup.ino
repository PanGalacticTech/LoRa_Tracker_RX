/*
 * 
 * 
 * 
 * 
 */





 void loraSetup(){


  rxHz = rxFrequency * MHz;    // Translate frequency in MHz to Hz


  while (!Serial);

  Serial.println("SkyTracker LoRa Receiver");

  delay(300);

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  delay(300);

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

  Serial.printf("Rx Frequency: %i Hz", rxHz);
  Serial.println(" ");





  
 }
