//Turn off onboard LED
digitalWrite(NodeMCU.D4,true);

var linearPWM = [0,0.25,0.5,0.75,1];
var correctedPWM = [0,0.015,0.125,0.422,1];

var linearPWMPhase=0;
var correctedPWMPhase=0;

function displayLinearPWM() {
  analogWrite(NodeMCU.D1,linearPWM[linearPWMPhase]);   
  linearPWMPhase++;
  if (linearPWMPhase>=linearPWM.length){
    linearPWMPhase=0;
    console.log('Now showing corrected PWM');
    setTimeout(displayCorrectedPWM,1000);
  }else{
    setTimeout(displayLinearPWM,1000);
  }
}

function displayCorrectedPWM() {
  analogWrite(NodeMCU.D1,correctedPWM[correctedPWMPhase]);   
  correctedPWMPhase++;
  if (correctedPWMPhase>=correctedPWM.length){
    correctedPWMPhase=0;
    console.log('Now showing linear PWM');
    setTimeout(displayLinearPWM,1000);
  }else{
    setTimeout(displayCorrectedPWM,1000);
  }
}

console.log('Start from linear PWM');
displayLinearPWM();
