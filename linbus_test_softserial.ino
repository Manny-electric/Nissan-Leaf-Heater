/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

byte lin_bus = 11;
byte data[9];
byte lin_ardes = 0b01100100;// 0x26 + Parity bits;
signed int i;

SoftwareSerial mySerial(10, 11, 1); // RX, TX, inv.

void send_lin(byte adres,byte numberOfBytes, byte lin_data[]){
  byte sendByte = 0x55;
  int crc = 0;
  byte p0 , p1;
  // 1bit @ 19200 = 52.1 us
  // 1bit @ 20000 = 50.0 us
  
    // calc Parity
    p0 = (
      (adres & 1) ^
      ((adres >> 1) & 1) ^
      ((adres >> 2) & 1) ^
      ((adres >> 4) & 1)
    );

    p1 = !(
      ((adres >> 1) & 1) ^
      ((adres >> 3) & 1) ^
      ((adres >> 4) & 1) ^
      ((adres >> 5) & 1)
    );

    
    adres += (p0 << 6);
    adres += (p1 << 7);

    // calc crc
    crc = adres;
    for(i=0;i<numberOfBytes;i++){
      crc += lin_data[i];
      if(crc > 256){
        crc -= 255;
      }
    }
    crc = 0xff & (~crc); // invert crc and limmit it to 8 bits

    // send lin
    digitalWrite(lin_bus,HIGH);
    delayMicroseconds(720);
    digitalWrite(lin_bus,LOW);
    delayMicroseconds(150);
    
    mySerial.write(0x55);
    
    delayMicroseconds(80);
    mySerial.write(adres);

    for(i=0;i<numberOfBytes;i++){
      mySerial.write(lin_data[i]);
      delayMicroseconds(80);
    }
    if(numberOfBytes>0){
      mySerial.write(crc);
    }
  
}
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }


  Serial.println("Linbus!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200);
  //mySerial.println("Hello, world?");
}

void loop() {
  
  data[0]=0;
  data[1]=0;
  //data[2]=0;
  data[3]=0xC0;
  data[4]=0xFF;
  data[5]=0;
  data[6]=0;
  data[7]=0;
 
  
  send_lin(0x24,0,data);
  delay(100);
  send_lin(0x3B,8,data); // 0x3B + Parity bits
  delay(100);

  if(Serial.available()){
    data[2] = Serial.read();
  }
}
