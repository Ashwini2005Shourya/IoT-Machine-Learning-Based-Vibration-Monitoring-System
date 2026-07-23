#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
bool machineFault=false;

void setup(void) {
  Serial.begin(115200);

  while (!Serial) delay(10);

  Serial.println("Initializing MPU6050");
  
  if(!mpu.begin()){
    Serial.println("Failed to find MPU6050 chip!");
    while(1) {delay(10);}
  }
  Serial.println("MPU6050 ready!");
  // Set up baseline sensor ranges
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("System Ready. Send 'F' to simulate Fault, 'N' for Normal.");

}

void loop() {
  // Check for simulation commands from Serial Monitor
   if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'F' || cmd == 'f') {
      machineFault = true;
      Serial.println("# STATUS: SIMULATING FAULTY STATE (HIGH VIBRATION) #");
    } else if (cmd == 'N' || cmd == 'n') {
      machineFault = false;
      Serial.println("# STATUS: SIMULATING NORMAL STATE #");
    }
   }
   // Get new sensor events
   sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x;
  float ay = a.acceleration.y;
  float az = a.acceleration.z;

  // Week 2 Task: Inject synthetic mechanical noise to simulate a failing bearing/motor
  if (machineFault) {
    ax += random(-500, 500) / 100.0;
    ay += random(-500, 500) / 100.0;
    az += random(-500, 500) / 100.0;
  } else {
    // Normal ambient operational noise
    ax += random(-50, 50) / 100.0;
    ay += random(-50, 50) / 100.0;
    az += random(-50, 50) / 100.0;
  }

  // Output format structured for easy CSV data logging
  // Format: timestamp, ax, ay, az, label (0=Normal, 1=Faulty)
  Serial.print(millis());
  Serial.print(",");
  Serial.print(ax);
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.print(az);
  Serial.print(",");
  Serial.println(machineFault ? 1 : 0);

  delay(50); // Sample rate: ~20Hz

}
