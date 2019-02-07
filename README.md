# Smart-Gas-Detector-NXP

System of early detection of accumulation of gases in homes, with activation of extractors through cloud connectivity based on Rapid IoT Prototyping Kit.

<img src="https://media.giphy.com/media/9VeuJ8sII8rYD7XViE/giphy.gif" width="1000">

Always use technology to improve the world, if you are a black hat or gray hat hacker please abstain at this point ......... or at least leave your star to make me feel less guilty XP.

# Table of contents

* [Introduction](#introduction)
* [Materials](#materials)
* [The Circuits](#the-circuits)
* [Development](#development)
* [The Final Product](#the-final-product)
* [Comments](#comments)
* [References](#references)

## Introduction:

Nowadays people tend to die from carelessness caused by themselves, such as leaving open the gas outlet of the stove or not cleaning a chimney and filling the home with CO2; Although these problems are not mortal by themselves, they can lead to death by suffocation if they are not tended immediately.

What are you going to build:
A system of real-time monitoring of air quality in homes to alert about harmful levels of hazardous gases in the environment, such as CO2, butane gas, etc. This integral solution integrate a intelligent ventilation systems that can extract dangerous gases before they can affect users and in turn use these devices to generate machine learning models. All this for the early prevention of these incidents and to determine their frequency.

Today there are basic sensors that provide smoke alerts, that warn the detection of smoke at home, some even having complex systems of aspersion to extinguish fires, nevertheless through these systems we can not collect data, which is one of the main purposes of IoT technology, besides that they are not easy to integrate into smart home systems.

It is extremely useful because thanks to this system users can be notified of direct threats to their lives caused by minor oversights such as those mentioned above.

## Materials:

- NXP Rapid IoT Prototyping Kit. x 1
- ESP32. x 2
(https://www.adafruit.com/product/3405 Preferably use this because it is easier to program it.)
- Luminosity/Lux/Light Sensor or in this case a LED diode. x 1
- Cases for aesthetics. x 2
- A Fan. x 1

In the case you want to use a relay.

- Relay Module for Arduino. x 1

In the case you want to make the PCB circuit all the instructions are in the following link:
https://github.com/altaga/MOSMusic-MM-

## The Circuit:

The first circuit is the activation of the ESP32 through the light alert of the kit.
<img src="https://i.ibb.co/HGYhS5N/NXP-Smart-Gas.png" width="1000">

The second circuit trigger the fan by another ESP32.

<img src="https://i.ibb.co/nnW8vmD/NXP-relay-gas.png" width="1000">

The third circuit is optional to not use the relay, all the instructions to do it are in the following link:
https://github.com/altaga/MOSMusic-MM-

<img src="https://i.ibb.co/jJxzjR9/NXPMOsfet.png" width="1000">

## Development:

For the development of this project we used a NXP Rapid IoT Prototyping Kit, which is a development kit with a large number of sensors and an impeccable hardware design.

As a first part of the development, a program was realized in https://rapid-iot-studio.nxp.com/ which is the IDE of development of NXP for this specific kit, as a base for this the IDE has several examples and documentation to perform the programming of the kit, this module is programmed by blocks and the interactions between them, we have simple blocks of comparison to make conditionals and complex blocks for connectivity with NXP or AWS cloud.

As a template we used the example of "Rapid IoT Kit Out Of Box Demo" and over it the following blocks were added to realize the luminous alert of the air quality, the project will be in the "NXP Codes" folder.

<img src="https://i.ibb.co/9GXzrYg/NXP-Compare.png" width="1000">

The comparison blocks have the following configuration.

<img src="https://i.ibb.co/yy1vXqR/NXP-Compare-2.png" width="300"><img src="https://i.ibb.co/B48DM9g/NXP-Compare1.png" width="300">

In this way we can control the NXP light alert so that it is detected by the LED connected to the ESP32.

NOTE: there are light detection sensors for the ESP32, but we take advantage of the fact that an LED is capable of functioning as a transducer, because if a voltage is passed through a LED this generate light, but if it receives light, it generate a small voltage between its terminals, in this case 800mV being this enough to be detected by the ESP32 as an analog input as shown in the image below, also you can see how the ESP32 is already inside a box and the LED on the outside.

<img src="https://i.ibb.co/ZHyP138/IMG-1762.jpg" width="1000">

The code of the ESP32 will be in the section "Arduino Codes" and this is called "ESP32 Send".

For the second ESP32 the code was used in the section of "Arduino Codes" and this is called "ESP32 Recv", the ESP32 will turn on one of its digital pins when receiving a turn on message through MQTT, to realize MQTT communication, we have several options.

- https://mosquitto.org/ (Works on EDGE).
- https://www.cloudmqtt.com/ (It is the simplest cloud to make MQTT through the internet).
- https://www.ibm.com/internet-of-things (It is more complex to configure but it gives better results, in addition we have an excellent manual to carry out projects on this platform). 

Link of the manual of Watson IoT Platform: https://github.com/altaga/The-Ultimate-IBM-Watson-IoT-Platform-Guide

## The Final Product:

The final project was installed in a room as shown in the video and several experiments were made on what kind of gases or hazards the NXP can detect effectively, it is a great advantage to have an integrated system like this one. This system could save the life of a person in a dangerous situation.

Video: Click on the image:

[![SGD](https://media.giphy.com/media/9VeuJ8sII8rYD7XViE/giphy.gif)](https://www.youtube.com/watch?v=uu8WHsOgXgg)

Sorry github does not allow embed videos.

## Comments:

This product was designed with the NXP Rapid IoT Prototyping Kit shows several competitive advantages over the products currently on the market.

- It's economic
- Does not require large infrastructure investment
- Provide an interal solution and easily adaptable to the needs of users.
- The relay module is capable of activating any type of high voltage system.

Therefore, the system could be complemented with a water sprinkler system if it were a fire or even adapted to any SmartHome system.

## References:

All the information about the technology used, and direct references are in our wiki:

Wiki: https://github.com/altaga/Smart-Gas-Detector/wiki

Top:

* [Table of Contents](#table-of-contents)

