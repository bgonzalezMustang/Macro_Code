/*
BLUETOOTH KEYBOARD CODE USING ESP32 WROOM AND ERGODOX REDOX LAYOUT WITH SOME FUTURE MODIFICATIONS PLANNED
-USING CUSTOM LIBRARY FOR COMBO BLUETOOTH KEYBOARD AND MOUSE

*/
#include <BleCombo.h>
#include <BleComboKeyboard.h>
#include <BleComboMouse.h>
#include <BleConnectionStatus.h>
#include <KeyboardOutputCallbacks.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//I am dumb, so this library should work waaaaay better than the code I was trying to write. Sad, but oh well.
//------------------------------------------------------------------------------

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#include <Keypad.h>

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


int delay0 = 400;
int delay1 = 350;
int delay2 = 700;
int keyw = 150;
int doubleTab=1;

static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

const byte ROWS = 8; //four rows
const byte COLS = 5; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'0','!','$','%','&'},
  {'1','q','a','z','*'},
  {'2','w','s','x','('},
  {'3','e','d','c',')'},
  {'4','r','f','v','-'},
  {'5','t','g','b','_'},
  {'`','@','+','^','='},
  {'~','!','@','#','+'}
  
};
byte rowPins[ROWS] = {19, 33, 26, 25, 13, 12, 14, 27}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {15, 4, 16, 17, 5}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;
char key;

int  x, minX;
char message[]="Baxter's Keyboard";
int displayCleared=0;

//---------------------------------------------------------------------------------------------------------


//SETTING PINS AS LETTERS TO MAKE ORGANIZING AND REFFERRING TO BUTTONS EASIER EASIER
const int colA =15;//YELLOW
const int colB =4;//ORANGE
const int colC =16;//RED
const int colD =17;//BROWN
const int colE =5;//BLACK

const int row1 =19;//WHITE
const int row2 =33;//GREY //21 worked
const int row3 =26;//PURPLE
const int row4 =25;//BLUE //problem
const int row5 =13;//GREEN
const int row6 =12;//FREE HANGING PURPLE
const int row7 =14;//WHITE(ATTACHED TO BLACK ONLY)
const int row8 =27;//BLACK(ATTACHED TO WHITE ONLY)

int layer=0;
char layerName[]= "Macro 1";

const int stragglerButtonCount =  5;//number of buttons in a row without a full set of buttons
const int stragglerRowCount = 2;//number of rows without full set of buttons
/*
  
 BUTTON/ROW CONFIGURATION
  0102030405060708
0A[][][][][][]
0B[][][][][][][]
0C[][][][][][][]
0D[][][][][][][][]
0E[][][][][][][]

LEADS TO EACH BUTTON HAVING A COORDINATE BASED ON ROW AND COLUMN
EX: buttonTopLeft=buttonState[colA][row1]
    button4thOver3rdDown=buttonState[colC][row4]

----------
NOTE: [A][7],[A][8],[B][8],[C][8],[E][8] 
      DO NOT EXIST!!!

      set them as constant int's and/or never ever reference them as they will spit out garbage values
*/

//pins that rows are connected to, dummy pins as 1 - 8
int rows[] = {row1, row2, row3, row4, row5, row6, row7, row8};


//pins that columns are connected to, dummy pins as A-E
//also variable to store size of columns
int cols[] = {colA, colB, colC, colD, colE};

const int colCount= sizeof(cols)/sizeof(cols[0]);
const int rowCount= sizeof(rows)/sizeof(rows[0]);
//The number of buttons/keys
  //The stupid addition at the end is because these are 2 rows not completley filled with buttons
int numOfButtons = (rowCount*colCount)-((stragglerRowCount*colCount)-stragglerButtonCount);

//making an array to hold current and previous button states
  //Each of these arrays actually holds more buttons than are available because I am dumb and my brain is small. Don't try to reference coordinates
  //that don't exist
int buttonState[colCount][rowCount];
int prevButtonState[colCount][rowCount];


void setup() {
  //initialization of serial and mouse/keyboard
  
  Keyboard.begin();
  Mouse.begin();
  
  loopCount = 0;
  startTime = millis();
    msg = "";
  Serial.begin(115200);



// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.setTextWrap(false);
  x    = display.width();
  minX = -12 * strlen(message); // 12 = 6 pixels/character * text size 2
    display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...

  



  for(int16_t i=0; i<display.height()/2-2; i+=2) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i,
      display.height()/4, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000);


