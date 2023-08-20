// Pin assignments
const int ledPin = LED_BUILTIN;    // LED pin for built-in light
const int buttonPin = 2;           // Pin for the push button
const int dotDuration = 200;       // Duration of a dot in milliseconds

// Morse code representation of the name "ADITYA"
const char* morseCode[] = {
  ".-", "-..", "..-", ".-", "-.--", ".-"
};

int currentCharIndex = 0;  // Index of the current character in Morse code
bool blinking = false;     // Flag indicating LED blinking status

void setup() {
  pinMode(ledPin, OUTPUT);        // Configure LED pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Configure button pin with internal pull-up resistor
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // Button press detected
    if (!blinking) {
      startBlinking();            // Start blinking the Morse code
    } else {
      currentCharIndex = 0;
      stopBlinking();             // Stop blinking and reset
    }
    delay(200);                   // Add debounce delay
  }
  
  if (blinking) {
    char morseChar = morseCode[currentCharIndex][0];
    if (morseChar == '.') {
      digitalWrite(ledPin, HIGH);
      delay(dotDuration);
      digitalWrite(ledPin, LOW);
      delay(dotDuration);
    } else if (morseChar == '-') {
      digitalWrite(ledPin, HIGH);
      delay(dotDuration * 3);
      digitalWrite(ledPin, LOW);
      delay(dotDuration);
    }

    currentCharIndex++;
    if (morseCode[currentCharIndex] == NULL) {
      currentCharIndex = 0;
      stopBlinking();
      delay(1000);                // Pause between name blinkings
    }
  }
}

void startBlinking() {
  blinking = true;
  currentCharIndex = 0;
}

void stopBlinking() {
  blinking = false;
  digitalWrite(ledPin, LOW);
}
