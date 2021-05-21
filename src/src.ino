#define TINY_GSM_MODEM_EC20
#include <TinyGsmClient.h>
HardwareSerial NETWORK_PORT(PA3, PA2);
HardwareSerial DEBUG_PORT(PA10, PA9);
TinyGsm Module(NETWORK_PORT);
TinyGsmClient client(Module);

void setup(){
    NETWORK_PORT.begin(115200);
    DEBUG_PORT.begin(115200);
    ec20Setup();
    gpsSetup();
    mqttSetup();
}
void loop(){
    ec20Loop();
    gpsLoop();
}