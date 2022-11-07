
// lê uma porta analógica e discretiza seus valores de 0 a 15
int escala1a15(int portaAnalogica){

  int valorAnalogico = analogRead(portaAnalogica);
  int valorDiscretizado = map(valorAnalogico, 0, 4095, 0, 15);

  return valorDiscretizado;
}

// valores binários de 0 a 15
char valoresBinarios[][15] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

// lê um valor de 0 a 15 e converte no valor binário correspondente
char* inteiroABinario(int valorInteiro){
  char* valorBinario = valoresBinarios[valorInteiro];

  return valorBinario;
}

// represente um valor binário informado por meio do acionamento (1) ou não (0) de 4 LEDS
void ligaLEDS(char binarioLEDS[]){

  if (binarioLEDS[0] == '1'){  
    //Serial.print("LED1 acionado - ");
    digitalWrite(LED1, HIGH);
  } else if (binarioLEDS[0] == '0'){
    //Serial.print("LED1 apagado - ");
    digitalWrite(LED1, LOW);
  }

  if (binarioLEDS[1] == '1'){
    //Serial.print("LED2 acionado - ");
    digitalWrite(LED2, HIGH);
  } else if (binarioLEDS[1] == '0'){
    //Serial.print("LED2 apagado - ");
    digitalWrite(LED2, LOW);
  }

  if (binarioLEDS[2] == '1'){
    //Serial.print("LED3 acionado - ");
    digitalWrite(LED3, HIGH);
  } else if (binarioLEDS[2] == '0'){
    //Serial.print("LED3 apagado - ");
    digitalWrite(LED3, LOW);
  }

  if (binarioLEDS[3] == '1'){
    //Serial.print("LED4 acionado");
    digitalWrite(LED4, HIGH);
  } else if (binarioLEDS[3] == '0'){
    //Serial.println("LED4 apagado");
    digitalWrite(LED4, LOW);
  }

}

// frequências a serem tocadas pelas buzzer
int tonsBuzzer[15] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000};

// toca uma frequência a partir de um valor binário correspondente
void tocaBuzzer(int pinoSom, char binarioBuzzer[]){

  if(binarioBuzzer == valoresBinarios[0]){
    //Serial.println(1);
    tone(pinoSom, tonsBuzzer[0], 500);
  } else if (binarioBuzzer == valoresBinarios[1]){
    //Serial.println(2);
    tone(pinoSom, tonsBuzzer[1], 500);
  } else if (binarioBuzzer == valoresBinarios[2]){
    //Serial.println(3);
    tone(pinoSom, tonsBuzzer[2], 500);
  } else if (binarioBuzzer == valoresBinarios[3]){
    //Serial.println(4);
    tone(pinoSom, tonsBuzzer[3], 500);
  } else if (binarioBuzzer == valoresBinarios[4]){
    //Serial.println(5);
    tone(pinoSom, tonsBuzzer[4], 500);
  } else if (binarioBuzzer == valoresBinarios[5]){
    //Serial.println(6);
    tone(pinoSom, tonsBuzzer[5], 500);
  } else if (binarioBuzzer == valoresBinarios[6]){
    //Serial.println(7);
    tone(pinoSom, tonsBuzzer[6], 500);
  } else if (binarioBuzzer == valoresBinarios[7]){
    //Serial.println(8);
    tone(pinoSom, tonsBuzzer[7], 500);
  } else if (binarioBuzzer == valoresBinarios[8]){
    //Serial.println(9);
    tone(pinoSom, tonsBuzzer[8], 500);
  } else if (binarioBuzzer == valoresBinarios[9]){
    //Serial.println(10);
    tone(pinoSom, tonsBuzzer[9], 500);
  } else if (binarioBuzzer == valoresBinarios[10]){
    //Serial.println(11);
    tone(pinoSom, tonsBuzzer[10], 500);
  } else if (binarioBuzzer == valoresBinarios[11]){
    //Serial.println(12);
    tone(pinoSom, tonsBuzzer[11], 500);
  } else if (binarioBuzzer == valoresBinarios[12]){
    //Serial.println(13);
    tone(pinoSom, tonsBuzzer[12], 500);
  } else if (binarioBuzzer == valoresBinarios[13]){
    //Serial.println(14);
    tone(pinoSom, tonsBuzzer[13], 500);
  } else if (binarioBuzzer == valoresBinarios[14]){
    //Serial.println(15);
    tone(pinoSom, tonsBuzzer[14], 500);
  } else if (binarioBuzzer == valoresBinarios[15]){
    //Serial.println(16);
    tone(pinoSom, tonsBuzzer[15], 500);
  } 

}

// detecta se um botão ligado a um pino específico está sendo pressionado ou não
int detectaBotao(int pinoBotao){

  if (digitalRead(pinoBotao) == HIGH){
    //Serial.println("Botão 1 pressionado");
    return 1;
  } else if (digitalRead(pinoBotao) == LOW){
    //Serial.println("Botão 1 não pressionado");
    return 0;
  }

}