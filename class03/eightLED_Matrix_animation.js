var displayArray=[0b0000,0b000];
var animationArray=[[0b0001,0b0000],[0b0110,0b0001],[0b1000,0b0110],[0b0000,0b1000],[0b0000,0b000]];

function enableLayer(index){
  if (index == 0){
    pinMode(NodeMCU.D2,'output');
    digitalWrite(NodeMCU.D2,false);
  }else if(index == 1){
    pinMode(NodeMCU.D3,'output');
    digitalWrite(NodeMCU.D3,false);    
  }else{
    disableLayers();
  }
}

function disableLayers(){
  pinMode(NodeMCU.D2,'input');
  pinMode(NodeMCU.D3,'input');
}

function setLedValue(value){
  digitalWrite([NodeMCU.D8,NodeMCU.D7,NodeMCU.D6,NodeMCU.D5],value);
}

function lightupBottomLED(){
  disableLayers();
  setLedValue(displayArray[0]);
  enableLayer(0);
  setTimeout(lightupTopLED,1);
}

function lightupTopLED(){
  disableLayers();
  setLedValue(displayArray[1]);
  enableLayer(1);
  setTimeout(lightupBottomLED,1);
}

var frameIndex = 0;
function switchFrame(){
  displayArray=animationArray[frameIndex];
  frameIndex++;
  if (frameIndex>=5) frameIndex=0;
}

//Prepare pins for anode LEDs
pinMode(NodeMCU.D5,'output');
pinMode(NodeMCU.D6,'output');
pinMode(NodeMCU.D7,'output');
pinMode(NodeMCU.D8,'output');

lightupBottomLED();
setInterval(switchFrame,100);

