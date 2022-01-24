#include <LiquidCrystal_Software_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2, A0, A1); // LiquidCrystal_I2C lcd(ADDRESS, COLUMNS, ROWS, SDA_PIN, SCL_PIN)


int analoginpin = A5;

int out = 13;
int sensorvalue = 0;


void setup() {
  Serial.begin(9600);  /* Define baud rate for serial communication */
  pinMode(out, OUTPUT);

  lcd.init();                               // LCD initialization
  lcd.backlight();                          // Turn on backlight
  lcd.print("Hello, world!");               // Print Hello, world!

}

void loop() {

  
  
  sensorvalue = analogRead(analoginpin);

  Serial.print("SENSOR: ");
  Serial.println(sensorvalue);
  delay(200);
  lcd.clear();
  

  if(sensorvalue > 700)
  {
    digitalWrite(out, 1);
    lcd.print("!!! FIRE !!!");
    lcd.setCursor(0,1);
    lcd.print("SENSOR Val:");
    lcd.print(sensorvalue);
    
  }
  else
  {
    digitalWrite(out, 0);
    lcd.print("    SAFE");
    lcd.setCursor(0,1);
    lcd.print("SENSOR Val:");
    lcd.print(sensorvalue);
    
    
  }

  
  
}
