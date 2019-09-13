/*
KEYMAP as found here: http://www.nouspikel.com/ti99/titechpages.htm
 
 # = wire from left to right looking at keyboard from normal orientation
 
      #12  #8   #13  #14  #15  #9  #6
 #1  entr   P    O    I    U    Y
 #2         0    9    8    7    6
 #3  shft   A    S    D    F    G
 #4  spac   ;    L    K    J    H
 #5    =    /    .    ,    M    N   
 #7  fctn   1    2    3    4    5  lock
 #10 ctrl   Q    W    E    R    T
 #11        z    X    C    V    B

 Wire     Chip    Pin
 #1       C0      10
 #2       C1      11
 #3       C2      12
 #4       C3      13
 #5       C4      14
 #6       C5      15
 #7       C6      16
 #8       C7      17
 #9       F7      45
 #10      F6      44
 #11      F5      43
 #12      F4      42
 #13      F3      41
 #14      F2      40
 #15      F1      39
 
 */

#include <Bounce.h>
#include <Keyboard.h>
const int bounceDelay = 90;
const int led = LED_BUILTIN;

Bounce wire1  = Bounce(10, bounceDelay);
Bounce wire2  = Bounce(11, bounceDelay);
Bounce wire3  = Bounce(12, bounceDelay);
Bounce wire4  = Bounce(13, bounceDelay);
Bounce wire5  = Bounce(14, bounceDelay);
Bounce wire6  = Bounce(15, bounceDelay);
Bounce wire7  = Bounce(16, bounceDelay);
Bounce wire8  = Bounce(17, bounceDelay);
Bounce wire9  = Bounce(45, bounceDelay);
Bounce wire10 = Bounce(44, bounceDelay);
Bounce wire11 = Bounce(43, bounceDelay);
Bounce wire12 = Bounce(42, bounceDelay);
Bounce wire13 = Bounce(41, bounceDelay);
Bounce wire14 = Bounce(40, bounceDelay);
Bounce wire15 = Bounce(39, bounceDelay);

boolean fctn;
boolean shft;
boolean ctrl;
boolean lock;


void setup(){
  pinMode(10, OUTPUT);  // 1 
  pinMode(11, OUTPUT);  // 2
  pinMode(12, OUTPUT);  // 3
  pinMode(13, OUTPUT);  // 4
  pinMode(14, OUTPUT);  // 5
  pinMode(15, INPUT );  // 6
  pinMode(16, OUTPUT);  // 7
  pinMode(17, INPUT );  // 8
  pinMode(45, INPUT );  // 9
  pinMode(44, OUTPUT);  // 10
  pinMode(43, OUTPUT);  // 11
  pinMode(42, INPUT );  // 12
  pinMode(41, INPUT );  // 13
  pinMode(40, INPUT );  // 14 
  pinMode(39, INPUT );  // 15
  pinMode(led, OUTPUT);
  
  Keyboard.begin();
}


