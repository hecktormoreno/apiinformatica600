//archivo escrito para propositos educativos
//ing informatica
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "INFINITUM46EC";
const char* password = "kt9xAksmQ3";
const char* serverUrl = "http://192.168.1.69/archivo/index.php";

void setup() {
  Serial.begin(115200);
  delay(4000);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando al WiFi...");
  }

  Serial.println("Conectado al WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Datos que deseas enviar
    String data = "dato1=valor1&dato2=valor2";

    int httpResponseCode = http.POST(data);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error en la petición HTTP: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }

  delay(5000); // Espera 5 segundos antes de enviar datos nuevamente
}
