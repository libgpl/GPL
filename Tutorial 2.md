Para criar uma janela, onde todos os elementos do jogo serão desenhados, nós usamos a classe Window do pacote JPlay.

O construtor da classe é o seguinte:

```C++
Window(int width, int height, outros parametros);   
```

No lugar de width colocamos o valor da largura da janela em pixels. 
No lugar de height colocamos o valor da altura da janela em pixels.

Obs.: Para criar um jogo usando a GPL, deve-se, primeiramente, criar a janela e depois todos os demais componentes do jogo. Este procedimento é obrigatório, caso não seja feito ocorrerão erros de execução.

Exemplo: Criação de uma janela

```C++
public class Window001  
{  
    //Create and show an window, gray and without borders.  
    //To quit press alt + F4  
    public static void main(String[] args)  
    {  
        //It creates an windows with 800 pixels of width and 600 pixels of height  
        ///This command always has to be the first to be executed.  
        Window janela = new Window(800,600);  
    }  
}
```
