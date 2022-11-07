// declaração dos pinos para o LDR, Buzzer, botões e LEDs
#define pinoLDR 18
#define pinoBuzzer 46
#define pinoBotao1 10
#define pinoBotao2 11
#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7

// declaração de variáveis auxiliares para a leitura
// dos valores de luminosidade, armazenamento dos estados
// de luminosidade e iteração para exibição do array onde
// os estados ficam armazenados, respectivamente
int valorLDR = 0;
char *estadosBinarios[4];
int contador = 0;

void setup() {
  
  // definição das funções dos pinos declarados como input, 
  // output, e input pull-up para detecção de estado de botões
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(pinoBotao1, INPUT_PULLUP);

  // Inicialização da comunicação serial
  Serial.begin(9600);

}

void loop() {
  
  // lê o valor do LDR discretizado de 0 a 4095 e o
  // converte para uma escala de 0 a 15
  int valorLido = escala1a15(pinoLDR);
  //Serial.print("Valor discretizado: ");
  //Serial.println(valorLido);
  // ----------------------------------

  // transforma o valor lido do LDR da escala de 
  // 0 a 15 para valores binários correspondentes
  char* valorBinario = inteiroABinario(valorLido);
  Serial.print("Valor binário: ");
  Serial.println(valorBinario);
  // ----------------------------------

  // funcão que recebe um valor binário e o representa
  // na forma do acionamento (1) ou não (0) de um
  // conjunto de 4 LEDs
  ligaLEDS(valorBinario);

  // função que recebe um pino no qual um buzzer está conectado
  // e um valor binário, convertendo-o em uma frequência que 
  // será reproduzida pelo buzzer
  tocaBuzzer(pinoBuzzer, valorBinario);

  // cria variáveis de estado para os dois botões do sistema
  // sendo 1 o valor para "botão pressionado" e 0 o valor para
  // "botão não pressionado"  
  int estadoBotao1 = detectaBotao(pinoBotao1);
  int estadoBotao2 = detectaBotao(pinoBotao2);

  // imprime todas as posições do array de armanzenamento de estados
  Serial.print(estadosBinarios[0]);
  Serial.print(" ");
  Serial.print(estadosBinarios[1]);
  Serial.print(" ");
  Serial.print(estadosBinarios[2]);
  Serial.print(" ");
  Serial.println(estadosBinarios[3]);

  // armazena um valor de luminosidade, convertido em valor 
  // binário em um array de armazenamento de estados de luminosidade
  // toda vez que o "botão 1" é pressionado e que o contador auxiliar
  // não indica que o array já está cheio    
  if (estadoBotao1 == 1 && contador <= 4){
    estadosBinarios[contador] = valorBinario;
    contador += 1;
    delay(100);
  }

  // percorre os valores em binário armazenados no array e 
  // usa-os como input das funções que os representam em 
  // acionamento dos LEDs e reprodução de frequências sonoras 
  if (estadoBotao2 == 1){
    Serial.println(" ");
    for (int i = 0; i <=3; i++){
      Serial.print("Tocando posicao: ");
      Serial.println(estadosBinarios[i]);
      ligaLEDS(estadosBinarios[i]);
      tocaBuzzer(pinoBuzzer, estadosBinarios[i]);
      delay(2000);
    }

    // uma vez reproduzido os valores armazenados no array
    // faz com ele o mesmo seja preenchido com 0s, esvaziando-o
    Serial.println("Esvaziando vetor de estados...");
    for (int j = 0; j <= 3; j++){
      estadosBinarios[j] = 0;
    }
    Serial.println("Vetor de estados apagado!");
    delay(3000);

  }

  // separa todos os elementos impressos por uma linha e
  // adiciona um delay como medida de segurança para a comunicação
  // serial do ESP32 S3 
  Serial.println();
  delay(100);
}