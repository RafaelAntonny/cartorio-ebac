#include <stdio.h>	//Biblioteca I/O (input/output)
#include <stdlib.h> //Biblioteca de alocação de memoria
#include <locale.h> //Biblioteca do char encoding
#include <string.h> //Biblioteca String

int salvarDados(char *string, char *arquivo, FILE *file) // função responsavel por salvar os dados do usuario
{
	file = fopen(arquivo, "a"); // a função abre o arquivo para anexar
	fprintf(file, string);		// a função salva a string dada pelo o usuario no arquivo
	fclose(file);				// fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file, ","); // adicionar uma virgula após a string do usuario ser salva
	fclose(file);
	return 0;
}

typedef int (*FunctionType)(); // nós criamos o tipo função para que nós possamos fazer callbacks

int callback(FunctionType func) // essa é a função que faz o callback
{

	system("cls");

	char opcao; // aqui criamos a variavel para guardar a seleção do usuario

	printf("Você quer continuar usando essa função ?\n");
	printf("Aperte [s]im aperte para continuar ou [n]ão para voltar ao menu\n");
	scanf(" %1c", &opcao);

	system("cls");

	if (opcao == 's') // aqui checamos se o usuario apertou S ou N ou alguma outra coisa
	{
		return func(); // chamamos a função que está sendo atualmente usada recursivamente
	}
	else if (opcao == 'n')
	{
		return 0; // retornamos zero para terminar a função já que o retorno dessa função é um int (as outras funções não tem isso porque elas automaticamente fazem isso)
	}
	else
	{
		printf("Por favor aperte s ou n\n");
	}
}

int registrar() // função responsavel por registrar usuarios
{
	char arquivo[40]; // variaveis que representam o arquivo e os dados do usuario
	char cpf[12];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%11s", cpf); // %11s --> s = string, 11 = só vamos scanear até o char 11

	strcpy(arquivo, cpf);

	FILE *file;					// FILE --> função da biblioteca *file --> ponteiro do arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	salvarDados(cpf, arquivo, file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	salvarDados(nome, arquivo, file);

	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	salvarDados(sobrenome, arquivo, file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	salvarDados(cargo, arquivo, file);

	fclose(file);

	system("pause");

	callback(registrar);
}

int consultar()
{

	setlocale(LC_ALL, "pt_BR.utf8");

	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // busca o arquivo com o CPF dado

	FILE *file;
	file = fopen(cpf, "r"); // abre o arquivo com a intenção de dar read

	if (file == NULL)
	{
		printf("Este CPF não foi encontrado.\n");
	}

	while (fgets(conteudo, 200, file) != NULL) // fgets pega os dados do arquivo, 200 é o tanto de caracteres maximo, e o file = arquivo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}

	system("pause");

	callback(consultar);
}

int deletar() // função responsavel por deletar
{
	setlocale(LC_ALL, "pt_BR.utf8");

	char cpf[40];

	printf("Digite o CPF que você queira deletar: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if (file == NULL)
	{
		printf("O usuario com o CPF: %s, não existe\n", cpf);
		system("pause");
	} else {
		fclose(file);
		remove(cpf); // procuramos o arquivo e deletamos recebendo o paramêtro cpf
	}

	callback(deletar);
}

int main()
{
	int opcao = 0;
	int laco = 1;
	char senhadigitada[10] = "a";
	int comparacao;

	for (laco = 1; laco == 1;)
	{

		system("cls");

		setlocale(LC_ALL, "pt_BR.utf8");
		printf("### Cartório da EBAC ###\n\n");
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s", senhadigitada);

		comparacao = strcmp(senhadigitada, "admin");

		if (comparacao == 0)
		{
			printf("Escolha a opção deseja do menu:\n\n");

			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair \n\n");
			printf("opção: "); // fim do menu que mostra a opção que o usuario selecionou atualmente

			scanf("%d", &opcao);

			system("cls");

			switch (opcao) // inicio da seleção
			{
			case 1:
				registrar();
				break;
			case 2:
				consultar();
				break;
			case 3:
				deletar();
				break;
			case 4:
				printf("Aperte enter novamente para fechar o programa\n");
				return 0; // mesma coisa aqui, como switch case é um if glorificado temos que manualmente terminar a função
				break;
			default:
				printf("opção não existente\n");
				system("pause");
				break;
			} // fim da seleção
		} else
			printf("Senha incorreta");
	}
}
