//MAX485 TTL To RS485 >> VCC >> +5V or +3.3V of Arduino Nano
//MAX485 TTL To RS485 >> GND >> GND of Arduino Nano
//MAX485 TTL To RS485 >> RO >> GPIO10 of Arduino Nano (SoftwareSerial RX)
//MAX485 TTL To RS485 >> DI >> GPIO11 of Arduino Nano (SoftwareSerial TX)
//MAX485 TTL To RS485 >> RE >> GPIO9 of Arduino Nano
//MAX485 TTL To RS485 >> DE >> GPIO9 of Arduino Nano

#include <SoftwareSerial.h>
#define RX        26    //Serial Receive pin
#define TX        27    //Serial Transmit pin
#define RTS_pin    33    //RS485 Direction control

#define RS485Transmit    HIGH
#define RS485Receive     LOW
//const char* fs_request[] = {"~20004642E00200FD37\r"};

SoftwareSerial RS485Serial(RX, TX);

void setup() {
  pinMode(RTS_pin, OUTPUT);  
  Serial.begin(19200);
  Serial.println("RS-FS-N01"); 
  RS485Serial.begin(19200);
  delay(1000);
}

void loop() {
  digitalWrite(RTS_pin, RS485Transmit);

  byte fs_request[] =  {0x7E,0x32,0x30,0x30,0x30,0x34,0x36,0x34,0x32,0x45,0x30,0x30,0x32,0x30,0x30,0x46,0x44,0x33,0x37,0x0D};
    
  RS485Serial.write(fs_request, sizeof(fs_request));
  RS485Serial.flush();
   RS485Serial.flush();
  digitalWrite(RTS_pin, RS485Receive);
  byte fs_buf[75];
  RS485Serial.readBytes(fs_buf, 75);
  for(int i=0 ;i<75;i++){
    
  
  Serial.print(fs_buf[i],HEX);
  Serial.print(" ");             
  delay(100);
    }
      Serial.println(" "); 
      //memset(fs_buf, 0, sizeof(fs_buf));
            

  
}
