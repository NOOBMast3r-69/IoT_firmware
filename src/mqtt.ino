#include <PubSubClient.h>

#define broker  "broker.hivemq.com"
#define MQTT_PORT       1883


String mqttWill;
String mqttTopic;
void mqttSetup(){
  mqtt.setClient(client);
  mqttTopic.reserve(30);
  mqttConfigure();
  mqtt.setServer(broker, MQTT_PORT);
  mqtt.setCallback(mqttCallback);
}
boolean mqttConnect() {
    DEBUG_PORT.print("Connecting to ");
    DEBUG_PORT.print(broker);

    if (!mqtt.connect("motor", , mqttPass,(const char *)MotorInit, 1, true, "0")) {
        return false;
  }

  mqtt.publish((const char *)"HYP/Testing", "1", true);
  mqtt.subscribe((const char *)"HYP/comm");
  return mqtt.connected();
}
void mqttSubscriberaw(const char* topic, int QOS){
  if(mqtt.connected() && strlen(topic) > 0){
    mqtt.subscribe(topic,QOS);
  }
}
void mqttpub(String Topic,String data){
    mqtt.publish((Topic.c_str(),data.c_str());
}
void mqttUnsubscribeRaw(const char * topic){
  if (mqtt.connected() && (strlen(topic) > 0)) {
    mqtt.unsubscribe(topic);
}
}

void mqttCallback(char* topic, byte* payload, unsigned int len) {
   DEBUG_PORT.print("Message arrived [");
   DEBUG_PORT.print(topic);
   DEBUG_PORT.print("]: ");
   DEBUG_PORT.write(payload, len);
   DEBUG_PORT.println();
 }
