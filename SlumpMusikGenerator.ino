//Arduino for Musicians
//Listing 5.5: Aleatoric music generator

void setup()
{
    Serial.begin(115200); //Set up serial output with standard MIDI baud rate
    
    //Seed the random number generator using a random value from analog 0:
    randomSeed(analogRead(0));
}

void loop() 
{
    //Select random parameters:
    byte note=random(20, 100);
    int duration=random(10, 1000);
    byte velocity=random(40, 127);
    
    //Play the note with the given parameters:
    playMIDINote(1, note, velocity);
    //Delay for the given duration
    delay(duration);
    
    //Turn the note off
    playMIDINote(1, note, 0);
    delay(10);
    
}

void playMIDINote(byte channel, byte note, byte velocity)
{
    byte noteOnStatus=0x90 + (channel-1);  //MIDI channels 1-16 are really 0-15
    
    //Send notes to MIDI output:
    Serial.write(noteOnStatus);
    Serial.write(note);
    Serial.write(velocity);
}

