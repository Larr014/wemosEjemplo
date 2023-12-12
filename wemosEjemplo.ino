




#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
//#include <WiFiClient.h> //usar si es protocolo http
#include <WiFiClientSecure.h> //usar si es protocolo https
#define WIFI_SSID "RN5g" //Nombre red wifi
#define WIFI_PASSWORD "pass1234" //Pass red wifi

void setup() {
  Serial.begin(115200);


  // Conectar a la red WiFi
  Serial.println();
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP());
  //Desde aca incorpora tus sentencias
}

void loop() {
  
  if (WiFi.status() == WL_CONNECTED) {
     WiFiClientSecure client;
    HTTPClient https;  //Declare an object of class HTTPClient
    client.setInsecure(); // Ignore SSL certificate errors

  //Modifica esta seccion para interactuar con el servidor o servicio que desees
  //<Desde ACA1>
    
    https.begin(client, "https://larr.cl/larr.cl/sensoresApp/registrar.php");
   // https.addHeader("Content-Type", "application/json");
    https.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpCode = https.POST(httpRequestData);
    //int httpCode = https.GET();
    Serial.println(httpCode);
    if (httpCode > 0) {
      String response = https.getString();
      Serial.println(httpCode);
      Serial.println(response);
    } else {
      Serial.println("Error en la petición POST");
    }

    https.end();
    
  }

  delay(10000);
  //<Hasta ACA1>
}
