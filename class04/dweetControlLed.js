var wifi = require("Wifi");
var http = require("http");

var WIFI_NAME = "TP-LINK_78AA";
var WIFI_OPTIONS = { password : "15937735" };

function getDataFromDweet(){
  http.get("http://dweet.io/get/latest/dweet/for/prototypingclass2017LedTest", httpCallback);
}

function httpCallback(res){
  var allData = "";
  res.on('data', function(data) {
    allData=allData+data;
  });
  res.on('close', function(data) {
    var dataParsed = JSON.parse(allData);
    try {
      if (dataParsed.with[0].content.led=='on'){
        digitalWrite(NodeMCU.D4,false);  
      }else{
        digitalWrite(NodeMCU.D4,true);
      }
    }catch(err) {
      //do nothing if server failed.
    }
  });
}

function connectCallBack(err){
  if (err){
    console.log("err=", err);
  }else{
    console.log("connected, info=", wifi.getIP());
    setInterval(getDataFromDweet,1500);
  }
}

pinMode(NodeMCU.D4,'output');
console.log("Try to connect to wifi...");
wifi.connect(WIFI_NAME, WIFI_OPTIONS,connectCallBack);
wifi.stopAP();

