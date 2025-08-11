#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

#define Pwd_Len 5  

Servo myservo;

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};
Keypad customKeypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char Data[Pwd_Len];
char Master[Pwd_Len] = "6#D1";
byte data_count = 0;
bool door = false;
char customKey;

void setup() {
  myservo.attach(10);
  ServoClose();
  lcd.begin(16, 2);
  lcd.print("Door is Locked");
  lcd.setCursor(0, 1);
  lcd.print("Loading.......");
  delay(1000);
  lcd.clear();
   pinMode(11, OUTPUT);
}


void loop()
{
  Open();
}


void ServoClose() {
  for (int position = 90; position >= 0; position -= 10) {
    myservo.write(position);
    delay(10);
  }
}


void ServoOpen() {
  for (int position = 0; position <= 90; position += 10) {
    myservo.write(position);
    delay(10);
  }
}


void Open() {
  lcd.setCursor(0, 0);
  lcd.print("ENTER PASSWORD:");
  customKey = customKeypad.getKey();

  if (customKey) {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print('*'); 
    tone(11,1000,50);
    data_count++;
  }

  if (data_count == Pwd_Len - 1) {
    if (strcmp(Data, Master) == 0) {
      lcd.clear();
      lcd.print("Opening Door...");
      tone(11,1500,200);
      delay(1000);
      ServoOpen();
      lcd.clear();
      lcd.print("OPENED");
      door = true;
      lcd.setCursor(0, 1);
      lcd.print("Waiting...");
      delay(5000);
      lcd.clear();
      lcd.print("Closing Door...");
      delay(1000);
      ServoClose();
      lcd.clear();
      lcd.print("Closed");
      door = false;
      delay(2000);
    } else {
      lcd.clear();
      lcd.print("Wrong Password");
      tone(11,400,200);
      delay(1500);
      lcd.clear();
      lcd.print("Try Again");
      door = false;
      delay(1500);
    }
    lcd.clear();
    clearData();
  }
}

void clearData() {
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
}

   
    
  
  
    
	