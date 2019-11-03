## TerasysHUB RESTFul API Example on ESP8266 with Arduino IDE
Below steps will guide you to run ESP8266 based TeraSysHub REST example via Arduino IDE. The temperature and humidity sensor will be [DHT11](https://www.adafruit.com/product/386).

### Wiring the HW
* DHT11 is a One Wire protocol based sensor so you need to provide 3.3V, Ground and Data pins. 
* Our Data pin is ESP8266's **GPIO 5**. Notice that it is equivalent to **D1** in NodeMCU fashion. Check **Hardware.cpp** and **Hardware.h** files if you are interested more or skip to the next steps.
* You need to construct your ESP8266 and DHT wiring as in the given diagram below :
![Alt text](img/sensorwiring.png?raw=true "ESP8266-DHT11 Wiring")

### Arduino IDE Setup
* Install the Arduino IDE 1.6.4 or greater from this [site](https://www.arduino.cc/en/Main/Software)
* To Install the ESP8266 Board Package, go to **File->Preferences** from IDE menu.
* Add below URL into **Additional Boards Manager URLs** section.
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
![Alt text](img/ard2.jpg?raw=true "ESP8266 platform")
* Go to Boards Manager from **Tools->Board->Boards Manager** :
![Alt text](img/ard3.jpg?raw=true "ESP8266 boards")
* Search for **esp8266** and press install :
![Alt text](img/ard4.png?raw=true "ESP8266 esp board")
* After installation, you will be able to select ESP8266 based devices as a board under **Tools->Board**.
![Alt text](img/ard6.png?raw=true "ESP8266 esp board selection")
* Select "NodeMCU 1.0" as board. It will auto complete board specifications; 80 MHz as CPU Frequency, 4M (1M SPIFFS) as Flash Size.
* To be able to write SW on device and get serial outputs, select a proper device path from **Tools->Port** section.
![Alt text](img/ard7.jpg?raw=true "ESP8266 port selection")
* For Linux users, add your user to the group of dialout to enable serial comm :
```
$ sudo adduser $USER dialout
```

### Required Arduino Libraries
* To install required libraries, navigate to **Sketch->Include Library->Manage Libraries->Library Manager** and install below libraries one by one by typing them into filter :
```
1. NTPClient (by Fabrice Weinberg)
2. DHT Sensor Library (by Adafruit)
3. Adafruit Unified Sensor (by Adafruit)
```

### Running the RESTFul code sample
* Now you are ready to get the sample code. First, clone the TerasysHUB client repository via git or just download as [zip](https://github.com/gabod2000/Arduino_TerasysHUB) :
```
$ git clone https://github.com/gabod2000/Arduino_TerasysHUB.git
```
* You may want to check the source code given under below path or skip to the next step :
```
Arduino_TerasysHUB/app
```
* Import **app.ino** file into the **Arduino IDE** via **File->Open** to get all other required files.
* Open **Credentials.h** file to update the given credentials with yours, like below:
```
/* User credentails, change them before proceeding! */
/* WiFi Credentials*/
#define WIFI_SSID "YOUR-WIFI-SSID"
#define WIFI_PASS "YOUR-WIFI-PASS"
/* Location info*/
#define LAT     "YOUR-LOCATION-LATITUDE"
#define LON     "YOUR-LOCATION-LONGITUDE"
/* The credential key to access TerasysHUB with given device. */
#define KEY     "YOUR-TERASYSHUB-DEVICE-KEY"
```
* After your credentials have been updated, compile the code (Ctrl + R) and upload (Ctrl + U) into your device. Please do not forget to select your ESP8266's serial device from the **Tools->Port** section.
* After you have successfully connect to your WiFi Network, the sample code will measure temperature and humidity and will post it to Terasys HUB periodically within 20 seconds.
* To see the data post to the TerasysHUB, from your device, you can enable **Serial Monitor** and check the logs.
