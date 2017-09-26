var wifi = require("Wifi");
var http = require("http");

var WIFI_NAME = "TP-LINK_78AA";
var WIFI_OPTIONS = { password : "15937735" };

function httpCallback(res){
  res.on('data', function(data) {
    console.log("HTTP> "+data);
  });
  res.on('close', function(data) {
    console.log("Connection closed");
  });
}

function connectCallBack(err){
  if (err){
    console.log("err=", err);
  }else{
    console.log("connected, info=", wifi.getIP());
    http.get("http://pur3.co.uk/hello.txt", httpCallback);
  }
}


console.log("Try to connect to wifi...");
wifi.connect(WIFI_NAME, WIFI_OPTIONS,connectCallBack);
wifi.stopAP();

