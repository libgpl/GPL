# Criando um projeto da GPL no Visual Studio#

1. Baixe e instale o Microsoft Visual Studio. 
    
    **Obs: A versão Express do Visual Studio é GRÁTIS**
    
    Link:
[VS2013](http://www.microsoft.com/en-us/download/details.aspx?id=44914);

2. Baixe e salve o pacote *.zip* que contém o biblioteca GPL [link](https://github.com/libgpl/GPL/archive/master.zip);
3. Descompacte o arquivo .zip baixado em uma pasta;
4. Na pasta descompactada *GPL > projects*, crie uma cópia da pasta base e renomeie-a com o nome de seu projeto;
5. Acesse a pasta de seu projeto e abra o arquivo *base.vcxproj*;
6. O Visual Studio se abrirá com seu projeto, contendo o código a seguir:

```C++
#include "gpl.hpp"

void main()
{
        // It creates an windows with 800 pixels of width and 600 pixels of height in fullscreeen mode  
        // This command always has to be the first to be executed.
        Window janela();

	// Assets load section

	// GAME MAIN LOOP
	while (!input->isPressed(KEY::Escape))
    {

        // This command always has to be the last to be executed.
		janela.flush();
    }
}
```
