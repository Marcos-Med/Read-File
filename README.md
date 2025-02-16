# 📖 Indexador e Buscador de Palavras  

## 📋 Descrição  

Este projeto foi desenvolvido em **C** como parte da disciplina de **Algoritmos e Estrutura de Dados 1**. O programa permite buscar palavras em um arquivo de texto e exibe:  
- O número de ocorrências da palavra no texto.  
- As linhas onde cada ocorrência foi encontrada.  
- O tempo de execução para cada busca.  
- O tempo de construção da estrutura de dados utilizada (**lista** ou **árvore**).  

## 🛠️ Funcionalidades  

1. Buscar palavras em arquivos `.txt`.  
2. Exibir o número de ocorrências e linhas das palavras encontradas.  
3. Escolha entre duas estruturas de dados: **lista** ou **árvore**.  
4. Medir o tempo de execução:  
   - Para criar a estrutura de dados.  
   - Para realizar a busca.  

## 🚀 Como Utilizar  

### Pré-requisitos  
- Sistema com suporte a **GCC** (compilador C).  
- Um terminal ou PowerShell para compilar e executar o programa.  

### Passo a Passo  

1. Clone ou baixe este repositório no seu computador.  

2. Compile o programa:  
   No terminal, navegue até o diretório onde o arquivo `program.c` está localizado e execute:  
   ```bash
   gcc -o program program.c
   ```  

3. Execute o programa, escolhendo o arquivo de texto e a estrutura de dados:  
   ```bash
   ./program texto.txt arvore
   ```  
   ou  
   ```bash
   ./program texto.txt lista
   ```  

4. O programa retornará:  
   - O número de ocorrências da palavra.  
   - As linhas onde a palavra foi encontrada.  
   - Os tempos de execução da busca e construção da estrutura.  


## 🛠️ Tecnologias  

- **Linguagem C**  
- **GCC**: Para compilar o código  
