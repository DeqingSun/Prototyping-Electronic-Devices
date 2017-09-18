function lightupBottomLED(){
  pinMode(NodeMCU.D2,'input');
  pinMode(NodeMCU.D3,'input');
  
  digitalWrite(NodeMCU.D5,true);
  digitalWrite(NodeMCU.D6,true);
  
  pinMode(NodeMCU.D2,'output');
  digitalWrite(NodeMCU.D2,false);
  
  setTimeout(lightupTopLED,1000);
}

function lightupTopLED(){
  pinMode(NodeMCU.D2,'input');
  pinMode(NodeMCU.D3,'input');
  
  digitalWrite(NodeMCU.D5,true);
  digitalWrite(NodeMCU.D6,false);
  
  pinMode(NodeMCU.D3,'output');
  digitalWrite(NodeMCU.D3,false);
  
  setTimeout(lightupBottomLED,1000);
}

//Prepare pins for front LEDs
pinMode(NodeMCU.D5,'output');
pinMode(NodeMCU.D6,'output');
//Disable pins for back LEDs for this experiment
pinMode(NodeMCU.D7,'input');
pinMode(NodeMCU.D8,'input');

lightupBottomLED();

