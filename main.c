#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
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

void clean() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

typedef struct cidade {
    char nome[50];
    char estado[50];
    char coordenadas[100];
    char curiosidade[150];
    char pergunta[150];
    char alt1[100];
    char alt2[100];
    char alt3[100];
    int correctAnswer;
} cidade;

int pontuacao = 0;

void embaralharCidades(cidade cidades[], int total) {
    for (int i = total - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        cidade temp = cidades[i];
        cidades[i] = cidades[j];
        cidades[j] = temp;
    }
}

void apresentarPergunta(cidade cidade) {
    // 1. Mensagem carregando
    clean();
    printf("Um momento...\nEstamos te transportando para uma nova aventura!\n");
    printf("Carregando informações sobre a cidade...\n");
    delay(1500);

    // 2. Cidade e coordenadas


    // 3. Pergunta e alternativas
    clean();
    printf("Curiosidade: %s\n\n", cidade.curiosidade);
    printf("%s\n", cidade.pergunta);
    printf("1) %s\n", cidade.alt1);
    printf("2) %s\n", cidade.alt2);
    printf("3) %s\n", cidade.alt3);

    int resposta;
    printf("\nDigite o número da alternativa correta: ");
    scanf("%d", &resposta);
    while(getchar() != '\n');

    // 4. Resposta e explicação
    clean();
    if (resposta == cidade.correctAnswer) {
        printf("Resposta correta! +10 pontos.\n\n");
        pontuacao += 10;
    } else {
        printf("Resposta incorreta! A resposta correta era: %d\n\n", cidade.correctAnswer);
    }
    printf("Você está na cidade de %s\n", cidade.nome);
    printf("Estado: %s\n", cidade.estado);
    printf("Coordenadas: %s\n", cidade.coordenadas);
    delay(5000);
    clean();

}

