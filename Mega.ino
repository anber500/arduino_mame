/*
 * Author: Berry Jordaan
 * Email: berry@lunarblink.com
 * 
 * Simple code capturing capturing digital button presses on the Arduino Mega. The code
 * support multiple button presses. My particular setup has is for the controls on an Arcade cabinet. 
 * The idea is to send the codes to an Arduino leonardo which will forward keyboard events which can be 
 * configured in MAME.
 * 
 * Use it as you wish.
 */
#include <Bounce2.h>
#include <Wire.h>

// The delay is used for the debounce class. 
// 5ms seems to work fine.
const long DELAY = 5;
// You can change the pin to whatever you like. I just used these pin for my 8 pin connectors.
// The colors are for my own reference.
// set pin numbers:
const int PLAYER_ONE = 13;     // One player button
const int PLAYER_TWO = 12;     // Two player button

const int UP1 = 22; //white
const int DOWN1 = 28;  //blue
const int LEFT1 = 26; //purple
const int RIGHT1 = 24; //grey

const int UP2 = 34;  //red
const int DOWN2 = 32;  //orange
const int LEFT2 = 36;  //brown
const int RIGHT2 = 30; //yellow 

// Player 1 buttons
const int P1B1 = 27; //yellow
const int P1B2 = 35; //grey
const int P1B3 = 33; //purple
const int P1B4 = 37; //white
const int P1B5 = 29; //green
const int P1B6 = 31; //blue
const int P1B7 = 25; //orange
const int P1B8 = 23; ///red

// Player 2 buttons
const int P2B1 = 52; //white
const int P2B2 = 48; //purple
const int P2B3 = 40; //orange
const int P2B4 = 50; //grey
const int P2B5 = 44; //green
const int P2B6 = 46; //blue
const int P2B7 = 42; //yellow
const int P2B8 = 38; //black

// Instantiate the Bounce objects
Bounce playerOne_debounce = Bounce(); 
Bounce playerTwo_debounce = Bounce(); 

//Player 1
Bounce Up1_debounce = Bounce(); 
Bounce Down1_debounce = Bounce(); 
Bounce Left1_debounce = Bounce(); 
Bounce Right1_debounce = Bounce(); 

//player on buttons
Bounce p1b1_debounce = Bounce(); 
Bounce p1b2_debounce = Bounce();
Bounce p1b3_debounce = Bounce();
Bounce p1b4_debounce = Bounce();
Bounce p1b5_debounce = Bounce();
Bounce p1b6_debounce = Bounce();
//player 1 aux buttons
Bounce p1b7_debounce = Bounce();
Bounce p1b8_debounce = Bounce();

//Player 2
Bounce Up2_debounce = Bounce(); 
Bounce Down2_debounce = Bounce(); 
Bounce Left2_debounce = Bounce(); 
Bounce Right2_debounce = Bounce(); 

Bounce p2b1_debounce = Bounce(); 
Bounce p2b2_debounce = Bounce();
Bounce p2b3_debounce = Bounce();
Bounce p2b4_debounce = Bounce();
Bounce p2b5_debounce = Bounce();
Bounce p2b6_debounce = Bounce();
//player 2 aux buttons
Bounce p2b7_debounce = Bounce();
Bounce p2b8_debounce = Bounce();

// buttons array
//The final "2" is optional and only used to check the end of the byte array on the leonardo.
//This is the byte array that will be send to the leonardo.
byte button_states[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2};

void setup() {

  Wire.begin(); // join i2c bus (address optional for master)

  // initialize the inputs:
  pinMode(PLAYER_ONE, INPUT_PULLUP);
  pinMode(PLAYER_TWO, INPUT_PULLUP);

  pinMode(UP1, INPUT_PULLUP);
  pinMode(DOWN1, INPUT_PULLUP);
  pinMode(LEFT1, INPUT_PULLUP);
  pinMode(RIGHT1, INPUT_PULLUP);
  pinMode(P1B1, INPUT_PULLUP);
  pinMode(P1B2, INPUT_PULLUP);
  pinMode(P1B3, INPUT_PULLUP);
  pinMode(P1B4, INPUT_PULLUP);
  pinMode(P1B5, INPUT_PULLUP);
  pinMode(P1B6, INPUT_PULLUP);
  pinMode(P1B7, INPUT_PULLUP);
  pinMode(P1B8, INPUT_PULLUP);

  pinMode(UP2, INPUT_PULLUP);
  pinMode(DOWN2, INPUT_PULLUP);
  pinMode(LEFT2, INPUT_PULLUP);
  pinMode(RIGHT2, INPUT_PULLUP);
  pinMode(P2B1, INPUT_PULLUP);
  pinMode(P2B2, INPUT_PULLUP);
  pinMode(P2B3, INPUT_PULLUP);
  pinMode(P2B4, INPUT_PULLUP);
  pinMode(P2B5, INPUT_PULLUP);
  pinMode(P2B6, INPUT_PULLUP);
  pinMode(P2B7, INPUT_PULLUP);
  pinMode(P2B8, INPUT_PULLUP);

  playerOne_debounce.attach(PLAYER_ONE);
  playerOne_debounce.interval(DELAY);

  playerTwo_debounce.attach(PLAYER_TWO);
  playerTwo_debounce.interval(DELAY);

  //Player 1
  Up1_debounce.attach(UP1);
  Up1_debounce.interval(DELAY);
  Down1_debounce.attach(DOWN1);
  Down1_debounce.interval(DELAY);
  Left1_debounce.attach(LEFT1);
  Left1_debounce.interval(DELAY);
  Right1_debounce.attach(RIGHT1);
  Right1_debounce.interval(DELAY);
  p1b1_debounce.attach(P1B1);
  p1b1_debounce.interval(DELAY);
  p1b2_debounce.attach(P1B2);
  p1b2_debounce.interval(DELAY);
  p1b3_debounce.attach(P1B3);
  p1b3_debounce.interval(DELAY);
  p1b4_debounce.attach(P1B4);
  p1b4_debounce.interval(DELAY);
  p1b5_debounce.attach(P1B5);
  p1b5_debounce.interval(DELAY);
  p1b6_debounce.attach(P1B6);
  p1b6_debounce.interval(DELAY);
  p1b7_debounce.attach(P1B7);
  p1b7_debounce.interval(DELAY);
  p1b8_debounce.attach(P1B8);
  p1b8_debounce.interval(DELAY);

  //Player 2
  Up2_debounce.attach(UP2);
  Up2_debounce.interval(DELAY);
  Down2_debounce.attach(DOWN2);
  Down2_debounce.interval(DELAY);
  Left2_debounce.attach(LEFT2);
  Left2_debounce.interval(DELAY);
  Right2_debounce.attach(RIGHT2);
  Right2_debounce.interval(DELAY);
  p2b1_debounce.attach(P2B1);
  p2b1_debounce.interval(DELAY);
  p2b2_debounce.attach(P2B2);
  p2b2_debounce.interval(DELAY);
  p2b3_debounce.attach(P2B3);
  p2b3_debounce.interval(DELAY);
  p2b4_debounce.attach(P2B4);
  p2b4_debounce.interval(DELAY);
  p2b5_debounce.attach(P2B5);
  p2b5_debounce.interval(DELAY);
  p2b6_debounce.attach(P2B6);
  p2b6_debounce.interval(DELAY);
  p2b7_debounce.attach(P2B7);
  p2b7_debounce.interval(DELAY);
  p2b8_debounce.attach(P2B8);
  p2b8_debounce.interval(DELAY);

}

