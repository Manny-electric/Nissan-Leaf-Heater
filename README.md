Nissan Leaf PTC heater

Connections
![alt text](https://github.com/Manny-electric/Nissan-Leaf-Heater/blob/main/aansluitingen.jpg?raw=true)

LV:
1. batt pos. (+12V)
2. nc
3. batt neg. (GND)
4. LIN bus
5. nc

HV:  
The HV connector uses an interlock. So the two small pins need to be shorted together.  
The LNK304GN is used as a buck converter to generate 16V.  
Using a multimeter on the diode setting, the HV input will show open in the correct polarity and 1.5V is the wrong polarity.  

LIN bus:  
The heater problely uses mlx80031/51 LIN bus transceiver. <br /> <br />

Data master to heater:  
|adres | byte 1 | byte 2 | byte 3 | byte 4 | byte 5 | byte 6 | byte 7 | byte 8 | CRC
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---:  
| 0x3B | 0x00 | 0x00 | 0x64 | 0xC0 | 0xFF | 0x00 | 0x00 | 0x00 | 0xDE

byte 3: The precentage of power 0-100.  
<br />
<br />
Data reading from the heater:  
| adres	| byte 1 | byte 2 | byte 3 | byte 4 | CRC
| :---: | :---: | :---: | :---: | :---: |  :---: 
| 0x24 | 0x00 | 0x48 | 0xFE | 0xFF | 0x54

byte 1: errors     
byte 2: HV Current (0,2A/bit)  

PCB
![alt text](https://github.com/Manny-electric/Nissan-Leaf-Heater/blob/main/aansluitingen_pcb.jpg?raw=true)
 
1: batt neg.(GND)<br />
2: LIN bus<br />
3: batt pos. (+12V)<br />
<br />
A: HV interlock<br />
B: HV interlock  <br />
\+ & \- High voltage<br />

![alt text](https://github.com/Manny-electric/Nissan-Leaf-Heater/blob/main/PTC.png?raw=true)
 
Red: 	2 ptc’s 700W (1)<br />
Yellow: 2 ptc’s 700W (2)<br />
Bleu:	4 ptc’s 1400W (3)<br />
Purple: 7 ptc’s 2450W (4)<br />
Black: common connection (+350V)




