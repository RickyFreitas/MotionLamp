
// Definir os pinos que vão ser utilizados para o funcionamento do código.

#define red 8
#define green 10
#define blue 6
#define microphone 3
#define L 13

int change = 0;
int minNum = 4000; // Gerar uma função entre 4000 e 15000 para mudar as cores dos leds.
int maxNum = 15000;

int x = 0;
int y = 0; // Serve para não repetir as cores mais que 3 vezes seguidas.
int z = 0;

int initFirstRGB = 500;
int initRGB = 150; // Inicia o RGB com 3 pausas de luz vermelha e 1 verde.
int initLastRGB = 1000;

bool soundstate; // Deteta o som do microfone.


void setup() {
  //Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(microphone, INPUT);

  digitalWrite(L, LOW); // Desliga os leds.
  initStrip();
}

void loop() {  //Define os padrões e a ordem pelos quais apareçe.
  
  chooseRandomColor();
  changeRandomTime();
  
  for (int i = 0; i < change; i++) {
  detectSound();

  if (soundstate == 1) {
    colorShow();
  }
  else {
    colorOff();
    }
  }
  
}

void initStrip() {  //Consoante o som detetado altera as cores dos leds.
    colorRed();
    delay(initFirstRGB);
    colorOff();
    delay(initRGB);
    colorRed();
    delay(initRGB);
    colorOff();
    delay(initRGB);
    colorRed();
    delay(initRGB);
    colorOff();
    delay(initRGB);
    colorGreen();
    delay(initFirstRGB);
    colorOff();
    delay(initLastRGB);
}

//Definir as cores no padrão RGB.

void colorRed() {  
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}

void colorGreen() {
  analogWrite(red, 50);
  analogWrite(green, 250);
  analogWrite(blue, 50);
}

void colorBlue() {
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}

void colorYellow() {
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 0);
}

void colorCyan() {
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

void colorPurple() {
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}

void colorOff() {
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}

int chooseRandomColor() {  //Escolhe uma cor ao randomicamente.
  while(y == x || z == x){
    x = random(1, 7);
  }

  z = y;
  y = x;
}

int changeRandomTime() {  //Mudar as cores aleatoriamente.
  change = random(minNum, maxNum);
}

bool detectSound() {  //Detetar o microfone.
  soundstate = digitalRead(microphone);
}

void colorShow() {  //Mostrar as cores defenidas anteriormente.
  if (x == 1) {
    colorRed();
  }

   if (x == 2) {
    colorGreen();
  }

   if (x == 3) {
    colorBlue();
  }

   if (x == 4) {
    colorYellow();
  }

   if (x == 5) {
    colorCyan();
  }

   if (x == 6) {
    colorPurple();
  }
}
