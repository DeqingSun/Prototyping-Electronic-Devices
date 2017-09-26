var wifi = require("Wifi");

var WIFI_NAME = "TP-LINK_78AA";
var WIFI_OPTIONS = { password : "15937735" };

function connectCallBack(err){
  if (err){
    console.log("err=", err);
  }else{
    console.log("connected, info=", wifi.getIP());
  }
}


console.log("Try to connect to wifi...");
wifi.connect(WIFI_NAME, WIFI_OPTIONS,connectCallBack);
wifi.stopAP();