void loop(){
  if(shft){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  // Write HIGH to each OUTPUT pin (row in matrix diagram above), one at a time.
  // Check all INPUT pins (column in matrix diagram abobve) for a signal.
  // If a signal is detected, write the character (@ the intersection of the row/column).

  // check for SHIFT, CTRL, FCTN, and/or ALPHA LOCK
  checkModifiers();
  
  // ------------------------ Wire 1 @ PIN 10
  digitalWrite(10, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  wire12.update(); 
  
  // ----------------------- P
  if(wire8.risingEdge()){
   if(lock == true){ 
    Keyboard.print('P'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('P'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('"');
     fctn = false;
   } else {
   Keyboard.print('p'); 
   } 
  }
  
  // ----------------------- Y
  if(wire9.risingEdge()){
   if(lock == true){ 
    Keyboard.print('Y'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('Y'); 
     shft = false;
   }
   else {
   Keyboard.print('y'); 
   }
  }
  
  // ----------------------- U
  if(wire15.risingEdge()){
   if(lock == true){ 
    Keyboard.print('U'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('U'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('_');
     fctn = false;
   } 
   else {
   Keyboard.print('u'); 
   }
  }
  
  // ----------------------- I
  if(wire14.risingEdge()){
   if(lock == true){ 
    Keyboard.print('I'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('I'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('?');
     fctn = false;
   } else {
   Keyboard.print('i'); 
   } 
  } 
  
  // ----------------------- O
  if(wire13.risingEdge()){
   if(lock == true){ 
    Keyboard.print('O'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('O'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('\'');
     fctn = false;
   } else {
   Keyboard.print('o'); 
   }
  }
  
  // ----------------------- ENTER
  if(wire12.risingEdge()){
   Keyboard.print('\n'); 
  }  
  digitalWrite(10, LOW);
  

  // -------------------------- Wire 2 @ PIN 11
  digitalWrite(11, HIGH); 
  wire6.update();
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  // ----------------------- 0
  if(wire8.risingEdge()){
   if(shft == true){
     Keyboard.print(')'); 
     shft = false;
   } else {
   Keyboard.print('0'); 
   } 
  }
  
  // ----------------------- 6
  if(wire9.risingEdge()){
   if(shft == true){
     Keyboard.print('^'); 
     shft = false;
   } else {
   Keyboard.print('6'); 
   }
  }
  
  // ----------------------- 7
  if(wire15.risingEdge()){
   if(shft == true){
     Keyboard.print('&'); 
     shft = false;
   } else {
   Keyboard.print('7'); 
   }
  }
  
  // ----------------------- 8
  if(wire14.risingEdge()){
   if(shft == true){
     Keyboard.print('*'); 
     shft = false;
   } else {
   Keyboard.print('8'); 
   }
  }
  
  // ----------------------- 9
  if(wire13.risingEdge()){
   if(shft == true){
     Keyboard.print('('); 
     shft = false;
   } else {
   Keyboard.print('9'); 
   }
  } 
  digitalWrite(11, LOW);


  // ------------------------ Wire 3 @ PIN 12
  digitalWrite(12, HIGH); 
  wire6.update();
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  // ----------------------- A
  if(wire8.risingEdge()){
   if(lock == true){ 
    Keyboard.print('A'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('A'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print(':');
     fctn = false;
   } else {
   Keyboard.print('a'); 
   }
  }
  
  // ----------------------- G
  if(wire9.risingEdge()){
   if(lock == true){ 
    Keyboard.print('G'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('G'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('}');
     fctn = false;
   } else {
   Keyboard.print('g'); 
   }
  }
  
  // ----------------------- F
  if(wire15.risingEdge()){
   if(lock == true){ 
    Keyboard.print('F'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('F'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('{');
     fctn = false;
   } else {
   Keyboard.print('f'); 
   }
  }
  
  // ----------------------- D
  if(wire14.risingEdge()){
   if(lock == true){ 
    Keyboard.print('D'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('D'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.press(KEY_RIGHT_ARROW);
     fctn = false;
     Keyboard.release(KEY_RIGHT_ARROW);
   } else {
   Keyboard.print('d'); 
   }
  }
  
  // ----------------------- S
  if(wire13.risingEdge()){
   if(lock == true){ 
    Keyboard.print('S'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('S'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.press(KEY_LEFT_ARROW);
     fctn = false;
     Keyboard.release(KEY_LEFT_ARROW);
   } else {
     Keyboard.print('s'); 
   }
  }
  digitalWrite(12, LOW);
  
  
  // ------------------------ Wire 4 @ PIN 13
  digitalWrite(13, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  wire12.update();  
  
  // ----------------------- ;
  if(wire8.risingEdge()){
   if(shft == true){
    Keyboard.print(':'); 
    shft = false;
   } 
   else {
    Keyboard.print(';'); 
   }
  }
  
  // ----------------------- H
  if(wire9.risingEdge()){
   if(lock == true){
    Keyboard.print('H'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('H');
    shft = false;
   } 
   else {
    Keyboard.print('h'); 
   }
  }
  
  // ----------------------- J
  if(wire15.risingEdge()){
    if(lock == true){
    Keyboard.print('J'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('J'); 
    shft = false;
   } 
   else {
    Keyboard.print('j'); 
   }
  }
  
  // ----------------------- K
  if(wire14.risingEdge()){
   if(lock == true){
    Keyboard.print('K'); 
    lock = false;
   } 
   else if(shft == true) {
    Keyboard.print('K');
    shft = false;
   } 
   else {
    Keyboard.print('k'); 
   }
  }
  
  // ----------------------- L
  if(wire13.risingEdge()){
   if(lock == true){
    Keyboard.print('L');
    lock = false; 
   } 
   else if(shft == true){
    Keyboard.print('L');
    shft = false;
   } 
   else {
    Keyboard.print('l'); 
   }
  }
  
  // ----------------------- SPACE
  if(wire12.risingEdge()){
   Keyboard.print(' '); 
  }  
  digitalWrite(13, LOW);

  
  // ------------------------ Wire 5 @ PIN 14
  digitalWrite(14, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  wire12.update();  
  
  // ----------------------- /
  if(wire8.risingEdge()){
   if(shft == true){
    Keyboard.print('-'); 
    shft = false;
   } 
   else {
    Keyboard.print('/'); 
   }
  }
  
  // ----------------------- N
  if(wire9.risingEdge()){
   if(lock == true){
    Keyboard.print('N'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('N'); 
   }
   else {
    Keyboard.print('n'); 
   }
  }
  
  // ----------------------- M
  if(wire15.risingEdge()){
   if(lock == true){
    Keyboard.print('M'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('M'); 
   }
   else {
    Keyboard.print('m'); 
   }
  }
  
  // ----------------------- ,
  if(wire14.risingEdge()){
   if(shft == true){
    Keyboard.print('<'); 
    shft = false;
   } else {
   Keyboard.print(','); 
   }
  }
  
  // ----------------------- .
  if(wire13.risingEdge()){
   if(shft == true){
    Keyboard.print('>'); 
    shft = false;
   } else {
   Keyboard.print('.'); 
   }
  }
  
  // ----------------------- =
  if(wire12.risingEdge()){
   if(shft == true){
    Keyboard.print('+'); 
    shft = false;
   } else {
   Keyboard.print('='); 
   }
  }  
  digitalWrite(14, LOW);

  
  // ------------------------ Wire 7 @ PIN 16
  digitalWrite(16, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();

  // ----------------------- 1
  if(wire8.risingEdge()){
   if(shft == true){
    Keyboard.print('!'); 
    shft = false;
   } 
   else if(ctrl == true){
    Keyboard.press(KEY_BACKSPACE);
    ctrl = false;
    Keyboard.release(KEY_BACKSPACE);
   } 
   else {
    Keyboard.print('1'); 
   }
  }
  
  // ----------------------- 5
  if(wire9.risingEdge()){
   if(shft == true){
    Keyboard.print('%'); 
   } 
   else {
    Keyboard.print('5'); 
   }
  } 
  
  // ----------------------- 4
  if(wire15.risingEdge()){
   if(shft == true){
    Keyboard.print('$'); 
   } 
   else {
    Keyboard.print('4'); 
   }
  } 
  
  // ----------------------- 3
  if(wire14.risingEdge()){
   if(shft == true){
    Keyboard.print('#'); 
   } 
   else {
    Keyboard.print('3'); 
   }
  }  
  
  // ----------------------- 2
  if(wire13.risingEdge()){
   if(shft == true){
    Keyboard.print('@'); 
   } 
   else {
    Keyboard.print('2'); 
   }
  }
  digitalWrite(16, LOW);

  
  // ------------------------ Wire 10 @ PIN 44
  digitalWrite(44, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  // ----------------------- Q
  if(wire8.risingEdge()){
   if(lock == true){
    Keyboard.print('Q'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('Q');
   shft = false; 
   }
   else {
    Keyboard.print('q'); 
   }
  } 
  
  // ----------------------- T
  if(wire9.risingEdge()){
   if(lock == true){
    Keyboard.print('T'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('T');
    shft = false; 
   }
   else if(fctn == true){
     Keyboard.print(']');
     fctn = false;
   }
   else {
    Keyboard.print('t'); 
   }
  }  
  
  // ----------------------- R
  if(wire15.risingEdge()){
   if(lock == true){
    Keyboard.print('R'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('R');
    shft = false; 
   }
   else if(fctn == true){
     Keyboard.print('[');
     fctn = false;
   }
   else {
    Keyboard.print('r'); 
   }
  }  
  
  // ----------------------- E
  if(wire14.risingEdge()){
   if(lock == true){
    Keyboard.print('E'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('E');
    shft = false; 
   }
   else if(fctn == true){
     Keyboard.press(KEY_UP_ARROW);
     fctn = false;
     Keyboard.release(KEY_UP_ARROW);
   }
   else {
    Keyboard.print('e'); 
   }
  } 
  
  // ----------------------- W
  if(wire13.risingEdge()){
   if(lock == true){
    Keyboard.print('W'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('W');
    shft = false; 
   }
   else if(fctn == true){
     Keyboard.print('~');
     fctn = false;
   }
   else {
    Keyboard.print('w'); 
   }
  } 
  digitalWrite(44, LOW);

  
  // ------------------------ Wire 11 @ PIN 43
  digitalWrite(43, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  // ----------------------- Z
  if(wire8.risingEdge()){
   if(lock == true){
    Keyboard.print('Z'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('Z');
    shft = false; 
   }
   else if(fctn == true){
     Keyboard.print('\\');
     fctn = false;
   }
   else {
    Keyboard.print('z'); 
   }
  } 
  
  // ----------------------- B
  if(wire9.risingEdge()){
   if(lock == true){
    Keyboard.print('B'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('B');
    shft = false; 
   }
   else {
    Keyboard.print('b'); 
   }
  } 
  
  // ----------------------- V
  if(wire15.risingEdge()){
   if(lock == true){
    Keyboard.print('V'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('V');
    shft = false; 
   }
   else {
    Keyboard.print('v'); 
   }
  } 
  
  // ----------------------- C
  if(wire14.risingEdge()){
   if(lock == true){
    Keyboard.print('C'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('C');
    shft = false; 
   }
   else if(fctn == true){
    Keyboard.print('`');
    fctn = false; 
   }
   else {
    Keyboard.print('c'); 
   }
  } 
  
  // ----------------------- X
  if(wire13.risingEdge()){
   if(lock == true){
    Keyboard.print('X'); 
    lock = false;
   } 
   else if(shft == true){
    Keyboard.print('X');
    shft = false; 
   }
   else if(fctn == true){
    Keyboard.press(KEY_DOWN_ARROW);
     fctn = false;
     Keyboard.release(KEY_DOWN_ARROW);
   }
   else {
    Keyboard.print('x'); 
   }
  } 
  digitalWrite(43, LOW);
}





//------------------------------------------------  MODIFIER KEYS
void checkModifiers(){ 
  
  // ------------------------ Wire 3 @ PIN 12: shft
  digitalWrite(12, HIGH);
  wire12.update();
  if(wire12.risingEdge()){
    shft = !shft;
  }
  //if(digitalRead(42) == 1){
  // shft = true; 
  //} else {
  // shft = false; 
  //}
  digitalWrite(12, LOW);
  
  // ------------------------ Wire 7 @ PIN 16: fctn & lock
  digitalWrite(16, HIGH); 
  wire12.update();
  wire6.update(); 
  if(digitalRead(42) == 1){
   fctn = true; 
  } else {
   fctn = false; 
  }
  if(digitalRead(15) == 1){
   lock = true; 
  } else {
   lock = false; 
  }
  digitalWrite(16, LOW);
 
   
  // ------------------------ Wire 10 @ PIN 44: ctrl
  digitalWrite(44, HIGH);
  wire12.update();
  if(digitalRead(42) == 1){
   ctrl = true; 
  } else {
   ctrl = false; 
  }
  digitalWrite(44, LOW);
}
