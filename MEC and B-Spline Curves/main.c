#include <graphics.h>
#include <stdio.h>
#include <math.h>
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

int comb(int n,int r)
{
    return (fact(n)/(fact(n-r)*fact(r)));
}
int main(void)
{
    initwindow(800,800);
    line(0,400,800,400);
    line(400,0,400,800);
    for(int i=8;i<=800;){
    	outtextxy(i,390,".");
    	i=i+28;
		}
		int deger=-14;
    for(int y=5;y<=390;){
    	char sayi[3];
    	sprintf(sayi,"%d",deger);
    	outtextxy(y,410,sayi);
    	y=y+28;
		deger++;
	}
	for(int k=5;k<=800;){
      	outtextxy(395,k,".");
    	k=k+28;
		}
		int deger1=14;
    for(int j=8;j<=399;){
    	char sayi1[3];
    	sprintf(sayi1,"%d",deger1);
    	outtextxy(410,j,sayi1);
    	j=j+28;
		deger1--;
	}
	deger1=-1;
	for(int j=425;j<=800;){
    	char sayi1[3];
    	sprintf(sayi1,"%d",deger1);
    	outtextxy(410,j,sayi1);
    	j=j+28;
		deger1--;
	}
	deger1=1;
	for(int j=425;j<=800;){
    	char sayi1[3];
    	sprintf(sayi1,"%d",deger1);
    	outtextxy(j,410,sayi1);
    	j=j+28;
		deger1++;
	}
   FILE *dosya;

    int karakter,karakter1;
    int diziSayac=0;
    if((dosya = fopen("noktalar.txt","r+"))!=NULL){
        while(!feof(dosya)){
            fscanf(dosya,"%d %d",&karakter,&karakter1);
            diziSayac++;
           printf("Dosyadan alinan %d. nokta = {%d,%d}\n",diziSayac,karakter,karakter1);
        }
    }
    else{
        printf("Dosya bulunamadi.");
    }

    fclose(dosya);

    float koordinatX[diziSayac];
    float koordinatY[diziSayac];
    if((dosya=fopen("noktalar.txt","r+"))!=NULL){
        for(int p=0; diziSayac>p; p++){
        fscanf(dosya,"%f %f",&koordinatX[p],&koordinatY[p]);
       // printf("%f %f\n",koordinatX[p],koordinatY[p]);

        }
    }

    else{
         printf("Dosya bulunamadi.");    }
    // printf("\n\n%d\n\n",koordinatX[2]); // TEST AMAÇLI KOD PARÇASI
   int i,j;
    float uzaklik=-1.0;
    float enbuyukUzaklik=0.0;
    int a=0,b=0;
    float r=0.0;
    for (i=0;i<diziSayac;i++){
        for(j=0;j<diziSayac;j++){
                uzaklik = (float)sqrt(pow((koordinatX[i]-koordinatX[j]),2)+pow((koordinatY[i]-koordinatY[j]),2));
            if (uzaklik > enbuyukUzaklik){
                enbuyukUzaklik=uzaklik;
                r=(float)(enbuyukUzaklik/2.0);
                a=i;
                b=j;
            }

        }
    }
  //  printf("%d. nokta ve %d. noktalar arasi uzaklik en fazladir ve ilk Yaricap %.4f olarak bulunur.\n\n",a+1,b+1,r);
    float sayacx=0.0;
    float sayacy=0.0;

    sayacx=koordinatX[a]+koordinatX[b];
    //printf("%f\n",sayacx);
    sayacy=koordinatY[a]+koordinatY[b];
    //z noktasýnýn x i imx y si imy.
	float imx=sayacx/2.0;
    float imy=sayacy/2.0;
    //printf("ilk merkez %f,%f\n",imx,imy);
    float uzaklikz=-1.0;
    float enbuyukUzaklikz=0.0;
    int q;
    //sanal merkezime en uzak noktayý buluyorum.
    for(int z=0;z<diziSayac;z++)
    {
    	uzaklikz = (float)sqrt(pow((imx-koordinatX[z]),2.0)+pow((imy-koordinatY[z]),2.0));
    	  if (uzaklikz > enbuyukUzaklikz)
    	  {
    	  	enbuyukUzaklikz=uzaklikz;
    	  	q=z;
		  }
	}
	float mx=0.0;
	float my=0.0;
    if(q!=a||q!=b)
    {
    sayacx+=koordinatX[q];
	sayacy+=koordinatY[q];
	mx=sayacx/3.0;
	my=sayacy/3.0;
	}
	if(q==a||q==b)
	{
	    mx=imx;
		my=imy;
	}
	float uzaklikm=-1.0;
    float enbuyukUzaklikm=0.0;
    float v=-1.0;
	for(int i=0;i<diziSayac;i++)
	{
		uzaklikm = (float)sqrt(pow((mx-koordinatX[i]),2)+pow((my-koordinatY[i]),2));
		 if (uzaklikm > enbuyukUzaklikm)
		  {
		  	enbuyukUzaklikm=uzaklikm;
		  	v=enbuyukUzaklikm;
		  }
	}
	printf("\nMerkez Noktamiz = {%.2f,%.2f}\n\nYaricapimiz = %.4f",mx,my,v);
	if(mx>0)
    {
    	mx=400.0+(mx*28.0);
	}
	 if(mx<0)
    {
    	mx=mx*-1.0;
    	mx=400.0-(mx*28.0);
	}
	if(my>0)
    {
    	my=400.0-(my*28.0);
	}
	 if(my<0)
    {
        my=my*-1.0;
    	my=400.0+(my*28.0);
	}
	if(mx==0){
		mx=400.0;
	}
	if(my==0)
	{
		my=400.0;
	}
    v=v*28.0;
    for(int i=0;i<diziSayac;i++)
    {
    	if(koordinatX[i]>0)
	 	{
	 		koordinatX[i]=400+koordinatX[i]*28;
		 }
		if(koordinatX[i]==0)
	 	{
	 		koordinatX[i]=400;
		 }
		if(koordinatX[i]<0)
	 	{
	 		koordinatX[i]=400+koordinatX[i]*28;
		}
		if(koordinatY[i]>0)
	 	{
	 		koordinatY[i]=400-koordinatY[i]*28;
		 }
		 if(koordinatY[i]==0)
	 	{
	 		koordinatY[i]=400;
		 }
		if(koordinatY[i]<0)
	 	{
	 		koordinatY[i]=400-koordinatY[i]*28;
		}
        circle(koordinatX[i],koordinatY[i],5);
    }
    int n=diziSayac-1;
    setcolor(10);
    delay(2000);
    for(float t=0;t<=1;t=t+0.000005)
    {
        int x=0;
		int y=0;
        for(i=0;i<=n;i++)
        {
           x = x + (comb(n,i)* pow(1-t,n-i)* pow(t,i)* koordinatX[i]);
           y = y + (comb(n,i)* pow(1-t,n-i)* pow(t,i)* koordinatY[i]);
        }
        putpixel(x,y,1);
    }
    circle(mx,my,v);
    getch();
    closegraph();
    return 0;
}
