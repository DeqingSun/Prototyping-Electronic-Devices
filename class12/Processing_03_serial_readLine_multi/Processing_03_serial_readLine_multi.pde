import processing.serial.*;

Serial myPort=null;  // Create object from Serial class
int val0, val1, val2;      // Data received from the serial port

void setup() 
{
  size(256, 256);
  String portList[] = Serial.list();
  String portName = null;
  for (int i=0; i<portList.length; i++) {
    if (portList[i].indexOf("Bluetooth")<0) {  //avoid bluetooth port on mac
      println(portList[i]);  
      portName=portList[i];  //get first port without "Bluetooth"
      break;
    }
  }
  if (portName!=null) {
    myPort = new Serial(this, portName, 9600);
    myPort.clear();
    // Throw out the first reading, in case we started reading 
    // in the middle of a string from the sender.
    myPort.readStringUntil('\n');
  } else {
    println("No port found");
  }
}

void draw()
{
  try {
    if (myPort!=null) {
      if ( myPort.available() > 0) {  // If data is available,
        String myString = myPort.readStringUntil('\n');
        if (myString != null) {
          myString=myString.trim();  //remove the newline in it's end
          int firstCommaPosition=myString.indexOf(',');
          int secondCommaPosition=myString.indexOf(',', firstCommaPosition+1);//start after 1st comma
          val0=int(myString.substring(0, firstCommaPosition));
          val1=int(myString.substring(firstCommaPosition+1, secondCommaPosition));
          val2=int(myString.substring(secondCommaPosition+1));
          //println(myString);
        }
      }
    }
  }
  catch(Exception e) {
    //ignore any error may happen
  }
  background(255);             // Set background to white
  ellipse(64, val0, 50, 50);
  ellipse(128, val1, 50, 50);
  ellipse(192, val2, 50, 50);
}
