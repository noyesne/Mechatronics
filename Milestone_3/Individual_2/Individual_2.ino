//  User Interaction Demo
//  Demonstrate various ways of interacting with a serial monitor user
//  Matthew R. Stein  March, 2018

//  integer read from user
int userInt;

// String read from user

String userString;

//  character array read from user

char userArray[30];


void setup() {
  // Set up the serial port, baud rate argument can be changed
  // to others supported by serial monitor
  Serial.begin(9600);
}

void loop() {
  //  Prompting the user

  Serial.println(" ");
  Serial.println("Welcome to the individual assessment, press any key to continue");

  //  Waiting for the user to type any key
  //  This loop does nothing until the user types any key or keys and presses enter

  while (Serial.available() == 0) {
    delay(20);  //Seems to work better when delaying a tiny bit between reads
  }
  //  Now, read and ignore all characters from the serial monitor
  while (Serial.available() > 0) {
    Serial.read();  //  Ignoring the returned value just empties the queue of characters
  }

  
  Serial.println("======================================");
  //  Get a string and store in an array of characters
  Serial.println("Enter a string of at least 10 characters (NO NUMBERS)");

  while (Serial.available() == 0) {
    delay(20);  //Seems to work better when delaying a tiny bit between reads
  }
  //  The 30 is the MAX length to read, limited by the size of your array
  //  the returned value inputLen is the number of characters actually read
  int inputLen = Serial.readBytesUntil('\n', userArray, 20);
  //  Do not read more than 30 bytes but read until the "newline" or "\n", produced when the
  //  user pressed enter.  Serial.available() would not have returned non-zero unless
  //  there are characters available, might as well read them all

  for(int i = 0; i < inputLen; i++){
    if(userArray[i] >= '0' && userArray[i]<= '9'){
      Serial.println("I SAID NO NUMBERS DAMMIT!");
      loop();
    }
  }

  if (inputLen > 9) {
    Serial.println("Your input in alphebectial order is: ");
    selectionSort(userArray, inputLen);
    for(int i = 0; i < inputLen; i++){\
        char c = userArray[i];
        if(c == ' '){
          c = '_';
        }

      Serial.print(c);
    }
    // Note the index starts at 0 so index of 2 is the third character
  } else {
    Serial.println("Shame on you, I asked you to enter ten or more characters");
  }
  Serial.println("\n======================================");
}

void selectionSort(char arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    // Find the index of the minimum element
    int min = i;

    for (int j = i + 1; j < n; j++) {
      if (toLower(arr[j]) < toLower(arr[min])) {
        min = j;
      }
    }

    // Swap the found minimum element with the current element
    if (min != i) {
      char temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}

char toLower(char x){ //I know this is probably built in but in the way I wanted to write this program it was easier to just write it myself
  if(x >= 'A' && x <='Z'){
      return x + 32; // this moves the character down the ascii table to be a lowercase letter;
  }
  return x;
}


