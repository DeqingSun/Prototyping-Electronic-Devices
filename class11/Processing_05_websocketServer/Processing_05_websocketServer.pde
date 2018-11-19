//https://github.com/alexandrainst/processing_websockets

import websockets.*;

WebsocketServer ws;
int now;
float x, y;
int bgColor=0;

void setup() {
  size(200, 200);
  ws= new WebsocketServer(this, 8025, "/");
}

void draw() {
  background(bgColor);
}

void webSocketServerEvent(String msg) {
  println("got message:"+msg);
  if (msg.indexOf("red")>=0) {
    bgColor=color(255, 0, 0);
    ws.sendMessage("Change to Red!");
  } else if (msg.indexOf("green")>=0) {
    bgColor=color(0, 255, 0);
    ws.sendMessage("Change to Green!");
  } else if (msg.indexOf("blue")>=0) {
    bgColor=color(0, 0, 255);
    ws.sendMessage("Change to Blue!");
  } else if (msg.indexOf("black")>=0) {
    bgColor=color(0, 0, 0);
    ws.sendMessage("Change to Black!");
  }
}