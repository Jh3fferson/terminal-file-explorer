# Explorador de Arquivos no Terminal (C++)

Um explorador de arquivos simples feito em C++ que roda diretamente no terminal do Windows. Ele permite navegar por diretórios, abrir arquivos, criar e deletar pastas/arquivos, e muito mais.

## ✨ Funcionalidades

- ✅ Navegação com setas ↑ ↓
- 📁 Abrir pastas com Enter
- 🔙 Voltar um diretório com Backspace
- ➕ Criar novo arquivo ou pasta com tecla `n`
- 🗑️ Deletar item selecionado com `Delete`
- 🚪 Sair do programa com `Esc`
- 📂 Abrir arquivos com o programa padrão do sistema (como o Explorador)

## ⚙️ Requisitos

- Sistema Operacional: **Windows**
- Compilador C++ com suporte a C++17 (ou superior)
- Console com suporte a ANSI escape codes (ativado automaticamente)

## 🛠️ Compilação

Você pode compilar com o `g++` assim:

```bash
g++ -o file_explorer main.cpp file_manager.cpp utils.cpp
```

## ▶️ Como usar

No terminal:

```bash
./file_explorer
```

Use os comandos mostrados na interface para interagir com os arquivos e pastas.

## 📂 Estrutura do Projeto

```
.
├── main.cpp
├── file_manager.cpp
├── file_manager.hpp
├── utils.cpp
├── utils.hpp
└── README.md
```

## ❗ Observações

- Este projeto foi feito com foco em aprendizado e prática de C++ com manipulação de arquivos.
- Pode não funcionar corretamente em terminais que não suportem ANSI codes (como o cmd.exe puro em versões antigas do Windows).

---

Feito com 💻 por Jhefferson