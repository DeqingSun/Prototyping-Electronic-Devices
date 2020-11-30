//board support from:
//https://github.com/sandeepmistry/arduino-nRF5
#include <SPI.h>
//Library from:
//https://github.com/sandeepmistry/arduino-BLEPeripheral
#include <BLEPeripheral.h>

BLEPeripheral blePeripheral  = BLEPeripheral();

BLEService basicService = BLEService("1111");

BLECharCharacteristic simpleReadCharacteristic = BLECharCharacteristic("2222", BLERead);
BLECharCharacteristic simpleWriteCharacteristic = BLECharCharacteristic("3333", BLEWrite);
BLECharCharacteristic simpleNotifyCharacteristic = BLECharCharacteristic("4444", BLENotify);

const int COL1 = 3;     // Column #1 control
const int LED = 26;     // 'row 1' led

void setup() {
  blePeripheral.setLocalName("MicroBit Test");
  blePeripheral.setAdvertisedServiceUuid(basicService.uuid());

  // add service and characteristic
  blePeripheral.addAttribute(basicService);
  blePeripheral.addAttribute(simpleReadCharacteristic);
  blePeripheral.addAttribute(simpleWriteCharacteristic);
  blePeripheral.addAttribute(simpleNotifyCharacteristic);
  
  // begin initialization
  blePeripheral.begin();

  Serial.begin(9600);

  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW);

  pinMode(LED, OUTPUT);
}

void loop() {
  blePeripheral.poll();

  simpleReadCharacteristic.setValue(analogRead(0) >> 2);

  if (simpleWriteCharacteristic.written()) {
    unsigned char writtenValue = simpleWriteCharacteristic.value();
    Serial.println(writtenValue);
    if (writtenValue & 1) {  //test last bit
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }
  }

  simpleNotifyCharacteristic.setValue(analogRead(0) >> 2);

}
