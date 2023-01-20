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
  pinMode(pbresetPin,INPUT);
}

void loop() {

  bool pbupState = digitalRead(pbupPin); //kondisi awal berniali 1(HIGH)
  bool pbdownState = digitalRead(pbdownPin); //kondisi awal berniali 1(HIGH)
  bool pbresetState = digitalRead(pbresetPin); //kondisi awal berniali 1(HIGH)
  
  if (pbupState == ditekan) { //Jika push button bernilai 0(LOW) maka fungsi pbUp akan dieksekusi
    pbUp(holdBtn);
  }

  if (pbdownState == ditekan) {//Jika push button bernilai 0(LOW) maka fungsi pbDown akan dieksekusi
    pbDown(holdBtn);
  }

  if(pbresetState == ditekan){//Jika push button bernilai 0(LOW) maka fungsi pbReset akan dieksekusi
    pbReset();
  }

}

void cetak(int a) { //Menampilkan ke lcd
  lcd.clear();
  Serial.print("Counter : ");
  Serial.println(a);
  lcd.setCursor(5,0);
  lcd.print("COUNTER");
  lcd.setCursor(8,1);
  lcd.print(a);
}

void pbUp(bool a) { //counter up
  if (a == 0) { 
    counter++;
    delay(500);
    cetak(counter);
    a = 1;
  } else {
    a = 0;
  }
}

void pbDown(bool a) { //counter down
  if (counter > 1) {
    counter--;
    delay(500);
    cetak(counter);
    a = 1;
  } else {
    a = 0;
  }
}

void pbReset() { //counter reset
  counter = 0;
  delay(500);
  cetak(counter);
}
