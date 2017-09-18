function lightupBottomLED(){
  pinMode(NodeMCU.D2,'input');
  pinMode(NodeMCU.D3,'input');
  
  digitalWrite([NodeMCU.D8,NodeMCU.D7,NodeMCU.D6,NodeMCU.D5],0b0111);
  
  pinMode(NodeMCU.D2,'output');
  digitalWrite(NodeMCU.D2,false);
  
  setTimeout(lightupTopLED,1);
}

function lightupTopLED(){
  pinMode(NodeMCU.D2,'input');
  pinMode(NodeMCU.D3,'input');
  
  digitalWrite([NodeMCU.D8,NodeMCU.D7,NodeMCU.D6,NodeMCU.D5],0b0100);
  
  pinMode(NodeMCU.D3,'output');
  digitalWrite(NodeMCU.D3,false);
  
  setTimeout(lightupBottomLED,1);
}

//Prepare pins for anode LEDs
pinMode(NodeMCU.D5,'output');
pinMode(NodeMCU.D6,'output');
pinMode(NodeMCU.D7,'output');
pinMode(NodeMCU.D8,'output');

lightupBottomLED();

