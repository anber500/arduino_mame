/*
 * Author: Berry Jordaan
 * Email: berry@lunarblink.com
 * 
 * Capture a byte array that's send from an Arduino Mega.
 * The key presses are then send to the Computer as keypresses that can be configured in Mame
 * Use it as you wish.
 */
 
#include <Wire.h>
 
void setup(){
   Wire.begin(1);                // join i2c bus with address #1
   Wire.onReceive(receiveEvent); // register event
   
   //Serial.begin(9600);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {

  //Init the array with clean values
  byte buttons[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int i= 0;
  while (0 < Wire.available()) { // loop through all but the last
    int c = Wire.read(); // receive byte as a character
    //Serial.print(c);         // print the character for debugging only
    buttons[i] = c;
    ++i;
  }
  //int x = Wire.read();    // receive byte is ignored here but can be used as a checksum.
  
  // The following code works for my setup but you may want to use your own key codes.
  // Keycodes can be found on this website:
  // http://www.asciitable.com/
  
  if(buttons[0] == 1){ //but "1"
    Keyboard.press(49);
  }else{
    Keyboard.release(49);
  }
  
  if(buttons[1] == 1){ //but "2"
    Keyboard.press(50);
  }else{
    Keyboard.release(50);
  }

  //Player 1
  if(buttons[2] == 1){ //but "Up"
    Keyboard.press(218);
  }else{
    Keyboard.release(218);
  }

  if(buttons[3] == 1){ //but "Down"
    Keyboard.press(217);
  }else{
    Keyboard.release(217);
  }

  if(buttons[4] == 1){ //but "Left"
    Keyboard.press(216);
  }else{
    Keyboard.release(216);
  }

  if(buttons[5] == 1){ //but "Right"
    Keyboard.press(215);
  }else{
    Keyboard.release(215);
  }
  
  if(buttons[6] == 1){ //but "p1b1" - q
    Keyboard.press(81);
  }else{
    Keyboard.release(81);
  }

  if(buttons[7] == 1){ //but "p1b2" - w
    Keyboard.press(119);
  }else{
    Keyboard.release(119);
  }

  if(buttons[8] == 1){ //but "p1b3" - e
    Keyboard.press(101);
  }else{
    Keyboard.release(101);
  }

  if(buttons[9] == 1){ //but "p1b4" - a
    Keyboard.press(97);
  }else{
    Keyboard.release(97);
  }

  if(buttons[10] == 1){ //but "p1b5" - s
    Keyboard.press(115);
  }else{
    Keyboard.release(115);
  }

  if(buttons[11] == 1){ //but "p1b6" - d
    Keyboard.press(100);
  }else{
    Keyboard.release(100);
  }

  if(buttons[12] == 1){ //but "p1b7" - r
    Keyboard.press(114);
  }else{
    Keyboard.release(114);
  }

  if(buttons[13] == 1){ //but "p1b8" - f
    Keyboard.press(102);
  }else{
    Keyboard.release(102);
  }

  //Player2
  if(buttons[14] == 1){ //Up2 - y
    Keyboard.press(121);
  }else{
    Keyboard.release(121);
  } 

  if(buttons[15] == 1){ //Down2 - g
    Keyboard.press(103);
  }else{
    Keyboard.release(103);
  } 

  if(buttons[16] == 1){ //Left2 - h
    Keyboard.press(104);
  }else{
    Keyboard.release(104);
  }

  if(buttons[17] == 1){ //Right2 - b
    Keyboard.press(98);
  }else{
    Keyboard.release(98);
  }

  if(buttons[18] == 1){ //but "p2b1" - u
    Keyboard.press(117);
  }else{
    Keyboard.release(117);
  }

  if(buttons[19] == 1){ //but "p2b2" - i
    Keyboard.press(105);
  }else{
    Keyboard.release(105);
  }

  if(buttons[20] == 1){ //but "p2b3" - o
    Keyboard.press(111);
  }else{
    Keyboard.release(111);
  }

  if(buttons[21] == 1){ //but "p2b4" - p
    Keyboard.press(112);
  }else{
    Keyboard.release(112);
  }

  if(buttons[22] == 1){ //but "p2b5" - j
    Keyboard.press(106);
  }else{
    Keyboard.release(106);
  }

  if(buttons[23] == 1){ //but "p2b6" - k
    Keyboard.press(107);
  }else{
    Keyboard.release(107);
  }

  if(buttons[24] == 1){ //but "p2b7" - l
    Keyboard.press(108);
  }else{
    Keyboard.release(108);
  }

  if(buttons[25] == 1){ //but "p2b8" - ;
    Keyboard.press(59);
  }else{
    Keyboard.release(59);
  }

}
  
void loop(){
  delay(10);
}
