var ledIsOn=false;
pinMode(NodeMCU.D4,'output');

function switchLED(){
  if (ledIsOn){
    digitalWrite(NodeMCU.D4,false);
    ledIsOn=false;
  }else{
    digitalWrite(NodeMCU.D4,true);
    ledIsOn=true;
  } 
}

setInterval(switchLED, 500);


