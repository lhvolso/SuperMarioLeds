int speakerPin = 9;
int pinLed = 2;
int length = 295;
char notes[] = "EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb  GNFR E uaC aCD GNFR E 1 11   GNFR E uaC aCD L  D C   CC C CD EC ag  CC C CDE  CC C CD EC ag  EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb EC g u aF Fa  bAAAGFEC ag  EC g u aF Fa  bF FFEDCe ec  "; // a space represents a rest
float beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 1
                2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 4, //Page 2
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, //Page4
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 5
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2 }; //Page 6
                
int tempo = 95;
void playTone(int ton1, int duration) {
  for (long i = 0; i < duration * 1000L; i += ton1) {
    tone(speakerPin, ton1);
    digitalWrite(pinLed, HIGH);
    delayMicroseconds(ton1);
    digitalWrite(pinLed, LOW);
  }
  noTone(speakerPin);
}
void playNote(char note, int duration) {
  char names[] = { ' ',  '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'i', 'N', 'R', 'u',  '1', 'L', 'k'};
  int tones[] =  {   0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 329, 349, 391, 440, 493, 523, 587, 659, 698, 783, 880, 987, 466, 740, 622, 415, 1046, 622u, 227};
  for (int i = 0; i < 34; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo);
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    delay(tempo / 2);
    pinLed++;
    if(pinLed == 8){
      pinLed = 2;
    }
  }
  while(1);
}
