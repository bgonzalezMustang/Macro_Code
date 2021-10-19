#include <Mouse.h>;
#include <Keyboard.h>;
using namespace std;

//define pins(surrently with dummy pin #'s)and some of the constant integers
const int button1 = 6;
const int button2 = 7;
const int button3 = 8;

const int button4 = 3;
const int button5 = 4;
const int button6 = 5;

const int button7 = A3;
const int button8 = A2;
const int button9 = 2;

const int button10 = A1;
const int button11 = A0;
const int button12 = 15;

const int button13 = 14;
const int button14 = 16;
const int button15 = 10;

const int buttonToggle = 9;
  
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

int button13State = HIGH;
int button14State = HIGH;
int button15State = HIGH;

int buttonToggleState = HIGH;

//delay times for automation/button presses
int delay0 = 400;
int delay1 = 350;
int delay2 = 700;
int keyw = 150;
int doubleTab=1;

void setup() {

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

digitalWrite(button13, INPUT_PULLUP);
digitalWrite(button14, INPUT_PULLUP);
digitalWrite(button15, INPUT_PULLUP);

digitalWrite(buttonToggle, INPUT_PULLUP);

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

  button13State = digitalRead(button13);
  button14State = digitalRead(button14);
  button15State = digitalRead(button15);

  buttonToggleState = digitalRead(buttonToggle);

}

void w(){
  delay(delay2);
}

