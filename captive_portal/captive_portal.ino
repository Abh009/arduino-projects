#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char * ssid = "End Game";
const char * password = "stark@space";

void setup() {
  // put your setup code here, to run once:
  pinMode( LED_BUILTIN, OUTPUT );
  
  digitalWrite( LED_BUILTIN, LOW );
  
  Serial.begin(9600);
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

  sendInitialRequest();

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite( LED_BUILTIN, HIGH );
  while( WiFi.status() == WL_CONNECTED ){
    sendInitialRequest();
    delay( 15000 );
  }
  Serial.println( "Disconnected..." );
  digitalWrite( LED_BUILTIN, LOW );
  
  setup();
  Serial.println( "Connected..." );
  
}

void sendInitialRequest(){
  HTTPClient http;
  http.begin( "http://172.16.16.16:8090/httpclient.html" );
  
  http.addHeader( "Content-Type", "text/plain" );
  http.addHeader( "Origin", "http://172.16.16.16:8090" );
  http.addHeader( "Accept-Encoding", "gzip, deflate" );
  http.addHeader( "Accept-Language", "en-US,en;q=0.9,hi-IN;q=0.8,hi;q=0.7,ml;q=0.6,la;q=0.5" );
  http.addHeader( "User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36" );
  http.addHeader( "Content-Type", "application/x-www-form-urlencoded" );
  http.addHeader( "Accept", "*/*" );
  http.addHeader( "Referer", "http://172.16.16.16:8090/httpclient.html" );
  http.addHeader( "Connection", "keep-alive" );
  http.addHeader( "DNT", "1" );
  

  int httpCode = http.POST( "mode=191&username=b14cs153&password=hello6e3&a=1518195542915&producttype=0" );
  String payload = http.getString();
  
  http.end();
  digitalWrite( LED_BUILTIN, LOW );
  Serial.println( "request send" );
}

void sendContinuosRequest(){
  HTTPClient http;
  http.begin( "http://172.16.16.16:8090/live?mode=192&username=b14cs153&a=1539020161001&producttype=0" );

  http.addHeader( "DNT", "1" );
  http.addHeader( "Accept-Encoding", "gzip, deflate" );
  http.addHeader( "Accept-Language", "en-US,en;q=0.9,hi-IN;q=0.8,hi;q=0.7,ml;q=0.6,la;q=0.5" );
  http.addHeader( "User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36" );
  http.addHeader( "Accept", "*/*" );
  http.addHeader( "Referer", "http://172.16.16.16:8090/httpclient.html" );
  http.addHeader( "Connection", "keep-alive" );  

  String payload = http.getString();
  
  http.end();
  digitalWrite( LED_BUILTIN, LOW );
  Serial.println( "request send" );
}
