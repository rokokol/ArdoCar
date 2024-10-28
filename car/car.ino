#include <NecDecoder.h>
#include <GyverMotor.h>

#define ulong unsigned long

#define IR_SENSOR_PIN 2 
#define LEFT_MOTOR_A 5
#define LEFT_MOTOR_B 4
#define RIGHT_MOTOR_A 6
#define RIGHT_MOTOR_B 7


NecDecoder ir;
GMotor motorL(DRIVER2WIRE, LEFT_MOTOR_A, LEFT_MOTOR_B, HIGH);
GMotor motorR(DRIVER2WIRE, RIGHT_MOTOR_A, RIGHT_MOTOR_B, HIGH);

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, ir_isr, FALLING);
}

void ir_isr() {
  ir.tick();
}

void loop() {
  nec_control_tick();
  motors_tick();
}