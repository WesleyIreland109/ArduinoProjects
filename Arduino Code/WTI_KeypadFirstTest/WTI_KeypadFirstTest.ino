#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//LiquidCrystal_I2C lcd(0x21, 16, 2);  

#define contra 9 
#define bri 10

void setup()
{
    //lcd.backlight();
  //lcd.init();

  lcd.begin(16, 2); //Tell the LCD that it is a 16x2 LCD
  pinMode(contra, OUTPUT); //set pin 9 to OUTPUT
  pinMode(bri, OUTPUT); //Set pin 10 to OUTPUT
  //pinMode-ing OUTPUT makes the specified pin output power
  digitalWrite(contra, LOW); /*outputs no power to the contrast pin.
                            this lets you see the words*/
  analogWrite(bri, 255); //Outputs full power to the screen brightness LED
}
  
void loop()
{
  char customKey = customKeypad.getKey();
  
  if (customKey)
  {
    lcd.clear();
    lcd.setCursor(0, 0); 
    //lcd.print(customKey);
    lcd.print("Hello World");
  }
}
