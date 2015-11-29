#define AO 14
#define CLK 1
#define SI 0

int pixels[128];

void setup() {
  Serial.begin(9600);
  pinMode(AO, INPUT);
  pinMode(CLK, OUTPUT);
  pinMode(SI, OUTPUT);
}

void loop() {
  outputWrite(); 
  //main function to store values into pixels array
  
  digitalWrite(CLK, HIGH); //reset clock pulse 
  digitalWrite(CLK, LOW);
  
  for(int j = 9; j > 0; j--) { //loop through lines of stars
    for(int i = 0; i < 128; i++) { //loop through each star criteria == 9, == 8, etc
      if(pixels[i] > 9) //Boundary condition for intensity value > 9
        pixels[i] = 9;
      if(pixels[i] >= j) //determines number of stars to print in each line
        Serial.print("*");
      else
        Serial.print(" "); //space
    }
    Serial.println(); //new line after each line of stars
  }
  for(int i = 0; i < 128; i++) { //prints numerical values of voltage (1023 / 25)
    Serial.print(pixels[i]);
  }
  delayMicroseconds(60); //60 original
  Serial.println();
}

void outputWrite() { //sets up pulse outputs and analyzes output
   for(int i = 0; i < 128; i++) { 
     if(i == 0) {
      digitalWrite(SI, HIGH);
      delayMicroseconds(50); //15 original
      digWrite(i);
     }
     else
      digWrite(i);
   }
}

void digWrite(int var) { //helper function for outputWrite
  digitalWrite(CLK, HIGH);
  delayMicroseconds(50); //15 orig
  digitalWrite(SI, LOW);
  pixels[var] = analogRead(AO)/25;
  delayMicroseconds(50);// 15 orig
  digitalWrite(CLK, LOW);
}