/*

  //declaring the column and row pins
  for (int i=0; i<rowCount; i++){
    pinMode(rows[i], INPUT);
    Serial.print("Declaring row pin: ");
    Serial.print(rows[i]);
    Serial.print(" as input");
    Serial.print("\n");
  }
  for(int i=0; i<colCount; i++){
    digitalWrite(cols[i], INPUT_PULLUP);
    Serial.print("Declaring column pin: ");
    Serial.print(cols[i]);
    Serial.print(" as input-pullup");
    Serial.print("\n");
  }
  */

  //Setup for connection sequence
  Serial.print("Booting up...\n");
   while(Keyboard.isConnected() == false) {

    display.clearDisplay();
  
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    display.println(F("Searching..."));
    
    Serial.print("Searching...\n");
    delay(10000);
  }
    Serial.print("Connected!");
    display.clearDisplay();
  
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner

    display.println(F("Connected!!!!"));
    delay(1000);
}

//runs through all columns one at a time, checks whether a row is pressed

void readMatrix(){
  //iterate through the columns, set one column at a time as ground
  for(int colIndex=0; colIndex<colCount; colIndex++){
    byte curCol = cols[colIndex];
    pinMode(curCol, OUTPUT);
    digitalWrite(curCol, LOW);
      
      //check all row buttons in the column that is active, then disable that row and move to the next one
      for(int rowIndex=0; rowIndex<rowCount; rowIndex++){
        byte rowCol = rows[rowIndex];
        pinMode(rowCol, INPUT_PULLUP);
        buttonState[colIndex][rowIndex]=digitalRead(rowCol);

        //debugging junk
        if (buttonState[colIndex][rowIndex]==LOW){
          Serial.print(buttonState[colIndex][rowIndex]);
          Serial.print(colIndex);
          Serial.print(" ");
          Serial.print(rowIndex);
          Serial.print("\n");
        }
        pinMode(rowCol, INPUT);
      //holds the previous state of the button, useful for holding buttons down
      prevButtonState[colIndex][rowIndex]=buttonState[colIndex][rowIndex];
    }
    //disable the column from being ground
    pinMode(curCol, INPUT);
  }
}

//Tool functions for making other functions





//Function for writing out a full word or several words, parameter is an array of chars because strings are dumb in c++
void writeString(char string[]){
  for(int i=0; i<sizeof(string)/sizeof(string[0]); i++){
    Keyboard.write(string[i]);
    delay(100);
  }
}

void write(char letter){
  Keyboard.write(letter);
  //delay(50);
}

//Functions to be called when keys pressed


//COPY AND PASTE FROM OTHER MACRO------------------------------------------------------------------------------------------



void finish(){
  delay(keyw);
  Keyboard.releaseAll();
}
void ent() {
  
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  
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
   ent();
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
  ent();
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

void hatch() {
  Keyboard.write('h');
  ent();
  Mouse.click();
  esc(2);
  delay(keyw);
  Keyboard.releaseAll();
}
void line() {
  Keyboard.write('p');
  Keyboard.write('l');
  ent();
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
  ent();
}
void push() {
  Keyboard.write('0');
  Keyboard.write('.');
  Keyboard.write('5');
  ent();
  delay(keyw);
  Keyboard.releaseAll();
}
void mirror() {
  Keyboard.write('m');
  Keyboard.write('i');
  ent();
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
  ent();
  delay(delay0);
  Keyboard.write('d');
  tab(2);
  ent();
  esc(2);
  delay(delay0);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  Keyboard.write('a');
  Keyboard.write('n');
  Keyboard.write('d');
  Keyboard.write('n');
  ent();
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
  ent();
  delay(delay0);
  Keyboard.write('s');
  tab(2);
  ent();
  esc(2);
  delay(delay0);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  Keyboard.write('a');
  Keyboard.write('n');
  Keyboard.write('d');
  Keyboard.write('n');
  ent();
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
void trimmer() {
  Keyboard.write('t');
  Keyboard.write('r');
  ent();
}

void mover() {
  Keyboard.write('m');
  ent();
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
  ent();
 
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
  
  ent();  
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
  ent();
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
  ent();  
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
  ent();
  delay(delay0);
  Mouse.click();
  delay(delay0);
  Keyboard.write('s');
  ent();
  }
void sendBack(){
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
    ent();
}

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
  else{
    Keyboard.write('c'); 
    Serial.write("selection value is: ");
    Serial.write(selection); 
    Serial.write("expected: 1,2, or 3");  
    
  }
  
  ent();
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


















//----------------------------------------------------------------------------------------------------------------------------
//Checking for button presses



void check(){
   loopCount++;
    if ( (millis()-startTime)>5000 ) {
        Serial.print("Average loops per second = ");
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                key=kpd.key[i].kchar;
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    chooseLayer();
                    msg = " PRESSED.";
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                    //chooseLayer();
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
               
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);
                
            }
        }
    }
}

