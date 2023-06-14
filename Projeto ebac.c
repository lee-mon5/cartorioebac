#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings
 
int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen (arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf (file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadatrado:");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale (LC_ALL,"Portuguese");
	 
	char cpf[40]; //definindo as variaveis
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf); 
	
	FILE *file; //nos arquivos se cria um arquivo
	file = fopen(cpf,"r"); //abre o arquivo e se � lido a variavel armazenada com o "r"
	
	if(file == NULL) //se o arquivo for comparado a nada 
	{
		printf("N�o foi possivel abrir o arquivo,n�o localizado!.\n");
	} //esse texto aparece
	
	while(fgets(conteudo,200,file) != NULL) // o while � um operador de repeti��o,enquanto sua condi��o n�o for alcan�ada( a condi��o � o que declaramos entre os par�nteses ) a a��o continuar� acontecendo ( a a��o � o que declaramos dentro das chaves ).
	
	{	
	    printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); 
	
}
int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
    
	remove(cpf);
	
    if(file == NULL)
	{  
		printf("O usu�rio n�o se encontra no sistema!.\n");
		fclose(file);
	}
	  
	if(file != NULL) //se o arquivo for diferente que nada ou seja ele existe
	{
		printf("\nUsu�rio deletado com sucesso!\n\n");
		fclose(file);
	}
	
	
	
	system("pause");
}



int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");
	
	    setlocale (LC_ALL,"Portuguese"); //Definindo a linguagem
	
        printf ("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n");
        printf("Op��o:"); //Fim do menu
    
        scanf ("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls");
    	
    	switch (opcao)
    	{
    		case 1:
    	    registro();
	        break;
	
            case 2:	
	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!");
	        return 0;
	        break;
	        
	        default:
	        printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
	        break; 
		}     
    }
}

