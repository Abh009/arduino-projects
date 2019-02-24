#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

char * ssid = "No Internet";
char * password = "valarmorghulis";

ESP8266WebServer server(80);

String page = "";


void setup() {
  // put your setup code here, to run once:
  page = "<h1>Simple Web Server <br> <small> ESP8266 </small> </h1><br> <a href=\"/turnon\"> Turn On LED</a> <br> <a href=\"/turnoff\"> Turn Off LED</a>";
  pinMode( LED_BUILTIN, OUTPUT );

  digitalWrite( LED_BUILTIN, LOW );

  Serial.begin( 9600 );

  WiFi.begin( ssid, password );

  while( WiFi.status() != WL_CONNECTED ){
    delay( 500 );
    digitalWrite( LED_BUILTIN, HIGH );
    delay( 500 );
    digitalWrite( LED_BUILTIN, LOW );
  }

  Serial.print( "Server running on port 80 of " );
  Serial.println( WiFi.localIP() );

  

  server.on( "/", [](){
    server.send( 200, "text/html", page );
  });

  server.on( "/turnon", [](){
    digitalWrite( LED_BUILTIN, LOW );
    server.send( 200, "text/html", "<h1>LED turned on ! <br> <a href=\"/\"> Back to Home </a> </h1>" );
  });

  server.on( "/turnoff", [](){
    digitalWrite( LED_BUILTIN, HIGH );
    server.send( 200, "text/html", "<h1>LED turned off ! <br> <a href=\"/\"> Back to Home </a> </h1>" );
  });

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();

}