void loop() {
  // Update the Bounce instances :
  playerOne_debounce.update();
  int val = playerOne_debounce.read();
  button_states[0] = (val == LOW) ? 1: 0;

  playerTwo_debounce.update();
  val = playerTwo_debounce.read();
  button_states[1] = (val == LOW) ? 1: 0;

  Up1_debounce.update();
  val = Up1_debounce.read();
  button_states[2] = (val == LOW) ? 1: 0;
  Down1_debounce.update();
  val = Down1_debounce.read();
  button_states[3] = (val == LOW) ? 1: 0;
  Left1_debounce.update();
  val = Left1_debounce.read();
  button_states[4] = (val == LOW) ? 1: 0;
  Right1_debounce.update();
  val = Right1_debounce.read();
  button_states[5] = (val == LOW) ? 1: 0;
  p1b1_debounce.update();
  val = p1b1_debounce.read();
  button_states[6] = (val == LOW) ? 1: 0;
  p1b2_debounce.update();
  val = p1b2_debounce.read();
  button_states[7] = (val == LOW) ? 1: 0;
  p1b3_debounce.update();
  val = p1b3_debounce.read();
  button_states[8] = (val == LOW) ? 1: 0;
  p1b4_debounce.update();
  val = p1b4_debounce.read();
  button_states[9] = (val == LOW) ? 1: 0;
  p1b5_debounce.update();
  val = p1b5_debounce.read();
  button_states[10] = (val == LOW) ? 1: 0; 
  p1b6_debounce.update();
  val = p1b6_debounce.read();
  button_states[11] = (val == LOW) ? 1: 0;
  p1b7_debounce.update();
  val = p1b7_debounce.read();
  button_states[12] = (val == LOW) ? 1: 0;
  p1b8_debounce.update();
  val = p1b8_debounce.read();
  button_states[13] = (val == LOW) ? 1: 0;

  //Player 2
  Up2_debounce.update();
  val = Up2_debounce.read();
  button_states[14] = (val == LOW) ? 1: 0;
  Down2_debounce.update();
  val = Down2_debounce.read();
  button_states[15] = (val == LOW) ? 1: 0;
  Left2_debounce.update();
  val = Left2_debounce.read();
  button_states[16] = (val == LOW) ? 1: 0;
  Right2_debounce.update();
  val = Right2_debounce.read();
  button_states[17] = (val == LOW) ? 1: 0;
  p2b1_debounce.update();
  val = p2b1_debounce.read();
  button_states[18] = (val == LOW) ? 1: 0;
  p2b2_debounce.update();
  val = p2b2_debounce.read();
  button_states[19] = (val == LOW) ? 1: 0;
  p2b3_debounce.update();
  val = p2b3_debounce.read();
  button_states[20] = (val == LOW) ? 1: 0;
  p2b4_debounce.update();
  val = p2b4_debounce.read();
  button_states[21] = (val == LOW) ? 1: 0;
  p2b5_debounce.update();
  val = p2b5_debounce.read();
  button_states[22] = (val == LOW) ? 1: 0; 
  p2b6_debounce.update();
  val = p2b6_debounce.read();
  button_states[23] = (val == LOW) ? 1: 0;
  p2b7_debounce.update();
  val = p2b7_debounce.read();
  button_states[24] = (val == LOW) ? 1: 0;
  p2b8_debounce.update();
  val = p2b8_debounce.read();
  button_states[25] = (val == LOW) ? 1: 0;

  Wire.beginTransmission(1); // transmit to device #1
  Wire.write(button_states, 27);
  Wire.endTransmission();    // stop transmitting
  delay(DELAY);
}
