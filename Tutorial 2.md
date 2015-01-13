#Criando uma Janela#

Para criar uma janela, onde todos os elementos do jogo serão desenhados, utiliza-se a classe Window, cujo construtor é o seguinte:

```C++
Window(int width, int height, string windowTitle, bool showMouse, bool fullscreen);
```

* *width* é a largura da janela em pixels (valor padrão 800 px); 
* *height* é a altura da janela em pixels (valor padrão 600 px);
* *windowTitle* é o nome da janela        (valor padrão 'GPL Game');
* *showMouse* é um booleano que determina se o cursor do mouse será exibido (valor padrão TRUE);
* *fullscreen* é um booleano que determina se o jogo será em tela cheia ou modo janela (valor padrão TRUE);

Obs.: Para criar um jogo usando a GPL, deve-se, primeiramente, criar a janela e depois todos os demais componentes do jogo. Este procedimento é obrigatório, caso não seja feito ocorrerão erros de execução.

Exemplo 1 - Criação de uma janela com definição de parâmetros, 1024 pixels de largura e 768 pixels de altura
```C++
void main()
{
    //To quit press Alt + F4 
    Window janela(1024, 768, "Meu Querido Jogo", true, false);

    // Game Loop (Loop principal do jogo)
    while(true)
    {
        // Lógica do Jogo
    
        // Atualiza o buffer de pintura (última coisa a ser chamada dentro do loop)
        window.flush();
    }
}
```

Exemplo 2 - Criação de uma janela com os parâmetros padrões, 800 pixels de largura e 600 pixels de altura

```C++
void main()
{
    //To quit press Alt + F4 
    Window janela();
    
    // Game Loop (Loop principal do jogo)
    while(true)
    {
        // Lógica do Jogo

        // Atualiza o buffer de pintura (última coisa a ser chamada dentro do loop)
        window.flush();
    }
}
```
