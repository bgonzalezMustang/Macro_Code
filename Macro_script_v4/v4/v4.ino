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
int button9state = HIGH;

int delay0 = 300;//250 works
int delay1 = 350;
int delay2 = 5;
int delay3 = 150;
int keyw = 150;

char entr = KEY_RETURN;
    
void setup() {
Keyboard.begin();
Mouse.begin();
Serial.begin(9600);
digitalWrite(16,INPUT_PULLUP);
digitalWrite(14,INPUT_PULLUP);
digitalWrite(15,INPUT_PULLUP);
digitalWrite(A0,INPUT_PULLUP);
digitalWrite(A1,INPUT_PULLUP);
digitalWrite(A2,INPUT_PULLUP);
digitalWrite(A3,INPUT_PULLUP);
digitalWrite(2,INPUT_PULLUP);
digitalWrite(10,INPUT_PULLUP);
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
//void flash() {
// digitalWrite(A3, HIGH);
// delay(100);
  //digitalWrite(A3, LOW);
//}

void loop(){
    button1state = digitalRead(10);
    button2state = digitalRead(16);
    button3state = digitalRead(14);
    button4state = digitalRead(15);
    button5state = digitalRead(A0);
    button6state = digitalRead(A1);
    button7state = digitalRead(A2);
    button8state = digitalRead(A3);
    button9state = digitalRead(2);
    
//------------------
//BUTTON 3
//Rectangle shortcut
//
//------------------
    
    if(button3state == LOW) {
      //esc();
      Keyboard.write('r');
      Keyboard.write('e');
      Keyboard.write('c');
      delay(delay0);
      ent();
      //flash();
      delay(keyw);
      Keyboard.releaseAll();
     }


    
 //------------------
//BUTTON 2
//Automation Shortcut for table pulls
//Takes ~7 seconds to run and fill out row
//------------------
     
     if(button2state == LOW) {
      //digitalWrite(A3, HIGH);
      //inserts field in cell
      Mouse.click(MOUSE_RIGHT);
      delay(delay1);
      Keyboard.write('i');
      delay(delay1);
      Keyboard.write('f');
      //delay(delay0);
      ent();
      delay(delay1);
      
      //selects pull manually
      tab(7);
      //delay(delay0);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      
      //waits until pull selected by pressing button second time
      while(digitalRead(16) != LOW) {
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
      delay(delay1);
      
      //moves over and repeats for secondary column to hold suffix
      Mouse.click(MOUSE_RIGHT);
      delay(delay1);
      Keyboard.write('i');
      delay(delay0);
      Keyboard.write('f');
      ent();
      
      //selects pull automatically by clicking in place
      tab(7);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      delay(delay0);
      Mouse.click();
      
      delay(delay1);
      tab(10);
      //delay(delay0);
      Keyboard.write('e');
      delay(delay1);
      left(2);
      delay(delay1);
      ent();

      //NOW FOR SIDEPULL

      //inserts field in cell
      delay(delay1);
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
      while(digitalRead(16) != LOW) {
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
      tab(2);
      //digitalWrite(A3, LOW);
      //flash();
     }
//------------------
//BUTTON 3
//short automation
//
//------------------
        
      if(button1state == LOW) {
      /*//flash();
      esc();
      //delay(delay0);
      Keyboard.write('h');
      //delay(delay0);
      ent();
      Mouse.click();
      delay(1);*/
      
      Mouse.click(MOUSE_RIGHT);
      delay(delay1);
      Keyboard.write('i');
      delay(delay1);
      Keyboard.write('f');
      //delay(delay0);
      ent();
      delay(delay1);
      
      //selects pull manually
      tab(7);
      //delay(delay0);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      
      //waits until pull selected by pressing button second time
      while(digitalRead(10) != LOW) {
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
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 5
//Regen
//
//------------------
      if(button5state == LOW) {
      Keyboard.write('r');
      Keyboard.write('e');
      ent();
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 4
//Line
//
//------------------
      //flash();
      if(button4state == LOW) {
      Keyboard.write('l');
      delay(delay0);
      ent();
      delay(delay0);
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 6
//move
//
//------------------
     // flash();
      if(button6state == LOW) {
      esc();
      //delay(delay0);
      Keyboard.write('h');
      //delay(delay0);
      ent();
      Mouse.click();
      delay(1);
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 7
//Ortho toggle
//
//------------------
     if(button7state == LOW) {
     // flash();
      Keyboard.press(KEY_F8);
      
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 8
//Snap toggle
//
//------------------
    if(button8state == LOW) {
      //flash();
      Keyboard.press(KEY_F3);
  
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 9
//Move 0.5
//
//------------------
     if(button9state == LOW) {
      //flash();
      Keyboard.write('0');
      Keyboard.write('.');
      Keyboard.write('5');
      delay(delay0);
      ent();
      delay(keyw);
      Keyboard.releaseAll();
     }

     
    delayMicroseconds(5000);
}
