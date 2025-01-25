# ChickenDoor

![SCREENLOGO](https://github.com/Pidow/ChickenDoor/blob/master/1.first%20WITH%20DIGISPARK/1.Connection%20&%20photos/definition.png?raw=true)![SCREENLOGO](https://github.com/Pidow/ChickenDoor/blob/master/1.first%20WITH%20DIGISPARK/1.Connection%20&%20photos/ouvert.png?raw=true)

TARGET:
Move the chicken house doors 2 times per day.
Estimate battery lifetime: 8 month with AAA battery(x8).

### VERSION HISTORY
*   _[1st Version](https://github.com/Pidow/ChickenDoor/tree/master/1.first%20WITH%20DIGISPARK): Digispark STD with LED to have some information. Not very userfriendly. To add a screen we should use digispark pro._
*   _[2nd Version](https://github.com/Pidow/ChickenDoor/tree/master/2.Rebuild%20with%20DIGISPARK%20PRO): Digispark pro with screen (code not optimised)._
*   _[3st Version](https://github.com/Pidow/ChickenDoor/tree/master/3.With%20light%20sensor%20with%20DIGISPARK%20PRO): Digispark pro with screen and light sensor. After test, Tune the light sensor is very difficult, black cloud may close the door._
*   _[4th Version](https://github.com/Pidow/ChickenDoor/tree/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO): Actually the better version, base on south french Ephemeris. Code optimised, add watchdog sleep mode, add a push button to enter in debug mode and to wake up the screen._


## FOURTH VERSION DISGISPARK PRO VERSION & PUSH BUTTON: less 15€
![SCREENLOGO](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/Description.jpg?raw=true)
*   ATTiny167 Digispark Pro
*   RTC DS3231 (Real Time clock)
*   Switch button
*   Battery holder 4 battery 1,5 v (x2)
*   Oled screen 128x64 I2C SPI serial.


## Description

Startup view.

![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/PRESENTATION.jpg?raw=true)

Press button after boot to enter in debug mode.
![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/DBG%20MODE.jpg?raw=true)

Press 8secondes to wake up the screen when need. (screen shutdown after boot to reduce power consuming).
![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/BUTTON%20ACTION.jpg?raw=true)


## CONNECTION
![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/digispark%20pro.png?raw=true)

Connection for the digispark pro
![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/digispark%20pro%20connections&.jpg?raw=true)

Connection for the Servomotor MG995
![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/MG995.png?raw=true)


## 3D PRINT
Motor support:
![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/Servo%20motor%203D%20print%20support.jpg?raw=true)

1/2 wheel
![FIRSTVERSION](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/1.Assy%20view/Wheel%203D%20print.jpg?raw=true)




## How it's work:
Push software to Digispark [following instruction](https://github.com/Pidow/ChickenDoor/blob/master/4.Ephemeris%20version%20with%20DIGISPARK%20PRO/3.Arduino%20code/Digispark%20arduino%20configuration.pdf), connect all component following instructions.
The system is ready !

Note:
If the RTC have power lost, software update it time automaticaly.
Oled screen & RTC use the same SDA and SCL connection to DIGISPARK.
RTC DS3231 allow to have Temp information.
I have put an relay to avoid battery consuming to maintain the servomotor position.
FYI Servomotor have only 180° angle, i have create a 3D print wheel to open the door.


> I'm available if any question.
> 
> Have fun !
> 
>    ARNAUD TOCABENS.
