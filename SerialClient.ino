#if defined(ARDUINO) 
SYSTEM_MODE(SEMI_AUTOMATIC); 
#endif

void setup() 
{
  // put your setup code here, to run once:
  RGB.control(true);
  Serial.begin(115200);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int color = random(0,7);
  sendcolor(color);
  delay(1000);
}

void sendcolor(int color)
{
  switch(color)
  {
    case 0: //R
      RGB.color(255,0,0);
      Serial.println("R");
      break;
    case 1: //G
      RGB.color(0,255,0);
      Serial.println("G");
      break;
    case 2: //B
      RGB.color(0,0,255);
      Serial.println("B");
      break;
    case 3: //Y
      RGB.color(255,255,0);
      Serial.println("Y");
      break;
    case 4: //M
      RGB.color(255,0,255);
      Serial.println("M");
      break;
    case 5: //C
      RGB.color(0,255,255);
      Serial.println("C");
      break;
    case 6: //W
      RGB.color(128,128,128);
      Serial.println("W");
      break;
     case 7: //Black
      Serial.println("-");
      RGB.color(0,0,0);
      break;
    
  }


  
}




