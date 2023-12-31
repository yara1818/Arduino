#include <TimerOne.h>

int ECG_val = 0;
int pulse_val = 0;

void  sendDate() {
  Serial.write("A0");
  ECG_val = analogRead(A0);
  Serial.write(map(ECG_val, 0, 1023, 0, 225));
  Serial.write("A3");
  pulse_val = analogRead(A3);
    Serial.write(map(pulse_val, 0, 1023, 0, 225));  
}

void setup () {
  Serial.begin(115200);
  Timer1.initialize(3000);
  Timer1.attachInterrupt(sendDate);
}

void loop() {}