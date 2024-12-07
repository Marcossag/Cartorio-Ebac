#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings
int registro() //Fun��o responsavel por cadastrar os usu�rio no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:\n\n\t "); //coletando iforma��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings. (str)=STRING (CPY)=COPIA
	
	FILE *file; //cria o arquivo no bando de dados
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel = (F) antes do printf � para salvar o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //para separa as variavel
	fclose(file); // file abre o arquivo
	
	printf("\nDigite o nome a ser cadastrado:\n\n\t ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // Abre o arquivo e o "a" atualiza
	fprintf(file,nome); //mostra o nome na tela
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nDigite o sobre nome a ser cadastrado:\n\n\t ");
	scanf("%s",sobrenome); //salva dentro da string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // ("a") de atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n\n\t ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a" );
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n\t ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //ler o arquivo (R = read)
	
	if(file == NULL) //dois cinais de == s�o compara��es
	{
		printf("N�o foi possivel abrir o arquivo, nao localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n\n\t ");
		printf("%s", conteudo);
			
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:\n\n\t ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" de ler
	
	if(file == NULL) //mostra que o arquivo � nulo
	{
		printf("\n O usu�rio foi deletado com sucesso!.\n\n");
		system("pause"); //pausa o sistema de dar loop
	}	
}
	
int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
	system("cls"); //responsavel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
	//inicio do menu
	printf("\n\n\t\tCart�rio da EBAC\t\n\n");
	printf("\tEscolha a op��o desejada do menu\n\n");
	printf("\t1 - Registrar nomes\n\n");
	printf("\t2 - Consultar nomes\n\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("\t4 - Sair do sistema\n\n");
	printf("_ Op��o ");
	//final do menu
	
	scanf("%d", &opcao); //armazenando as escolha do usu�rio
	
	system("cls");
		
		switch(opcao) // inicio da sele��o do menu; o switch case s� consegue falar oque ela for
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();4
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("\tOp��o invalida!\n\n");
			system("pause");
			break;	
		}
	

		
	}
	
}
