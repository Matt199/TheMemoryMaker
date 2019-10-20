import processing.serial.*;
final boolean useSerial = true;
Serial myPort; // The serial port
String dataString = "";
boolean[] boolArray = new boolean[2048];
int savedBoolCount;
int SW = 6; //stroke weight

void setup () {
  // set the window size: 1920x1080
  size(1920, 1080);
  strokeWeight(8);
  textSize(32);

  if (useSerial)
  {
    println(Serial.list());
  }
  
  if (useSerial)
  {
    myPort = new Serial(this, Serial.list()[2], 9600);
  }
}

void draw () {
  background(0);
  strokeWeight(SW);
  stroke(255);
  drawData(dataString);
  text(dataString, 10, 10, width/2 - 10, height);
}

void keyPressed() {
  if (key == ' ' || (key >= '0' && key <='9') || (key>='A' && key <= 'Z') || (key>='a' && key <= 'z'))
  {
    dataString += key;
  }
  if (key == 8) //backspace
  {
    dataString = trimLast(dataString, 1);
  }
  if (keyCode == ENTER) //enter
  {
    if (useSerial)
    {
      myPort.write(dataString);
    }
  }
}

void ChangeStringToBoolTable(String string)
{
  savedBoolCount = 0;
  int boolTableIterator = 0;
  for (int i=0; i<string.length(); i++)
  {
    char charToConvert = string.charAt(i);
    for (int j=0; j<8; j++)
    {
      if ((charToConvert & 1) > 0) //mask on LSB
        boolArray[boolTableIterator] = true;
      else
        boolArray[boolTableIterator] = false;
      charToConvert >>= 1; //right bitwise shift
      boolTableIterator++;
    }
  }
  savedBoolCount = boolTableIterator;
}

public String trimLast(String str, int trimCount)
{
  if (str != null && str.length() >= trimCount) 
  {
    str = str.substring(0, str.length() - 1);
  }
  return str;
}

public void drawData(String inputString)
{
  textAlign(CENTER, TOP);
  ChangeStringToBoolTable(inputString);
  int printIterator = 0;
  push();
  translate(width/2, SW);
  while (printIterator < savedBoolCount)
  {
    push();
    for (int i=0; i<8; i++)
    {
      if (boolArray[printIterator])
      {
        drawLine(width/(2*8) - SW*2, true);
        translate(width/(2*8), 0);
      } else
      {
        drawLine(width/(2*8) - SW*2, false);
        translate(width/(2*8), 0);
      }
      printIterator++;
    }
    pop();
    translate(0, SW*2);
  }
  pop();
}

void drawLine(int len, boolean value)
{
  if (value)
  {
    line(0, 0, len, 0);
  } else
  {
  }
}
