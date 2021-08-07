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

A compilação gera um executável com o nome keno dentro da pasta build, __no windows__ esse executável fica na pasta Debug. Logo após a compilação, para executar o programa gerado use os comandos:

  

No linux:

```

./concordo

```

No windows:

```

.\Debug\keno.exe

```

  

## Como executar o conjunto dos testes planejados?

Para executar com o arquivo de aposta ou os arquivos de teste é necessário adicionar o local do arquivo após o comando, exemplo com o teste1.txt:

  

No linux:

```

./concordo < ../teste1.txt


```

No windows:

```

.\Debug\keno.exe ..\data\bet_1.dat

```

  

# Limitações ou funcionalidades não implementadas no programa.
Não conseguimos identificar limitações ou funcionalidades não implementadas no programa.