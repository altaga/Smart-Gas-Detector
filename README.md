# Smart-Gas-Detector-NXP

System of early detection of accumulation of gases in homes, with activation of extractors through cloud connectivity based on Rapid IoT Prototyping Kit.

<img src="https://media.giphy.com/media/9VeuJ8sII8rYD7XViE/giphy.gif" width="1000">

GIF image

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

El primer circuito es el de activacion del ESP32 a travez de la alerta luminosa del kit.
<img src="https://i.ibb.co/HGYhS5N/NXP-Smart-Gas.png" width="1000">

El segundo circuito de activacion de el ventilador mediante otro ESP32.

<img src="https://i.ibb.co/nnW8vmD/NXP-relay-gas.png" width="1000">

El tercet circuito es la opcion para no usar el relevador, todas las intrucciones para hacerlo estan en el siguiente link:
https://github.com/altaga/MOSMusic-MM-

<img src="https://i.ibb.co/jJxzjR9/NXPMOsfet.png" width="1000">

## Development:

Para el desarollo de este proyecto se utilizo un NXP Rapid IoT Prototyping Kit, el cual es un kit de desarollo con una gran cantidad de sensores y un impecable diseño de hardware.

Como primera parte del desarollo se realizo un programa en https://rapid-iot-studio.nxp.com/ el cual es el IDE de desarollo de NXP para este kit especifico, como base para esto el IDE tiene varios ejemplos y documentacion para realizar la programacion de el kit, la programacion de este modulo se realiza primordialmente por bloques y las interacciones entre estos, desde bloques de comparacion para hacer condicionales hasta bloques para conectividad a la cloud de NXP o AWS.

Como template se utilizo el ejemplo de "Rapid IoT Kit Out Of Box Demo" y spbre el se agregaron los siguientes bloques para realizar la alerta luminosa de la calidad del aire, el proyecto estara en la carpeta de "NXP Codes".

<img src="https://i.ibb.co/9GXzrYg/NXP-Compare.png" width="1000">

Donde la comparacion de ambos bloques tienen la siguiente configuracion.

<img src="https://i.ibb.co/yy1vXqR/NXP-Compare-2.png" width="300"><img src="https://i.ibb.co/B48DM9g/NXP-Compare1.png" width="300">

De esta manera podremos controlar la alerta luminosa de el NXP para que asi sea detectada por el LED conectado a al ESP32.

NOTA: existen sensores de deteccion de luz para el ESP32, pero aprovechamos que un LED es capaz de funcionar como un transductor, debido a que si se la pasa voltaje a un LED este es capaz de generar luz, pero si este recibe luz, es capaz de generar un pequeño voltaje entre sus terminales, en este caso de 800mV siendo esto suficiente para ser detectado por el ESP32 como una entrada analoga como se muestra en la imagen de abajo, ademas se puede ver como el esp ya esta dentro de un cajita y el LED por fuera.

<img src="https://i.ibb.co/ZHyP138/IMG-1762.jpg" width="1000">

El codigo de este ESP32 estara en la seccion "Arduino Codes" y este se llama "ESP32 Send".

Para el segundo ESP32 se utilizo el codigo en la seccion de "Arduino Codes" y este se llama "ESP32 Recv", este se utilizara para que el ESP32 sea capaz de encender uno de sus pines digitales al recibir una señal de encendido mediante el MQTT, para realizar esta comunicacion por MQTT tenemos varias opciones.

- https://mosquitto.org/ (Funciona en EDGE).
- https://www.cloudmqtt.com/ (Es la cloud mas sencilla para hacer mqtt a travez de internet).
- https://www.ibm.com/internet-of-things (Es mas compleja de configurar pero es la que da mejores resultados, ademas tenemos un manual excelente para realizar proyectos en esta plataforma). 

Link del manual de Watson IoT Platform: https://github.com/altaga/The-Ultimate-IBM-Watson-IoT-Platform-Guide

## The Final Product:

El proyecto final se instalo en una habitacion como se muestra en el video y se hicieron varios experimentos de que tipo de gases o peligros puedes detectar el NXP de forma efectiva, notaran la gran ventaja de tener un sistema integrado como el que se muestra ya que ests sistema podria salvarles la vida en algun momento.

Video: Click on the image:

[![https://youtu.be/bxBXAHCA2i4](https://media.giphy.com/media/9VeuJ8sII8rYD7XViE/giphy.gif)](https://youtu.be/bxBXAHCA2i4)

Sorry github does not allow embed videos.

## Comments:

Este producto diseñado con el NXP Rapid IoT Prototyping Kit muestra varias ventajas competitivas sobre los productos actualmente en el mercado, debido a que este producto es economico, no requiere gran inversion de infraestructura y provee una solucion interal y facilmente adaptable a las necesidades de los usuarios, debido a que el modulo de relevador es capaz de activar cualquier tipo de sistema de alto voltaje, por lo tanto el sistema podria complemetarse con algun sistema de aspersion de agua si fuera un incendio o incluive adaptarse a cualquier sistema de SmartHome.

## References:

All the information about the technology used, and direct references are in our wiki:

Wiki: https://github.com/altaga/Smart-Gas-Detector/wiki

Top:

* [Table of Contents](#table-of-contents)

