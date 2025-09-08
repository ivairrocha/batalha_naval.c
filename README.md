# 🚢 Projeto Final - Batalha Naval com Habilidades Especiais

📌 **Autor:** Ivair Rocha  
📌 **Disciplina:** Vetores e Matrizes  
📌 **Desafio:** Nível Mestre  

---

## 📖 Descrição do Projeto
Este projeto expande o jogo de **Batalha Naval**, adicionando **habilidades especiais com áreas de efeito** que podem ser aplicadas sobre o tabuleiro.  

As habilidades implementadas foram:  

- **Cone** → área em formato triangular (expande de cima para baixo).  
- **Cruz** → linha e coluna centrais.  
- **Octaedro** → formato de losango, representando a vista frontal de um octaedro.  

Cada habilidade é representada por uma **matriz de 5x5**, onde:  
- `1` = posição afetada pela habilidade  
- `0` = posição não afetada  

No tabuleiro 10x10:  
- `0` = água (~)  
- `3` = navio (N)  
- `5` = área de habilidade (X)  

---

## ⚙️ Tecnologias Utilizadas
- Linguagem **C**
- Compilador **GCC**

---

## ▶️ Como Executar
1. Clone este repositório ou baixe os arquivos.  
2. Compile o programa:  
   ```bash
   gcc batalha_naval.c -o batalha
