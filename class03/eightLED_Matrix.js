function lightupBottomLED(){
  pinMode(NodeMCU.D2,'input');
  pinMode(NodeMCU.D3,'input');
  
  digitalWrite(NodeMCU.D5,true);
  digitalWrite(NodeMCU.D6,true);
  digitalWrite(NodeMCU.D7,true);
  digitalWrite(NodeMCU.D8,false);
  
  pinMode(NodeMCU.D2,'output');
  digitalWrite(NodeMCU.D2,false);
  
  setTimeout(lightupTopLED,1);
}

function lightupTopLED(){
  pinMode(NodeMCU.D2,'input');
  pinMode(NodeMCU.D3,'input');
  
  digitalWrite(NodeMCU.D5,false);
  digitalWrite(NodeMCU.D6,false);
  digitalWrite(NodeMCU.D7,true);
  digitalWrite(NodeMCU.D8,false);
  
  pinMode(NodeMCU.D3,'output');
  digitalWrite(NodeMCU.D3,false);
  
  setTimeout(lightupBottomLED,10);
}

//Prepare pins for anode LEDs
pinMode(NodeMCU.D5,'output');
pinMode(NodeMCU.D6,'output');
pinMode(NodeMCU.D7,'output');
pinMode(NodeMCU.D8,'output');

lightupBottomLED();