void chooseLayer(){
  switch(layer){
    case 0:
      layer0();
      break;
    case 1:
      layer1();
      break;
    case 2:
      layer2();
      break;
    case 3:
      layer3();
      break;
    default:
      layer0();
  }
}

void layer0(){
  
  if(key=='0'){Keyboard.press(KEY_LEFT_CTRL);Keyboard.releaseAll(); }
  if(key=='!'){tab(1); }
  if(key=='$'){Keyboard.press(KEY_CAPS_LOCK);Keyboard.releaseAll();}
  if(key=='%'){Keyboard.press(KEY_LEFT_SHIFT);Keyboard.releaseAll(); }
  if(key=='&'){esc(1); }
  
  if(key=='1'){Keyboard.press(KEY_LEFT_GUI); Keyboard.releaseAll();}
  if(key=='q'){write('q'); }
  if(key=='a'){write('a'); }
  if(key=='z'){write('z'); }
  if(key=='*'){write('1'); }
  
  if(key=='2'){Keyboard.press(KEY_LEFT_ALT);}
  if(key=='w'){write('w'); }
  if(key=='s'){write('s'); }
  if(key=='x'){write('x'); }
  if(key=='('){write('2'); }
  
  if(key=='3'){write(';');}
  if(key=='e'){write('e'); }
  if(key=='d'){write('d');Serial.print(key); }
  if(key=='c'){write('c'); }
  if(key==')'){write('3'); }
  
  if(key=='4'){Keyboard.press(KEY_BACKSPACE);Keyboard.releaseAll(); }
  if(key=='r'){write('r'); }
  if(key=='f'){write('f'); }
  if(key=='v'){write('v'); }
  if(key=='-'){write('4'); } 
  
  if(key=='5'){write(' '); }
  if(key=='t'){write('t'); }
  if(key=='g'){write('g'); }
  if(key=='b'){write('b'); }
  if(key=='_'){write('5'); }
  if(key=='`'){layer=3;display.clearDisplay(); }
  if(key=='@'){Keyboard.press(KEY_LEFT_CTRL);Keyboard.press(KEY_DELETE);Keyboard.releaseAll();}
  if(key=='+'){ent(); }
  if(key=='^'){Keyboard.press(KEY_LEFT_CTRL);write('z');Keyboard.releaseAll(); }
  if(key=='='){ }
   
  if(key=='~'){ }
  //if(key=='!'){ }
  if(key==','){}
  if(key=='#'){layer++;display.clearDisplay(); }
  if(key=='='){ }
}

void layer1(){
  if(key=='0'){ }
  if(key=='!'){ }
  if(key=='$'){ }
  if(key=='%'){ }
  if(key=='&'){ }
  
  if(key=='1'){ }
  if(key=='q'){ }
  if(key=='a'){ }
  if(key=='z'){ }
  if(key=='*'){ }
  
  if(key=='2'){ }
  if(key=='w'){ }
  if(key=='s'){ }
  if(key=='x'){ }
  if(key=='('){ }
  
  if(key=='3'){ }
  if(key=='e'){ }
  if(key=='d'){ }
  if(key=='c'){ }
  if(key==')'){ }
  
  if(key=='4'){ }
  if(key=='r'){ }
  if(key=='f'){ }
  if(key=='v'){ }
  if(key=='-'){ } 
  
  if(key=='5'){ }
  if(key=='t'){ }
  if(key=='g'){ }
  if(key=='b'){ }
  if(key=='_'){ }
  if(key=='`'){layer--;display.clearDisplay();  }
  if(key=='@'){ortho(); }
  if(key=='+'){snap(); }
  if(key=='^'){ }
  if(key=='='){ }
   
  if(key=='~'){ }
  if(key=='!'){ }
  if(key==','){}
  if(key=='#'){layer++;display.clearDisplay();  }
  if(key=='='){ }}

