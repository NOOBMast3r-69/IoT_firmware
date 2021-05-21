#define apn  "airtelgprs.com"
#define user ""
#define pass ""
void ec20Setup(){
      if (!Module.waitForNetwork()) {
        while (true);
  }
     DEBUG_PORT.println(" OK");
   DEBUG_PORT.print("Connecting to ");
   DEBUG_PORT.print(apn);
     if (!Module.gprsConnect(apn, user, pass)) {
    DEBUG_PORT.println(" fail");
    while (true);
  }
}
void ec20Loop(){
    Module.networkLoop();
}