void showQuiz() {
cidade cidades[25] = {
    {"Feira de Santana", "Bahia", "12\xB0 16' 01\" S, 38\xB0 58' 01\" O",
     "Maior cidade do interior nordestino.",
     "Qual cidade baiana é um dos principais entroncamentos rodoviários do Brasil?",
     "Juazeiro", "Feira de Santana", "Petrolina", 2},

    {"Salvador", "Bahia", "12\xB0 58' 16\" S, 38\xB0 30' 39\" O",
     "Primeira capital do Brasil.",
     "Qual cidade é famosa pelo Pelourinho e pelo Elevador Lacerda?",
     "São Paulo", "Salvador", "Rio de Janeiro", 2},

    {"Recife", "Pernambuco", "08\xB0 03' 14\" S, 34\xB0 52' 52\" O",
     "Tem mais pontes que Veneza.",
     "Qual cidade nordestina é chamada de Veneza Brasileira?",
     "Natal", "Recife", "Fortaleza", 2},

    {"Fortaleza", "Ceará", "03\xB0 43' 00\" S, 38\xB0 31' 23\" O",
     "Famosa pela Praia do Futuro.",
     "Qual cidade sedia o Beach Park, um dos maiores parques aquáticos do país?",
     "João Pessoa", "Maceió", "Fortaleza", 3},

    {"Natal", "Rio Grande do Norte", "05\xB0 47' 42\" S, 35\xB0 12' 34\" O",
     "Conhecida como Cidade do Sol.",
     "Qual cidade abriga o Forte dos Reis Magos?",
     "São Luís", "Recife", "Natal", 3},

    {"Belo Horizonte", "Minas Gerais", "19\xB0 55' 15\" S, 43\xB0 56' 16\" O",
     "Famosa pela Pampulha e pão de queijo.",
     "Qual cidade abriga o estádio Mineirão?",
     "Contagem", "Uberlândia", "Belo Horizonte", 3},

    {"São Paulo", "São Paulo", "23\xB0 33' 01\" S, 46\xB0 38' 02\" O",
     "Maior cidade da América do Sul.",
     "Qual cidade é atravessada pela Avenida Paulista?",
     "São Paulo", "Rio de Janeiro", "Belo Horizonte", 1},

    {"Rio de Janeiro", "Rio de Janeiro", "22\xB0 54' 30\" S, 43\xB0 11' 47\" O",
     "Famosa pelo Cristo Redentor.",
     "Qual cidade tem o Maracanã e o Pão de Açúcar como atrações turísticas?",
     "Rio de Janeiro", "São Paulo", "Brasília", 1},

    {"Curitiba", "Paraná", "25\xB0 25' 40\" S, 49\xB0 16' 23\" O",
     "Conhecida pela organização urbana.",
     "Qual cidade é famosa pelo Jardim Botânico com estufa de vidro?",
     "Joinville", "Curitiba", "Londrina", 2},

    {"Porto Alegre", "Rio Grande do Sul", "30\xB0 01' 59\" S, 51\xB0 13' 48\" O",
     "Capital dos gaúchos.",
     "Qual cidade é banhada pelo Lago Guaíba?",
     "Caxias do Sul", "Pelotas", "Porto Alegre", 3},

    {"Manaus", "Amazonas", "03\xB0 06' 08\" S, 60\xB0 01' 30\" O",
     "Porta de entrada para a Amazônia.",
     "Qual cidade abriga o Teatro Amazonas?",
     "Belém", "Manaus", "Rio Branco", 2},

    {"Belém", "Pará", "01\xB0 27' 31\" S, 48\xB0 29' 20\" O",
     "Famosa pelo Círio de Nazaré.",
     "Qual cidade tem o tradicional Mercado Ver-o-Peso?",
     "Belém", "São Luís", "Macapá", 1},

    {"Florianópolis", "Santa Catarina", "27\xB0 36' 30\" S, 48\xB0 31' 40\" O",
     "Conhecida como Ilha da Magia.",
     "Qual cidade abriga a Ponte Hercílio Luz?",
     "Joinville", "Florianópolis", "Blumenau", 2},

    {"João Pessoa", "Paraíba", "07\xB0 07' 02\" S, 34\xB0 51' 52\" O",
     "Tem o pôr do sol mais oriental do continente americano.",
     "Qual cidade tem o Farol do Cabo Branco?",
     "Natal", "João Pessoa", "Maceió", 2},

    {"Maceió", "Alagoas", "09\xB0 39' 14\" S, 35\xB0 43' 30\" O",
     "Famosa pelas praias de água cristalina.",
     "Qual cidade possui as famosas piscinas naturais de Pajuçara?",
     "Fortaleza", "Aracaju", "Maceió", 3},

    {"Campinas", "São Paulo", "22\xB0 54' 18\" S, 47\xB0 03' 17\" O",
     "Importante polo tecnológico do estado.",
     "Qual cidade abriga a Unicamp, uma das principais universidades do Brasil?",
     "Campinas", "Ribeirão Preto", "São Carlos", 1},

    {"Vitória", "Espírito Santo", "20\xB0 19' 18\" S, 40\xB0 20' 43\" O",
     "Conhecida pelas praias e pela Ilha de Vitória.",
     "Qual cidade é ligada à Vila Velha pela Terceira Ponte?",
     "Serra", "Vitória", "Cariacica", 2},

    {"Cuiabá", "Mato Grosso", "15\xB0 35' 42\" S, 56\xB0 06' 48\" O",
     "Porta de entrada para o Pantanal.",
     "Qual cidade é conhecida por ser o centro geodésico da América do Sul?",
     "Cuiabá", "Campo Grande", "Sinop", 1},

    {"Campo Grande", "Mato Grosso do Sul", "20\xB0 26' 19\" S, 54\xB0 38' 48\" O",
     "Famosa pelo comércio e cultura indígena.",
     "Qual cidade é conhecida como Cidade Morena?",
     "Corumbá", "Dourados", "Campo Grande", 3},

    {"Goiânia", "Goiás", "16\xB0 40' 00\" S, 49\xB0 16' 00\" O",
     "Conhecida pela arquitetura modernista e parques.",
     "Qual cidade foi planejada para ser capital de Goiás?",
     "Goiânia", "Anápolis", "Itumbiara", 1},

    {"Aracaju", "Sergipe", "10\xB0 54' 29\" S, 37\xB0 03' 33\" O",
     "Famosa pelas praias e pelo forró.",
     "Qual cidade é cortada pelo rio Sergipe?",
     "Natal", "Aracaju", "Maceió", 2},

    {"Teresina", "Piauí", "05\xB0 05' 33\" S, 42\xB0 48' 25\" O",
     "Única capital nordestina localizada no interior do estado.",
     "Qual cidade é banhada pelos rios Poti e Parnaíba?",
     "João Pessoa", "São Luís", "Teresina", 3},

    {"Palmas", "Tocantins", "10\xB0 11' 30\" S, 48\xB0 20' 30\" O",
     "Capital mais jovem do Brasil.",
     "Qual cidade foi construída para ser a capital do Tocantins?",
     "Palmas", "Gurupi", "Araguaína", 1},

    {"Boa Vista", "Roraima", "02\xB0 49' 41\" N, 60\xB0 40' 30\" O",
     "Única capital brasileira situada ao norte da linha do Equador.",
     "Qual cidade tem um centro urbano projetado em forma de leque?",
     "Rio Branco", "Boa Vista", "Manaus", 2},

    {"Macapá", "Amapá", "00\xB0 02' 36\" N, 51\xB0 03' 30\" O",
     "A linha do Equador passa pelo meio da cidade.",
     "Qual cidade brasileira não possui ligação rodoviária com outras capitais?",
     "Boa Vista", "Belém", "Macapá", 3}
};


    srand(time(NULL));
    embaralharCidades(cidades, 10);

    for (int i = 0; i < 10; i++) {
        apresentarPergunta(cidades[i]);
    }

    clean();
    printf("\nFim do quiz!\nSua pontuação final foi: %d\n\n", pontuacao);
    if (pontuacao >= 70) {
        printf("Parabéns, aventureiro!\n");
        printf("Você demonstrou um grande conhecimento sobre as cidades brasileiras!\n");
        printf("Continue explorando e aprendendo mais sobre o Brasil!\n");

    } else {
        printf("Continue estudando e explorando as cidades brasileiras!\n");
        printf("Você pode melhorar sua pontuação na próxima vez!\n");
    }

    delay(5000);
    clean();
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    showQuiz();
    return 0;
}
