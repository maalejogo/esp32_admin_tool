//----------------------------------------------------------------
// Definiciones
//----------------------------------------------------------------
#define RELAY1 27           //GPIO para salida de Relay 1
#define RELAY2 26           //GPIO para salida de Relay 2
#define WIFILED 12          //GPIO LED INDICADOR WIFI
#define MQTTLED 13          //GPIO LED INDICADOR MQTT

//----------------------------------------------------------------
// Versión de Hardware
//----------------------------------------------------------------
#define HW "ADMINESP32 v1 000"          //Versión de Hardware
//----------------------------------------------------------------
//Zona configuración general
//----------------------------------------------------------------
char id[30];                 //ID del dispositivo
int bootCount;               //Número de reinicios  
//----------------------------------------------------------------
// Zona WIFI
//----------------------------------------------------------------
bool wifi_staticIP;          //Uso de Ip estática
char wifi_ssid[30];          //Red WiFi
char wifi_passw[30];      //Contraseña Red WiFi
char wifi_local_ip[15];      //IP estático
char wifi_gateway[15];       //Gateway
char wifi_subnet[15];        //subred
char wifi_primaryDNS[15];    //DNS primario
char wifi_secondaryDNS[15];  //DNS secundario
//----------------------------------------------------------------
// Zona AP
//----------------------------------------------------------------
bool ap_accessPoint;            // Uso de Modo AP
char ap_nameap[31];             // SSID AP
char ap_passwordap[63];         // SSID AP
int ap_canalap;                 // Canal AP
int ap_hiddenap;                // Es visible o no el AP (0 - Visible 1 - Oculto)
int ap_connetap;                // Npumero de conexiones en el AP   
// Zona Otras 
uint8_t ip[4];              // variable funcion convertir String a IP

