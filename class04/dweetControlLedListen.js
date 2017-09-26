var wifi = require("Wifi");
var http = require("http");

var WIFI_NAME = "TP-LINK_78AA";
var WIFI_OPTIONS = { password : "15937735" };

function getDataFromDweet(){
  http.get("http://dweet.io/listen/for/dweets/from/prototypingclass2017LedTest", httpCallback);
}

function httpCallback(res){
  res.on('data', function(data) {
    if (data.indexOf('"on')>=0){
      digitalWrite(NodeMCU.D4,false);
    }
    if (data.indexOf('"off')>=0){
      digitalWrite(NodeMCU.D4,true);
    }
    console.log(data);
  });
  res.on('close', function(data) {

  });
}

function connectCallBack(err){
  if (err){
    console.log("err=", err);
  }else{
    console.log("connected, info=", wifi.getIP());
    getDataFromDweet();
  }
}

pinMode(NodeMCU.D4,'output');
console.log("Try to connect to wifi...");
wifi.connect(WIFI_NAME, WIFI_OPTIONS,connectCallBack);
wifi.stopAP();

