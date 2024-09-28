/*----------------------------------------------------------------
*AdminESP - maalejogoIOT 2024
*Correo: maalejogo@gmail.com
*Plataforma ESP32
*proyecto Admin Panel Tool para el ESp32
*-----------------------------------------------------------------
*/

//----------------------------------------------------------------
// Leer configuraciones de los parámetros WIFI
//----------------------------------------------------------------
bool settingsReadWiFi(){
    //StaticJsonDocument<500> jsonConfig;
    JsonDocument jsonConfig;
    File file = SPIFFS.open("/SettingWifi.json", "r");
    if(deserializeJson(jsonConfig,file)){
        // Si falla la lectura inicia valores por defecto
        settingResetWifi();
        log("Error: Falló la lectura de la configuración WiFi, tomando valores por defecto");
        return false;
    }else{
        /*---------------GENERAL-----------------*/
        strlcpy(id, jsonConfig["id"], sizeof(id));
        bootCount = jsonConfig["boot"];
        /*---------------CLIENTE-----------------*/
        bootCount = jsonConfig["boot"];
        wifi_staticIP = jsonConfig["wifi_staticIP"];
        strlcpy(wifi_ssid, jsonConfig["wifi_ssid"], sizeof(wifi_ssid));
        strlcpy(wifi_passw, jsonConfig["wifi_passw"], sizeof(wifi_passw));      //Contraseña Red WiFi
        strlcpy(wifi_local_ip, jsonConfig["wifi_local_ip"], sizeof(wifi_local_ip));      //IP estático
        strlcpy(wifi_gateway, jsonConfig["wifi_gateway"], sizeof(wifi_gateway));       //Gateway
        strlcpy(wifi_subnet, jsonConfig["wifi_subnet"], sizeof(wifi_subnet));        //subred
        strlcpy(wifi_primaryDNS, jsonConfig["wifi_primaryDNS"], sizeof(wifi_primaryDNS));    //DNS primario
        strlcpy(wifi_secondaryDNS, jsonConfig["wifi_secondaryDNS"], sizeof(wifi_secondaryDNS));  //DNS secundario
        /*----------------AP-------------------*/
        ap_accessPoint = jsonConfig["ap_accessPoint"];            // Uso de Modo AP
        strlcpy(ap_nameap, jsonConfig[ap_nameap], sizeof(ap_nameap));             // SSID AP
        strlcpy(ap_passwordap, jsonConfig[ap_passwordap], sizeof(ap_passwordap));         // SSID AP
        ap_canalap = jsonConfig[ap_canalap];                 // Canal AP
        ap_hiddenap = jsonConfig[ap_hiddenap];                // Es visible o no el AP (0 - Visible 1 - Oculto)
        ap_connetap = jsonConfig[ap_connetap];
        file.close();
        log("Info: lectura configuración WiFi correcta");
        return true;
    }

}