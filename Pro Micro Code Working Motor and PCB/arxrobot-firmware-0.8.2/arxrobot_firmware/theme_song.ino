  //This will allow to play an anthem for our Goliath before we start the laser tag battle.
  

  void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(tone);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(tone);      
    }
  }
  
  void playNote(String note, int duration) {
    String noteNames[] = { "D#4/Eb4", "E4", "F4", "F#4/Gb4", "G4", "G#4/Ab4", "A4", "A#4/Bb4", "B4", "C5", "C#5/Db5", "D5", "D#5/Eb5", "E5", "F5", "F#5/Gb5", "G5", "G#5/Ab5", "A5", "A#5/Bb5", "B5", "C6", "C#6/Db6", "D6", "D#6/Eb6", "E6", "F6", "F#6/Gb6", "G6" };
    int tones[] = { 1607, 1516, 1431, 1351, 1275, 1203, 1136, 1072, 1012, 955, 901, 851, 803, 758, 715, 675, 637, 601, 568, 536, 506, 477, 450, 425, 401, 379, 357, 337, 318 };
    for (int i = 0; i < 29; i++) {
      if (noteNames[i] == note) {
        playTone(tones[i], duration);
      }
    }
  }
  

  
 
  
 


