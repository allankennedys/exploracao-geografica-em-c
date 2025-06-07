# EQUIPE:

Allan Kennedy Santos Pinho, 
Felipe Santos de Oliveira, 
Murilo Silva Ribeiro,
Lucas Kevyn Pereira Araujo


# 🧠 Quiz Cidades Brasileiras 🇧🇷

Este é um jogo de perguntas e respostas em C sobre cidades do Brasil. A cada rodada, o jogador é "transportado" para 10 cidades aleatórias e responde a uma pergunta sobre cada uma. As perguntas vêm acompanhadas de curiosidades e informações geográficas, tornando o jogo educativo e divertido.

## 🎮 Como jogar

1. Compile o código com um compilador C moderno e atualizado (como gcc).

2. Execute o jogo.

3. Responda às perguntas escolhendo uma alternativa entre 1, 2 ou 3.

4. No final, sua pontuação será exibida com uma mensagem personalizada.


## ⚙️ Compatibilidade com sistemas operacionais

O jogo possui diretivas de pré-processamento `#ifdef` que garantem sua execução tanto no Windows quanto no Linux/MacOS:

- **Limpar a tela (clean)**:
  ```c
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
  ```

- **Delay de milissegundos (delay)**:
  ```c
  #ifdef _WIN32
      Sleep(ms); // função do Windows
  #else
      usleep(ms * 1000); // função do POSIX
  #endif
  ```

Isso permite que o jogo tenha uma experiência semelhante em diferentes sistemas, como limpar a tela entre perguntas e inserir pausas temporais para narrativa.

## 📦 Estrutura do jogo

- As informações sobre as cidades (nome, estado, coordenadas, curiosidades e perguntas) estão armazenadas em uma `struct`.
- Cada execução do jogo sorteia 10 cidades aleatórias entre 25 disponíveis.
- O jogador ganha 10 pontos por resposta correta.
- Ao final do quiz, a pontuação é exibida com um feedback motivacional.

## 💡 Melhorias futuras

- Acrescentaremos a funcionalidade de exibir a trilha com as cidades pelas quais o jogador passou, utilizando uma pilha.

## 
Este projeto foi desenvolvido com foco educacional e pode ser expandido conforme o interesse em C e desenvolvimento de jogos simples via terminal.
