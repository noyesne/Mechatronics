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
  Serial.println("User interaction demo, press any key to continue");

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
  // Get an valid integer from the user
  Serial.println("Enter a signed but non-zero integer");

  while (Serial.available() == 0) {
    delay(20);  //Seems to work better when delaying a tiny bit between reads
  }
  userInt = Serial.parseInt();
  if (userInt == 0) {
    Serial.println("You did not enter a valid integer or entered zero.");
    Serial.println("The parseInt method cannot handle zero as an integer");
  } else {
    Serial.print("Thanks, you entered: ");
    Serial.println(userInt);
  }
  Serial.println("======================================");
  // Insist on getting three valid integers from the user but let user
  // quit the process by typing 'q' or 'Q'
  int intCount = 0;
  while (intCount < 3) {
    Serial.println("Enter three signed but non-zero integers, or 'q' to quit");

    while (Serial.available() == 0) {
      delay(20);  //Seems to work better when delaying a tiny bit between reads
    }
    // peek looks at the first character but does not consume it.  If the user
    // typed 3567 then reading the first character would consume the '3' and
    // parseInt would then incorrectly return 567
    if (Serial.peek() == 'q' || Serial.peek() == 'Q') {
      //  Now, read and ignore all characters from the serial monitor
      //  Allows user to type qzw134ks5 and still quit without leaving zw134ks5
      //  in the buffer for the next read
      while (Serial.available() > 0) {
        Serial.read();  //  Ignoring the returned value just empties the queue of characters
      }
      Serial.println("OK, quitting");
      intCount = 3;
    } else {
      userInt = Serial.parseInt();
      intCount++;
      if (userInt == 0) {
        Serial.println("You did not enter a valid integer or entered zero.");
      } else {
        Serial.print("Integer number ");Serial.print(intCount);Serial.print(" is ");
        Serial.println(userInt);
      }
    }
  }
  Serial.println("======================================");
  //  Get a String object from the user and convert it to uppercase
  Serial.println("Enter a string of characters any length");
  while (Serial.available() == 0) {
    delay(20);  //Seems to work better when delaying a tiny bit between reads
  }
  userString = Serial.readString();
  userString.toUpperCase();
  Serial.println(userString);
  Serial.println("======================================");
  //  Get a string and store in an array of characters
  Serial.println("Enter a string of at least 3 characters");

  while (Serial.available() == 0) {
    delay(20);  //Seems to work better when delaying a tiny bit between reads
  }
  //  The 30 is the MAX length to read, limited by the size of your array
  //  the returned value inputLen is the number of characters actually read
  int inputLen = Serial.readBytesUntil('\n', userArray, 30);
  //  Do not read more than 30 bytes but read until the "newline" or "\n", produced when the
  //  user pressed enter.  Serial.available() would not have returned non-zero unless
  //  there are characters available, might as well read them all
  Serial.print("You entered "); Serial.print(inputLen); Serial.println(" characters");

  if (inputLen > 2) {
    Serial.println("The HEX ASCII code for the");
    Serial.print("third character you entered is ");
    Serial.println(userArray[2], HEX);
    // Note the index starts at 0 so index of 2 is the third character
  } else {
    Serial.println("Shame on you, I asked you to enter 3 characters");
  }
  Serial.println("======================================");
}


