# Sobre
O Chip-8 é uma linguagem de programação interpretada, desenvolvida originalmente por Joseph Weisbecker nos anos 70 para ser usada em microcomputadores de 8 bits, como o COSMAC VIP e o Telmac 1800. Embora simples, o Chip-8 pode ser considerado uma espécie de “console de videogame virtual” ou uma máquina virtual simplificada. Sua especificação inclui um conjunto de instruções (opcodes), uma organização de memória, registradores, e mecanismos de entrada e saída.

Por sua simplicidade e arquitetura bem definida, a implementação de um interpretador Chip-8 tornou-se um rito de passagem popular para estudantes e entusiastas interessados em aprender sobre emulação, interpretação de bytecode e o funcionamento de máquinas virtuais.

# Dependências
- Compilador C++20 ou superior;
- CMake 3.10 ou superior;
- Makefile;
- SDL2 instalada no sistema. Caso o CMake não a encontre, você pode editar o arquivo `CMakeLists.txt` e fornecer o caminho correto da SDL, ou deixar o CMake a compilar do zero a partir do submódulo (external/SDL);
- A biblioteca `argparse` está sendo utilizada para tratar os argumentos do programa. O CMake também faz a inclusão dela automaticamente.

# Compilação
Lembre de clonar o repositório com `--recursive` para clonar os submódulos necessários para a compilação funcionar como esperado.

Para compilar o código, use o comando `cmake --preset debug|release` na pasta raiz do projeto. Você pode escolher se quer compilar em modo debug ou release. Após isso, será criado uma pasta do build com o nome `build/{CMAKE_BUILD_TYPE}`, entre nela e execute o comando `make`. Todos os arquivos serão compilados e o executável terá o nome `Chip8`.

# Uso
Pode se executar `./Chip8 -h` para ver as opções, e as seguintes informações serão dispostas na tela:

```
Usage: Chip8 [--help] [--version] [--scale VAR] [--clock VAR] [--address VAR] ROM_PATH

Positional arguments:
  ROM_PATH       Chip8 ROM file location [required]

Optional arguments:
  -h, --help     shows help message and exits 
  -v, --version  prints version information and exits 
  -s, --scale    Amount of times the screen will be multiplied by [nargs=0..1] [default: 13]
  -c, --clock    Amount of instructions the program will run each second [nargs=0..1] [default: 500]
  -a, --address  Address to where the PC will start. This might break sprites rendering, be careful [nargs=0..1] [default: 512]
```

Exemplo para rodar o Chip8 com uma rom:

```sh
./Chip8 roms/c8games/MAZE -c 1000 -s 10
```

É necessário informar a rom do programa a ser executado pelo emulador. Na pasta do build terá um diretório `roms` com vários programas disponíveis para teste.

O teclado do emulador está mapeado para a seguinte configuraçao:
| Tecla CHIP-8 (Hex) | Tecla Física Correspondente |
| :------------------------: | :-------------------------: |
| **1** | `1` |
| **2** | `2` |
| **3** | `3` |
| **C** | `4` |
| **4** | `Q` |
| **5** | `W` |
| **6** | `E` |
| **D** | `R` |
| **7** | `A` |
| **8** | `S` |
| **9** | `D` |
| **E** | `F` |
| **A** | `Z` |
| **0** | `X` |
| **B** | `C` |
| **F** | `V` |

# Referências
- Artigo de especificaçao que nos baseamos: [
Guide to making a CHIP-8 emulator](https://tobiasvl.github.io/blog/write-a-chip-8-emulator/). Esse artigo se demonstrou mais preciso e detalhista nas especificaçoes do Chip8;

- Utilizamos o repositório [chip8-test-suite](https://github.com/Timendus/chip8-test-suite) para realizar os testes das instruções implementadas. Foi de imensa ajuda, e sem as roms de teste, não conseguiriamos identificar os problemas e progredir no emulador;

- Link para o pack de rom dos jogos: [c8games](ttps://www.zophar.net/pdroms/chip8/chip-8-games-pack.html).

# Autores
BCC6002 - Aspectos De Linguagens De Programação | UTFPR-CM | 2025/1

**Eduardo Kurek & Vinicius Kurek**
