
#include <OneWire.h>


OneWire  ds(A3);

byte addr[8];
String keyStatus = "";


void setup(void) {
  Serial.begin(9600);
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
}


void loop(void) {
  getKeyCode();
  if (keyStatus == "ok") {
    digitalWrite(A1, HIGH);
    unsigned char i;
    Serial.print("iButton Number");
    for ( i = 5; i > 0; i--) {
      Serial.print(":");
      Serial.print(addr[i], HEX);
    }
    Serial.println();
    digitalWrite(A1, LOW);
  }
  else if (keyStatus != "") {
    Serial.println(keyStatus);
  }

  delay(200);
}


void getKeyCode() {
  byte present = 0;
  byte data[12];
  keyStatus = "";

  if ( !ds.search(addr)) {
    ds.reset_search();
    return;
  }


  if ( OneWire::crc8( addr, 7) != addr[7]) {
    keyStatus = "CRC invalid";
    return;
  }

  if ( addr[0] != 0x01) {
    keyStatus = "not DS1990A";
    return;
  }
  keyStatus = "ok";
  ds.reset();
}
