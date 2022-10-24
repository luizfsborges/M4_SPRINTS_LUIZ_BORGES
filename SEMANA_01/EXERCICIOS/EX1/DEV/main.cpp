#include <iostream>
#include <string>
using namespace std;

/*
1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores mínimo e máximo e retorna esse valor
*/

/*
float converteSensor(float valorAjustado, float valorMinimo, float valorMaximo){

  float resultado = (valorAjustado-valorMinimo)/(valorMaximo-valorMinimo); // transformação linear / "regra de 3"

  return resultado;

}
*/

/*
// Descomente a função main abaixo para testar o exercício 1
int main(){
  cout << "Teste Ex 1" << endl;
	cout << converteSensor(100,100,400) << endl;
  //valor esperado: 0
	cout << converteSensor(400,100,400) << endl;
  //valor esperado: 1
	cout << converteSensor(250,100,400) << endl;
  //valor esperado: 0.5
}
*/

// ----------------------------------------------------------

/*
2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor
*/

/*
int leComando() {
  int comando;
  cin >> comando;

  if (comando != 0 && comando != 1) {
    cout << "Comando inválido." << endl;
    return comando;
  }

  return comando;

}
*/

/*
// Descomente a função main abaixo para testar o exercício 2
int main(){
  cout << "Digite o Comando (0 ou 1):";
	int cmd = leComando();
	cout << "Comando Recebido: " << cmd << endl;
}
*/

// ----------------------------------------------------------

/*
3 - Faça uma função que armazena uma medida inteira qualquer em um vetor fornecido. Note que como C não possui vetores nativos da linguagem, lembre-se que você precisa passar o valor máximo do vetor assim como a última posição preenchida.
Evite também que, por acidente, um valor seja escrito em uma área de memória fora do vetor
*/

/*
int insereVetor(int elemento, int valorMax, int lastPos, int Vetor[]) {

  Vetor[lastPos + 1] = elemento;

  if (lastPos + 1 >= valorMax) {

    cout << "Erro: valorMax: " << valorMax << " lastPos + 1 (indice): " <<
    valorMax << endl;
  }

  return 0;
}
*/

/*
// Descomente a função main abaixo para testar o exercício 3
int main(){
  int valorMax = 10;
  int lastPos = -1;
  int Numbers[valorMax];
  insereVetor(9, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(8, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(7, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(6, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(5, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(4, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(3, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(2, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(1, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(0, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(100, valorMax, lastPos, Numbers);
  // valor esperado: mensagem de erro "Erro: valorMax: 10, lastPos + 1 (indice): 10"
  cout << Numbers[0] << endl; // valor esperado: 9
  cout << Numbers[1] << endl; // valor esperado: 8
  cout << Numbers[2] << endl; // valor esperado: 7
  cout << Numbers[3] << endl; // valor esperado: 6
  cout << Numbers[4] << endl; // valor esperado: 5
  cout << Numbers[5] << endl; // valor esperado: 4
  cout << Numbers[6] << endl; // valor esperado: 3
  cout << Numbers[7] << endl; // valor esperado: 2
  cout << Numbers[8] << endl; // valor esperado: 1
  cout << Numbers[9] << endl; // valor esperado: 0
}
*/

// ----------------------------------------------------------

/*
4 - Faça duas funções que recebem um vetor com 4 posições que contém o valor da distância de um pequeno robô até cada um dos seus 4 lados.
A primeira função deve retornar a direção de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a segunda função deve retornar esta maior distância.
*/

/*
string dirMaiorDist(int Vetor[]){

  string direcao;

  if (Vetor[0] > Vetor[1] && Vetor[0] > Vetor[2] && Vetor[0] > Vetor[3]){
    direcao = "Direita";
    return direcao;

  } else if (Vetor[1] > Vetor[0] && Vetor[1] > Vetor[2] && Vetor[1] > Vetor[3]){
    direcao = "Esquerda";
    return direcao;

  } if (Vetor[2] > Vetor[0] && Vetor[2] > Vetor[1] && Vetor[2] > Vetor[3]){
    direcao = "Frente";
    return direcao;

  } if (Vetor[3] > Vetor[0] && Vetor[3] > Vetor[1] && Vetor[3] > Vetor[2]){
    direcao = "Trás";
    return direcao;
  }

  return "None";

}

int maiorDist(int Vetor[]){

  int maior = -1;

  for (int i = 0; i <= 3; i++) {
    if (Vetor[i] > maior){
      maior = Vetor[i];
    }
  }

  return maior;
}
*/

