/*********
@author Luana Rauber Sostisso, Eduarda Barth Cordova, Eduardo Palinski, Julio Schons
@date Dezember 2021
@brief Manipulação de Imagens
 4323
****/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void informacoes(int *altura,int *largura,FILE *abrir,char imagem[])
{
	struct cabe //Struct do cabeçalho pegando todas as informações do tipo até a profundidade
	{
		unsigned char tipo[2];
		unsigned long tam;
		unsigned char reserv[4];
		unsigned long desloc;
		unsigned long tamcab;
		unsigned long larg;
		unsigned long alt;
		short int biplanes;
		short int profundidade;
	}img;
	if((abrir=fopen(imagem,"r+b")) !=NULL) //Teste de abertura da imagem
	{
		fread(img.tipo,sizeof(char),2,abrir);
		if(img.tipo[0]=='B'&&img.tipo[1]=='M') //se é uma imagem bmp
		{
        fread(&img.tam,sizeof(unsigned long),1,abrir); //Pegando os valores para o cabeçalho
        fread(img.reserv,sizeof(unsigned char),4,abrir);
        fread(&img.desloc,sizeof(unsigned long),1,abrir);
        fread(&img.tamcab,sizeof(unsigned long),1,abrir);
        fread(&img.larg,sizeof(unsigned long),1,abrir);
        fread(&img.alt,sizeof(unsigned long),1,abrir);
        fread(&img.biplanes,sizeof(short int),1,abrir);
        fread(&img.profundidade,sizeof(short int),1,abrir);
        printf("O tamanho da imagem enviada eh de %d bytes de largura \n",img.larg);
        printf("Altura de %d bytes\n", img.alt);
        printf("Pronfundidade de cores %d bytes\n", img.profundidade);
        fclose(abrir);
        *altura=img.alt; //Salvando os valores de altura e largura para utilizar em outras funções posteriormente
        *largura=img.larg;
    }
    else{
    printf("Impossivel abrir por nao ser imagem bmp\n");
    exit(0);
    }
}
	else
	{
	printf("Nao foi possivel abrir a imagem!\n");
	exit(0);
}
}
int azull(int altura, int largura, FILE *abrir, FILE *azul, unsigned char abrindo[], char cab[],char imagem[])
{
	char nome[100];
	for(int go=0;go<(strlen(imagem)-4);go++) //nome[] copia o imagem[] descontando os ultimos 4 caracteres e as substitui por _B.bmp
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='B';
    nome[strlen(imagem)-2]='.';
    nome[strlen(imagem)-1]='b';
    nome[strlen(imagem)]='m';
    nome[strlen(imagem)+1]='p';
    nome[strlen(imagem)+2]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir); //Le cabeçalho pra string cab
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir); //Pega os valores da imagem original
            }
            fclose(abrir);
        }
    azul=fopen(nome,"w+b");
    fwrite(cab,1,54,azul);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg++){
                    	if(larg==0||larg%3==0) //Caso larg seja 0 ou divisivel por 3 ele mantem o valor nesse byte do pixel
                        fputc(abrindo[larg + (3*(largura+1)*alt)],azul);
                        else
                        fputc(0,azul); //Caso não ele coloca 0 no byte
                }
        }
        fclose(azul);
}
int verdee(int altura, int largura, FILE *abrir, FILE *verde, unsigned char abrindo[], char cab[],char imagem[])
{
	int i=0;
	char nome[100];
	for(int go=0;go<(strlen(imagem)-4);go++) //nome[] copia o imagem[] descontando os ultimos 4 caracteres e as substitui por _G.bmp
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='G';
    nome[strlen(imagem)-2]='.';
    nome[strlen(imagem)-1]='b';
    nome[strlen(imagem)]='m';
    nome[strlen(imagem)+1]='p';
    nome[strlen(imagem)+2]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir);
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir);
            }
            fclose(abrir);
        }
    verde=fopen(nome,"w+b");
    fwrite(cab,1,54,verde);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg++){ //Ele vai incrementendo 1 a uma variavel começada em 0 e toda a vez que ela é 1
                    	if(i==0)                                  //ele mantem o valor no byte do pixel
                    	{
                    	fputc(0,verde);
                    	i++;
                    }
                    else
                    if(i==1)
                    {
                    	fputc(abrindo[larg + (3*(largura+1)*alt)],verde);
                    	i++;
					}
					else
					if(i==2)
					{
						fputc(0,verde);
						i=0;
					}

					}
                }
                fclose(verde);
        }

