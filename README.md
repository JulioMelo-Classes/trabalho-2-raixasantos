# Projeto 2: Concordo

Clone do Discord, para humanos mais civilizados.

# Como compilar?

## Usando CMake...
A compilação e execução do trabalho será feita usando CMake, para executá-lo faremos:

  

```

cd trabalho-2-raixasantos (ou o nome da pasta em que o projeto se encontra)

mkdir build && cd build

cmake ..

cmake --build .

```

  

# Como executar o projeto?

A compilação gera um executável com o nome concordo dentro da pasta build, __no windows__ esse executável fica na pasta Debug. Logo após a compilação, para executar o programa gerado use os comandos:

  

No linux:

```

./concordo

```

No windows:

```

.\Debug\concordo.exe

```

  

## Como executar o conjunto dos testes planejados?

Para executar com o arquivo de aposta ou os arquivos de teste é necessário adicionar o local do arquivo após o comando, exemplo com o teste1.txt:

  

No linux:

```

./concordo < ../teste1.txt


```

No windows:

```

# Basta copiar o conteúdo do arquivo que será executado em ordem

```

  

# Limitações ou funcionalidades não implementadas no programa.
Encontrar uma forma mais prática de executar com arquivos de forma mais prática.
