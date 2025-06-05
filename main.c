#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> // Adicionado para a função de sorteio
#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
#endif

void delay(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

void clean(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

typedef struct cidade{
    char nome[50];
    char estado[50];
    char coordenadas[50];
    char curiosidade[100];
    char pergunta[100];
    char alt1[100];
    char alt2[100];
    char alt3[100];
    int correctAnswer;
} cidade;

// Função para sortear uma cidade aleatoriamente
cidade sortearCidade(cidade cidades[], int totalCidades) {
    int indiceSorteado = rand() % totalCidades;
    return cidades[indiceSorteado];
}

int pontuacao = 0;
// Função para apresentar a pergunta e receber a resposta
void apresentarPergunta(cidade cidadeAtual) {
    printf("Sua pontuação atual é: %d", pontuacao);
    printf("\nPergunta sobre %s:\n", cidadeAtual.nome);
    printf("%s\n", cidadeAtual.pergunta);
    printf("1) %s\n", cidadeAtual.alt1);
    printf("2) %s\n", cidadeAtual.alt2);
    printf("3) %s\n", cidadeAtual.alt3);
    
    int resposta;
    printf("\nDigite o número da alternativa correta: ");
    scanf("%d", &resposta);
    
    if (resposta == cidadeAtual.correctAnswer) {
        printf("\nResposta correta! Parabéns!\n");
        pontuacao += 10;
    } else {
        printf("\nResposta incorreta! A alternativa correta era: %d\n", cidadeAtual.correctAnswer);
    }
    delay(3000);
    clean();
}

void showQuiz(){
    cidade cidades[5] = {
        {"Feira de Santana", "Bahia", "12° 16′ 01″ S, 38° 58′ 01″ O", "TANTO FAZ", "Qual o nome da cidade?", "Teste1", "Teste 2", "Feira", 3},
        {"Salvador", "Bahia", "12° 58′ 16″ S, 38° 30′ 39″ O","TANTO FAZ",  "Qual é a capital da Bahia?", "Teste3", "Teste4", "SSA", 1},
        {"Recife", "Pernambuco", "08° 03′ 14″ S, 34° 52′ 52″ O","TANTO FAZ",  "Qual cidade é conhecida como a Veneza Brasileira?", "Teste5", "Teste6", "REC", 2},
        {"Fortaleza", "Ceará", "03° 43′ 00″ S, 38° 31′ 23″ O","TANTO FAZ",  "Qual cidade é famosa pela Praia do Futuro?", "Teste7", "Teste8", "FOR", 4},
        {"Natal", "Rio Grande do Norte", "05° 47′ 42″ S, 35° 12′ 34″ O", "TANTO FAZ", "Qual cidade é conhecida como a Cidade do Sol?", "Teste9", "Teste10", "NAT", 5}
    };
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    for(int i = 0; i < 5; i++) {
        cidade cidadeSorteada = sortearCidade(cidades, 5);
        printf("Você está na cidade de %s\nEstado: %s\nLocalizada sob as coordenadas: %s\n", 
               cidadeSorteada.nome, cidadeSorteada.estado, cidadeSorteada.coordenadas);
        delay(5000);
        printf("Uma curiosidade sobre %s é que %s\n", cidadeSorteada.nome, cidadeSorteada.estado); //colocar aqui .curiosidades
        delay(5000);
        clean();
                apresentarPergunta(cidadeSorteada);

        
    }
    printf("Sua pontuação final é %d", pontuacao);
}



int main(){
    showQuiz();
    return 0;
}
