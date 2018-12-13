/*
Copy and paste the following code into the arduino IDE, connect your arduino board to
your laptop or PC, select the board and pCOM port from the tools menu, and upload the code

Make sure to connect the sensors properly. Giving wrong connections may lead to permanantly
damaging the sensors.
*/

#include <LiquidCrystal.h>
#include <dht.h>
#define sensor_pin A0 // DHT sensor is connected to analog pin 0 
LiquidCrystal lcd_display(12, 11, 5, 4, 3, 2);  //lcd_display object with the interfacing pins
//12-> RS
//11-> E
//5,4,3,2 -> data pins to the display module
dht DHT;  //DHT object is created
int hum; //DHT.Humidity returns double value, so we are assigning and converting it to a integer 

void setup() {
  lcd_display.begin(16, 2);  // starts the LED display
  Serial.begin(9600);
  delay(500);  //Delay to let system boot
}

void loop() {


  DHT.read11(sensor_pin);

  //delete lines 21 and 31 to 36 if you don't want to use the serial monitor
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);  //dht.humidity is a already present function that gives the humidity value
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);  //dht.temperature is a already present function that gives the humidity value
  Serial.println("C  ");

  delay(1000); //Wait 1 second before accessing sensor again.
  lcd_display.setCursor(0,0); //sets cursor at 0,0
  lcd_display.print("Temp : ");  //displays "Temp : " in the LCD
  lcd_display.setCursor(7, 0);       // Sets cursor to 7,0
  lcd_display.print(DHT.temperature);      //Prints the temperature measureed byt the DHT sensor
  lcd_display.setCursor(0, 1);           //Sets cursor to 0,1
  lcd_display.print("Humidity : ");     // displays "Humidity : " in the LCD at row 2
  lcd_display.setCursor(11,1);            //Sets cursor after humidity is displayed
  hum = int(DHT.humidity);  //assigns and converts double value of DHT.Humidity into a integer variable
  lcd_display.print(hum); //displays the humidity value in the LCD
  lcd_display.setCursor(15,1); //
  lcd_display.print("%");

}
