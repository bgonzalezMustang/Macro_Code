// macro.cpp

//IMPLEMENTATION FILE FOR MACRO.H

#include "macro.h"
#include <Mouse.h>;
#include <Keyboard.h>;

using namespace N;
using namespace std;

//UTILITY FUNCTIONS------------------------------------------------------------------------------------------------------------------

void macro::finish(){
  delay(keyw);
  Keyboard.releaseAll();
}

void macro::esc(int num){
  for(int i=0; i< num; i++) {
    Keyboard.press(KEY_ESC);
    delay(delay0);
    finish();
}

void macro::tab(int tabs){
  for(int i=0; i< tabs; i++) {
    Keyboard.press(KEY_TAB);
    finish();
  }
}

void macro::ent(){
  Keyboard.press(KEY_RETURN);
  finish();
}

void macro::left(int num) {
   for(int i=0; i< num; i++) {
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
  }
}

void macro::writeString(char myStr[]){
  int wordLength= sizeof(myStr);
  for(int i=0; i<wordLength; i++) {
    Keyboard.write(myStr[i]);
    delay(1);
  }
}

//WOEK FUNCTIONS---------------------------------------------------------------------------------------------------------------------

void macro::saveAndPlot(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('s');
  delay(delay0);
  Keyboard.release(KEY_LEFT_SHIFT);
  delay(delay0);
  Keyboard.write('c');
  Keyboard.releaseAll();
  ent();
  Keyboard.write('y');
  delay(delay0);
  Keyboard.write('p');
  Keyboard.write('l');
  Keyboard.write('o');
  Keyboard.write('t');
  ent();
  delay(delay0+500);
  ent();
  delay(delay0+500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('v');
  Keyboard.releaseAll();
}

void macro::insertRow(){
  Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('a');
  Keyboard.write('i');
  Keyboard.write('b');       
}

void macro::deleteRow(){
  Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('a');
  Keyboard.write('d');
  Keyboard.write('r'); 
}

void macro::mergeRow(){
  Keyboard.press(KEY_LEFT_ALT);
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('a');
  Keyboard.write('m');
  Keyboard.write('e');
  tab(1);
  ent();
}

void macro::push(){
  Keyboard.write('0');
  Keyboard.write('.');
  Keyboard.write('5');
  ent();
  delay(keyw);
  Keyboard.releaseAll();
}

void macro::clayer(){
  Keyboard.write('c');
  Keyboard.write('l');
  Keyboard.write('a');
  Keyboard.write('y');
  Keyboard.write('e');
  Keyboard.write('r');
  ent();
}

void macro::lineAndLayer(){
  clayer();
  Keyboard.write('b');
  Keyboard.write('o');
  Keyboard.write('u');
  Keyboard.write('n');
  Keyboard.write('d');
  Keyboard.write('a');
  Keyboard.write('r');
  Keyboard.write('y');
  ent();
  delay(delay0);
  Keyboard.write('p');
  Keyboard.write('l');
  ent();

void macro::layer0(){
  clayer();
  Keyboard.write('0');
  ent();
}

void macro::changeSuffix(int selection){
  
  int num=selection;
  Keyboard.write('q');
  Keyboard.write('p');
  ent();
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
  else if (selection==4){
     Keyboard.write('n');
     
  }
  else if (selection==5){
     Keyboard.write('s');
     
  }
  else if (selection==6){
     Keyboard.write('e');
     
  }
  else if (selection==7){
     Keyboard.write('w');
     
  }
  else{
    Keyboard.write('c'); 
    Serial.write("selection value is: ");
    Serial.write(selection); 
    Serial.write("expected: 1,2,3,4,5,6, or 7");  
    
  }
  
  ent();
    for(int y=0; y<10; y++){
    Mouse.move(0,2,0);
  }
   for(int x=0; x<10; x++){
    Mouse.move(-10,0,0);
  }
  delay(delay0);
  esc();
}

void macro::overWall(){
  changeSuffix(3);
}

void macro::toWall(){
  changeSuffix(2);
}

void macro::center(){
  changeSuffix(1);
}

void macro::north(){
  changeSuffix(4);
}

void macro::south(){
  changeSuffix(5);
}

void macro::east(){
  changeSuffix(6);
}

void macro::west(){
  changeSuffix(7);
}

void macro::scale(){
  Keyboard.write('s');
  Keyboard.write('c');
  Keyboard.write('a');
  Keyboard.write('l');
  Keyboard.write('e');
  ent();
  Mouse.click();
  delay(100);
  Keyboard.write('r');
  ent();
  finish();
}

void macro::block(){
  Keyboard.write('b');
  Keyboard.write('l');
  Keyboard.write('o');
  Keyboard.write('c');
  Keyboard.write('k');
  ent();
  finish();
}

void macro::extend() {
  Keyboard.write('e');
  Keyboard.write('x');
  Keyboard.write('t');
  ent();
  finish();
}

void macro::tableFillOld(){
  
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
  tab(6);
  Keyboard.write(' ');
  delay(delay0);
  Mouse.click();      
  delay(delay1);
  //sets dim as measurement
  tab(10);
  delay(delay0);
  Keyboard.write('m');
  ent();
  delay(delay2);
  esc();
  tab(1);
  //delay(delay1);
  
  //moves over and repeats for secondary column to hold suffix
 
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('a');
  Keyboard.write('f');
  Keyboard.write('i');
  delay(delay0);
  Keyboard.release(KEY_LEFT_ALT);
  delay(delay0);
  
  //selects pull automatically by clicking in place
  tab(7);
  Keyboard.write(' ');
  delay(delay0);
  //Keyboard.releaseAll();
  //delay(delay0);
  Mouse.click();
  delay(delay0);
  tab(10);
  Keyboard.write('e');
  //delay(delay1);
  left(2);
  //delay(delay1);
  ent();
  delay(delay0);
  esc();
  tab(2);
}

void macro::tableFillNew() {
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
  ent();
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
  ent();
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

void macro::rectangle() {
   Keyboard.write('r');
   Keyboard.write('e');
   Keyboard.write('c');
   delay(delay0);
   ent();
   delay(keyw);
   Keyboard.releaseAll();
}

void macro::hatch() {
  Keyboard.write('h');
  ent();
  Mouse.click();
  esc(2);
  delay(keyw);
  Keyboard.releaseAll();
}

void macro::line() {
  Keyboard.write('p');
  Keyboard.write('l');
  ent();
  delay(keyw);
  Keyboard.releaseAll();
}

void macro::ortho() {
  Keyboard.press(KEY_F8);
  delay(keyw);
  Keyboard.releaseAll();
}

void macro::regen() {
  Keyboard.write('r');
  Keyboard.write('e');
  ent();
}

void macro::mirror() {
  Keyboard.write('m');
  Keyboard.write('i');
  ent();
}

void macro::overall() {
  Keyboard.write('-');
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('s');
  Keyboard.write('t');
  Keyboard.write('y');
  Keyboard.write('l');
  Keyboard.write('e');
  ent();
  delay(keyw);
  Keyboard.write('r');
  delay(keyw);
  ent();
  Keyboard.write('o');
  Keyboard.write('v');
  Keyboard.write('e');
  Keyboard.write('r');
  Keyboard.write('a');
  Keyboard.write('l');
  Keyboard.write('l');
  ent();
  delay(keyw);
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('l');
  Keyboard.write('i');
  Keyboard.write('n');
  ent();
}

void macro::rotate(){
  Keyboard.write('r');
  Keyboard.write('o');
  ent();
  delay(delay0);
  Mouse.click();
  delay(delay0);
  Keyboard.write('s');
  ent();
  }

void macro::sendBack(){
  Keyboard.write('d');
  Keyboard.write('r');
  Keyboard.write('a');
  Keyboard.write('w');
  Keyboard.write('o');
  Keyboard.write('r');
  ent();
  Keyboard.write('b');
  ent(); 
}

//MACROPAD FUNCTIONS-----------------------------------------------------------------------------------------------------------------
