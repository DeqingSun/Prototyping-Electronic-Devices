var neopixelController = require("neopixel");

//use array of 3 numbers can drive one LED, 6 numbers can drive 2 
var colorArray=[[15,0,0],[0,15,0],[0,0,15]];

var colorIndex = 0;

function switchColor(){
  neopixelController.write(NodeMCU.D1, colorArray[colorIndex]);
  colorIndex++;
  if (colorIndex>=3) colorIndex=0;
}

E.setClock(80);   //LED we use need low frequency
setInterval(switchColor,100);