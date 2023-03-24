#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int button1Pin = 8; // Botón para velocidad rápida
const int button2Pin = 9; // Botón para velocidad media
const int button3Pin = 10; // Botón para velocidad lenta
int delayTime = 1000; // Tiempo de retraso inicial (en milisegundos)

LiquidCrystal_I2C lcd(0x27, 16, 2); // (dirección I2C, número de columnas, número de filas)

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Hex Counter:");
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
}

void loop() {
  for (int i = 0; i <= 15; i++) {
    lcd.setCursor(0, 1);
    lcd.print(i, HEX);
    delay(delayTime);

    if (digitalRead(button1Pin) == HIGH) { // Si se presiona el botón 1
      delayTime = 100; // Velocidad rápida
    }
    if (digitalRead(button2Pin) == HIGH) { // Si se presiona el botón 2
      delayTime = 500; // Velocidad media
    }
    if (digitalRead(button3Pin) == HIGH) { // Si se presiona el botón 3
      delayTime = 1000; // Velocidad lenta
    }
  }
}
