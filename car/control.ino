// IR BLOCK
#define FORWARD_SIG 0x18
#define BACKWARD_SIG 0x4A
#define LEFT_SIG 0x10
#define RIGHT_SIG 0x5A
#define OK_SIG 0x38
// IR BLOCK

ulong motor_tick_time = 0;
int motor_tick_duration = 50;

void nec_control_tick() {
  if (ir.available()) {
    switch (ir.readCommand()) {
      case FORWARD_SIG: forward(100, 150); break;
      case BACKWARD_SIG: backward(50, 150); break;
      case LEFT_SIG: left(50, 150); break;
      case RIGHT_SIG: right(50, 150); break;
    }
  }
}

void motors_tick() {
  if (millis() - motor_tick_time >= motor_tick_duration) {
    motorL.setMode(STOP);
    motorR.setMode(STOP);
  }
}

void forward(int dur, int speed) {
  motor_tick_duration = dur;

  motorL.setMode(FORWARD);
  motorR.setMode(FORWARD);
  motorL.setSpeed(speed);
  motorR.setSpeed(speed);

  motor_tick_time = millis();
}

void backward(int dur, int speed) {
  motor_tick_duration = dur;

  motorL.setMode(BACKWARD);
  motorR.setMode(BACKWARD);
  motorL.setSpeed(speed);
  motorR.setSpeed(speed);

  motor_tick_time = millis();
}

void left(int dur, int speed) {
  motor_tick_duration = dur;
  
  motorL.setMode(BACKWARD);
  motorR.setMode(FORWARD);
  motorL.setSpeed(speed);
  motorR.setSpeed(speed);

  motor_tick_time = millis();
}

void right(int dur, int speed) {
  motor_tick_duration = dur;

  motorL.setMode(FORWARD);
  motorR.setMode(BACKWARD);
  motorL.setSpeed(speed);
  motorR.setSpeed(speed);

  motor_tick_time = millis();
}
