// Name: Aditya
// Student I'D: 2210994754
//task2.1


const int ledPin = LED_BUILTIN;    
const int buttonPin = 2;           
const int dotDuration = 210;       // Duration of a dot in milliseconds

// Morse code representation of the name "ADITYA"
const char* morseCode[] = {
  ".-",  //A
   "-..", //D
    "..-", //I
     ".-", //T
      "-.--", //Y
       ".-" //A
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
      BlinkingStart();            // Start blinking according to Morse code
    } else {
      currentCharIndex = 0;
      BlinkingStop();             // Stop blinking and reset
    }
    delay(200);                   
  }
  
  if (blinking) 
    {
        char morseChar = morseCode[currentCharIndex][0];
        if (morseChar == '.') {
        digitalWrite(ledPin, HIGH);
        delay(dotDuration);
        digitalWrite(ledPin, LOW);
        delay(dotDuration);
    } 
    
    else if (morseChar == '-') 
    {
        digitalWrite(ledPin, HIGH);
        delay(dotDuration * 3);
        digitalWrite(ledPin, LOW);
        delay(dotDuration);
    }

    currentCharIndex++;
    if (morseCode[currentCharIndex] == NULL) 
      {
        currentCharIndex = 0;
        BlinkingStop();
        delay(1000);                // Pause between name blinkings
      }
  }
}

void BlinkingStart() 
{
  blinking = true;
  currentCharIndex = 0;
}

void BlinkingStop() 
{
  blinking = false;
  digitalWrite(ledPin, LOW);
}
