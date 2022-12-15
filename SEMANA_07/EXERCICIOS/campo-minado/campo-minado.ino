// Importação de bibliotecas
#include <WiFi.h>
#include <FS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
 
// Definição das credenciais para acesso a rede Wifi
const char* ssid = "AndroidAP";
const char* password =  "alquimia";

// Definição de variáveis auxiliares para as mensagens 
const char* PARAM_INPUT = "value";
String estadoBomba = "0";

// Pinos dos LEDs dos jogadores
int jogador1 = 7;
int jogador2 = 6;
 
// Inicialização do servidor
AsyncWebServer server(80);
 
const char HTML[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html lang="pt-br">
<meta charset="UTF-8"/>

<body onload="sorteiaLetra()">

    <h1> Campo Minado</h1>

    <div id="campo-jogo"> 

        <p id="jogador"> Jogador 1, escolha sabiamente uma das letras abaixo: </p>

        <!-- Cria os botões que representam os campos do "Campo Minado" -->

        <button id="A" onclick="botaoA()">A</button>
        <button id="B" onclick="botaoB()">B</button>
        <button id="C" onclick="botaoC()">C</button>
        <button id="D" onclick="botaoD()">D</button>
        <button id="E" onclick="botaoE()">E</button>
        <button id="F" onclick="botaoF()">F</button>

    </div>

    <!-- Cria os campos onde mensagens serão exibidas -->

    <p id="mensagem"></p>
    <p id="vitoria"></p>

    <script>

        // Função de processamento do comando enviado via XML HTTP Request
        function enviaComando(comando){
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/campo-minado?value="+comando, true);
            xhr.send();
        }


        // Faz com que seja uma mina diferente a ser detonada toda vez
        function sorteiaLetra(){

            // Apaga os LEDs caso estejam acessos
            enviaComando(0);

            jogador = 1;

            const alternativas = ["A", "B", "C", "D", "E", "F"];
            const indice = Math.floor(Math.random() * alternativas.length);

            localBomba = alternativas[indice];

            // Linha abaixo mostra qual é a porção do campo minado com explosivo
            // document.getElementById("mensagem").innerHTML = localBomba;

        }

        // Função de botão (vale para as funções dos botões de A a F)
    
        function botaoA(){

            // Remove o botão que foi pressionado
            var a = document.getElementById("A");
            a.parentNode.removeChild(a);

            // Verifica se o local da bomba é o do botão que o jogador apertou
            if (localBomba == "A"){

                var campo_jogo = document.getElementById("campo-jogo");
                campo_jogo.parentNode.removeChild(campo_jogo);

                // Exibe uma "mensagem de detonação"
                document.getElementById("mensagem").innerHTML = "CABUMMMMMMM";

                // Verifica qual foi o jogador que apertou o botão com o explosivo
                if (jogador == 1){
                    jogador_vitorioso = 2;
                } else if (jogador == 2){
                    jogador_vitorioso = 1;
                }

                // Declara vitória ao jogador que não tenha apertado o botão com o explosivo
                document.getElementById("vitoria").innerHTML = "Vitória do Jogador " + jogador_vitorioso;

                // Envia a informação de qual foi o jogador vitorioso para o firmware, via XML HTTP Request, para o firmware acender o LED correspondente
                enviaComando(jogador_vitorioso);

            } else {

                // Se o botão selecionado não for o que contém o explosivo, exibe uma mensagem de continuidade do jogo
                document.getElementById("mensagem").innerHTML = "Hoje é seu dia de sorte";
            }

            // Verifica qual jogador fez a última jogada e convida o outro a jogar
            if (jogador == 1){
                jogador = 2;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 2";
                // Envia a informação sobre qual é o jogador da vez para o firmware acender o LED correspondente
                enviaComando(20);
            } else if (jogador == 2){
                jogador = 1;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 1";
                enviaComando(10);
            }

        }

        function botaoB(){
            var b = document.getElementById("B");
            b.parentNode.removeChild(b);
            
            if (localBomba == "B"){

                var campo_jogo = document.getElementById("campo-jogo");
                campo_jogo.parentNode.removeChild(campo_jogo);

                document.getElementById("mensagem").innerHTML = "CABUMMMMMMM";

                if (jogador == 1){
                    jogador_vitorioso = 2;
                } else if (jogador == 2){
                    jogador_vitorioso = 1;
                }

                document.getElementById("vitoria").innerHTML = "Vitória do Jogador " + jogador_vitorioso;

                enviaComando(jogador_vitorioso);
 
            } else {
                document.getElementById("mensagem").innerHTML = "Te pego na próxima!";
            }

            if (jogador == 1){
                jogador = 2;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 2";
                enviaComando(20);
            } else if (jogador == 2){
                jogador = 1;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 1";
                enviaComando(10);
            }

        }

        function botaoC(){
            var c = document.getElementById("C");
            c.parentNode.removeChild(c);
            document.getElementById("mensagem").innerHTML = "CABUM!!!!!!!!!!!!";

            if (localBomba == "C"){

                var campo_jogo = document.getElementById("campo-jogo");
                campo_jogo.parentNode.removeChild(campo_jogo);

                document.getElementById("mensagem").innerHTML = "CABUMMMMMMM";

                if (jogador == 1){
                    jogador_vitorioso = 2;
                } else if (jogador == 2){
                    jogador_vitorioso = 1;
                }

                document.getElementById("vitoria").innerHTML = "Vitória do Jogador " + jogador_vitorioso;

                enviaComando(jogador_vitorioso);
                
            } else {
                document.getElementById("mensagem").innerHTML = "Agradeça ao seu destino!";
            }

            if (jogador == 1){
                jogador = 2;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 2";
                enviaComando(20);
            } else if (jogador == 2){
                jogador = 1;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 1";
                enviaComando(10);
            }

        }

        function botaoD(){
            var d = document.getElementById("D");
            d.parentNode.removeChild(d);
            document.getElementById("mensagem").innerHTML = "Hoje é seu dia de sorte";

            if (localBomba == "D"){
              
                var campo_jogo = document.getElementById("campo-jogo");
                campo_jogo.parentNode.removeChild(campo_jogo);

                document.getElementById("mensagem").innerHTML = "CABUMMMMMMM";

                if (jogador == 1){
                    jogador_vitorioso = 2;
                } else if (jogador == 2){
                    jogador_vitorioso = 1;
                }

                document.getElementById("vitoria").innerHTML = "Vitória do Jogador " + jogador_vitorioso;

                enviaComando(jogador_vitorioso);

            } else {
                document.getElementById("mensagem").innerHTML = "Usou toda a sua reversa de sorte!";
            }

            if (jogador == 1){
                jogador = 2;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 2";
                enviaComando(20);
            } else if (jogador == 2){
                jogador = 1;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 1";
                enviaComando(10);
            }

        }

        function botaoE(){
            var e = document.getElementById("E");
            e.parentNode.removeChild(e);
            document.getElementById("mensagem").innerHTML = "Hahahahah!";
            
            if (localBomba == "E"){
         
                var campo_jogo = document.getElementById("campo-jogo");
                campo_jogo.parentNode.removeChild(campo_jogo);

                document.getElementById("mensagem").innerHTML = "CABUMMMMMMM";

                if (jogador == 1){
                    jogador_vitorioso = 2;
                } else if (jogador == 2){
                    jogador_vitorioso = 1;
                }

                document.getElementById("vitoria").innerHTML = "Vitória do Jogador " + jogador_vitorioso;

                enviaComando(jogador_vitorioso);

            } else {
                document.getElementById("mensagem").innerHTML = "Quase!!! Mais cuidado na próxima!";
            }

            if (jogador == 1){
                jogador = 2;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 2";
                enviaComando(20);
            } else if (jogador == 2){
                jogador = 1;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 1";
                enviaComando(10);
            }
            
        }

        function botaoF(){
            var f = document.getElementById("F");
            f.parentNode.removeChild(f);
            document.getElementById("mensagem").innerHTML = "Muito esperto!";

            if (localBomba == "F"){
       
                var campo_jogo = document.getElementById("campo-jogo");
                campo_jogo.parentNode.removeChild(campo_jogo);

                document.getElementById("mensagem").innerHTML = "CABUMMMMMMM";

                if (jogador == 1){
                    jogador_vitorioso = 2;
                } else if (jogador == 2){
                    jogador_vitorioso = 1;
                }

                document.getElementById("vitoria").innerHTML = "Vitória do Jogador " + jogador_vitorioso;

                enviaComando(jogador_vitorioso);

            } else {
                document.getElementById("mensagem").innerHTML = "Escapou por uma perna de uma pulga!";
            }

            if (jogador == 1){
                jogador = 2;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 2";
                enviaComando(20);
            } else if (jogador == 2){
                jogador = 1;
                document.getElementById("jogador").innerHTML = "Sua vez, jogador 1";
                enviaComando(10);
            }

        }

    </script>

</body>
</html>

)rawliteral";

