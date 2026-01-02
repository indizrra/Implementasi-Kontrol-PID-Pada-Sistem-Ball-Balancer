#include <Servo.h>

Servo servo;
#define trig 2
#define echo 3

// Tuning parameter PID - perlu disesuaikan
#define kp 2.0    // Lebih kecil dari sebelumnya
#define ki 0.01   // Lebih kecil
#define kd 1.0    // Lebih kecil

// Variabel PID
double priError = 0;
double toError = 0;

// Parameter sistem
const int SETPOINT = 15;  // Jarak tengah (cm)
const int MIN_DISTANCE = 5;  // Jarak minimal (bola dekat sensor)
const int MAX_DISTANCE = 25; // Jarak maksimal (bola jauh dari sensor)

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(5);
  Serial.begin(9600);
  servo.write(90);  // Posisi netral (tengah)
  delay(1000);      // Waktu stabilisasi
}

void loop() {
  PID();
}

long distance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  return cm;
}

void PID() {
  int dis = distance();
  
  // Batasi pembacaan dalam range yang valid
  dis = constrain(dis, MIN_DISTANCE, MAX_DISTANCE);
  
  double error = SETPOINT - dis;

  // Komponen PID
  double Pvalue = error * kp;
  double Ivalue = toError * ki;
  double Dvalue = (error - priError) * kd;

  double PIDvalue = Pvalue + Ivalue + Dvalue;
  
  // Update error
  priError = error;
  toError += error;
  
  // Batasi akumulasi error (anti windup)
  toError = constrain(toError, -100, 100);

  // Mapping nilai PID ke sudut servo
  int servoAngle = map(PIDvalue, -100, 100, 0, 180);
  servoAngle = constrain(servoAngle, 0, 180);

  // Debugging
  Serial.print("Jarak: ");
  Serial.print(dis);
  Serial.print(" cm | Error: ");
  Serial.print(error);
  Serial.print(" | Servo: ");
  Serial.println(servoAngle);

  servo.write(servoAngle);
  delay(50);  // Delay untuk stabilitas
}