#include <SPI.h>
#include <UIPEthernet.h>
//#include <ESP8266WiFi.h>
// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
char serverName[] = "mew.ezver.com.ar";
long local_time = 0;
// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
  Serial.begin(115200);
  Serial.println("inicio");
 Serial.println("inicio"); 
 Serial.println("inicio");  

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");
ñ
  // if you get a connection, report back via serial:


}

void loop()
{
  // if there are incoming bytes available 
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  if (local_time + 10000 < millis()){
    local_time = millis();
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
      client.connect(serverName, 80);
      Serial.println("connected");
    // Make a HTTP request:
    client.print(String("GET /api/post.json?apikey=cc0972e202f0aebc9e0ea327b6e19043&json={ut:"+String(millis()/60000)+"} HTTP/1.1\r\nHost: mew.ezver.com.ar\r\nConnection: close\r\n\r\n"));
 
  }else{
    client.print(String("GET /api/post.json?apikey=cc0972e202f0aebc9e0ea327b6e19043&json={ut:"+String(millis()/60000)+"} HTTP/1.1\r\nHost: mew.ezver.com.ar\r\nConnection: close\r\n\r\n"));
 
  }
//    Serial.println();
//    Serial.println("disconnecting.");
//    client.stop();

    // do nothing forevermore:
  
}
}