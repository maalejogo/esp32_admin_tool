/*----------------------------------------------------------------
*AdminESP - maalejogoIOT 2024
*Correo: maalejogo@gmail.com
*Plataforma ESP32
*proyecto Admin Panel Tool para el ESp32
*-----------------------------------------------------------------
*/

//----------------------------------------------------------------
// Librerias
//----------------------------------------------------------------
#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

//----------------------------------------------------------------
// archivos *.hpp - Fragmentar el Código
//----------------------------------------------------------------
#include "settings.hpp"
#include "functions.hpp"
#include "settingsReset.hpp"
#include "settingsRead.hpp"
#include "settingsSave.hpp"
#include "esp32_wifi.hpp"


//----------------------------------------------------------------
// Setup
//----------------------------------------------------------------
void setup() {
  //Baudrate
  Serial.begin(115200);
  //CPU Freq
  setCpuFrequencyMhz(240);
  //Inicio del Log por serial
  log("\nInfo: IniciandoSetup");
  //Configurar los Pines
  settingPines();
  //Inicio del SPIFFS
  if (!SPIFFS.begin (true)){
    log(F("Error: Fallo la inicializacion del SPFFS"));
    while (true);
  }
  log("inicializacion wifi");
  //Lee la configuración WiFi
  settingsReadWiFi();
  WiFi.disconnect(true);
  delay(1000);
  // Setup del WiFi
  wifi_setup();

}
//----------------------------------------------------------------
// Loop Principal Nucleo 0 
//----------------------------------------------------------------
void loop() {
  yield();
  //----------------------------------------------------------------
  // Loop Principal Nucleo 0 
  //----------------------------------------------------------------
  if(wifi_mode == WIFI_STA){
    wifiLoop();
  }
  if(wifi_mode == WIFI_AP){
    wifiAPLoop();
  }
}

