# EMERGENCY ALERT AND NOTIFICATION SYSTEM USING GPS AND GSM

## Abstract:

   In today's trend as usage of vehicle is increasing drastically,the hazards due to vehicles is also increased which often results in accidents.Most of the casualities from accidents are due to poor communication to the concerned agencies and late arrival of medical assistance.This introduces an emergency alert and accident detection usin GPS and GSM which alerts the person who is driving the vehicle.The hardware components such as GPS,LED,Ultrasonic sensor,Accelerometer along with Vibration sensor are given as inputs to arduino and the output is displayed in LCD which is placed as if it is visible to person driving the vehicle.
   
   Initially vibration in the three axes(x,y,z) is displayed in the LCD with the help of accelerometer as analog voltage values.By measuring the acceleration due to gravity,accelerometer can figure out the angle it is tilted at with respect to the earth.While driving in hairpin bend and in the normal roads ultrasonic sensor helps in alerting the driver about the vehicle coming from the other side.And when the high vibration is sensed i.e when accident has occurred the GSM gets initialized and the message is sent to the programmed contact users which includes family members,hospital and police station with location stating that the accident has occured. 

## Requirements:

### High Level Requirements:

HLR01-Alerting the driver about the vehicle coming from the other side.

HLR02-Message should be sent to the hospital,police or family after the accident occured.

HLR03-Location of the accident should be shared with family,hospital and police.

### Low Level Requirements:

LLR01-Automatic reduction in the speed of the vehicle.

LLR02-Alarm sound can be enabled.

## SWOT Analysis:

### Strengthness:

Fast recovery of the person who is involved in the accident.

### Weakness:

Additional power supply is required.

### Opportunities:

Can be used in all the automobiles.

### Threats:

Low battery can be occured if all the circuits are connected to the bike battery.

## 5W and 1H

What-Emergency alert and notification system using GPS and GSM.

Where-Automobiles.

Who-Person who drives the vehicle.

When-During accidents.

Why-To avoid accidents and fast recovery of people after the accident.

How-Alerting the driver and sending messages to hospital,police and family.

## Components:

1.Arduino Uno ATmega328p-Open source microcontroller.

2.LCD--->To display.

3.Accelerometer--->It measures the angle tilted with respect to the earth.

4.GSM--->Used to control and monitor the transformer by sending a message.

5.GPS--->Used for tracking and navigation.

6.Vibration sensor--->Used to detect the vibrations from various means.

7.Ultra sonic sensor--->To measure the distance of a targeted objects.

8.LED--->Used for indication.

## Future Scope

1.The system can be connected to the drivers medical record and that can be sent along with the accident notification,which helps in better and faster treatment.

2.A renewable energy source can be used in place of connecting the prototype to a power source.
