@echo off


IF [%1]==[] ( ECHO ERRO	Arquivo ou pasta faltante
	ECHO.
	ECHO 	Arraste um arquivo ou pasta sobre este icone 
	ECHO.
	pause
	exit )

IF [%1] NEQ [] set /p id="Digite seu nome: "
	set id=%id: =_%
	set /p project="Digite o nome do projeto: "
	set project=%project: =_%
	set "filename=%id%___%project%"
	SET filename=%filename:a=A%
	SET filename=%filename:b=B%
	SET filename=%filename:c=C%
	SET filename=%filename:d=D%
	SET filename=%filename:e=E%
	SET filename=%filename:f=F%
	SET filename=%filename:g=G%
	SET filename=%filename:h=H%
	SET filename=%filename:i=I%
	SET filename=%filename:j=J%
	SET filename=%filename:k=K%
	SET filename=%filename:l=L%
	SET filename=%filename:m=M%
	SET filename=%filename:n=N%
	SET filename=%filename:o=O%
	SET filename=%filename:p=P%
	SET filename=%filename:q=Q%
	SET filename=%filename:r=R%
	SET filename=%filename:s=S%
	SET filename=%filename:t=T%
	SET filename=%filename:u=U%
	SET filename=%filename:v=V%
	SET filename=%filename:w=W%
	SET filename=%filename:x=X%
	SET filename=%filename:y=Y%
	SET filename=%filename:z=Z%
	set "filename=%filename%.zip"
    ..\GPLib\resources\7za.exe a -tzip %filename% %1
	ECHO "Arquivo %filename% criado com sucesso =)"
pause
