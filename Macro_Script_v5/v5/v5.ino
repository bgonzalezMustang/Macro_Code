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

int delay0 = 400;//250 works
int delay1 = 360;
int delay2 = 500;
int delay3 = 150;
int keyw = 150;
int doubleTab=1;

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

void finish(){
  delay(keyw);
  Keyboard.releaseAll();
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
void saveAndPlot(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('s');
  delay(delay0);
  Keyboard.release(KEY_LEFT_SHIFT);
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
void insertRow(){
    Keyboard.press(KEY_LEFT_ALT);
    delay(delay0);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.write('t');
    Keyboard.write('a');
    Keyboard.write('i');
    Keyboard.write('a');       
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
    ent();
}
void move13(){
      Keyboard.write('1');
      Keyboard.write('3');
      delay(delay0);
      ent();
}
void move2(){
      Keyboard.write('2');
      delay(delay0);
      ent();
}
void mover() {
  Keyboard.write('m');
  ent();
}
void lineAndLayer(){
  Keyboard.write('c');
  Keyboard.write('l');
  Keyboard.write('a');
  Keyboard.write('y');
  Keyboard.write('e');
  Keyboard.write('r');
  ent();
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
}

void layer0(){
  Keyboard.write('c');
  Keyboard.write('l');
  Keyboard.write('a');
  Keyboard.write('y');
  Keyboard.write('e');
  Keyboard.write('r');
  ent();
  Keyboard.write('0');
  ent();
}

//must have quick properties location enabled as 0 offset, cursor dependent



void changeSuffix(int selection){
  
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


void overWall(){
  changeSuffix(3);
}
void toWall(){
  changeSuffix(2);
}
void center(){
  changeSuffix(1);
}
void north(){
  changeSuffix(4);
}
void south(){
  changeSuffix(5);
}
void east(){
  changeSuffix(6);
}
void west(){
  changeSuffix(7);
}

void scale(){
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
void block(){
  Keyboard.write('b');
  Keyboard.write('l');
  Keyboard.write('o');
  Keyboard.write('c');
  Keyboard.write('k');
  ent();
  finish();
}
void extend() {
  Keyboard.write('e');
  Keyboard.write('x');
  Keyboard.write('t');
  ent();
  finish();
}
void overall(){
  Keyboard.write('-');
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('s');
  Keyboard.write('t');
  Keyboard.write('y');
  ent();
  Keyboard.write('r');
  ent();
  Keyboard.write('o');
  Keyboard.write('v');
  Keyboard.write('e');
  Keyboard.write('r');
  Keyboard.write('a');
  Keyboard.write('l');
  Keyboard.write('l');
  ent();
  Keyboard.write('d');
  Keyboard.write('i');
  Keyboard.write('m');
  Keyboard.write('l');
  Keyboard.write('i');
  Keyboard.write('n');
  ent();
  finish();
}
void check(){
    button1state = digitalRead(10);
    button2state = digitalRead(16);
    button3state = digitalRead(14);
    button4state = digitalRead(15);
    button5state = digitalRead(A0);
    button6state = digitalRead(A1);
    button7state = digitalRead(A2);
    button8state = digitalRead(A3);
    button9state = digitalRead(2);
  }

void layer1(){
  check();
  
}
void loop(){
check();
//------------------
//BUTTON 3
//inserts a row above selected cell
//
//------------------
    
    if(button3state == LOW) {
      insertRow();
    }


    
 //------------------
//BUTTON 1
//Automation Shortcut for table pulls
//Takes ~7 seconds to run and fill out row
//------------------
     
     if(button1state == LOW) {
      //digitalWrite(A3, HIGH);
      //inserts field in cell
   


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
//Bailout/escape
//
//------------------
        
      if(button2state == LOW) {
      mergeRow();
     }
//------------------
//BUTTON 5
//Regen
//
//------------------
      if(button5state == LOW) {
      deleteRow();
     }
//------------------
//BUTTON 4
//Line
//


//BROKEN!!!!!!
//------------------
      //flash();
      if(button4state == LOW) {
      mergeRow();
     }
//------------------
//BUTTON 6
//move
//
//------------------
     // flash();
      if(button6state == LOW) {
       move13();
     }
//------------------
//BUTTON 7
//Ortho toggle
//
//------------------
     if(button7state == LOW) {
     move2();
     }
//------------------
//BUTTON 8
//Snap toggle
//
//------------------
    if(button8state == LOW) {
      //flash();
      Keyboard.write('0');
      Keyboard.write('.');
      Keyboard.write('5');
      delay(delay0);
      ent();
     }
//------------------
//BUTTON 9
//Move 0.5
//
//------------------
     if(button9state == LOW) {
      saveAndPlot();
     }

     
    delayMicroseconds(5000);
}