//function tfor writing out a string with macropad, needs to have array of char's as parameter
void writeString(char myStr[]){
  int wordLength= sizeof(myStr);
  for(int i=0; i<wordLength; i++) {
    Keyboard.write(myStr[i]);
    delay(1);
  }
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
      delay(delay0);
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

void tableFillOld(int button) {
  Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('a');                   
  Keyboard.write('f');
  Keyboard.write('i');
  delay(delay0);
  //sets object as field type

  
  Keyboard.write('a');
  tab(1);
  Keyboard.write('o');
  delay(delay0);
  
  
  //selects pull manually
  tab(6);//6 when changing field type
  Keyboard.write(' ');
  delay(delay0);
  //waits until pull selected by pressing button second time
  
  Mouse.click();      
  delay(delay0);
  //sets dim as measurement
  tab(10);
  delay(delay0);
  Keyboard.write('m');
  //delay(delay0);
  ent(1);
  delay(delay2);
  esc(2);
  tab(1);
  //delay(delay0);
  
  //moves over and repeats for secondary column to hold suffix
 
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('a');
  Keyboard.write('f');
  Keyboard.write('i');
  //delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  delay(delay0);
    
  //selects pull automatically by clicking in place
  tab(7);
  Keyboard.write(' ');
  delay(delay0);
  Mouse.click();
  delay(delay0);
  tab(10);
  Keyboard.write('e');
  left(2);
  ent(1);
  delay(delay0);
  esc(2);
  if(doubleTab==0){
        doubleTab++;
        tab(2);
      }
      else{
        tab(1);
        doubleTab--;
      }
 
}

void tableFillNew() {
  Keyboard.press(KEY_DELETE);
  delay(delay1);
  Keyboard.release(KEY_DELETE);
  delay(delay1);
  Keyboard.write(' ');
  delay(delay0);
  Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('e');                   
  Keyboard.write('f');
  Keyboard.write('i');
  delay(delay0);
  //sets object as field type

  
  Keyboard.write('a');
  tab(1);
  Keyboard.write('o');
  delay(delay0);
  
  
  //selects pull manually
  tab(6);//6 when changing field type
  Keyboard.write(' ');
  delay(delay0);
  //waits until pull selected by pressing button second time
  
  Mouse.click();      
  delay(delay0);
  //sets dim as measurement
  tab(10);
  delay(delay0);
  Keyboard.write('m');
  //delay(delay0);
  ent(1);
  delay(delay2);
  //delay(delay0);
  
  //moves over and repeats for secondary column to hold suffix
 
  Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('e');
  Keyboard.write('f');
  Keyboard.write('i');
  delay(delay0);
    
  //selects pull automatically by clicking in place
  tab(7);
  Keyboard.write(' ');
  delay(delay0);
  Mouse.click();
  delay(delay0);
  tab(10);
  Keyboard.write('e');
  left(2);
  ent(1);
  delay(delay0);
  esc(2);
  if(doubleTab==0){
        doubleTab++;
        tab(2);
      }
      else{
        tab(1);
        doubleTab--;
      }
  delay(keyw);
  esc(1);
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
  Keyboard.write('p');
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




//not working
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
//not working
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

//undo last action
void undo(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('z');
  finish();
}

void copy() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('c');
  finish();
}

void paste(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('c');
  finish();
}
void scale(){
  Keyboard.write('s');
  Keyboard.write('c');
  Keyboard.write('a');
  Keyboard.write('l');
  Keyboard.write('e');
  ent(1);
  Mouse.click();
  delay(100);
  Keyboard.write('r');
  ent(1);
  finish();
}
void block(){
  Keyboard.write('b');
  Keyboard.write('l');
  Keyboard.write('o');
  Keyboard.write('c');
  Keyboard.write('k');
  ent(1);
  finish();
}
void extend() {
  Keyboard.write('e');
  Keyboard.write('x');
  Keyboard.write('t');
  ent(1);
  finish();
}
void trimmer() {
  Keyboard.write('t');
  Keyboard.write('r');
  ent(1);
}

void mover() {
  Keyboard.write('m');
  ent(1);
}

//insert fixture block
void fixtureLeft(){
  Keyboard.write('-');
  Keyboard.write('i');
  Keyboard.write('n');
  Keyboard.write('s');
  Keyboard.write('e');
  Keyboard.write('r');
  Keyboard.write('t');
  ent(1);
 
  Keyboard.write('l');
  Keyboard.write('e');
  Keyboard.write('f');
  Keyboard.write('t');
  Keyboard.write('f');
  Keyboard.write('i');
  Keyboard.write('x');
  Keyboard.write('t');
  Keyboard.write('u');
  Keyboard.write('r');
  Keyboard.write('e');
  Keyboard.write('.');
  Keyboard.write('v');
  Keyboard.write('1');
  
  ent(1);  
}


//insert fixture block
void fixtureRight(){
  Keyboard.write('-');
  Keyboard.write('i');
  Keyboard.write('n');
  Keyboard.write('s');
  Keyboard.write('e');
  Keyboard.write('r');
  Keyboard.write('t');
  ent(1);
  Keyboard.write('r');
  Keyboard.write('i');
  Keyboard.write('g');
  Keyboard.write('h');
  Keyboard.write('t');
  Keyboard.write('f');
  Keyboard.write('i');
  Keyboard.write('x');
  Keyboard.write('t');
  Keyboard.write('u');
  Keyboard.write('r');
  Keyboard.write('e');
  Keyboard.write('.');
  Keyboard.write('v');
  Keyboard.write('1');
  ent(1);  
}

void save(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('s');
  delay(delay0);
  Keyboard.release(KEY_LEFT_SHIFT);
  delay(delay0);
  Keyboard.write('c');
  Keyboard.releaseAll();
  ent(1);
  Keyboard.write('y');
  delay(delay0);
  Keyboard.write('p');
  Keyboard.write('l');
  Keyboard.write('o');
  Keyboard.write('t');
  ent(1);
  delay(delay0+500);
  ent(1);
  delay(delay0+500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('v');
  Keyboard.releaseAll();
}
void overall() {
  Keyboard.write('-');
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('s');
  Keyboard.write('t');
  Keyboard.write('y');
  Keyboard.write('l');
  Keyboard.write('e');
  ent(1);
  delay(keyw);
  Keyboard.write('r');
  delay(keyw);
  ent(1);
  Keyboard.write('o');
  Keyboard.write('v');
  Keyboard.write('e');
  Keyboard.write('r');
  Keyboard.write('a');
  Keyboard.write('l');
  Keyboard.write('l');
  ent(1);
  delay(keyw);
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('l');
  Keyboard.write('i');
  Keyboard.write('n');
  ent(1);
  /*Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('m');
  Keyboard.write('c');
  Keyboard.write('o');
  Keyboard.write('v');
  Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('a');
  Keyboard.write('n');
  esc(2);*/
}
void rotate(){
  Keyboard.write('r');
  Keyboard.write('o');
  ent(1);
  delay(delay0);
  Mouse.click();
  delay(delay0);
  Keyboard.write('s');
  ent(1);
  }
void sendBack(){
  Keyboard.write('d');
  Keyboard.write('r');
  Keyboard.write('a');
  Keyboard.write('w');
  Keyboard.write('o');
  Keyboard.write('r');
  ent(1);
  Keyboard.write('b');
  ent(1); 
}
void insertRow(){
    Keyboard.press(KEY_LEFT_ALT);
    delay(delay0);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.write('t');
    Keyboard.write('a');
    Keyboard.write('i');
    Keyboard.write('b');       
  }
void deleteRow(){
    Keyboard.press(KEY_LEFT_ALT);
    delay(delay0);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.write('t');
    Keyboard.write('a');
    Keyboard.write('d');
    Keyboard.write('r'); 
 }
void mergeRow(){
    Keyboard.press(KEY_LEFT_ALT);
    delay(delay0);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.write('t');
    Keyboard.write('a');
    Keyboard.write('m');
    Keyboard.write('e');
    tab(1);
    ent(1);
}

void changeSuffix(int selection){
  
  int num=selection;
  Keyboard.write('q');
  Keyboard.write('p');
  ent(1);
  delay(delay0+200);
  for(int x=0; x<10; x++){
    Mouse.move(10,0,0);
  }
  for(int y=0; y<15; y++){
    Mouse.move(0,-2,0);
  }
  
  Mouse.click();

  if (selection ==1){
    Keyboard.write('c');
  }
  else if (selection ==2){
    Keyboard.write('t');
    Keyboard.write('w');
  }
  else if(selection==3){
    Keyboard.write('o');
    Keyboard.write('w');
  }
  else{
    Keyboard.write('c'); 
    Serial.write("selection value is: ");
    Serial.write(selection); 
    Serial.write("expected: 1,2, or 3");  
    
  }
  
  ent(1);
    for(int y=0; y<10; y++){
    Mouse.move(0,2,0);
  }
   for(int x=0; x<10; x++){
    Mouse.move(-10,0,0);
  }
  delay(delay0);
  esc(2);
  regen();
}

void toggleState(){
while(buttonToggleState==LOW){
check();
if(button1State==LOW) {
  tableFillNew();
  finish();
}
if(button2State==LOW){
  rotate();
  finish();
}
if(button3State==LOW){
  sendBack();
  finish();
}

  //COLUMN 2
if(button4State==LOW) {
  overall();
  finish();
}
if(button5State==LOW){
  
  finish();
}
if(button6State==LOW){
  
  finish();
}

//COLUMN 3
if(button7State==LOW) {
  mergeRow();
  finish();
}
if(button8State==LOW){
  insertRow();
  finish();
}
if(button9State==LOW){
  deleteRow();
  finish();
}


//COLUMN 4
if(button10State==LOW) {
  
  finish();
}
if(button11State==LOW){
  
  finish();
}
if(button12State==LOW){
  
  finish();
}

//COLUMN 5
if(button13State==LOW) {
  changeSuffix(2);
  finish();
}
if(button14State==LOW){
  changeSuffix(1);
  finish();
}
if(button15State==LOW){
  changeSuffix(3);
  finish();
}
}
}


void loop() {
check();
//COLUMN 1

if(button1State==LOW) {
  tableFillOld(button1);
  finish();
}
if(button2State==LOW){
  rectangle();
  finish();
}
if(button3State==LOW){
  line();
  finish();
}

  //COLUMN 2
if(button4State==LOW) {
  extend();
  finish();
}
if(button5State==LOW){
  trimmer();
  finish();
}
if(button6State==LOW){
  push();
  finish();
}

//COLUMN 3
if(button7State==LOW) {
  hatch();
  finish();
}
if(button8State==LOW){
  regen();
  finish();
}
if(button9State==LOW){
  block();
  finish();
}


//COLUMN 4
if(button10State==LOW) {
  mirror();
  finish();
}
if(button11State==LOW){
  save();
  finish();
}
if(button12State==LOW){
  scale();
  finish();
}

//COLUMN 5
if(button13State==LOW) {
  ortho();
  finish();
}
if(button14State==LOW){
  snap();
  finish();
}
if(button15State==LOW){
  mover();
  finish();
}

//THUMB BUTTON
//sets macro to alternate key-layout, basically creates 30 buttons

if(buttonToggleState==LOW) {
  toggleState();
  finish();
}

}
