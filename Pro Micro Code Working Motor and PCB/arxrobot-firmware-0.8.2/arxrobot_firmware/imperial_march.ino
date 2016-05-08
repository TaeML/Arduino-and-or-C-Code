void anthem()
{
   for (int i = 0; i < length; i++) 
    {
      if (notes[i] == "rest") 
      {
        delay(beats[i] * tempo);
      } else {
        playNote(notes[i], beats[i] * tempo);      
      }
      delay(tempo / 2);
    }
}

