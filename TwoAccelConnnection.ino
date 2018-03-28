#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

const int MPU1_addr = 0x68;
const int MPU2_addr = 0x69;

int16_t AcXW, AcYW, AcZW;
int16_t AcXF, AcYF, AcZF;


void setup() {
  Serial.print("this line");
  Wire.begin();
  Wire.beginTransmission(MPU1_addr);
  Wire.beginTransmission(MPU2_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  Serial.print("***********************Beginning Transmission******************");

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU1_addr);
  Wire.write(0x3B);
  Wire.beginTransmission(MPU2_addr);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU1_addr, 8, true); 

    AcXW = Wire.read() << 8 | Wire.read();
    AcYW = Wire.read() << 8 | Wire.read();
    AcZW = Wire.read() << 8 | Wire.read();

//  Wire.requestFrom(MPU2_addr, 8, true);

    AcXF = Wire.read() << 8 | Wire.read();
    AcYF = Wire.read() << 8 | Wire.read();
    AcZF = Wire.read() << 8 | Wire.read();

  Serial.print("AcXW = "); Serial.println(AcXW);
  Serial.print("AcYW = "); Serial.println(AcYW);
  Serial.print("AcZW = "); Serial.println(AcZW);
  Serial.print("AcXF = "); Serial.println(AcXF);
  Serial.print("AcYF = "); Serial.println(AcYF);
  Serial.print("AcZF = "); Serial.println(AcZF);

  delay(100);
}
