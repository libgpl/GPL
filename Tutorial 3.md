#Colocando uma imagem como background#

Para a exibição de uma imagem é preciso de uma [Window](Tutorial 2.md), de uma imagem e de um loop.
A Window se faz necessária para exibir as imagens cada frame. 
O loop pode ser considerado o coração do jogo, nele serão colocadas todas as condições de interações e atualizações de gráficos na tela.

Para-se exibir as atualizações utiliza-se o método:

```C++
void flush();  
```

Obs.: O método **flush()** deve ser a última coisa a ser chamada dentro do loop.
Isto se faz necessário, pois este método irá desenha na tela todos os objetos as atualizações realizadas 
durante a iteração do loop.

Exemplo - Criação de uma janela com os parâmetros padrões, 800 pixels de largura e 600 pixels de altura

```C++
void main()
{
    Sprite imagem;
    imagem.load("minhaQueridaImagem.png");

    //To quit press Alt + F4 
    Window janela();
    
    // Game Loop (Loop principal do jogo)
    while(true)
    {
        // Lógica do Jogo
        minhaQueridaImagem.draw(100,200);

        // Atualiza o buffer de pintura (última coisa a ser chamada dentro do loop)
        window.flush();
    }
}
```
