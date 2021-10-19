//jacob

#include <Keyboard.h>;
#include <Mouse.h>;

int button1state = HIGH;
int button2state = HIGH;
int button3state = HIGH;
int button4state = HIGH;
int button5state = HIGH;
int button6state = HIGH;
int button7state = HIGH;
int button8state = HIGH;

int delay0 = 300;//250 works
int delay1 = 200;
int delay2 = 5;
int delay3 = 150;
char entr = KEY_RETURN;
    
void setup() {
Keyboard.begin();
Mouse.begin();
Serial.begin(9600);
digitalWrite(2,INPUT_PULLUP);
digitalWrite(3,INPUT_PULLUP);
digitalWrite(4,INPUT_PULLUP);
digitalWrite(5,INPUT_PULLUP);
digitalWrite(6,INPUT_PULLUP);
digitalWrite(7,INPUT_PULLUP);
digitalWrite(8,INPUT_PULLUP);
digitalWrite(9,INPUT_PULLUP);
digitalWrite(A3, OUTPUT);
}

void esc() {
Keyboard.press(KEY_ESC);
Keyboard.releaseAll();
Keyboard.press(KEY_ESC);  
Keyboard.releaseAll();
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

    button1state = digitalRead(2);
    button2state = digitalRead(3);
    button3state = digitalRead(4);
    button4state = digitalRead(5);
    button5state = digitalRead(6);
    button6state = digitalRead(8);
    button7state = digitalRead(7);
    button8state = digitalRead(9);
  
}
void loop(){
    check();
    
//------------------
//BUTTON 1
//bailout/esc
//
//------------------
    
    if(button1state == LOW) {
      esc();
      esc();
      delay(delay3);
      Keyboard.releaseAll();
     }


    
 //------------------
//BUTTON 5
//Automation Shortcut for table pulls
//Takes ~7 seconds to run and fill out row
//------------------
     
     if(button5state == LOW) {
      
      //inserts field in cell
      Mouse.click(MOUSE_RIGHT);
      delay(delay1);
     Keyboard.write('i');
      delay(delay1);
      Keyboard.write('f');
      //delay(delay0);
      ent();
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
      while(digitalRead(6) != LOW) {
        
         //bailout check
        check();
        if(button1state==LOW){
          esc();
          esc();
          return;
          esc();
        }
        
        delay(50);
      }
      //hopefully clicks and exits loop when button pressed again
      Mouse.click();      
      delay(delay1);
      
      //sets dim as measurement
      tab(10);
      //delay(delay1);
      Keyboard.write('m');
      ent();
      tab(1);
      delay(delay0);
      
      //moves over and repeats for secondary column to hold suffix
      Mouse.click(MOUSE_RIGHT);
      delay(delay0);
      Keyboard.write('i');
      delay(delay0);
      Keyboard.write('f');
      ent();
      
      //selects pull automatically by clicking in place
      tab(7);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      //delay(delay0);
      Mouse.click();
      
      delay(delay0);
      tab(10);
      //delay(delay0);
      Keyboard.write('e');
      delay(delay1);
      left(2);
      delay(delay1);
      ent();

      //NOW FOR SIDEPULL

      //inserts field in cell
      delay(delay0);
      tab(1);
      delay(delay0);
      Mouse.click(MOUSE_RIGHT);
      delay(delay0);
      Keyboard.write('i');
      delay(delay0);
      Keyboard.write('f');
      //delay(delay1);
      ent();
      delay(delay0);
      
      //selects pull manually
      tab(7);
      delay(delay0);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      
      //waits until pull selected by pressing button second time
      while(digitalRead(6) != LOW) {
        
         //bailout check
        check();
        if(button1state==LOW){
          esc();
          esc();
          return;
        }
        
        delay(50);
      }

      //hopefully clicks and exits loop when button pressed again
      Mouse.click();      
      delay(delay0);
      
      //sets dim as measurement
      tab(10);
      delay(delay0);
      Keyboard.write('m');
      ent();
      tab(1);
      
      //moves over and repeats for secondary column to hold suffix
      
      delay(delay0);
      Mouse.click(MOUSE_RIGHT);
      delay(delay0);
      Keyboard.write('i');
      delay(delay0);
      Keyboard.write('f');
      ent();
      
      //selects pull by pressing button
      
      delay(delay0);
      tab(7);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      delay(delay0);
      Mouse.click();
      delay(delay0);
      
      tab(10);
      //delay(delay0);
      Keyboard.write('e');
      delay(delay0);
      left(2);
      delay(delay0);
      ent();
     digitalWrite(A3, LOW);
}
//------------------
//BUTTON 3
//Hatch
//
//------------------
        
      if(button3state == LOW) {
      flash();
      esc();
      //delay(delay0);
      Keyboard.write('h');
      //delay(delay0);
      ent();
      Mouse.click();
      delay(1);
      esc();
      esc();
      delay(200);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 4
//Press Escape 4 times
//
//------------------
     if(button4state == LOW) {
     /* flash();
      esc();
      esc();
      delay(delay3);
      Keyboard.releaseAll();*/
      Keyboard.write('0');
      Keyboard.write('.');
      Keyboard.write('5');
      delay(delay0);
      ent();
      delay(delay3);
      Keyboard.releaseAll();
     }
     
//------------------
//BUTTON 2
//Wipeout on a rectangle
//
//------------------
      flash();
      if(button2state == LOW) {
      Keyboard.write('w');
      //delay(delay0);
      Keyboard.write('i');
      //delay(delay0);
      Keyboard.write('p');
     // delay(delay0);
      Keyboard.write('e');
      delay(delay0);
      ent();
      delay(delay0);
      Keyboard.write('p');
      delay(delay0);
      ent();
      delay(delay0);
      Keyboard.write('y');
      delay(delay0);
      ent();
      delay(delay0);
      delay(delay3);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 6
//Delete
//
//------------------
      flash();
      if(button6state == LOW) {
      //Mouse.click();
      //delay(delay0);
      Keyboard.press(KEY_DELETE);
      delay(delay3);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 7
//Ortho toggle
//
//------------------
      if(button7state == LOW) {
      flash();
      Keyboard.press(KEY_F8);
      delay(delay3);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 8
//Snap toggle
//
//------------------
     if(button8state == LOW) {
      flash();
      Keyboard.press(KEY_F3);
      delay(delay3);
      Keyboard.releaseAll();
     }

     
    delayMicroseconds(5000);
}
