# Sistema de Cadastro em C

Programa de terminal para gestão de clientes e produtos, desenvolvido em C como trabalho acadêmico/prático.

## 📋 Funcionalidades

### 👥 Módulo de Clientes
- Cadastro com validação de:
  - **CPF** (formato `XXX.XXX.XXX-XX`)
  - **Telefone** (formato `(XX)XXXXX-XXXX`)
  - **E-mail** (valida presença de `@` e `.`)
  - **Endereço completo** (com validação de siglas de estado brasileiras)

### 📦 Módulo de Produtos
- Cadastro com validação de:
  - Código (campo obrigatório)
  - Nome (campo obrigatório)
  - Preço (apenas valores positivos)
  - Estoque (não aceita valores negativos)

### 📊 Listagens
- Visualização tabular de todos os registros
- Identificação clara quando não há dados cadastrados

## 🛠️ Tecnologias Utilizadas
- Linguagem C pura
- Biblioteca padrão (stdio.h, string.h, ctype.h)
- Validações sem uso de bibliotecas externas


## ▶️ Como Executar
1. Compilação:
gcc cadastro.c -o cadastro -Wall

2. Execução
./cadastro

3. Utilize o menu interativo para:
- Cadastrar clientes/produtos
- Listar registros
- Sair do sistema

## Validações Implementadas

### Clientes:
CPF no formato XXX.XXX.XXX-XX
Telefone no formato (XX)XXXXX-XXXX
E-mail deve conter '@' e '.'
Estado deve ser uma sigla válida do Brasil
Campos obrigatórios não podem ser vazios

### Produtos:
Código e nome não podem ser vazios
Preço deve ser positivo
Quantidade em estoque não pode ser negativa

## Limitações
Armazena dados apenas em memória (perdidos ao sair do programa)
Limite máximo de 100 clientes e 100 produtos
Não permite edição ou exclusão de registros

Autor
Carlos Eduardo Barcelos
