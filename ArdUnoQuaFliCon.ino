const int THROTTLE_PIN = 2;
const int AILERON_PIN = 4;
const int ELEVATOR_PIN = 7;
const int RUDDER_PIN = 8;
const int GEAR_PIN = 12;
const int AUX_PIN =13;

const int FRONT_LEFT_PIN = 3;
const int FRONT_RIGHT_PIN = 5;
const int BACK_LEFT_PIN = 6;
const int BACK_RIGHT_PIN = 9;

// Calibration values
const int THROTTLE_MIN = 1077;
const int THROTTLE_MAX = 1877;
const int AILERON_MIN = 1088;
const int AILERON_MAX = 1861;
const int ELEVATOR_MIN = 989;
const int ELEVATOR_MAX = 1758;
const int RUDDER_MIN = 1137;
const int RUDDER_MAX = 1860;
const int GEAR_MIN = 1089;
const int GEAR_MAX = 1878;
const int AUX_MIN = 1088;
const int AUX_MAX = 1878;
const int BR_MIN = 1176;
const int BR_MAX = 2000:
const int FR_MIN = 1135:
const int FR_MAX = 2000;
const int BL_MIN = 1180;
const int BL_MAX = 2000;
const int FL_MIN = 1180;
const int FL_MAX = 2000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read all inputs
  int throttleValue = pulseIn(THROTTLE_PIN, HIGH);
  int aileronValue = pulseIn(AILERON_PIN, HIGH);
  int elevatorValue = pulseIn(ELEVATOR_PIN, HIGH);
  int rudderValue = pulseIn(RUDDER_PIN, HIGH);
  int gearValue = pulseIn(GEAR_PIN, HIGH);
  int auxValue = pulseIn(AUX_PIN, HIGH);

  // map inputs to motor outputs
  int frontLeft = map(throttleValue, THROTTLE_MIN, THROTTLE_MAX, FL_MIN, FL_MAX);
  int frontRight = map(throttleValue, THROTTLE_MIN, THROTTLE_MAX, FR_MIN, FR_MAX);
  int backLeft = map(throttleValue, THROTTLE_MIN, THROTTLE_MAX, BL_MIN, BL_MAX);
  int backRight = map(throttleValue, THROTTLE_MIN, THROTTLE_MAX, BR_MIN, BR_MAX);

  // set motor output pins
  analogWrite(FRONT_LEFT_PIN, frontLeft);
  analogWrite(FRONT_RIGHT_PIN, frontRight);
  analogWrite(BACK_LEFT_PIN, backLeft);
  analogWrite(BACK_RIGHT_PIN, backRight);
}


// Map input values to motor output values
//  front_left_output = throttle_input + yaw_input + pitch_input - roll_input;
//  front_right_output = throttle_input - yaw_input + pitch_input + roll_input;
//  back_left_output = throttle_input + yaw_input - pitch_input + roll_input;
//  back_right_output = throttle_input - yaw_input - pitch_input - roll_input;



  delay(100);
}