int vermelhoo(int altura, int largura, FILE *abrir, FILE *vermelho, unsigned char abrindo[], char cab[],char imagem[])
{
	int i=0;
	char nome[100];
	int agir;
	for(int go=0;go<(strlen(imagem)-4);go++)
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='R';
    nome[strlen(imagem)-2]='.';
    nome[strlen(imagem)-1]='b';
    nome[strlen(imagem)]='m';
    nome[strlen(imagem)+1]='p';
    nome[strlen(imagem)+2]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir);
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir);
            }
            fclose(abrir);
        }
    vermelho=fopen(nome,"w+b");
    fwrite(cab,1,54,vermelho);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg++){ //Identico ao do verde porem ele coloca o valor apenas quando a variavel é 2
                    	if(i==0)
                    	{
                    	fputc(0,vermelho);
                    	i++;
                    }
                    else
                    if(i==1)
                    {
					    fputc(0,vermelho);

                    	i++;
					}
					else
					if(i==2)
					{
						fputc(abrindo[larg + (3*(largura+1)*alt)],vermelho);
						i=0;
					}
                }
        }
        fclose(vermelho);

}
int cinzaa(int altura, int largura, FILE *abrir, FILE *cinza, unsigned char abrindo[], char cab[],char imagem[])
{
	float media=0;
	int i=0;
	char nome[100];
	for(int go=0;go<(strlen(imagem)-4);go++)
	{
	nome[go]=imagem[go];
}
    nome[strlen(imagem)-4]='_';
    nome[strlen(imagem)-3]='g';
    nome[strlen(imagem)-2]='s';
    nome[strlen(imagem)-1]='.';
    nome[strlen(imagem)]='b';
    nome[strlen(imagem)+1]='m';
    nome[strlen(imagem)+2]='p';
    nome[strlen(imagem)+3]='\0';
	if((abrir = fopen(imagem,"r+b"))!=NULL);
	{
        fread(cab,1,54,abrir);
        fseek(abrir,54,SEEK_SET);
        for(int alt=0;alt<altura;alt++)
            for(int larg=0;larg<(3*(largura+1));larg++)
            {
                abrindo[larg+(3*(largura+1)*alt)]=getc(abrir);
            }
            fclose(abrir);
        }
    cinza=fopen(nome,"w+b");
    fwrite(cab,1,54,cinza);
    fseek(abrir,54,SEEK_SET);
                for(int alt=0;alt<altura;alt++){
                    for(int larg=0; larg<(3*(largura+1)); larg+=3){ //Faz a media
                    	media=(abrindo[larg+(3*(largura+1)*alt)] + abrindo[larg+1+(3*(largura+1)*alt)] + abrindo[larg+2+(3*(largura+1)*alt)])/3;
                    	fputc(media,cinza);
                    	fputc(media,cinza);
                    	fputc(media,cinza);
                    	media=0;
					}
                }
				fclose(cinza);

        }


int main()
{
	FILE *abrir, *azul, *verde, *vermelho, *cinza;
	int altura, largura, escolha;
	char imagem[70], cab[53];
	printf("Coloque o nome da sua imagem bmp (Ex:Teste2.bmp):\n");
	gets(imagem); //Pega o nome da imagem

	system("cls");
	informacoes(&altura,&largura,abrir, imagem);
	unsigned char abrindo[1999999];

	azull(altura,largura,abrir,azul,abrindo,cab,imagem);
	verdee(altura,largura,abrir,verde,abrindo,cab,imagem);
	vermelhoo(altura,largura,abrir,vermelho,abrindo,cab,imagem);
	cinzaa(altura,largura,abrir,cinza,abrindo,cab,imagem);

}
