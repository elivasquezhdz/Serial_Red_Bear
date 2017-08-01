#if defined(ARDUINO) 
SYSTEM_MODE(SEMI_AUTOMATIC); 
#endif

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void setup() 
{
  // put your setup code here, to run once:
  RGB.control(true);
  Serial.begin(115200);
  inputString.reserve(20);
}

 
void loop() 
{
  // put your main code here, to run repeatedly:
  if (stringComplete) 
  {
    Serial.println(inputString);
    turncolors(inputString);
  /*if(inputString=="R\n")
      RGB.color(255, 0, 0);
  if(inputString=="G\n")
      RGB.color(0, 255, 0);
  if(inputString=="B\n")
      RGB.color(0, 0, 255);
  if(inputString=="Y\n")
      RGB.color(255, 255, 0);
  if(inputString=="C\n")
      RGB.color(255, 0, 255);
  if(inputString=="M\n")
      RGB.color(0, 255, 255);
  if(inputString=="W\n")
      RGB.color(255, 255, 255);

    */
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void turncolors(String input)
{
  if(input=="R\n")
      RGB.color(255, 0, 0);
  if(input=="G\n")
      RGB.color(0, 255, 0);
  if(input=="B\n")
      RGB.color(0, 0, 255);
  if(input=="Y\n")
      RGB.color(255, 255, 0);
  if(input=="C\n")
      RGB.color(0, 255, 255);
  if(input=="M\n")
      RGB.color(255, 0, 255);
  if(input=="W\n")
      RGB.color(128, 128, 128);


}


