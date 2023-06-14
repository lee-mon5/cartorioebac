#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings
 
int registro() //Função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
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
	file = fopen(cpf,"r"); //abre o arquivo e se é lido a variavel armazenada com o "r"
	
	if(file == NULL) //se o arquivo for comparado a nada 
	{
		printf("Não foi possivel abrir o arquivo,não localizado!.\n");
	} //esse texto aparece
	
	while(fgets(conteudo,200,file) != NULL) // o while é um operador de repetição,enquanto sua condição não for alcançada( a condição é o que declaramos entre os parênteses ) a ação continuará acontecendo ( a ação é o que declaramos dentro das chaves ).
	
	{	
	    printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); 
	
}
int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
    
	remove(cpf);
	
    if(file == NULL)
	{  
		printf("O usuário não se encontra no sistema!.\n");
		fclose(file);
	}
	  
	if(file != NULL) //se o arquivo for diferente que nada ou seja ele existe
	{
		printf("\nUsuário deletado com sucesso!\n\n");
		fclose(file);
	}
	
	
	
	system("pause");
}



int main()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");
	
	    setlocale (LC_ALL,"Portuguese"); //Definindo a linguagem
	
        printf ("### Cartório da EBAC ###\n\n"); //Inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n");
        printf("Opção:"); //Fim do menu
    
        scanf ("%d", &opcao); //Armazenando a escolha do usuário
	
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
	        printf("Essa opção não está disponivel!\n");
		    system("pause");
	        break; 
		}     
    }
}

