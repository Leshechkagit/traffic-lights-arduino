//Made by Alexei Shrubok
//Github https://github.com/Leshechkagit

unsigned long currentMillis;
unsigned long previousMillis; 
unsigned long previousMillis2;

//<----------CUSTOMIZE---------->
int redledpin = A0;
int yellowledpin = A1;
int greenledpin = A2;
//<----------CUSTOMIZE---------->

void redbrightness(int brightness){  //Функция включения красного светодиода на определенную яркость. Принимает: яркость светодиода 0-1023
  analogWrite(redledpin,brightness);
}
void yellowbrightness(int brightness){  //Функция включения Жёлтого светодиода на определенную яркость. Принимает: яркость светодиода 0-1023
  analogWrite(yellowledpin,brightness);
}
void greenbrightness(int brightness){  //Функция включения Зелёного светодиода на определенную яркость. Принимает: яркость светодиода 0-1023
  analogWrite(greenledpin,brightness);
}
void redblink(int time, int glowtime, int period){ //Функция для мигания красным светодиодом. Принимает: продолжительность работы функции, время свечения светодиода, длительность перерыва между свечением.
  previousMillis = millis();
  currentMillis = millis();
  while(currentMillis - previousMillis <= time){
    currentMillis = millis();
    previousMillis2 = millis();
    while((currentMillis - previousMillis2 <= glowtime) and (currentMillis - previousMillis <= time)){
      currentMillis = millis();
      redbrightness(1023);
    }
    previousMillis2 = millis();
    while((currentMillis - previousMillis2 <= period) and (currentMillis - previousMillis <= time)){
      currentMillis = millis();
      redbrightness(0);
    }
  }
  redbrightness(0);
}
void yellowblink(int time, int glowtime, int period){ //Функция для мигания жёлтым светодиодом. Принимает: продолжительность работы функции, время свечения светодиода, длительность перерыва между свечением.
  previousMillis = millis();
  currentMillis = millis();
  while(currentMillis - previousMillis <= time){
    currentMillis = millis();
    previousMillis2 = millis();
    while((currentMillis - previousMillis2 <= glowtime) and (currentMillis - previousMillis <= time)){
      currentMillis = millis();
      yellowbrightness(1023);
    }
    previousMillis2 = millis();
    while((currentMillis - previousMillis2 <= period) and (currentMillis - previousMillis <= time)){
      currentMillis = millis();
      yellowbrightness(0);
    }
  }
  yellowbrightness(0);
}
void greenblink(int time, int glowtime, int period){ //Функция для мигания зелёным светодиодом. Принимает: продолжительность работы функции, время свечения светодиода, длительность перерыва между свечением.
  previousMillis = millis();
  currentMillis = millis();
  while(currentMillis - previousMillis <= time){
    currentMillis = millis();
    previousMillis2 = millis();
    while((currentMillis - previousMillis2 <= glowtime) and (currentMillis - previousMillis <= time)){
      currentMillis = millis();
      greenbrightness(1023);
    }
    previousMillis2 = millis();
    while((currentMillis - previousMillis2 <= period) and (currentMillis - previousMillis <= time)){
      currentMillis = millis();
      greenbrightness(0);
    }
  }
  greenbrightness(0);
}

void lights(int reddelay, int yellowdelay, int greendelay){ // Светофор 
  redbrightness(1023);
  delay(reddelay);
  redbrightness(0);
  yellowbrightness(1023);
  delay(yellowdelay);
  yellowbrightness(0);
  greenbrightness(1023);
  delay(greendelay);
  greenbrightness(0);
}

void lights2(int reddelay, int redblinktime, int yellowdelay, int greendelay, int greenblinktime){ // Светофор с миганием
  redbrightness(1023);
  delay(reddelay);
  redblink(redblinktime, 200, 200);
  redbrightness(0);
  yellowbrightness(1023);
  delay(yellowdelay);
  yellowbrightness(0);
  greenbrightness(1023);
  delay(greendelay);
  greenblink(greenblinktime, 200, 200);
  greenbrightness(0);
  yellowbrightness(1023);
  delay(yellowdelay);
  yellowbrightness(0);
}

void setup() {
  pinMode(redledpin,OUTPUT);
  pinMode(yellowledpin,OUTPUT);
  pinMode(greenledpin,OUTPUT);
}

void loop() {
  lights2(4000, 2000, 2000, 4000, 2000);
}