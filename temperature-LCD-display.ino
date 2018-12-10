#include <LiquidCrystal.h>
#include <dht.h>
#define sensor_pin A0 // Analog Pin sensor is connected to analog pin 0 
LiquidCrystal lcd_display(12, 11, 5, 4, 3, 2);  //lcd_display object with the interfacing pins
dht DHT;
int hum;

void setup() {
  lcd_display.begin(16, 2);  // starts the LED display
  Serial.begin(9600);
  delay(500);  //Delay to let system boot
}

void loop() {


  DHT.read11(sensor_pin);

  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);  //dht.humidity is a already present function that gives the humidity value
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);  //dht.temperature is a already present function that gives the humidity value
  Serial.println("C  ");

  delay(1000); //Wait 1 second before accessing sensor again.
  lcd_display.setCursor(0,0);
  lcd_display.print("Temp : ");
  lcd_display.setCursor(7, 0);          //sets the cursor at row 0 column 0
  lcd_display.print(DHT.temperature); // prints 16x2 lcd_display MODULE
  lcd_display.setCursor(0, 1);          //sets the cursor at row 1 column 2
  lcd_display.print("Humidity : ");     // prints HELLO WORLD
  lcd_display.setCursor(11,1);
  hum = int(DHT.humidity);
  lcd_display.print(hum);
  lcd_display.setCursor(15,1);
  lcd_display.print("%");

}
