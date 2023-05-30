#include <stdio.h> //Bibioteca de comunica��o com o usuario
#include <stdlib.h> //Bibioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //Bibioteca de aloca��es de textos por regi�es
#include <string.h> //Bibioteca reponsavel por cuidar das strings



int registro() //Fun��o respons�vel por cadastrar usu�rio
{
	//Cria��o de variavel
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Final da Cria��o de variavel
	
	printf("Digite o CPF: "); //Coleta a resposta do usuario
	
	scanf("%s",&cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Copia os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva os valores das variaveis
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite seu nome: ");
	scanf("%s",&nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s",&sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s",&cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo linguagem
	
	//Cria��o de variavel
	
	char cpf[40];
	char conteudo[200];
	
	//Final da Cria��o de variavel
	
	printf("Digite o cpf que deseja consultar: ");
	scanf("%s",&cpf); //%s refere-se a strings
	
	FILE *file;
	
	file = fopen(cpf,"r");
	
	if(file == NULL )
	{
		printf("Nao encontrei esse nome :(\n");
	}

	while(fgets(conteudo,200,file) != NULL) //while=enquanto... fgets=ler caracteres strings da variavel conteudo com 200 slots
	{
		printf("\nEssas s�o as informa��es do usuario");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar: ");
	scanf("%s",&cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	remove(cpf);
	
	if(file == NULL)
	{
		printf("Nao encontrei esse CPF no sistema :(\n");
		system("pause");
	}
	
		if(file != NULL)
	{
		printf("CPF deletado do sistema :)\n");
		system("pause");
	}

}


int main() //Definindo vari�veis
{	
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	
		printf("### Cart�rio EBAC ###\n\n"); //Inicio o menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1-Registrar nomes\n");
		printf("\t2-Consultar nomes\n");
		printf("\t3-Deletar nomes\n"); 
		printf("\t4-Sair do programa\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d",&opcao); //Armazenando a escolha
	
		system("cls"); //Limpando a tela
	
	switch(opcao)
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
		printf("Obrigado por tudo e at� a proxima!");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o esta dispon�vel!\n");
		system("pause");
	}
	}
}
