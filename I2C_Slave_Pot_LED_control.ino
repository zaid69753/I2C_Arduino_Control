// 2nd part of 
// Pot controlling LED 
// Programming for Slave

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Define LED Pin
int LED = 13;

// Variable for received data
int rd;

// Variable for blink rate
int br;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);

  // Initialize I2C communication as Slave
  Wire.begin(SLAVE_ADDR);

  // Function to run when data received from Master
  Wire.onReceive(receiveEvent);

  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}

void receiveEvent() {
  // read on character from the I2C
  rd = Wire.read(); // value from 1 to 255 and assining this value to variable "rd"
  //Print value of incoming data to Serial monitor
  Serial.println(rd);
}



void loop() {
  // put your main code here, to run repeatedly:
  delay(50);

  // Calculate blink value
  br = map(rd, 1, 255, 100, 2000); // blink rate will be from 100 milli seconds to 2000 milli seconds between the flashes of the LED

  digitalWrite(LED, HIGH);
  delay(br);
  digitalWrite(LED, LOW);
  delay(br);

}