void layer2(){
  
  if(key=='0'){ }
  if(key=='!'){ }
  if(key=='$'){ }
  if(key=='%'){ }
  if(key=='&'){ }
  
  if(key=='1'){ }
  if(key=='q'){ }
  if(key=='a'){ }
  if(key=='z'){ }
  if(key=='*'){ }
  
  if(key=='2'){ }
  if(key=='w'){ }
  if(key=='s'){ }
  if(key=='x'){ }
  if(key=='('){ }
  
  if(key=='3'){ }
  if(key=='e'){ }
  if(key=='d'){ }
  if(key=='c'){ }
  if(key==')'){ }
  
  if(key=='4'){ }
  if(key=='r'){ }
  if(key=='f'){ }
  if(key=='v'){ }
  if(key=='-'){ } 
  
  if(key=='5'){ }
  if(key=='t'){ }
  if(key=='g'){ }
  if(key=='b'){ }
  if(key=='_'){ }
  if(key=='`'){layer--;display.clearDisplay();  }
  if(key=='@'){ }
  if(key=='?'){ }
  if(key=='^'){ }
  if(key=='='){ }
   
  if(key=='~'){ }
  if(key=='!'){ }
  if(key==','){}
  if(key=='#'){layer++;display.clearDisplay();  }
  if(key=='='){ }
}

void layer3(){

 
  if(key=='0'){ }
  if(key=='!'){ }
  if(key=='$'){ }
  if(key=='%'){ }
  if(key=='&'){ }
  
  if(key=='1'){ }
  if(key=='q'){ }
  if(key=='a'){ }
  if(key=='z'){ }
  if(key=='*'){ }
  
  if(key=='2'){ }
  if(key=='w'){ }
  if(key=='s'){ }
  if(key=='x'){ }
  if(key=='('){ }
  
  if(key=='3'){ }
  if(key=='e'){ }
  if(key=='d'){ }
  if(key=='c'){ }
  if(key==')'){ }
  
  if(key=='4'){ }
  if(key=='r'){ }
  if(key=='f'){ }
  if(key=='v'){ }
  if(key=='-'){ } 
  
  if(key=='5'){ }
  if(key=='t'){ }
  if(key=='g'){ }
  if(key=='b'){ }
  if(key=='_'){ }
  if(key=='`'){layer--;display.clearDisplay(); }
  if(key=='@'){ }
  if(key=='?'){ }
  if(key=='^'){ }
  if(key=='='){ }
   
  if(key=='~'){ }
  if(key=='!'){ }
  if(key==','){ }
  if(key=='#'){layer=0;display.clearDisplay();  }
  if(key=='='){ }
}

void scroll(char message[], int height){
  
  //display.clearDisplay();
  
  display.setCursor(x, height);
  display.print(message);
  display.display();
  display.setTextColor(BLACK, WHITE);
  display.print(message);
  display.display();
  
  if(--x < minX) x = display.width();
  if(x==display.width()/4||x==display.width()/2||x==3*display.width()/4||x==display.width()||x==minX){display.clearDisplay();}
}

void displayDefault(){
    if(displayCleared==0){
      display.clearDisplay();
      displayCleared=1;
    }
    display.setTextSize(2);
    scroll("Baxter's Keyboard!!!", 50);
    display.setCursor(0, 0);
    display.print("Layer:\n");
      if(layer==0){display.print("Keys");}
      else if(layer==1){display.print("Macro 1");}
      else if(layer==2){display.print("Macro 2");}
      else if(layer==3){display.print("Macro 3");}
      else{display.print("NOTHING");}
   display.display();
}


void loop() {
    displayDefault();
    
    
    check();
    delay(25);
  
}
