# Criando um projeto da GPL no Visual Studio#

1. Baixe e instale o Microsoft Visual Studio. 
    
    **Obs: A versão Express do Visual Studio é GRÁTIS**
    
    Links:
[VS2010](http://www.microsoft.com/en-us/download/details.aspx?id=23691),
[VS2012](http://www.microsoft.com/en-pk/download/details.aspx?id=34673)
ou [VS2013](http://www.microsoft.com/en-us/download/details.aspx?id=44914);

2. Baixe e salve o pacote *.zip* que contém o biblioteca GPL [link](https://github.com/libgpl/GPL/archive/master.zip);
3. Descompacte o arquivo .zip baixado em uma pasta;
4. Na pasta descompactada *GPL > projects*, crie uma cópia da pasta base_VS e renomeie-a com o nome de seu projeto;
5. Acesse a pasta de seu projeto e abra o arquivo *base.vcxproj*;
6. O Visual Studio se abrirá com seu projeto, contendo o código a seguir:

```C++
#include <gpl.h>

void main()
{
	// Seção de carregamento de assets

	Window window(800,600,"Título da Janela",true,false);	// Inicializa a biblioteca

	while (!isKeyDown(KEY::Escape))		// Loop principal do jogo
    {
		// Lógica do Jogo
		
		window.flush();		// Atualiza a tela - última coisa a ser chamada dentro do loop
    }
}
```
