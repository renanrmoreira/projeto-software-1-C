#include <stdio.h>  //funções padrão de entrada e saída
#include <stdlib.h> //usadas neste programa para gerar números aleatórios.
#include <time.h>   // inicializar o gerador de números aleatórios com uma semente baseada no tempo atual do sistema.

int perguntasRespostas()
{
    char resposta;
    int pontos = 0, check, jogarDenovo = 1;

    do
    {
        printf("----------------------------------------------\n");
        printf("Bem vindo ao jogo de perguntas e respostas\n ");
        printf("----------------------------------------------\n");

        printf("Primeira pergunta\n");
        printf("1. Qual foi o primeiro imperador do Brasil?\n");
        printf("A) Pedro I\n");
        printf("B) Pedro II\n");
        printf("C) Dom Joao VI\n");
        printf("D) Getulio Vargas\n");
        printf("Resposta: ");
        scanf(" %c", &resposta);

        if (resposta == 'A' || resposta == 'a')
        {
            printf("ACERTOU!!");
            pontos++;
        }
        else
        {
            printf("ERROU :/ Reposta correta -> A) Pedro I");
        }

        printf("Segunda pergunta\n");
        printf("\n2. Qual eh o maior rio do mundo em volume de agua?\n");
        printf("A) Rio Nilo\n");
        printf("B) Rio Amazonas\n");
        printf("C) Rio Mississipi\n");
        printf("D) Rio Yangtze\n");
        printf("Resposta: ");
        scanf(" %c", &resposta);

        if (resposta == 'B' || resposta == 'b')
        {
            printf("ACERTOU!!");
            pontos++;
        }
        else
        {
            printf("ERROU :/ Reposta correta -> B) Rio Amazonas");
        }

        printf("Terceira pergunta\n");
        printf("\n3. Qual eh a maior cadeia de montanhas do mundo?\n");
        printf("A) Cordilheira dos Andes\n");
        printf("B) Montanhas Rochosas\n");
        printf("C) Himalaias\n");
        printf("D) Alpes\n");
        printf("Resposta: ");
        scanf(" %c", &resposta);

        if (resposta == 'C' || resposta == 'c')
        {
            printf("ACERTOU!!");
            pontos++;
        }
        else
        {
            printf("ERROU :/ Reposta correta -> C) Himalaias");
        }

        printf("\nQuarta pergunta\n");
        printf("\n4. Qual eh o país mais populoso do mundo?\n");
        printf("A) China\n");
        printf("B) India\n");
        printf("C) Estados Unidos\n");
        printf("D) Russia\n");
        printf("Resposta: ");
        scanf(" %c", &resposta);

        if (resposta == 'A' || resposta == 'a')
        {
            printf("ACERTOU!!");
            pontos++;
        }
        else
        {
            printf("ERROU :/ Reposta correta -> A) China");
        }

        printf("\nQuinta pergunta\n");
        printf("\n5. Qual foi o primeiro pais a abolir a escravidao na America Latina?\n");
        printf("a) Brasil\n");
        printf("b) Mexico\n");
        printf("c) Cuba\n");
        printf("d) Haiti\n");
        printf("Resposta: ");
        scanf(" %c", &resposta);

        if (resposta == 'D' || resposta == 'd')
        {
            printf("ACERTOU!!");
            pontos++;
        }
        else
        {
            printf("ERROU :/ Reposta correta -> D) Haiti\n");
        }

        printf("Fim de jogo!\n");
        printf("Score: %d\n", pontos);
        printf("1- Voltar ao menu \n2- Jogar novamente \n3- Sair\n");
        scanf(" %d", &check);

        if (check == 1)
        {
            printf("Obrigado por jogar\n");
            jogarDenovo = 0;
            return 0;
        }
        else if (check == 2)
        {
            printf("Iniciando o jogo novamente\n");
            continue;
        }
        else if (check == 3)
        {
            printf("Obrigador por jogar\n");
            jogarDenovo = 0;
            return 1;
        }

        else
        {
            printf("Valor invalido\n");
            return 0;
        }
    } while (jogarDenovo == 1);
}

int cobraNaCaixa()
{
    char jogador1[50], jogador2[50];
    int check, jogarDenovo=1;
    int caixas[5] = {0, 0, 0, 0, 0};
    int primeiroJogador, escolhaCaixa, cobra, botao, jogadorAtual = 0;

    do{
        srand(time(0));
        primeiroJogador = rand() % 2;
        cobra = (rand() % 5) + 1;
        botao = (rand() % 5) + 1;

        while (cobra == botao) {
            botao = rand() % 5;
        }

        caixas[cobra] = 1;
        caixas[botao] = 2;

        printf("Digite o nome do primeiro jogador: ");
        scanf(" %s", &jogador1);
        printf("Digite o nome do segundo jogador:  ");
        scanf(" %s", &jogador2);

        if(primeiroJogador == 0){
            printf("Primeiro jogar: %s \n", jogador1);
        }else{
            printf("Primeiro jogar: %s \n", jogador2);
        }

        while (1)
        {
            printf("Escolha uma caixa de 1 a 5: ");
            scanf("%d", &escolhaCaixa);

            if (escolhaCaixa < 0 || escolhaCaixa > 5) {
                printf("Escolha invalida. Tente novamente.\n");
                continue;
            }

            if(caixas[escolhaCaixa] == -1) {
                printf("Caixa ja escolhida \n");
                continue;
            }

            if (caixas[escolhaCaixa] == 1) {
                printf("DERROTA! Jogador encontrou a cobra! Fim de jogo.\n");
                break;
            } else if (caixas[escolhaCaixa] == 2) {
                printf("VENCEU! Jogador encontrou o botao! Fim de jogo.\n");
                break;
            }else{
                printf("Caixa vazia. Vez do proximo jogador.\n");
                caixas[escolhaCaixa] = -1;
                jogadorAtual = (jogadorAtual + 1) % 2;
            } 


        }
        
        printf("1- Voltar ao menu \n2- Jogar novamente \n3- Sair\n");
        scanf(" %d", &check);

        if (check == 1)
        {
            printf("Obrigado por jogar\n");
            jogarDenovo = 0;
            return 0;
        }
        else if (check == 2)
        {
            printf("Iniciando o jogo novamente\n");
            continue;
        }
        else if (check == 3)
        {
            printf("Obrigador por jogar\n");
            jogarDenovo = 0;
            return 1;
        }

        else
        {
            printf("Valor invalido\n");
            return 0;
        }
    } while (jogarDenovo == 1);
}

int main()
{

    int check;
    int success=1;

    printf("############################################\n");
    printf("    ##### BEM VINDO A FAZE CLAN JOGOS #####\n");
    printf("############################################\n");
    

    do
    {
        printf("Digite o numero do jogo que voce deseja jogar: \n");
        printf("1- Perguntas e respostas\n");
        printf("2- Cobra na caixa\n");
        printf("3- Para sair do jogo :(\n");
        scanf(" %d", &check);

        switch (check) {
        case 1:
            if (perguntasRespostas()==1) {
                printf("Obrigado por usar!");
                success = 0;
            }
            
            break;

        case 2:
            if (cobraNaCaixa()==1) {
                printf("Obrigado por usar!");
                success = 0;
            }
            break;

        case 3:
            printf("Obrigado por usar!");
            success = 0;
            break;

        default:
            printf("Valor invalido");
            break;
        }

    } while (success == 1);

    return 0;
}
