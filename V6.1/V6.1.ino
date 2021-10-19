#include <Mouse.h>;
#include <Keyboard.h>;

//define pins(surrently with dummy pin #'s)and some of the constant integers
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;

const int button4 = 5;
const int button5 = 6;
const int button6 = 7;

const int button7 = 8;
const int button8 = 9;
const int button9 = A0;

const int button10 = 15;
const int button11 = 14;
const int button12 = 16;
  
const int joystickButton = A1;  //joystick push button pin
const int xAxis = A3; //joystick x axis pin
const int yAxis = A2; //joystick y axis pin
const int y = 1; //just defining the y and x for read axis function (1 for y and 0 for x)
const int x = 0;

int button1State = HIGH;
int button2State = HIGH;
int button3State = HIGH;

int button4State = HIGH;
int button5State = HIGH;
int button6State = HIGH;

int button7State = HIGH;
int button8State = HIGH;
int button9State = HIGH;

int button10State = HIGH;
int button11State = HIGH;
int button12State = HIGH;

int joystickState = HIGH;
//joystick specific parameters


int range = 7;  //output rangeof x and y movement
int responseDelay = 5; //delay in responses in mili-seconds
int threshold = range/3; // resting range of mouse
int center = range/2; //resting threshold (honestly not sure what this does)
int slow = range/2;
int medium = 0.75*range;

//delay times for automation/button presses
int delay0 = 450;
int delay1 = 450;
int delay2 = 5;
int keyw = 150;

void setup() {
digitalWrite(joystickButton, INPUT_PULLUP); //just declares the mouse button to allow board to read joystick click

digitalWrite(button1, INPUT_PULLUP);
digitalWrite(button2, INPUT_PULLUP);
digitalWrite(button3, INPUT_PULLUP);

digitalWrite(button4, INPUT_PULLUP);
digitalWrite(button5, INPUT_PULLUP);
digitalWrite(button6, INPUT_PULLUP);

digitalWrite(button7, INPUT_PULLUP);
digitalWrite(button8, INPUT_PULLUP);
digitalWrite(button9, INPUT_PULLUP);

digitalWrite(button10, INPUT_PULLUP);
digitalWrite(button11, INPUT_PULLUP);
digitalWrite(button12, INPUT_PULLUP);

Mouse.begin(); //board takes control of the mouse (other mouse still works)
Keyboard.begin(); //keyboard begins
Serial.begin(9600);//never actually used, possibly useful later?
}
void check() {
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);

  button4State = digitalRead(button4);
  button5State = digitalRead(button5);
  button6State = digitalRead(button6);

  button7State = digitalRead(button7);
  button8State = digitalRead(button8);
  button9State = digitalRead(button9);

  button10State = digitalRead(button10);
  button11State = digitalRead(button11);
  button12State = digitalRead(button12);

  joystickState = digitalRead(joystickButton);
}

int readAxis(int thisAxis) {
  int reading = analogRead(thisAxis);
  reading = map(reading, 0,1023,0, range); //I honestly have no clue what this is mapping to
  int distance = reading-center; //amount the mouse moves is the displacement from center
  
  //Setting 3 speeds for joystick. Slow, medium, and fast.
  
   /* if(abs(distance) <= abs(center)) { //if the joystick is past the threshold, move at a slower speed
    distance = 0;
    Keyboard.releaseAll();
  }
  else if(abs(distance) > abs(center) && abs(distance) <= abs(slow)){
    distance = distance*0.3;
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.releaseAll();
  }
  else if (abs(distance) > abs(slow) && abs(distance) <= abs(medium)) {
    distance = distance*0.5;
    Keyboard.releaseAll();
  }
  else if (abs(distance) > abs(medium)) {
    distance = distance;
    Keyboard.releaseAll();
  }
     return distance;
}*/
if(abs(distance) < threshold) { //if the joystick is past the threshold, move at a slower speed
    distance = distance/3;
     }
  
     return distance;
}
void checkJoystick() {

  
 /* if(yVal!=0 || xVal!=0 && isMoved ==false)
  {
     //Keyboard.press(KEY_LEFT_CTRL);  
     Mouse.click(MOUSE_MIDDLE); 
     isMoved = true;
  }
  else if (xVal ==0 && yVal==0) {
      Keyboard.releaseAll();
      isMoved=false;
  }
*/
}
void setJoystick() {//use an array to hold these
int yVal = -readAxis(yAxis); //pulls the inverted y value for the mouse/joystick
int xVal = -readAxis(xAxis); //pulls the inverted x value for the mouse/joystick
int scrollVal =0;// -readAxis(yAxis)/5; //pulls the value for scroll
}

