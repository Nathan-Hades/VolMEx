int i = 0;
int controlChange = 176;
int dreipotiPin[] = {A0,A2,A5};
int dreicontrollerNummer[] = {1,11,7};
int dreicontrollerWertAlt[3];
int dreicontrollerWert[3];
int dreifirstRead[3];
int dreipotiWert[3];

void setup() {
  Serial1.begin(31250);
}

void loop () {
for (i = 0; i <= 2; i++) {
    dreipotiWert[i] = 0.96 * dreipotiWert[i] + 0.04 * analogRead(dreipotiPin[i]);
    dreifirstRead[i] = map(dreipotiWert[i],0,1000,0,127);
    if (dreifirstRead[i] > 127) {
      dreifirstRead[i] = 127;
    }
    //dreicontrollerWert[i] = 0.6 * dreicontrollerWert[i] + 0.4 * dreifirstRead[i];
    dreicontrollerWert[i] = dreifirstRead[i];
    if (dreicontrollerWertAlt[i] != dreicontrollerWert[i]) {
      usbMIDI.sendControlChange(dreicontrollerNummer[i], dreicontrollerWert[i], 1);
      Serial1.write(controlChange);
      Serial1.write(dreicontrollerNummer[i]);
      Serial1.write(dreicontrollerWert[i]);
    }
    dreicontrollerWertAlt[i] = dreicontrollerWert[i];
  }
}
/*int potiWert;
void setup()
{
  Serial.begin(9600); // USB is always 12 Mbit/sec
}

void loop()
{
  potiWert = analogRead(A1);
  Serial.println(potiWert);
  delay(500);  // do not print too fast!
}*/
