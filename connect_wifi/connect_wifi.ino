#include <ESP8266WiFi.h>

const char * ssid = "No Internet";
const char * password = "valarmorghulis";

void setup() {
  // put your setup code here, to run once:
  pinMode( LED_BUILTIN, OUTPUT );
  
  digitalWrite( LED_BUILTIN, LOW );
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin( ssid, password );

  Serial.println();
  Serial.println( "Connecting...." );

  while( WiFi.status() != WL_CONNECTED ){
    delay( 100 );
    digitalWrite( LED_BUILTIN, LOW );
    delay( 100 );
    digitalWrite( LED_BUILTIN, HIGH );
  }

  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

}

void loop() {
  // put your main code here, to run repeatedly:
  while( WiFi.status() == WL_CONNECTED ){
    delay( 1500 );
    digitalWrite( LED_BUILTIN, LOW );
    delay( 1500 );
    digitalWrite( LED_BUILTIN, HIGH );
  }
  Serial.println( "Disconnected..." );
  setup();
  Serial.println( "Connected..." );

}
