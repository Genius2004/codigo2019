//#VERSION: 1.0
/*######################################################################################################################
  ###  PROYECTO:              Encuentrame                                                                            ###
  ###                                                                                                                ###
  ###  DESARROLLADORES:       Gudelia Hernández Molina         GHM                                                   ###
  ###  FECHA DE INICIO:       Viernes 26, octubre del 2019                                                           ###
  ###                                                                                                                ###
  ######################################################################################################################
   VERSION:
    V.1.00      (20191025 -         ) GHM: Primera Versión

   CAMBIOS:
    V.1.0.X    (1910XX)  GHM:

    Requerimientos:
    1. Conexión a la BD
   
######################################################################################################################*/

//Bibliotecas
#include <UnoWiFiDevEd.h>
#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

//Conexion Internet
#define WIFI_SSID "CECUNAM"
#define WIFI_PASSWORD "Ch0c0l$t3"

//Conexión Firebase
#define FIREBASE_HOST "sistema-encuentrame.firebaseio.com/"; 
#define FIREBASE_AUTH "skr6RP3BOKm2IHS0TyyxeO6sOooHn9cGHTIR3TcU";

void setup() {
   //Conexión a Internet
   Serial.begin(9600);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   Serial.print(".");
   while (Wifi.status[] !=  WL_CONNECTED)
   {
      Serial.print(".");
      delay(500);
   }
   Serial.println();
   Serial.print("Se ha conectado con la IP: ");
   Serial.println(WiFi.localIP());

   //Conexion a Firebase
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
}
