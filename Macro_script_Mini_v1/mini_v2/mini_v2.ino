#include <Keyboard.h>;
#include <Mouse.h>;

int button1state = HIGH;
int button2state = HIGH;
int button3state = HIGH;
int button4state = HIGH;
int button5state = HIGH;

int delay0 = 300;//250 works
int delay1 = 200;
int delay2 = 5;
int delay3 = 150;
char entr = KEY_RETURN;
int keyw = 150;
    
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
       Mouse.click(MOUSE_RIGHT);
      delay(delay1);
      Keyboard.write('i');
      delay(delay1);
      Keyboard.write('f');
      //delay(delay0);
      ent();
      delay(delay1);
        
         //bailout check
        check();
        if(button2state==LOW){
          esc();
          esc();
          return;
          esc();
        }
        

      //selects object as field type
      Keyboard.write('a');
      tab(1);
      Keyboard.write('o');
      
          
         //bailout check
        check();
        if(button2state==LOW){
          esc();
          esc();
          return;
          esc();
        }
        
      //selects pull manually
      tab(6);
      //delay(delay0);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      
      //waits until pull selected by pressing button second time
      while(digitalRead(15) != LOW) {
          
         //bailout check
        check();
        if(button2state==LOW){
          esc();
          esc();
          return;
          esc();
        }
        
        delay(50);
      }
      //hopefully clicks and exits loop when button pressed again
      Mouse.click();
      ent();      
      delay(delay1);
      
      //sets dim as measurement
      tab(10);
      //delay(delay1);
      Keyboard.write('m');
      ent();
      tab(1);
      delay(delay0);
        
         //bailout check
        check();
        if(button2state==LOW){
          esc();
          esc();
          return;
          esc();
        }
        
      
      //moves over and repeats for secondary column to hold suffix
      Mouse.click(MOUSE_RIGHT);
      delay(delay0);
      Keyboard.write('i');
      delay(delay0);
      Keyboard.write('f');
      ent();

        
         //bailout check
        check();
        if(button2state==LOW){
          esc();
          esc();
          return;
          esc();
        }
        
      
      //selects pull automatically by clicking in place
      tab(7);
      Keyboard.write(' ');
      delay(delay0);
      Keyboard.releaseAll();
      //delay(delay0);
      Mouse.click();
      ent();

        
         //bailout check
        check();
        if(button2state==LOW){
          esc();
          esc();
          return;
          esc();
        }
        
      
      delay(delay0);
      tab(10);
      //delay(delay0);
      Keyboard.write('e');
      delay(delay1);
      left(2);
      delay(delay1);
      ent();
      tab(1);
      delay(keyw);
      Keyboard.releaseAll();
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
     
//------------------
//BUTTON 2
//Wipeout on a rectangle
//
//------------------
    /*  flash();
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
      delay(keyw);
      Keyboard.releaseAll();
     }*/
//------------------
//BUTTON 5
//Delete
//
//------------------
      flash();
      if(button5state == LOW) {
      Keyboard.press(KEY_DELETE);
      delay(keyw);
      Keyboard.releaseAll();
     }
//------------------
//BUTTON 7
//Ortho toggle
//
//------------------
     /* if(button7state == LOW) {
      flash();
      Keyboard.press(KEY_F8);
      delay(keyw);
      Keyboard.releaseAll();
     }*/
//------------------
//BUTTON 8
//Snap toggle
//
//------------------
    /* if(button8state == LOW) {
      flash();
      Keyboard.press(KEY_F3);
      delay(keyw);
      Keyboard.releaseAll();
     }
*/
     
    delayMicroseconds(5000);
}
