#include <Keyboard.h>;
#include <Mouse.h>;
#include <SD.h>;

int button1state = HIGH;
int button2state = HIGH;
int button3state = HIGH;
int button4state = HIGH;
int button5state = HIGH;

int delay0 = 450;//250 works
int delay1 = 400;
int delay2 = 5;
int delay3 = 150;
char entr = KEY_RETURN;
int keyw = 150;
int doubleTab=0;
    
void setup() {
Keyboard.begin();
Mouse.begin();
Serial.begin(9600);
digitalWrite(15,INPUT_PULLUP);
digitalWrite(A0,INPUT_PULLUP);
digitalWrite(A1,INPUT_PULLUP);
digitalWrite(A2,INPUT_PULLUP);
digitalWrite(A3,INPUT_PULLUP);
}

void esc() {
Keyboard.press(KEY_ESC);
Keyboard.releaseAll();
delay(delay0);
Keyboard.press(KEY_ESC);  
Keyboard.releaseAll();
delay(delay0);
}
void tab(int tabs) {
  for(int i=0; i< tabs; i++) {
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
  }
}
void ent() {
  Keyboard.press(entr);
  Keyboard.releaseAll();
}
void left(int num) {
   for(int i=0; i< num; i++) {
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
  }
  
}
void flash() {
  digitalWrite(A3, HIGH);
  delay(100);
  digitalWrite(A3, LOW);
}
void check() {
    button1state = digitalRead(15);
    button2state = digitalRead(A0);
    button3state = digitalRead(A1);
    button4state = digitalRead(A2);
    button5state = digitalRead(A3);
}
void loop(){
    check();
    
//------------------
//BUTTON 1
//short automation
//
//------------------
    
    if(button1state == LOW) {
     
  
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
  
  //selects pull manually
  tab(6);
  Keyboard.write(' ');
  delay(delay0);
  //waits until pull selected by pressing button second time

  
  Mouse.click();      
  delay(delay1);
  //sets dim as measurement
  tab(10);
  delay(delay1);
  Keyboard.write('m');
  ent();
  delay(delay0);
  esc();
  
  delay(delay1);
  tab(1);
  delay(delay0);
  
  //moves over and repeats for secondary column to hold suffix
 
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('t');
  Keyboard.write('a');
  Keyboard.write('f');
  Keyboard.write('i');
  delay(delay1);
  Keyboard.release(KEY_LEFT_ALT);
  
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
  delay(delay0);
  ent();
  delay(delay0);
  esc();
  

   if(doubleTab==0){
        doubleTab++;
        tab(2);
      }
      else{
        tab(1);
        doubleTab--;
      }
      }




    
 //------------------
//BUTTON 2
//bailout/escape
//
//------------------
     
     if(button2state == LOW) {
      esc();
      esc();
      delay(delay0);
      Keyboard.releaseAll();
      
}
//------------------
//BUTTON 3
//Enter
//
//------------------
        
      if(button3state == LOW) {
      ent();
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 4
//Tab
//
//------------------
     if(button4state == LOW) {
     tab(1);
      delay(keyw);
      Keyboard.releaseAll();
     }

     
if(button5state == LOW) {
      Keyboard.press(KEY_DELETE);
      delay(keyw);
      Keyboard.releaseAll();
     }
     
    delayMicroseconds(5000);
}