void esc(int val);
void ent(int val);

// starts layer change, needs followup text
void changeToLayer(){
  Keyboard.write('-');
  Keyboard.write('L');
  Keyboard.write('A');
  delay(delay1);
  ent(1);
  Keyboard.write('m');
  delay(delay1);
  ent(1);
}  

void writeSidepull(){
  Keyboard.write('S');
  Keyboard.write('I');
  Keyboard.write('D');
  Keyboard.write('E');
  Keyboard.write('P');
  Keyboard.write('U');
  Keyboard.write('L');
  Keyboard.write('L');
  delay(delay1);
  ent(1);
  delay(delay1);
}

void writeBackpull(){
  Keyboard.write('B');
  Keyboard.write('A');
  Keyboard.write('C');
  Keyboard.write('K');
  Keyboard.write('P');
  Keyboard.write('U');
  Keyboard.write('L');
  Keyboard.write('L');
  delay(delay1);
  ent(1);
  delay(delay1);
}


void writeGeneral(){
  Keyboard.write('G');
  Keyboard.write('E');
  Keyboard.write('N');
  Keyboard.write('E');
  Keyboard.write('R');
  Keyboard.write('A');
  Keyboard.write('L');
  delay(delay1);
  ent(1);
  delay(delay1);
}

// Creates dummy annotation. Orientation 1 is left, 2 is up, 3 is right
void createDummyAnnotation(int orientation){
  int i;
  Keyboard.write('D');
  Keyboard.write('I');
  Keyboard.write('M');
  Keyboard.write('L');
  Keyboard.write('I');
  Keyboard.write('N');
  ent(1);
  delay(delay1);
  for( i=0; i<10; i++){  
    Mouse.move(-1,0,0);
    delay(1);
  }
  delay(delay1);
  for( i=0; i<10; i++){  
    Mouse.move(1,0,0);
    delay(1);
  }
  delay(delay1);
  Mouse.click();
  for( i=0; i<20; i++){  
    if (orientation == 1){
      Mouse.move(-1,0,0);
    } else if (orientation == 2){
      Mouse.move(0,1,0);
    } else {
      Mouse.move(1,0,0);
    }
    delay(1);
  }
  delay(delay1);
  Keyboard.write('5');
  Keyboard.write('0');
  ent(1);
  Mouse.click();  
}

