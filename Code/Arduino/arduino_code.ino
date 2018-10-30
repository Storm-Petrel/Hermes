#include <Keypad.h>
#include <LiquidCrystal.h>
#include <timer.h>
auto timer = timer_create_default();

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {46, 44,42, 40};
byte colPins[COLS] = {52, 50, 48};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const String Senha_Correta = "1234";
const String Senha_Emergen = "4321";
String Senha_Digitada = "";

int buzzer = 37;

int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};

int chances = 3;

void setup(){
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.blink();
  String Senha_Digitada = "";
  tone(buzzer, 1519);
  delay(1000);
  noTone(buzzer);
  reset();
}

void reset(){
  lcd.print("Senha:");
  lcd.setCursor(0,1);
  lcd.blink();
  Senha_Digitada = "";
}
  
void timeout() {
  lcd.clear();
  Serial.print("Tempo Esgotado! Alerta Iniciado!");
  lcd.print("Tempo Esgotado");
  lcd.setCursor(0, 1);
  lcd.print("Alerta Iniciado!");
  delay(1000);
  lcd.clear();
  lcd.noBlink();
  exit(0);
}

void loop(){
  timer.in(300000, timeout);
  timer.tick();
  
  char customKey = keypad.getKey();
  if (customKey){
    
    switch(customKey) { 
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
              Senha_Digitada += customKey;
             lcd.print("*");
             break;

      case '*':
         lcd.clear();
         reset();
         break;
              

      case '#':
            lcd.clear();
                 
            if(Senha_Correta == Senha_Digitada){
              lcd.print("Senha Correta");
              Serial.print("Senha Correta \n");
            } 
            else if(Senha_Emergen == Senha_Digitada){
              lcd.print("Senha Correta");
              Serial.print("Alerta Iniciado! \n");
             } 
            else{
              chances = chances - 1;
              lcd.print("Senha Incorreta");
              lcd.setCursor(0, 1);
              lcd.print("Chances rest: ");
              lcd.print(int(chances));
              Serial.print("Senha Incorreta. Chances restantes: ");
              Serial.print(int(chances));
              Serial.print("\n");
              if (chances == 0) {
                lcd.print("Senha Incorreta");
                lcd.setCursor(0, 1);
                lcd.print("Alerta Iniciado!");
                Serial.print("Senha Incorreta! Alerta Iniciado! \n");
              }
              delay(1000);
             }  
     if(Senha_Correta == Senha_Digitada or Senha_Emergen == Senha_Digitada or chances == 0) {
          delay(1000);
          lcd.clear();
          lcd.noBlink();
          exit(0);
         }
        else {
          delay(1000);
          lcd.clear();
          reset();
        }
    }
  } 
}
