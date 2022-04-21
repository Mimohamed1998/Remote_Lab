/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"

#define BLYNK_TEMPLATE_ID "TMPLHyJ5nNu4"
#define BLYNK_DEVICE_NAME "Quickstart Template"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

# define BLYNK_PRINT Serial

int sensePin = A0; //This is the Arduino Pin that will read the sensor output
int sensorInput; //The variable we will use to store the sensor input
double temp; //The variable we will use to store temperature in degrees.



// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "sZeSSpBoPYRr9Bz_gIo3Jg_7ydho5khH";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AndroidAP";
char pass[] = "bilalinas";

/*
BLYNK_WRITE(V0)
{
  int pinValue_1 = param.asInt();
  digitalWrite(15,pinValue_1);
}
*/
BLYNK_WRITE(V1)
{
  int pinValue_2 = param.asInt();
  digitalWrite(2,pinValue_2);
}
/*

BLYNK_READ(V2) //Blynk app has something on V5
{
  double current_sensorData_1 = analogRead(13)/4095*3.3; ; //reading the sensor on A0
  Blynk.virtualWrite(V2, current_sensorData_1); //sending to Blynk
}

BLYNK_READ(V3) //Blynk app has something on V5
{
  double current_sensorData_2 = analogRead(12)/4095*3.3;; //reading the sensor on A0
  Blynk.virtualWrite(V3, current_sensorData_2); //sending to Blynk
}



BLYNK_READ(V4) //Blynk app has something on V5
{
  double voltage_sensorData_1 = analogRead(14)/4095*3.3; //reading the sensor on A0
  Blynk.virtualWrite(V4, voltage_sensorData_1); //sending to Blynk
}
*/
/*

BLYNK_READ(V5) //Blynk app has something on V5
{
  double  voltage_sensorData_2 = analogRead(A19) ; //reading the sensor on A0
  Serial.print("Mohamed");
  Blynk.virtualWrite(V5, 2.5); //sending to Blynk
}
*/



BlynkTimer timer;

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  delay(500); 
  double sensorInput_v1 = analogRead(A0); //read the analog sensor and store it
  double temp_v5 = (sensorInput_v1 / 4095)*3.23; //find percentage of input reading
  Serial.print("Voltage1_v5: ");
  Serial.println(temp_v5);

  double sensorInput_i1 = analogRead(A3); //read the analog sensor and store it
  double temp_v3 = (sensorInput_i1 / 4095)*1.5; //find percentage of input reading
  Serial.print("current_v4: ");
  Serial.println(temp_v3);
  
  Blynk.virtualWrite(V5,temp_v5);
  Blynk.virtualWrite(A0,temp_v5);
  Blynk.virtualWrite(V3,temp_v3);
  
}






/***************************************/
void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(100);

  // Declaring pins 
  pinMode(15,OUTPUT);
  pinMode(2,OUTPUT);

  pinMode(A0,INPUT);
  pinMode(A3,INPUT);
  //pinMode(14,INPUT);
  //pinMode(26,INPUT);

  
  
  

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  delay(500); 
 // double sensorInput = analogRead(A0); //read the analog sensor and store it
 // double temp = (sensorInput / 4095)*2; //find percentage of input reading
 // Serial.print("Current Temperature: ");
  //Serial.println(temp);
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
 
  
}
