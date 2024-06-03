// Define the pin for the speaker
const int speakerPin = 9;

// Define the pin for the pushbuttons
const int ambulanceButtonPin = 2;
const int policeButtonPin = 3;
const int fireButtonPin = 4;

// Define the minimum and maximum frequencies for the siren effects
const int ambulanceLowFrequency = 440;
const int ambulanceHighFrequency = 800;
const int policeLowFrequency = 500;
const int policeHighFrequency = 2000;
const int fireLowFrequency = 200;
const int fireHighFrequency = 3000;

// Define the rate of change in frequency (adjust as needed)
const int frequencyChange = 20;

void setup() {
  // Set the speaker pin as an output
  pinMode(speakerPin, OUTPUT);
  
  // Set the pushbutton pins as inputs
  pinMode(ambulanceButtonPin, INPUT_PULLUP);
  pinMode(policeButtonPin, INPUT_PULLUP);
  pinMode(fireButtonPin, INPUT_PULLUP);
}

void loop() {
  // Check if the ambulance button is pressed
  if (digitalRead(ambulanceButtonPin) == LOW) {
    playAmbulanceSiren();
  }
  
  // Check if the police button is pressed
  if (digitalRead(policeButtonPin) == LOW) {
    playPoliceSiren();
  }
  
  // Check if the fire button is pressed
  if (digitalRead(fireButtonPin) == LOW) {
    playFireSiren();
  }
}

// Function to play ambulance siren
void playAmbulanceSiren() {
  for (int i = 0; i < 5; i++) {
    tone(9, 440, 500);
  delay(500);

  
tone(9, 800, 500);
  delay(500);
  }
  noTone(speakerPin);
}

// Function to play police siren
void playPoliceSiren() {
  for (int i = 0; i < 10; i++) {
    for (int frequency = policeLowFrequency; frequency <= policeHighFrequency; frequency += frequencyChange) {
      tone(speakerPin, frequency);
      delay(2);
    }
    for (int frequency = policeHighFrequency; frequency >= policeLowFrequency; frequency -= frequencyChange) {
      tone(speakerPin, frequency);
      delay(2);
    }
  }
  noTone(speakerPin);
}

// Function to play fire truck siren
void playFireSiren() {
  for (int i = 0; i < 5; i++) {
    for (int frequency = fireLowFrequency; frequency <= fireHighFrequency; frequency += frequencyChange) {
      tone(speakerPin, frequency);
      delay(8);
    }
    for (int frequency = fireHighFrequency; frequency >= fireLowFrequency; frequency -= frequencyChange) {
      tone(speakerPin, frequency);
      delay(8);
    }
  }
  noTone(speakerPin);
}
