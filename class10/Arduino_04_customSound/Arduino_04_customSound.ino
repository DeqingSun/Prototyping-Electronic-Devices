#include <MozziGuts.h>
#include <Sample.h>
#include <EventDelay.h>
#include <mozzi_rand.h> // for rand()
#include <samples/bamboo/bamboo_00_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_01_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_02_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_03_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_04_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_05_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_06_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_07_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_08_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_09_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_10_2048_int8.h> // wavetable data

#define CONTROL_RATE 64

byte ms_per_note = 111; // subject to CONTROL_RATE

const byte NUM_PLAYERS = 3; // 3 seems to be enough
const byte NUM_TABLES = 11;

Sample <BAMBOO_00_2048_NUM_CELLS, AUDIO_RATE> aSample[NUM_PLAYERS] = {
  Sample <BAMBOO_00_2048_NUM_CELLS, AUDIO_RATE> (BAMBOO_00_2048_DATA),
  Sample <BAMBOO_01_2048_NUM_CELLS, AUDIO_RATE> (BAMBOO_01_2048_DATA),
  Sample <BAMBOO_02_2048_NUM_CELLS, AUDIO_RATE> (BAMBOO_02_2048_DATA),
};

// watch out - tables are const (but you can choose which ones you reference)
const int8_t * tables[NUM_TABLES] = {
  BAMBOO_00_2048_DATA,
  BAMBOO_01_2048_DATA,
  BAMBOO_02_2048_DATA,
  BAMBOO_03_2048_DATA,
  BAMBOO_04_2048_DATA,
  BAMBOO_05_2048_DATA,
  BAMBOO_06_2048_DATA,
  BAMBOO_07_2048_DATA,
  BAMBOO_08_2048_DATA,
  BAMBOO_09_2048_DATA,
  BAMBOO_10_2048_DATA
};

const int ledPin =  13;      // the number of the LED pin

//----------SET EVENTDELAY FOR DEBOUNCING--------------
EventDelay buttonDelay0;
boolean switchWasClosed0 = false;
EventDelay buttonDelay1;
boolean switchWasClosed1 = false;
//-----------------------------------------

void setup() {
  for (int i = 0; i < NUM_PLAYERS; i++) { // play at the speed they're sampled at
    (aSample[i]).setFreq((float) BAMBOO_00_2048_SAMPLERATE / (float) BAMBOO_00_2048_NUM_CELLS);
  }

  startMozzi(CONTROL_RATE);

  pinMode(ledPin, OUTPUT);

  //----------SET PIN MODE HERE--------------
  pinMode(10, INPUT_PULLUP);
  buttonDelay0.set(100);
  pinMode(11, INPUT_PULLUP);
  buttonDelay1.set(100);
  //-----------------------------------------

  Serial.begin(9600);
}

void loop() {
  audioHook();
  //----------Write code here--------------
  boolean switchClosed0 = (digitalRead(10) == LOW);
  if (switchClosed0 != switchWasClosed0) {
    if (buttonDelay0.ready()) { //debouncing, ingore toggle within 100ms
      if (switchClosed0) {
        playNewTone(10);  //there are 11 tones, 0~10
      }
      switchWasClosed0 = switchClosed0;
      buttonDelay0.start();
    }
  }
  boolean switchClosed1 = (digitalRead(11) == LOW);
  if (switchClosed1 != switchWasClosed1) {
    if (buttonDelay1.ready()) { //debouncing, ingore toggle within 100ms
      if (switchClosed1) {
        playNewTone(5);  //there are 11 tones, 0~10
      }
      switchWasClosed1 = switchClosed1;
      buttonDelay1.start();
    }
  }
  //-----------------------------------------
}

void updateControl() {
}

int updateAudio() {
  long asig = 0;
  for (byte i = 0; i < NUM_PLAYERS; i++) {
    asig += (int) (aSample[i]).next() * 255;
  }
  asig >>= 6; // shift into usable range
  //clip any stray peaks to max output range
  return (int)constrain((int)asig, -244, 243);
}

boolean playNewTone(unsigned char toneNumber) {
  if (toneNumber >= NUM_TABLES) return false;
  for (byte i = 0; i < NUM_PLAYERS; i++) {
    if (!aSample[i].isPlaying ()) {
      (aSample[i]).setTable(tables[toneNumber]);
      aSample[i].start();
      return true;
    }
  }
  return false;
}

















