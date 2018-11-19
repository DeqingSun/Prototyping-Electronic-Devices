import processing.serial.*;

Serial myPort=null;  // Create object from Serial class
int val0=0, val1=0, val2=0, val3=0, val4=0;      // Data received from the serial port

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
  frameRate(30);
}

void draw()
{
  if (myPort!=null) {
    if (frameCount%30==0) {  //send once a second
      String output=val0+","+val1+","+val2+"\n";
      myPort.write(output);
      println("Sent:");
      print(output);
      val0=(val0+16)%256; 
      val1=(val1+8)%256; 
      val2=(val2+4)%256; 
      val3=(val3+2)%256;
      val4=(val4+1)%256;
    }

    if ( myPort.available() > 0) {  // If data is available,
      String myString = myPort.readStringUntil('\n');
      if (myString != null) {
        myString=myString.trim();  //remove the newline in it's end
        println("Received:");
        println(myString);
      }
    }
  }
}