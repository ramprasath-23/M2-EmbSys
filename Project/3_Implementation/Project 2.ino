#include <math.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>
const int x_out = A1; /* connect x_out of module to A1 of UNO
board */
const int y_out = A2; /* connect y_out of module to A2 of UNO
board */
int vib_pin=7;
/* connect z_out of module to A3 of UNO board */
TinyGPS gps;
float lat=12.9647771,lon=77.7088037;
SoftwareSerial gpsSerial(3,4);//rx,tx
SoftwareSerial mySerial(9,10);
void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
gpsSerial.begin(9600);
pinMode(vib_pin,INPUT);
delay(1000);
}
void readgsm()
{
 //Begin serial communication with Arduino and Arduino IDE
(Serial Monitor)
 Serial.begin(9600);

 //Begin serial communication with Arduino and SIM900
 mySerial.begin(9600);
 Serial.println("Initializing...");
 delay(1000);
 mySerial.println("AT"); //Handshaking with SIM900
 updateSerial();
 //Serial.println("Hello");
 mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
 updateSerial();
 //Serial.println("Hello");
 mySerial.println("AT+CMGS=\"+919030246810\"");//change ZZ with
country code and xxxxxxxxxxx with phone number to sms
 updateSerial();
 //Serial.println("Hello");
 mySerial.print("http://maps.google.com/maps?q="); //text
content
 mySerial.print(lat);
 mySerial.print(",");
 mySerial.print(lon);
 updateSerial();
 mySerial.write(26);
 return;
}
void updateSerial()
{
 delay(500);
 while (Serial.available())
 {
 mySerial.write(Serial.read());//Forward what Serial received
to Software Serial Port
 }
 while(mySerial.available())
 {
 Serial.write(mySerial.read());//Forward what Software Serial
received to Serial Port
 }
}
void readgps(){
 while(gpsSerial.available()){ // check for gps data
 if(gps.encode(gpsSerial.read()))// encode gps data
 {
 gps.f_get_position(&lat,&lon); // get latitude and longitude
 // display position
// lcd.clear();
// lcd.setCursor(1,0);
// lcd.print("GPS Signal");
 Serial.print("Position: ");
 Serial.print("Latitude:");
 Serial.print(lat,6);
 Serial.print(";");
 Serial.print("Longitude:");
 Serial.println(lon,6);
// lcd.setCursor(1,0);
// lcd.print("LAT:");
// lcd.setCursor(5,0);
// lcd.print(lat);
 Serial.print(lat);
 Serial.print(" ");
// lcd.setCursor(0,1);
// lcd.print(",LON:");
// lcd.setCursor(5,1);
// lcd.print(lon);
}
}
String latitude = String(lat,6);
 String longitude = String(lon,6);
Serial.println(latitude+";"+longitude);
delay(1000);
readgsm();
}
void loop() {
 // put your main code here, to run repeatedly:
 vib();
 acc();
}

void acc(){
 int x_adc_value, y_adc_value;
 x_adc_value = analogRead(x_out); /* Digital value of voltage
on x_out pin */
 y_adc_value = analogRead(y_out);
 Serial.print("x = ");
 Serial.println(analogRead(x_out));
 Serial.print("y = ");
 Serial.println(analogRead(y_out));

 delay(1000);
 if (((x_adc_value)-(y_adc_value)>=25) || ((y_adc_value)-
(x_adc_value)>=25))
 {

 Serial.println("accident happened");
 Serial.println("$accident happened#");
 delay(1000);
 readgps();
 delay(1000);
 //readGSM();
 delay(10000);
 }
}
void vib()
{
 int val;
 val=digitalRead(vib_pin);
 if(val==0)
 //if(digitalRead(vib_pin)==0)
{

 Serial.println("$accident occured#");
 delay(1000);
 readgps();
 delay(1000);
 //readGSM();
 delay(10000);
// lcd.clear();
}
}