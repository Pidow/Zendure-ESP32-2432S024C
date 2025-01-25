# Zendure & Shelly to ESP32-2432S024C

![SCREENLOGO](https://github.com/Pidow/Zendure-ESP32-2432S024C/blob/main/img/IMG1.jpg?raw=true)

TARGET:
Display Shelly & Zendure gateway & EDF Tempo informations trough Wifi.
Track the solar production and electric consumption with Shelly Pro 3EM information
Follow the Zendure battery load trough the Zendure's MQTT message reception.


## VERSION HISTORY
*   NONE

## FIRST VERSION:

Overview:
*   ESP32 : 20€ https://fr.aliexpress.com/item/1005006182025099.html
*   Shelly pro 3EM: 120€ https://fr.zendure.com/products/shelly?variant=41867203084424
*   Battery pack with Hyper2000 https://fr.zendure.com/

## How it's work:
First, install ESP32 parameter in arduino IDE.
Fill wifi SSID, Password; Zendure mail & Serial number.
You must generate your MQTT password by active line 75 (zendure();)
Upload software to ESP32, save information shown on screen.
Fill this information in MQTT parameter, disable line 75, and upload software to ESP32

The system is ready !

## CONNEXION
![SCREENLOGO](https://github.com/Pidow/Zendure_Esp32_TTGO_Shelly/blob/master/img/wifi1.jpg?raw=true)
![SCREENLOGO](https://github.com/Pidow/Zendure_Esp32_TTGO_Shelly/blob/master/img/wifi2.jpg?raw=true)

### PRODUCTION INFORMATION
![SCREENLOGO](https://github.com/Pidow/Zendure_Esp32_TTGO_Shelly/blob/master/img/Production.jpg?raw=true)
![SCREENLOGO](https://github.com/Pidow/Zendure_Esp32_TTGO_Shelly/blob/master/img/shelly2.jpg?raw=true)
### CONSUMPTION INFORMATION
![SCREENLOGO](https://github.com/Pidow/Zendure_Esp32_TTGO_Shelly/blob/master/img/Consommation.jpg?raw=true)
![SCREENLOGO](https://github.com/Pidow/Zendure_Esp32_TTGO_Shelly/blob/master/img/shelly.jpg?raw=true)

### BATTERY INFORMATION
![SCREENLOGO](https://github.com/Pidow/Zendure_Esp32_TTGO_Shelly/blob/master/img/Zendure.jpg?raw=true)
## 3D PRINT
CASE PROTECTION (in progress)



## Note:
No RTC needed, the system is connected to Network Time Protocol.
The screen enter in standby mode after few minutes, but a simple touch wake it.
A RVB led blink information during screen off, red for consumption, blue for batterie use, green for solar production.

> I'm available if any question.
> 
> Have fun !
> 
>    ARNAUD TOCABENS.
