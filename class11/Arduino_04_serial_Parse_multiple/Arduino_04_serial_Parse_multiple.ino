String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }

  if (stringComplete) {
    inputString.trim();
    int firstCommaPosition = inputString.indexOf(',');
    int secondCommaPosition = inputString.indexOf(',', firstCommaPosition + 1); //start after 1st comma
    int var0 = inputString.substring(0, firstCommaPosition).toInt();
    int var1 = inputString.substring(firstCommaPosition+1, secondCommaPosition).toInt();
    int var2 = inputString.substring(secondCommaPosition+1).toInt();
    Serial.print("1st val: ");
    Serial.print(var0);
    Serial.print(", 2nd val: ");
    Serial.print(var1);
    Serial.print(", 3rd val: ");
    Serial.print(var2);
    Serial.print('\n');
    
    inputString = ""; //clear string for next receive
    stringComplete = false;
  }

}

