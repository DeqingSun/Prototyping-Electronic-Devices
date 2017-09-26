var wifi = require("Wifi");
var http = require("http");

var WIFI_NAME = "TP-LINK_78AA";
var WIFI_OPTIONS = { password : "15937735" };

var counterObj = {"counter":0};

function connectCallBack(err){
  if (err){
    console.log("err=", err);
  }else{
    console.log("connected, info=", wifi.getIP());
    http.createServer(function (req, res) {
      res.writeHead(200,{
        "Access-Control-Allow-Origin": "*"});
      res.end(JSON.stringify(counterObj));
    }).listen(80);
  }
}

function buttonPressed(){
  counterObj.counter++;
  console.log(counterObj.counter);
}

console.log("Try to connect to wifi...");
wifi.connect(WIFI_NAME, WIFI_OPTIONS,connectCallBack);
wifi.stopAP();

pinMode(NodeMCU.D3,'input');
setWatch(buttonPressed, NodeMCU.D3, {repeat: true,edge:'falling',debounce:100 });


