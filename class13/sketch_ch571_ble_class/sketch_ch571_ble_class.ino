
// Test with:
// https://deqingsun.github.io/Javascript-Signal-Processing/bleFunctions.html

// For CH571 chip, the default config enables CFG_DEBUG_EN, use following command to disable it for USB flashing
// wchisp config disable-debug

#include <SimpleUsbSerial.h>
#include <CH573BlePeripheral.h>

CH573BlePeripheral blePeripheral = CH573BlePeripheral();

// Create one or more services. In this case we create a simple service with UUID "1111"
BLEService simpleService = BLEService("1111");

// Create one or more characteristics
// Characteristic 1: read and write with UUID "1111"
BLECharCharacteristic simpleProfilechar1 = BLECharCharacteristic("1111", BLERead | BLEWrite);
BLEDescriptor descriptorChar1 = BLEDescriptor("2901", "char 1, RW");
// Characteristic 2: read only with UUID "2222"
BLECharCharacteristic simpleProfilechar2 = BLECharCharacteristic("2222", BLERead);
BLEDescriptor descriptorChar2 = BLEDescriptor("2901", "char 2, R");
// Characteristic 3: write only with UUID "3333"
BLECharCharacteristic simpleProfilechar3 = BLECharCharacteristic("3333", BLEWrite);
BLEDescriptor descriptorChar3 = BLEDescriptor("2901", "char 3, W");
// Characteristic 4: notify only with UUID "4444"
BLECharCharacteristic simpleProfilechar4 = BLECharCharacteristic("4444", BLENotify);
BLEDescriptor descriptorChar4 = BLEDescriptor("2901", "char 4, N");

#define CONVERT_TO_HEX(x) ((x) > 9 ? (x) + 'A' - 10 : (x) + '0')

void setup() {
  SerialUSB.begin();
  //LED on the left
  pinMode(PA14, OUTPUT);
  //LED on the right
  pinMode(PA15, OUTPUT);
  //IR LED in the reflective sensor
  pinMode(PA12, OUTPUT);
  digitalWrite(PA12, HIGH);
  //IR receiver input
  pinMode(PA13, INPUT_ANALOG);
  //Button
  pinMode(PB22, INPUT_PULLUP);

  uint8_t MacAddr[6];
  GetMACAddress(MacAddr);

  // setLocalName just copy pointer, so need to be static
  static char deviceName[11];
  strcpy(deviceName, "CH573_0000");
  // set the last 4 digits of the device name to the MAC address
  deviceName[6] = CONVERT_TO_HEX((MacAddr[1] >> 4) & 0x0F);
  deviceName[7] = CONVERT_TO_HEX(MacAddr[1] & 0x0F);
  deviceName[8] = CONVERT_TO_HEX((MacAddr[0] >> 4) & 0x0F);
  deviceName[9] = CONVERT_TO_HEX(MacAddr[0] & 0x0F);

  // set device name and advertised service UUID
  blePeripheral.setLocalName(deviceName);
  blePeripheral.setAdvertisedServiceUuid(simpleService.uuid());

  // add attributes (services, characteristics, descriptors) to peripheral
  // Add service (1111)
  blePeripheral.addAttribute(simpleService);
  // Add characteristic (1111) under service (1111)
  blePeripheral.addAttribute(simpleProfilechar1);
  // descriptor is optional
  //blePeripheral.addAttribute(descriptorChar1);
  // Add characteristic (2222) under service (1111)
  blePeripheral.addAttribute(simpleProfilechar2);
  // descriptor is optional
  //blePeripheral.addAttribute(descriptorChar2);
  // Add characteristic (3333) under service (1111)
  blePeripheral.addAttribute(simpleProfilechar3);
  // descriptor is optional
  //blePeripheral.addAttribute(descriptorChar3);
  // Add characteristic (4444) under service (1111)
  blePeripheral.addAttribute(simpleProfilechar4);
  // descriptor is optional
  //blePeripheral.addAttribute(descriptorChar4);

  // set initial value
  blePeripheral.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  blePeripheral.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);

  blePeripheral.begin();

  blePeripheral.startBle();
  // Do not put any code after startBle()
}

void loop() {
  unsigned long currentMillis = millis();
  static unsigned long previousAdcMillis = 0;
  const long interval = 100;  // interval at which to blink (milliseconds)

  if (currentMillis - previousAdcMillis >= interval) {
    previousAdcMillis = currentMillis;
    int analogValue = analogRead(PA13);
    // Scale down to 8 bits, send to characteristic 4, the notify characteristic
    simpleProfilechar4.setValue(analogValue >> 2);
    SerialUSB.print("Sensor value: ");
    SerialUSB.println(analogValue);
  }

  // Update button state, set to characteristic 2, the read only characteristic
  simpleProfilechar2.setValue(!digitalRead(PB22));  //button state

  // When characteristic 1, update left LED
  if (simpleProfilechar1.written()) {
    SerialUSB.println("char1 written");
    SerialUSB.println(((int)simpleProfilechar1.value()) & 0xFF, HEX);
    SerialUSB.flush();
    if (simpleProfilechar1.value() & 1) {
      digitalWrite(PA14, HIGH);
    } else {
      digitalWrite(PA14, LOW);
    }
  }
  // When characteristic 3, update right LED
  if (simpleProfilechar3.written()) {
    SerialUSB.println("char3 written");
    SerialUSB.println(((int)simpleProfilechar3.value()) & 0xFF, HEX);
    SerialUSB.flush();
    if (simpleProfilechar3.value() & 1) {
      digitalWrite(PA15, HIGH);
    } else {
      digitalWrite(PA15, LOW);
    }
  }

  SerialUSB.flush();
}

void blePeripheralConnectHandler(BLECentral& central) {
  // central connected event handler
  SerialUSB.print(F("Connected event, central: "));
  SerialUSB.println(central.address());
  SerialUSB.flush();
}

void blePeripheralDisconnectHandler(BLECentral& central) {
  // central disconnected event handler
  SerialUSB.print(F("Disconnected event, central: "));
  SerialUSB.println(central.address());
  SerialUSB.flush();
}
