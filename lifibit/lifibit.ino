
int led = 2;

int sensorLed = 0;

int currentBit = 0;

int interval = 50;

void setup() {                
  Serial.begin(9600);
  pinMode(led, OUTPUT);     
}

void loop() {
  currentBit = !currentBit;
  
  sendBit(led, currentBit);
  
  delay(interval);
  
  int reading = readBit(sensorLed);
  
  compareValues(currentBit, reading);
}

int sendBit(int pin, int binaryValue)
{
  Serial.print("Sending: ");
  Serial.println(binaryValue);
  
  digitalWrite(pin, binaryValue);
}

int readBit(int pin)
{
  int reading = analogRead(pin);
 
  int output; 

  if (reading > (1023/2))
    output = 1;
  else
    output = 0;

  Serial.print("Reading: ");
  Serial.println(output);
        
  return output;
}

void compareValues(int sentBit, int receivedBit)
{
  if (sentBit == receivedBit)
    Serial.println("Transmission successful!");
  else  
    Serial.println("Transmission failed!");
}
