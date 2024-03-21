Nissan Leaf PTC heater

Connections
https://github.com/Manny-electric/Nissan-Leaf-Heater/blob/main/aansluitingen.jpg

LV:
	1: batt pos. (+12V)
	2: nc
	3: batt neg.(GND)
	4: LIN bus
	5: nc
 
HV:
The HV connector uses an interlock detention. So the two small pins need to be shorted together.
The LNK304GN is used as a buck converter to generate 16V.
Using a multimeter on the diode setting, the HV input will show open in the correct polarity and 1.5V is the wrong polarity.


LIN bus:
The heater problely uses mlx80031/51 LIN bus transceiver. 

Data master to heater:
0x3B	0x00	  0x00	  0x64	  0xC0	  0xFF	  0x00	  0x00	  0x00    0xDE
adres	byte 1	byte 2	byte 3	byte 4	byte 5	byte 6	byte 7	byte 8	CRC
byte 3: The precentage of power 0-100.

Data reading from the heater.
0x24	0x00	  0x48	  0xFE	  0xFF	  0x54
adres	byte 1	byte 2	byte 3	byte 4	CRC

byte 1: errors
byte 2: HV Current (0,2A/bit)



PCB
https://github.com/Manny-electric/Nissan-Leaf-Heater/blob/main/aansluitingen_pcb.jpg
 
1: batt neg.(GND)
2: LIN bus
3: batt pos. (+12V)
A & B: HV interlock
+ & -: High voltage
 
Red : 	2 ptc’s 700W (1)
Yellow : 2 ptc’s 700W (2)
Bleu :	4 ptc’s 1400W (3)
Purple : 7 ptc’s 2450W (4)
Black : common connection (+350V)




