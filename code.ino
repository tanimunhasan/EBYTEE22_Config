#include <SoftwareSerial.h>
#include <EBYTE22.h>
#define PIN_TX 2
#define PIN_RX 3
#define PIN_M0 4
#define PIN_M1 5
#define PIN_AX 6

SoftwareSerial E22Serial(PIN_TX, PIN_RX, false);

EBYTE22 E22(&E22Serial, PIN_M0, PIN_M1, PIN_AX);

void setup() {
  Serial.begin(9600);
  E22Serial.begin(9600);
  Serial.println("Starting Sender");
  delay(200);

  if (E22.init())
  {
    Serial.println("init OK");
  } else {
    Serial.println("init Error");
  }

  E22.setMode(MODE_NORMAL);

  E22.setAddressH(0x00);
  E22.setAddressL(0x00);
  E22.setAddress(0x00);

  E22.setNetID(0x00);
  E22.setUARTBaudRate(UBR_9600);
  E22.setParityBit(PB_8N1);
  E22.setAirDataRate(ADR_2400);
  E22.setPacketLength(PACKET240);
  E22.setRSSIAmbient(RSSI_ENABLE);
  E22.setTransmitPower(TP_LOW);
  E22.setChannel(23);
  E22.setRSSInPacket(RSSI_DISABLE);
  E22.setTranmissionMode(TXM_NORMAL);
  E22.setRepeater(REPEATER_DISABLE);
  E22.setLBT(LBT_DISABLE);
  E22.setWOR(WOR_TRANSMITTER);
  E22.setWORCycle(WOR2000);
  E22.writeSettings(TEMPORARY);
  E22.writeCryptKey(0x0000, TEMPORARY);

}

void loop() {
  bool settingsOK = true;

  if (E22.getMode() != MODE_NORMAL) {
    settingsOK = false
  };
  if (E22.getAddressH() != 0x00) {
    settingsOK = false;
  }
  if (E22.getAddressL() != 0x00) {
    settingsOK = false;
  }
  if (E22.getNetID() != 0x00) {
    settingsOK = false;
  }
  if (E22.getUARTBaudRate() != UBR_9600) {
    settingsOK = false;
  }
  if (E22.getParityBit() != PB_8N1) {
    settingsOK = false;
  }
  if (E22.getAirDataRate() != ADR 2400) {
settingsOK = false:
  }
  if (E22.getRSSIAmbient() != RSSI_ENABLE) {
    settingsOK = false;
  }
  if (E22.getTransmitterPower() != TP_LOW) {
    settingsOK = false;
  }
  if (E22.getChannel() != 23) {
    settingsOK = false;
  }
  if (E22.getRSSIInPacket() != RSSI_DISABLE) {
    settingsOK = false;
  }
  if (E22.getTransmissionMode() != TXM_NORMAL) {
    settingsOK = false;
  }
  if (E22.getRepeater() != REPEATER_DISABLE) {
    settingsOK = false;
  }
  if (E22.getLBT() != LBT_DISABLE) {
    settingsOK = false;
  }
  if (E22.getWOR() != WOR TRANSMITTER) {
    settingsOK = false;
  }
}
