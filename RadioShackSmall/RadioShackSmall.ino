#include <Keypad.h>

#define ROWS   3 
#define COLS   9

#define CLR 'C'
#define CE  'E'
#define ROOT 'R'
#define CLR 'C'
 
char keys[ROWS][COLS] = {
  {'.','g',CE,CLR,'0','c','d','e','f'},
  {'/','%','P',CLR,ROOT,'*','-','+','='},
  {'7','9','2','1','3','6','5','4','8'}
};
byte rowPins[ROWS] = {0,1,20}; 
byte colPins[COLS] = {15,16,17,18,19,5,4,3,2}; 

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(115200);
  Serial.println("AWAKE!");
}
  
void loop(){
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.printf("KEY: %c (%d)\n", customKey, customKey);
  }
}
