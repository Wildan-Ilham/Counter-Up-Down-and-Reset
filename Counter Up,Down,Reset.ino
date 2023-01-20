#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int pbupPin = 2;
int pbdownPin = 3;
int pbresetPin = 4;
bool ditekan = false;
bool holdBtn = 0;
int counter = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(pbupPin, INPUT);
  pinMode(pbdownPin, INPUT);
}

void loop() {

  bool pbupState = digitalRead(pbupPin);
  bool pbdownState = digitalRead(pbdownPin);
  bool pbresetState = digitalRead(pbresetPin);
  
  if (pbupState == ditekan) {
    pbUp(holdBtn);
  }

  if (pbdownState == ditekan) {
    pbDown(holdBtn);
  }

  if(pbresetState == ditekan){
    pbReset();
  }

}

void cetak(int a) {
  lcd.clear();
  Serial.print("Counter : ");
  Serial.println(a);
  lcd.setCursor(5,0);
  lcd.print("COUNTER");
  lcd.setCursor(8,1);
  lcd.print(a);
}

void pbUp(bool a) {
  if (a == 0) {
    counter++;
    delay(500);
    cetak(counter);
    a = 1;
  } else {
    a = 0;
  }
}

void pbDown(bool a) {
  if (counter > 1) {
    counter--;
    delay(500);
    cetak(counter);
    a = 1;
  } else {
    a = 0;
  }
}

void pbReset() {
  counter = 0;
  delay(500);
  cetak(counter);
}