#define adc1 16
#define adc2 17

void printLine(int sig1, int sig2);

void setup() {
  // put your setup code here, to run once:
  pinMode(adc1, INPUT);
  pinMode(adc2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int signal1 = analogRead(adc1);
  int signal2 = analogRead(adc2);
  
}

void printLine(int sig1, int sig2) {
  int arrayptr* = new int linePosition[];
  
}