void setup(){

    Serial.begin(115200);

    // Declara os pinos dos LEDs que representam os jogadores como output
    pinMode(jogador1, OUTPUT);
    pinMode(jogador2, OUTPUT);

    // Garante que os LEDs estejam desligados no início
    digitalWrite(jogador1, LOW);
    digitalWrite(jogador2, LOW);

    // Inicia a conexão com o Wifi
    WiFi.begin(ssid, password);

    // Exibe esta mensagem enquanto o ESP32 não estiver conectado a rede
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando ao Wifi");
    }

    // Exibe IP do ESP32 
    Serial.println(WiFi.localIP());

    // Definição dos tipos de request
    server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", HTML);
    });

    server.on("/campo-minado", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String informacaoBomba;

    // Se há um tipo de request...
    if (request->hasParam(PARAM_INPUT)) {

        // Consegue a informação do estado da bomba e/ou do jogador
        informacaoBomba = request->getParam(PARAM_INPUT)->value();
        estadoBomba = informacaoBomba;

        // Controla os LEDs de acordo com o valor recebido
        if (estadoBomba == "10"){
            digitalWrite(jogador1, HIGH);
            digitalWrite(jogador2, LOW);
        } else if (estadoBomba == "20"){
            digitalWrite(jogador2, HIGH);
            digitalWrite(jogador1, LOW);
        } else if (estadoBomba == "1"){
            digitalWrite(jogador2, LOW);
            // Pisca LED
            for (int i = 0; i <= 20; i++){
                digitalWrite(jogador1, HIGH);
                delay(500);
                digitalWrite(jogador1, LOW);
                delay(500);
            }

        } else if (estadoBomba == "2"){
            digitalWrite(jogador1, LOW);

        for (int i = 0; i <= 20; i++){
            digitalWrite(jogador2, HIGH);
            delay(500);
            digitalWrite(jogador2, LOW);
            delay(500);
        }
        
        } else if (estadoBomba == "0"){
            digitalWrite(jogador1, LOW);
            digitalWrite(jogador2, LOW);
        }

    }

    else {
        informacaoBomba = "Nenhuma requisição foi feita.";
    }

    request->send(200, "text/plain", "OK");

    });

    // Inicialização
    server.begin();

}
 
void loop(){
}