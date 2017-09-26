var wifi = require("Wifi");
var http = require("http");

var WIFI_NAME = "TP-LINK_78AA";
var WIFI_OPTIONS = { password : "15937735" };

var counter = 0;

function connectCallBack(err){
  if (err){
    console.log("err=", err);
  }else{
    console.log("connected, info=", wifi.getIP());
  }
}

function httpCallback(res){
  res.on('data', function(data) {
    console.log("resp >",data);
  });
  res.on('close', function(data) {
    console.log("connection closed");
  });
}

function buttonPressed(){
  counter++;
  http.get("http://dweet.io/dweet/for/prototypingclass2017BtnTest?counter="+counter,httpCallback);
  console.log(counter);
}

console.log("Try to connect to wifi...");
wifi.connect(WIFI_NAME, WIFI_OPTIONS,connectCallBack);
wifi.stopAP();

pinMode(NodeMCU.D3,'input');
setWatch(buttonPressed, NodeMCU.D3, {repeat: true,edge:'falling',debounce:100 });

