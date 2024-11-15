 
 
 
 
 //  Never change these functions
//  If they have the reversed outcome rewire the platform
//  Do not re-write these functions
void platformForward()
{
  leftForward();
  rightForward();
}
void platformBackward()
{
  leftBackward();
  rightBackward();
}
void platformStop()
{
  leftStop();
  rightStop();
}
void platformSpinLeft()
{
  rightBackward(); //CHANGE THIS 
  leftForward();
}
void platformSpinRight()
{
  leftBackward(); //CHANGE THIS
  rightForward();
}
//left
void leftForward()
{
      digitalWrite(leftA, HIGH);
      Serial.print("IN HERE");
      digitalWrite(leftB, LOW); 
}
void leftBackward()
{
      digitalWrite(leftA, LOW);
      digitalWrite(leftB, HIGH); 
}

void leftStop()
{
      digitalWrite(leftA, LOW);
      digitalWrite(leftB, LOW); 
}
//right
void rightForward()
{
      digitalWrite(rightA, HIGH);
      digitalWrite(rightB, LOW); 
}
void rightBackward()
{
      digitalWrite(rightA, LOW);
      digitalWrite(rightB, HIGH); 
}

void rightStop()
{
      digitalWrite(rightA, LOW);
      digitalWrite(rightB, LOW); 
}