/*
// Descomente a função main abaixo para testar o exercício 3
int main(){
  //Considere que os valores sempre serão distintos
  //Considere valores de distância inteiros entre 0 e 100
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes [4] = {0, 20, 100, 50};
  cout << dirMaiorDist(posicoes) << endl;
  //valor esperado: Frente
  cout << maiorDist(posicoes) << endl;
  //valor esperado: 100
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes2 [4] = {95, 70, 80, 50};
  cout << dirMaiorDist(posicoes2) << endl;
  //valor esperado: Direita
  cout << maiorDist(posicoes2) << endl;
  //valor esperado: 95
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes3 [4] = {10, 0, 50, 60};
  cout << dirMaiorDist(posicoes3) << endl;
  //valor esperado: Tras
  cout << maiorDist(posicoes3) << endl;
  //valor esperado: 60
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes4 [4] = {54, 55, 30, 0};
  cout << dirMaiorDist(posicoes4) << endl;
  //valor esperado: Esquerda
  cout << maiorDist(posicoes4) << endl;
  //valor esperado: 55
}
*/

// ----------------------------------------------------------

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e retorna verdadeiro ou falso

/*
int continuar(){
  int numero;
  cout << "Digite 1 para parar o mapeamento! ";
  cin >> numero;
  if (numero != 1){
    return 0;
  } else {
    return numero;
  }
}
*/

/*
// Descomente a função main abaixo para testar o exercício 5
int main(){
  int parar = 0;
  while (parar == 0){
    parar = continuar();
  }
  //A função deve perguntar: "Digite 1 para parar o mapeamento!"
  //Se o usuário digitar 1, deve sair do loop while declarado acima
  // Em caso contrário, continua no loop acima e pergunta novamente
  return 1;
}
*/

// ----------------------------------------------------------

/*
6 - Escreva uma função que vai "dirigindo" virtualmente um robô e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", "Frente", "Tras").
A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno para uma movimentação futura.
Ele vai armazenando estas distancias em um vetor fornecido como parâmetro e retorna a ultima posicao preenchida do vetor.
Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado.
Para simular os sensores e os comandos de pare, use as funções já construídas nos ítens anteriores e em um looping contínuo até que um pedido de parada seja enviado pelo usuário.
A função final deve utilizar as funções declaradas acima para ler os sensores e o movimento do robô e no final percorrer o vetor e mostrar o movimento a cada direção na maior distância a cada movimento.
*/

/*
int dirige(int vetor[]) {

  struct informacoes {
    string direcoes[4] = {};
    int distancias[4] = {};
  } info6;

  string comandos[4] = {"Direita", "Esquerda", "Frente", "Trás"};

  for (int i = 0; i <= 3; i++) {
    info6.distancias[i] = vetor[i];
  }

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (info6.distancias[i] < info6.distancias[j]) {
        int temp = info6.distancias[i];
        info6.distancias[i] = info6.distancias[j];
        info6.distancias[j] = temp;
      }
    }
  }

  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      if (info6.distancias[j] == vetor[i]) {
        info6.direcoes[i] = comandos[i];
      }
    }
  }

  cout << "[Log de percurso do robô]" << endl << "\n";
  cout << "Andou " << info6.distancias[0] << " cm para a " << info6.direcoes[0] << endl << "\n";

  cout << "Andou " << info6.distancias[1] << " cm para a " << info6.direcoes[1] << endl << "\n";

  cout << "Andou " << info6.distancias[2] << " cm para a " << info6.direcoes[2] << endl << "\n";

  cout << "Andou " << info6.distancias[3] << " cm para a " << info6.direcoes[3] << endl << "\n";
  
  return -1;
}

int main() {

  int posicoes[4] = {0, 20, 100, 50};
  cout << dirige(posicoes);
  
}

*/

