/*----------------------------------------------------------------
*AdminESP - maalejogoIOT 2024
*Correo: maalejogo@gmail.com
*Plataforma ESP32
*proyecto Admin Panel Tool para el ESp32
*-----------------------------------------------------------------
*/

void settingResetWifi(){
/*---------------GENERAL-----------------*/
        strlcpy(id, "adminesp32", sizeof(id));
        bootCount = 0;
        /*---------------CLIENTE-----------------*/
        wifi_staticIP = false;
        strlcpy(wifi_ssid, "ALEXA", sizeof(wifi_ssid));
        strlcpy(wifi_passw, "Luig452*", sizeof(wifi_passw));      //Contraseña Red WiFi
        strlcpy(wifi_local_ip, "192.168.0.37", sizeof(wifi_local_ip));      //IP estático
        strlcpy(wifi_gateway, "192.168.0.1", sizeof(wifi_gateway));       //Gateway
        strlcpy(wifi_subnet, "255.255.255.0", sizeof(wifi_subnet));        //subred
        strlcpy(wifi_primaryDNS, "8.8.8.8", sizeof(wifi_primaryDNS));    //DNS primario
        strlcpy(wifi_secondaryDNS, "8.8.4.4", sizeof(wifi_secondaryDNS));  //DNS secundario
        /*----------------AP-------------------*/
        ap_accessPoint = false;            // Uso de Modo AP
        strlcpy(ap_nameap, deviceID().c_str(), sizeof(ap_nameap));             // SSID AP
        strlcpy(ap_passwordap, "admin", sizeof(ap_passwordap));         // SSID AP
        ap_canalap = 9;                 // Canal AP
        ap_hiddenap = false;                // Es visible o no el AP (0 - Visible 1 - Oculto)
        ap_connetap = 4;
}