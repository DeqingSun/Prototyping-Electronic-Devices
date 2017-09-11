//Turn off onboard LED
digitalWrite(NodeMCU.D4,true);

var displayLayer = 0;

function displayFunction() {
  if (displayLayer == 0){
    //disable all layers
    digitalWrite([NodeMCU.D2,NodeMCU.D3],0b11);
    //set LED within layer
    digitalWrite([NodeMCU.D5,NodeMCU.D6,NodeMCU.D7,NodeMCU.D8],0b1110);
    //show bottom layer
    digitalWrite(NodeMCU.D2,false);
  }else if (displayLayer==1){
    //disable all layers
    digitalWrite([NodeMCU.D2,NodeMCU.D3],0b11);
    //set LED within layer
    digitalWrite([NodeMCU.D5,NodeMCU.D6,NodeMCU.D7,NodeMCU.D8],0b1001);
    //show top layer
    digitalWrite(NodeMCU.D3,false);
  }
  displayLayer++;
  if (displayLayer>=2) displayLayer=0;
}

setInterval(displayFunction,10);
 