// Creates annotation in SIDEPULL layer, then moves to GENERAL layer
void leftSidepull(){

  esc(2);

  // Move to SIDEPULL layer
  changeToLayer();
  writeSidepull();

  // Create annotation at point
  esc(2);
  createDummyAnnotation(1);  
  // Move to GENERAL layer
  esc(2);
  changeToLayer();
  writeGeneral();
  esc(1);
}
void backpull() {

  esc(2);

  // Move to BACKPULL layer
  changeToLayer();
  writeBackpull();  // Need to write this function before implementation

  // Create annotation at point
  esc(2);
  createDummyAnnotation(2);  
  // Move to GENERAL layer
  esc(2);
  changeToLayer();
  writeGeneral();
  esc(1);
}
void finish(){
  delay(keyw);
  Keyboard.releaseAll();
}
void ent(int num) {
  for(int i=0; i<num; i++) {
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}
void tab(int tabs) {
  for(int i=0; i< tabs; i++) {
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
  }
}
void left(int num) {
   for(int i=0; i< num; i++) {
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
  }
}
void esc(int num) {
  for(int i=0; i< num; i++) {
      Keyboard.press(KEY_ESC);
      Keyboard.releaseAll();
  }
}

void rectangle() {
   Keyboard.write('r');
   Keyboard.write('e');
   Keyboard.write('c');
   delay(delay0);
   ent(1);
   delay(keyw);
   Keyboard.releaseAll();
}

void tableFill(int button) {
   Mouse.click(MOUSE_RIGHT);
      delay(delay1);
      Keyboard.write('i');
      delay(delay1);
      Keyboard.write('f');
      //delay(delay0);
      ent(1);
      delay(delay1);
       

      //selects object as field type
      Keyboard.write('a');
      tab(1);
      Keyboard.write('o');
      
          
     
        
      //selects pull manually
      tab(6);
      //delay(delay0);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      
      //waits until pull selected by pressing button second time
      while(digitalRead(button) == LOW) {
          
        
        
        delay(50);
      }
      //hopefully clicks and exits loop when button pressed again
      Mouse.click();
      ent(1);      
      delay(delay1);
      
      //sets dim as measurement
      tab(10);
      //delay(delay1);
      Keyboard.write('m');
      ent(1);
      tab(1);
      delay(delay0);
        
         
        
      
      //moves over and repeats for secondary column to hold suffix
      Mouse.click(MOUSE_RIGHT);
      delay(delay0);
      Keyboard.write('i');
      delay(delay0);
      Keyboard.write('f');
      ent(1);

        
        
        
      
      //selects pull automatically by clicking in place
      tab(7);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      //delay(delay0);
      Mouse.click();
      ent(1);

        
         
        
      
      delay(delay0);
      tab(10);
      //delay(delay0);
      Keyboard.write('e');
      delay(delay1);
      left(2);
      delay(delay1);
      ent(1);
      tab(1);
      delay(keyw);
      Keyboard.releaseAll();
     }

void hatch() {
  Keyboard.write('h');
  ent(1);
  Mouse.click();
  esc(2);
  delay(keyw);
  Keyboard.releaseAll();
}
void line() {
  Keyboard.write('P');
  Keyboard.write('l');
  ent(1);
  delay(keyw);
  Keyboard.releaseAll();
}
void ortho() {
  Keyboard.press(KEY_F8);
  delay(keyw);
  Keyboard.releaseAll();
}
void snap() {
  Keyboard.press(KEY_F3);
  delay(keyw);
  Keyboard.releaseAll();
}
void regen() {
 Keyboard.write('r');
  Keyboard.write('e');
  ent(1);
}
void push() {
  Keyboard.write('0');
  Keyboard.write('.');
  Keyboard.write('5');
  ent(1);
  delay(keyw);
  Keyboard.releaseAll();
}
void mirror() {
  Keyboard.write('m');
  Keyboard.write('i');
  ent(1);
}
void undo(){
  Keyboard.press(KEY_LEFT_CTRL);
  delay(delay1);
  Keyboard.write('z');
}
void mover(){
  Keyboard.write('m');
  ent(1);
}
void block(){
  Keyboard.write('b');
  Keyboard.write('l');
  ent(1); 
}
void extend() {
  Keyboard.write('e');
  Keyboard.write('x');
  Keyboard.write('t');
  ent(1);
}
void trimmer() {
   Keyboard.write('t');
   Keyboard.write('r');
   ent(1);
}
void overall() {
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('s');
  Keyboard.write('t');
  ent(1);
  delay(delay0);
  Keyboard.write('o');
  tab(2);
  ent(1);
  esc(2);
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('l');
  Keyboard.write('i');
  Keyboard.write('n');
  ent(1);
  //Mouse.click();
}



void joystickPan(){
int xSum=0;
int ySum=0;
  //Keyboard.press(KEY_LEFT_CTRL); 
  //delay(delay0); 
  Mouse.press(MOUSE_MIDDLE); 
  while(button12State != LOW) {
    check();
    //delay(responseDelay);
      int yVal = readAxis(yAxis); //pulls the inverted y value for the mouse/joystick
      int xVal = readAxis(xAxis); //pulls the inverted x value for the mouse/joystick
      int scrollVal =0;
      xSum = xSum + abs(xVal);
      ySum = ySum + abs(yVal);
      Mouse.move(yVal, -xVal, scrollVal);
    }
    Mouse.release(MOUSE_MIDDLE);
    finish();
   // Mouse.move(-xSum, -ySum, 0);
}
void downpull(){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  Keyboard.write('a');
  Keyboard.write('n');
  Keyboard.write('t');
  Keyboard.write('y');
  tab(3);
  ent(1);
  delay(delay0);
  Keyboard.write('d');
  tab(2);
  ent(1);
  esc(2);
  delay(delay0);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  Keyboard.write('a');
  Keyboard.write('n');
  Keyboard.write('d');
  Keyboard.write('n');
  ent(1);
}
void sidepull(){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  Keyboard.write('a');
  Keyboard.write('n');
  Keyboard.write('t');
  Keyboard.write('y');
  tab(3);
  ent(1);
  delay(delay0);
  Keyboard.write('s');
  tab(2);
  ent(1);
  esc(2);
  delay(delay0);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  Keyboard.write('a');
  Keyboard.write('n');
  Keyboard.write('d');
  Keyboard.write('n');
  ent(1);
}

void loop() {
check();
int yVal = readAxis(yAxis)/1000; //pulls the inverted y value for the mouse/joystick
int xVal = readAxis(xAxis); //pulls the inverted x value for the mouse/joystick
int scrollVal =0;// -readAxis(yAxis)/5; //pulls the value for scroll

//I want to make the joystick pan only when it is moved from the center position. The problem now is that ctrl and middle mouse button are both held buttons, and the way that 
 //arduino is being poopy, because every time I run the loop, it runs the command to press the button again, which means it spams them at a the refresh rate. That is unfortunate. In
//the meantime I will just assign one of the buttons to do this, but it is annoying as all heck
/*bool isMoved=true;
if(yVal!=0 || xVal!=0 && isMoved ==false)
  {
    Keyboard.press(KEY_LEFT_CTRL);  
    Mouse.click(MOUSE_MIDDLE); 
    isMoved = true;
   
    Keyboard.write('a');
  }
  if (xVal ==0 && yVal==0 && isMoved==true) {
    isMoved=false;
  }*/
//Mouse.move(xVal, yVal, scrollVal); //THIS IS THE STANDARD METHOD
Mouse.move(0, 0, xVal); //THIS IS JUST FOR SCROLLONG

//INDEX FINGER

if(button10State!=LOW) {
  line();
  finish();
}
if(button11State!=LOW){
  rectangle();
  finish();
}
if(button12State!=LOW){
  joystickPan();
  finish();
}

  //MIDDLE FINGER
if(button4State!=LOW) {
  ortho();
  finish();
}
if(button5State!=LOW){
  snap();
  finish();
}
if(button6State!=LOW){
  push();
  finish();
}

//RING FINGER
if(button7State!=LOW) {
  hatch();
  finish();
}
if(button8State!=LOW){
  regen();
  finish();
}
if(button9State!=LOW){
  mirror();
  finish();
}



//PINKEY FINGER
if(button1State!=LOW) {
  extend();
  finish();
}
if(button2State!=LOW){
  overall();
  finish();
}
if(button3State!=LOW){
  mover();
  finish();
}

//JOYSTICK SWITCH
if(joystickState == LOW) {
  tableFill(A1);
  finish();
}
 delay(responseDelay);

}
