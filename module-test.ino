#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];
#define CAN0_INT 6
MCP_CAN CAN0(A0);   

byte zero[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte one[8] = {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte two[8] = {0x00, 0x00, 0xFF, 0x20, 0x72, 0x06, 0x75, 0x90};
byte three[3] = {0x03,0x04,0x00};
byte four[8] = {0x45, 0x00, 0x00, 0x02, 0xCF, 0x82, 0x00, 0x00};


void setup(){
    delay(3000);
    Serial.begin(115200);
    if(CAN0.begin(MCP_ANY, CAN_125KBPS, MCP_8MHZ) == CAN_OK) Serial.println("MCP2515 CAN0 Initialized Successfully!");
    else Serial.println("Error Initializing MCP2515 CAN0...");
    CAN0.setMode(MCP_NORMAL);
    delay(1000);
}

void loop(){
    byte sndStat = CAN0.sendMsgBuf(0x124, 0, 8, zero);
    if(sndStat == CAN_OK) Serial.println("Message Sent Successfully!");
    else Serial.println("Error Sending Message...");

    sndStat = CAN0.sendMsgBuf(0x3A0, 0, 8, four);
    if(sndStat == CAN_OK) Serial.println("Message Sent Successfully!");
    else Serial.println("Error Sending Message...");

    sndStat = CAN0.sendMsgBuf(0x3E7, 0, 8, zero);
    if(sndStat == CAN_OK) Serial.println("Message Sent Successfully!");
    else Serial.println("Error Sending Message...");
    
    sndStat = CAN0.sendMsgBuf(0x35E, 0, 8, one);
    if(sndStat == CAN_OK) Serial.println("Message Sent Successfully!");
    else Serial.println("Error Sending Message...");

    sndStat = CAN0.sendMsgBuf(0x41A, 0, 8, two);
    if(sndStat == CAN_OK) Serial.println("Message Sent Successfully!");
    else Serial.println("Error Sending Message...");

    sndStat = CAN0.sendMsgBuf(0x503, 0, 3, three);
    if(sndStat == CAN_OK) Serial.println("Message Sent Successfully!");
    else Serial.println("Error Sending Message...");
    delay(500);
}