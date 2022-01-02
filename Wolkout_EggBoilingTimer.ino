/*
 Project Name  : EGG BOILING TIMER
 Revision Date : 30.12.2021
 Author        : Abdullah Esad Ozcelik
 //--------------------------------------------------------------------------------------------------
 Purpose       : Providing a timer after the water to be boiled reaches 100 degree celcius to ensure 
                 the egg to be cooked becomes most favorable for the cook.
 //--------------------------------------------------------------------------------------------------                  
 */

#include <OneWire.h> // Adding OneWire library

// We set the digital pin we plugged temperature sensor as pin 2.
int DS18S20_Pin = 2; 
int i=0;
// Temperature Sensor Input-Output
OneWire ds(DS18S20_Pin);  // 2. Dijital pin.

void setup(void) {
  Serial.begin(9600); 
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop(void) {
  float temperature = getTemp();
  digitalWrite(8,HIGH);
  // We print the temperature value coming from temperature sensor on serial monitor.
 if(temperature>=60 && i<1){
  digitalWrite(5,HIGH);
  delay(3000);
  digitalWrite(5,LOW);
  delay(16000);
  delay(16000);
  delay(16000);
  delay(12000);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  delay(16000);
  delay(16000);
  delay(16000);
  delay(12000);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
 
  delay(16000);
  delay(16000);
  delay(16000);
  delay(12000);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(300);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(300);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(300);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(300);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  i++;
 }
  
  Serial.print("Sicaklik: ");
  Serial.println(temperature);
  // Waiting 1 second. It will continue to write 1 temperature value second each second.
  delay(1000);

}

// Function below is used to convert datas coming from
// DS18B20 temperature sensor to Celcius format.
// No adjustment required.

float getTemp(){
  //returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized");
      return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); // Read Scratchpad

  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;

}
