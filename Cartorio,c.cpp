#include <stdio.h> //Biblioteca de comunicação com o usuário.
#include <stdlib.h> //Biblioteca de alocação de espaço.
#include <locale.h> //Biblioteca de alocação de texto por região.
#include <string.h> //Biblioteca responsável por cuidar das strings.

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf);//Responsável com copiar os valores das strings.
	
	FILE *file; //Cria o arquivo. 
	file = fopen(arquivo,"w");//Cria o arquivo.
	fprintf(file,cpf);//Salva o valor da variável.
	fclose(file);//Fecha o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas são as informações do usuário:  ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		;printf("O usuário não se encontra o sistema!.\n");
		system("pause");
	}
	
	
}

int main()
{
    int opcao=0;//Defininfo variáveis.
    
    int x=1;//
    
    for(x=1;x=1;)//Repetição
    {
	
        system("cls");
        
	    setlocale(LC_ALL, "Portuguese");// Definindo a linguagem.
	
	    printf("### Cartório da EBAC ###\n\n");//Início do menu.
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção:");//Fim do Menu.
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário.
	
	    system("cls");//Limpar a tela do Menu, Clean Screen;
	    
	    switch(opcao)//Início da seleção.
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
		    printf("Obrigado por usar esse sistema!");
		    return 0;
		    break;
		    
		    default:
		    printf("Essa opção não existe!\n");
		    system("pause");
		    break;
		    	
	    }//Fim da seleção.
    }
}
