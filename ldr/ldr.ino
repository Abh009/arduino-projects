int sensorPin_ldr1 = A0;
int sensorPin_ldr2 = A1;
int sensorValue_ldr1 = 0;
int sensorValue_ldr2 = 0;


int going_in = 0;
int going_out = 0;
int people_inside = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode( LED_BUILTIN, OUTPUT ); 
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue_ldr1 = analogRead(sensorPin_ldr2); 
   sensorValue_ldr2 = analogRead(sensorPin_ldr2); 

  if( sensorValue_ldr1 == 0 && sensorValue_ldr2 != 0 ){
    if( !going_out )
      going_in = 1; 
    else{
      people_inside -= 1;   // person passed out
      going_in = 0;
      going_out = 0;
    }
  }
  else if( sensorValue_ldr2 != 0 && sensorValue_ldr1 == 0 ){
    if( ! going_in ){
      going_out = 1;
    }
    else{ 
      people_inside += 1;
      going_in = 0;
      going_out = 0;} // person passed in
  }

  if( people_inside > 0 ){
    // turn on lights
    digitalWrite( LED_BUILTIN, HIGH );
  }
  
  Serial.println(sensorValue_ldr1);
  delay(10);
}
