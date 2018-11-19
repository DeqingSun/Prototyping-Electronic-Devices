import processing.serial.*;

Serial myPort=null;  // Create object from Serial class
int val;      // Data received from the serial port

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
  } else {
    println("No port found");
  }
}

void draw()
{
  if (myPort!=null) {
    if ( myPort.available() > 0) {  // If data is available,
      val = myPort.read();         // read it and store it in val
    }
  }
  background(255);             // Set background to white
  ellipse(128,val,50,50);
}