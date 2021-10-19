// macro.h
#ifdef MACRO_H
#define MACRO_H

namespace N


{
  class macro
  {
    public:

         //variables to save and define per macropad
         
         int delay0;
         int delay1;
         int delay2;
         int keyw;
         
         //utility functions referenced in other functions
         
         void finish(); //releases all keys
         void esc(int num);//presses escape num times
         void tab(int tabs);//presses tab tabs times
         void ent();//presses enter
         void left(int num);//taps left num times
         
         void writeString(char myStr[]);//types all characters of a char array

         //actual work functions, things that interface with autocad/computer
         
         void saveAndPlot();//saves and plots
         void insertRow();//inserts row into autocad table
         void deleteRow();//removes row from autocad table
         void mergeRow();//merges rows in autocad table
         void push();//moves snap 0.5 inches
         void clayer();//(need to write)current layer
         void lineAndLayer();//sets layer to boundary and draws line
         void layer0();//sets layer to layer 0
         void changeSuffix(int selection);//changes suffix and/or orientation variable for dynamic block based on selection
         void overWall();//sets suffix as 'ow'
         void toWall();//sets suffix as 'tw'
         void center();//sets suffix as 'c'
         void north();//sets orientation as 'north'
         void south();//sets orientation as 'south'
         void east();//sets orientation as 'east'
         void west();//sets orientation as 'west'
         void scale();//scales to reference
         void block();//block command
         void extend();//extend command
         void tableFillOld();//old style of filling tables, with 5 coulumns
         void tableFillNew();//(need to write)new style of filling table, compatible with 3 column
         void rectangle();//rectangle command
         void hatch();//(possibly obsolete) hatches a rectangle
         void line();//draws a polyline
         void ortho();//toggles ortho with F8
         void snap();//toggles snapping with F3
         void regen();//regenerates drawing
         void mirror();//mirrors selection
         void overall();//(need to write new version)sets dim style as overall and calls dimlin
         void rotate();//rotates object 90 degrees colckwise
         void sendBack();//sends to back of draworder

         //MacroPad specific functions, mostly shifting chords and button layers

         /*
         int pins[];//array that holds all pins for 
         int currentLayer;//the active button layer
         void check();//checks state of all pins
         void layerUp();//(might not use here)shifts active layer up
         void layerDown();//shifts active layer down
         void layerReset();//shifts active layer to default
         */
  };
}
