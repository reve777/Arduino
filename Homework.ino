#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define LM35_PIN A1

#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int LED_PIN = 11;
const int CDS_PIN = 0;
//---------------------
#define led 9 //定义led灯为13引脚
#define button 7 //定义button键盘为3引脚
bool b1=false;
int i;
//void keyScan()
//{
//if(digitalRead(button)==HIGH)
//{
//delay(5);
//if(digitalRead(button)==HIGH)
//{
//b1=!b1;
//while(digitalRead(button)==HIGH);
//}
//}
//}
//-------------------------
void setup() {
 //LCD輸出顯示
 Serial.begin(9600);
     lcd.init();
     lcd.backlight();
     lcd.clear();
 lcd.setCursor(0, 0); // 欄(0-15), 列(0, 1)
  // 印字
  lcd.print("CDS:123 Humd:50%");
  // 設定 cursor
  lcd.setCursor(0, 1); // 欄(0-15), 列(0, 1)
  // 印字
  lcd.print("TP:21C HTP:19c");
//----------------CDS
 
  pinMode(LED_PIN, OUTPUT);//CDS
  pinMode(LM35_PIN, INPUT);//LM35
 dht.begin();
//-------
pinMode(button,INPUT);//设置button所用的引脚为输入引脚

  
}

void loop() {
//光敏電阻CDS
   int value = analogRead(CDS_PIN);
    Serial.println(value);
      if(value < 300) {
    analogWrite(LED_PIN, 255);
  } else if(value < 600) {
    analogWrite(LED_PIN, 50);
  } else {
    analogWrite(LED_PIN, 0);  
  }
    delay(200);

//--------------------------------------LM35
  float val = analogRead(LM35_PIN);
  float temp = (val/1024.0*5.0)/0.01;
  Serial.println(temp);
   delay(200);
//----------------------------------DHT11
  float h = dht.readHumidity();
  // 攝式溫度
  float t = dht.readTemperature();
  // 華式溫度
  float f = dht.readTemperature(true);
  // 若讀取失敗則重讀
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // 華式體感溫度
  float hif = dht.computeHeatIndex(f, h);
  // 攝式體感溫度
  float hic = dht.computeHeatIndex(t, h, false);
  delay(200);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
//------------------------------------LCD
  lcd.setCursor(0, 0);
  lcd.print("CDS:");
  lcd.print(value);
  lcd.print(" Humd:");
  lcd.print(h,0);
  lcd.print("%");
  
//  lcd.setCursor(0, 1);
//  lcd.print("TP:");
//  lcd.print(t,1);
//  lcd.print("c HTP:");
//  lcd.print(hic,0);
//  lcd.print("c");

  
  
  delay(200); 

 //----------------------------
 keyScan();
// i=digitalRead(button); //设置i=button输入的信号
if(b1==true){ //如果i为1，也就是键盘输入高信号
 Serial.println(b1);
lcd.setCursor(0, 1);
  lcd.print("TP:");
  lcd.print(t,1);
  lcd.print("c HTP:");
  lcd.print(hic,0);
  lcd.print("c");

//键盘输入高信号，led灯所在的口输出为高
}else{
Serial.println(b1);
  lcd.setCursor(0, 1);
  lcd.print("TP:");
  lcd.print(f,1);
  lcd.print("F HTP:");
  lcd.print(hif,0);
  lcd.print("F");
}


}
void keyScan()
{
if(digitalRead(button)==HIGH)
{
delay(5);
if(digitalRead(button)==HIGH)
{
b1=!b1;
while(digitalRead(button)==HIGH);
}
}
}
