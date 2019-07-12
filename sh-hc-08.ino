#include <SoftwareSerial.h>

#define RxD 10
#define TxD 11
#define throttlePin 13
#define collectivePin 12
#define rudderPin 8

// Set the Transmit and Receive pins for a SoftwareSerial class object.
//SoftwareSerial BTSerial( RxD, TxD ); // Recive (RxD), Transmit (TxD)

void setup()
{
  pinMode( throttlePin, OUTPUT );
  pinMode( collectivePin, OUTPUT );
  pinMode( rudderPin, OUTPUT );
  pinMode( RxD, INPUT );
  pinMode( TxD, OUTPUT );
  // Begin communicating with the SoftwareSerial object.
  //  BTSerial.begin( 9600 );
}

void loop()
{
  char servoPrefix;
  byte servoValue;

  // Read from the SoftwareSerial object.
  if ( Serial.available() > 0 )
  {
    // Get the servo prefix ('t', 'c', 'r') so we know if this is for the throttle, collective, or rudder.
    servoPrefix = Serial.read();
    // Read one byte (0-255) into servoValue.
    servoValue = Serial.read();

    // Set the throttle LED.
    if ( servoPrefix == 't' )
    {
      if ( servoValue > 127 )
      {
        digitalWrite( throttlePin, HIGH );
      }
      else if ( servoValue < 128 )
      {
        digitalWrite( throttlePin, LOW );
      }
    }
    // Set the collective LED.
    if ( servoPrefix == 'c' )
    {
      if ( servoValue > 127 )
      {
        digitalWrite( collectivePin, HIGH );
      }
      else if ( servoValue < 128 )
      {
        digitalWrite( collectivePin, LOW );
      }
    }
    // Set the rudder LED.
    if ( servoPrefix == 'r' )
    {
      if ( servoValue > 127 )
      {
        digitalWrite( rudderPin, HIGH );
      }
      else if ( servoValue < 128 )
      {
        digitalWrite( rudderPin, LOW );
      }
    }
  }
  delay( 1000 );
}
