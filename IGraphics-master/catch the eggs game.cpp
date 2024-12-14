# include "iGraphics.h"

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#include<Windows.h>
#include<mmsystem.h>


int musicon=1;
int ex=0;

char str[100], str2[100];
int len;

int w=0;
struct player
{
    char name[80];
    int scr;
};
typedef struct player pl;
pl p[10];


char scro[20][20];
int lev=0;


int mode=0;


double egg_x[]= {200,500,900,459,1156};     ////white, gold ,blue ,black ,red  egg
double egg_y[]= {769,2000,766,800,966};
int gg=0;                                     // egg speed
int a=550;

double basket_x=500;                      //basket
double basket_y=0;
int bspeed=10;
int b=0;

int i;


double perk_y[]= {1287,8005,10088};            ////  big basket ,egg speed fast ,slow
double perk_x[]= {211,479,600};

int speed=8;                                      //// egg speed


double skull_x=500;                                  //danger
double skull_y=766;

char Score[20]="000";                              //score
int scoreint=0;


char eggcount[20]="00";                                //eggcount
int eggcountint=0;


char life[20]="00";                                //life
int lifeint=3;


int m=0;                                           //basket change


int level=1;
int sub;                                    //game level



char timar[20]="000";
int timeint;


int er;
int eg;
int amp;




void ti_me()
{
    timeint--;


}




void skull()
{
    skull_y-=8;                         //danger  life is 1 less
    if(skull_y<110)
    {
        skull_y=888;
        skull_x=rand()%1000;
    }

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void egg_ychange0()
{
    egg_y[0]-=8+gg;                             //white egg
    if(egg_y[0]<100)
    {


        egg_y[0]=766;
        egg_x[0]=rand()%(766+(100*1));
    }
}

void egg_ychange1()
{
    egg_y[1]-=8+gg;
    if(egg_y[1]<110)
    {
        egg_y[1]=1108;
        egg_x[1]=rand()%1000;
    }                                             //gold egg

}



void egg_ychange2()
{
    egg_y[2]-=8+gg;
    if(egg_y[2]<110)
    {
        egg_y[2]=1108;
        egg_x[2]=rand()%1000;
    }                                             //blue egg

}

void egg_ychange3()
{
    egg_y[3]-=10+gg;

    if(egg_y[3]<110)
    {
        egg_y[3]=908;
        egg_x[3]=rand()%1000;
    }                                          //black egg

}

void egg_ychange4()
{
    egg_y[4]-=9+gg;
    if(egg_y[4]<110)
    {
        egg_y[4]=988;
        egg_x[4]=rand()%1000;
    }                                       //red egg

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void perk0()
{
    perk_y[0]-=9;                                  ////basket
    if(perk_y[0]<110)
    {
        perk_y[0]=1388;
        perk_x[0]=rand()%1000;
    }

                                                    //big basket
}

void perk1()
{
    perk_y[1]-=9;

    if(perk_y[1]<110)
    {
        perk_y[1]=8008;
        perk_x[1]=rand()%1000;
    }
                                                        //egg speed increase
}


void perk2()
{
    perk_y[2]-=8;

    if(perk_y[2]<110)                                     //egg speed slow
    {
        perk_y[2]=10008;
        perk_x[2]=rand()%1200;
    }

}










void iDraw()
{

    iClear();

    if(mode==0)
    {
        iShowBMP(0,0,"game pic 000.bmp");
        iSetColor(255,255,0);

        iSetColor(255,255,255);
        iText(620,22,"CLICK HERE",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iSetColor(255,104,204);


    if(mode==1)
    {
        iShowBMP(0,0,"home page.bmp");

        iSetColor(255,104,204);
        iFilledRectangle(590,550,230,60);
        iSetColor(0,0,0);
        iText(650,570,"START",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,104,204);
        iFilledRectangle(590,435,230,60);
        iSetColor(0,0,0);
        iText(650,455,"RESUME",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,104,204);
        iFilledRectangle(590,320,230,60);
        iSetColor(0,0,0);
        iText(650,340,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,104,204);
        iFilledRectangle(590,225,230,60);
        iSetColor(0,0,0);
        iText(650,245,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(255,104,204);
        iFilledRectangle(590,110,230,60);
        iSetColor(0,0,0);
        iText(650,130,"MUSIC",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iFilledRectangle(1100,90,200,60);
        iSetColor(255,255,255);
        iText(1160,110,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);




    }



    if(mode==2)
    {


        iShowBMP(0,0,"timerlevelpic.bmp");


        iSetColor(255,140,8);
        iFilledRectangle(590,600,230,60);
        iSetColor(0,0,0);
        iText(670,620,"TIME",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,104,204);
        iFilledRectangle(590,440,230,60);
        iSetColor(0,0,0);
        iText(650,460,"60 SECONDS",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,104,204);
        iFilledRectangle(590,330,230,60);
        iSetColor(0,0,0);
        iText(650,350,"120 SECONDS",GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(255,104,204);
        iFilledRectangle(590,220,230,60);
        iSetColor(0,0,0);
        iText(650,240,"180 SECONDS",GLUT_BITMAP_TIMES_ROMAN_24);




    }



    if(mode==12)
    {

        iShowBMP(0,0,"timerlevelpic.bmp");


        iSetColor(255,140,8);
        iFilledRectangle(590,600,230,60);
        iSetColor(0,0,0);
        iText(670,620,"TIME",GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(255,104,204);
        iFilledRectangle(300,440,230,60);
        iSetColor(0,0,0);
        iText(350,460,"60 SECONDS",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,104,204);
        iFilledRectangle(590,440,230,60);
        iSetColor(0,0,0);
        iText(640,460,"120 SECONDS",GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(255,104,204);
        iFilledRectangle(880,440,230,60);
        iSetColor(0,0,0);
        iText(930,460,"180 SECONDS",GLUT_BITMAP_TIMES_ROMAN_24);

    }



    if(mode==13)

    {


        iShowBMP(0,0,"rulepage.bmp");
        iSetColor(135,206,250);
        iFilledEllipse(670,700,150,50,100);
        iSetColor(0,0,0);
        iText(630,690,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);



        iText(5,570,"MOVEMENT :",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(200,572,"  You can move the basket using arrow keys or press the mouse and drag left or right.",GLUT_BITMAP_HELVETICA_18);

        iText(5,520,"EGGS              :",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,255);
        iText(200,522,"  White egg  -",GLUT_BITMAP_HELVETICA_18);
        iSetColor(0,0,0);
        iText(350,522,"point  +2",GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,0,255);
        iText(200,402,"  Red egg  -",GLUT_BITMAP_HELVETICA_18);
        iSetColor(0,0,0);
        iText(350,402,"point  -2",GLUT_BITMAP_HELVETICA_18);


        iSetColor(0,0,255);
        iText(200,492,"  Black egg  -",GLUT_BITMAP_HELVETICA_18);
        iSetColor(0,0,0);
        iText(350,492,"point  -10           Time  -5",GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,0,255);
        iText(200,462,"  Golden egg  -",GLUT_BITMAP_HELVETICA_18);
        iSetColor(0,0,0);
        iText(350,462,"point  +10            Life  +1",GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,0,255);
        iText(200,432,"  Blue egg  -",GLUT_BITMAP_HELVETICA_18);
        iSetColor(0,0,0);
        iText(350,432,"point  +5             Time  +5",GLUT_BITMAP_HELVETICA_18);



        iText(5,350,"PERKS :",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(150,352," SKULL  :   Life  -1  ;",GLUT_BITMAP_HELVETICA_18);


        iText(350,352," Red Brick   :  Egg speed gets faster   ;",GLUT_BITMAP_HELVETICA_18);
        iText(700,352," Blue Brick   :   Egg speed gets slower ",GLUT_BITMAP_HELVETICA_18);

        iText(150,322," Brown Brick   : Large Basket / Small Basket   and   Normal egg speed .  ",GLUT_BITMAP_HELVETICA_18);

        iText(5,290,"LEVEL  :",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(150,292," 3 levels   (1) 60 seconds  (2) 120 seconds  (3) 180 seconds .",GLUT_BITMAP_HELVETICA_18);


        iText(150,242," Press F1 to leave the game and the progress will be saved ",GLUT_BITMAP_HELVETICA_18);

        iText(150,212," Press F5 to on / off music  .        Press F12 to go to menu .     Press END to quit the game but the progress will not be saved .",GLUT_BITMAP_HELVETICA_18);

        iText(150,182," Try to score as many points as you can within the time limit .",GLUT_BITMAP_HELVETICA_18);
        iText(150,152," Press p / P for pause and  r / R for resume the game .",GLUT_BITMAP_HELVETICA_18);

        iSetColor(255,0,0);
        iText(500,105,"||  BEST OF LUCK  ||",GLUT_BITMAP_TIMES_ROMAN_24);






    }




    if(mode==3)
    {



        iShowBMP(0,0,"game page.bmp");
        iSetColor(0,0,0);


        iText(0,750,"PRESS F1 TO GO TO MENU",GLUT_BITMAP_HELVETICA_18);


        sprintf(eggcount,"EGG COUNT : %d",eggcountint);
        iText(700,700,eggcount,GLUT_BITMAP_TIMES_ROMAN_24);




        sprintf(Score,"SCORE : %d",scoreint);
        iText(1100,700,Score,GLUT_BITMAP_TIMES_ROMAN_24);

        sprintf(life,"LIFE : %d",lifeint);
        iText(500,700,life,GLUT_BITMAP_TIMES_ROMAN_24);

        if(amp==1)
        {
            timeint=60;
            amp=0;
        }

        if(amp==2)
        {
            timeint=120;
            amp=0;
        }
        if(amp==3)
        {
            timeint=180;
            amp=0;
        }




        sprintf(timar,"TIME : %d",timeint);
        iText(200,700,timar,GLUT_BITMAP_TIMES_ROMAN_24);




        if(m==0)
            iShowBMP2(basket_x,basket_y,"basket.bmp",0);
        if(m==1)
            iShowBMP2(basket_x,basket_y,"basket big.bmp",0);





        iShowBMP(perk_x[0],perk_y[0],"basperk.bmp");
        if(perk_x[0]>basket_x&&perk_x[0]<basket_x+150&&perk_y[0]<120&&perk_y[0]>110)/////
        {

            gg=0;

            m=(m+1)%2;


        }


        iShowBMP(perk_x[1],perk_y[1],"red brick.bmp");
        if(perk_x[1]>basket_x&&perk_x[1]<basket_x+150&&perk_y[1]<120&&perk_y[1]>90)
        {
            gg=3;

        }


        iShowBMP(perk_x[2],perk_y[2],"blue brick.bmp");

        if(perk_x[2]>basket_x&&perk_x[2]<basket_x+150&&perk_y[2]<120&&perk_y[2]>90)
        {
            gg=-2;

        }



        // iShowBMP2(egg_x[0],egg_y[0],"egg.bmp",0xffffff);
        if(egg_x[0]>basket_x&&egg_x[0]<basket_x+150&&egg_y[0]<110)
        {

            scoreint+=2;

            eggcountint++;



        }
        iShowBMP2(egg_x[0],egg_y[0],"egg.bmp",0xffffff);



        iShowBMP2(egg_x[1],egg_y[1],"goldegg.bmp",0xffffff);

        if(egg_x[1]>basket_x&&egg_x[1]<basket_x+150&&egg_y[1]<120)
        {
            lifeint++;
            eggcountint++;
            if(lifeint>3)
                lifeint=3;
            scoreint+=10;

        }




        iShowBMP(skull_x,skull_y,"skull.bmp");

        if(skull_x>basket_x&&skull_x<basket_x+150&&skull_y<125)
        {
            lifeint--;
            skull_y=1000;
        }




        iShowBMP2(egg_x[2],egg_y[2],"blue egg.bmp",0xffffff);

        if(egg_x[2]>basket_x&&egg_x[2]<basket_x+150&&egg_y[2]<120)
        {

            scoreint+=5;
            eggcountint++;

            timeint+=5;
            if(er==1)
                if(timeint>60)
                    timeint=60;


            if(er==2)
                if(timeint>120)
                    timeint=120;



            if(er==3)
                if(timeint>180)
                    timeint=180;


        }



        iShowBMP2(egg_x[3],egg_y[3],"black egg.bmp",0xffffff);

        if(egg_x[3]>basket_x&&egg_x[3]<basket_x+150&&egg_y[3]<120)
        {

            scoreint-=10;
            eggcountint++;
            if(scoreint<0)
                scoreint=0;

            timeint-=5;
        }



        iShowBMP2(egg_x[4],egg_y[4],"red egg.bmp",0xffffff);

        if(egg_x[4]>basket_x&&egg_x[4]<basket_x+150&&egg_y[4]<120)
        {

            scoreint-=2;
            eggcountint++;
            if(scoreint<0)
                scoreint=0;

        }


        if(lifeint<=0)
        {
            mode=4;
        }


        if(timeint<=0)
        {
            mode=4;

        }
    }



    if(mode==5)
    {
        FILE *fp;
        int i;
        fp=fopen("file.txt","w");
        for(i=0; i<5; i++)
            fprintf(fp,"%lf %lf ",egg_x[i],egg_y[i]);

        fprintf(fp,"%lf %lf ",perk_x[0],perk_y[0]);
        fprintf(fp,"%lf %lf ",perk_x[1],perk_y[1]);
   //     fprintf(fp,"%lf %lf ",perk_x[2],perk_y[2]);


        fprintf(fp,"%lf %lf ",basket_x,basket_y);

        fprintf(fp,"%lf %lf ",skull_x,skull_y);

        fprintf(fp,"%d %d %d %d %d",scoreint,timeint,lifeint,er,eggcountint);

        fclose(fp);

        mode=1;


    }



    if(mode==6)
    {



        FILE *fp;
        int i;
        fp=fopen("file.txt","r");
        for(i=0; i<5; i++)
            fscanf(fp,"%lf %lf ",&egg_x[i],&egg_y[i]);
        fscanf(fp,"%lf %lf ",&perk_x[0],&perk_y[0]);

        fscanf(fp,"%lf %lf ",&perk_x[1],&perk_y[1]);
    //    fscanf(fp,"%lf %lf ",&perk_x[2],&perk_y[2]);



        fscanf(fp,"%lf %lf ",&basket_x,&basket_y);
        fscanf(fp,"%lf %lf ",&skull_x,&skull_y);

        fscanf(fp,"%d %d %d %d %d",&scoreint,&timeint,&lifeint,&er,&eggcountint);
        fclose(fp);
        mode=3;                       //game
        if(timeint<=0)

            mode=4;                    //game over

    }


    if(mode==4)
    {



        iShowBMP(0,0,"woodpic.bmp");
        iShowBMP(550,500,"game over pic.bmp");


        iSetColor(255,222,181);

        iFilledEllipse(690,420,200,50,100);
        sprintf(Score,"SCORE : %d",scoreint);
        iSetColor(0,0,0);
        iText(640,415,Score,GLUT_BITMAP_TIMES_ROMAN_24);

        iText(575,300,"ENTER YOUR NAME",GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(0, 0, 0);
        iRectangle(540, 200, 300, 70);

        iText(520, 150, "Click to activate the box, enter to finish",GLUT_BITMAP_HELVETICA_18);

        iSetColor(0, 0, 0);
        iRectangle(1100, 200, 150, 50);
        iText(1130,215,"MENU",GLUT_BITMAP_TIMES_ROMAN_24);


        iText(1080,175,"PRESS F12 TO GO TO MENU",GLUT_BITMAP_HELVETICA_12);



        if(lev==1)
        {

            iSetColor(0, 0, 0);
            iText(560, 225, str,GLUT_BITMAP_TIMES_ROMAN_24);

        }


        if(lev==2)
        {


            strcpy(p[0].name,"unknown");
            strcpy(p[1].name,"unknown");
            strcpy(p[2].name,"unknown");
            strcpy(p[3].name,"unknown");
            strcpy(p[4].name,"unknown");
            strcpy(p[5].name,"unknown");
            strcpy(p[6].name,"unknown");
            strcpy(p[7].name,"unknown");
            strcpy(p[8].name,"unknown");
            strcpy(p[9].name,"unknown");



            FILE *fa;
            if(er==1)
                fa=fopen("high1.txt","rb");

            if(er==2)
                fa=fopen("high2.txt","rb");

            if(er==3)

                fa=fopen("high3.txt","rb");

            int k;

            for(k=0; k<10; k++)
            {

                fread(&p[k],sizeof(p[0]),1,fa);
            }
            fclose(fa);

            if(scoreint>p[9].scr && scoreint<p[8].scr )

            {

                p[9].scr=scoreint;
                strcpy(p[9].name,str);

                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");
                if(er==3)
                    fa=fopen("high3.txt","wb");


                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);
                }
                fclose(fa);
            }
            if( scoreint>p[8].scr && scoreint<p[7].scr )
            {
                p[9].scr=p[8].scr;
                strcpy(p[9].name,p[8].name);

                p[8].scr=scoreint;
                strcpy(p[8].name,str);

                if(er==1)
                    fa=fopen("high1.txt","wb");
                if(er==2)
                    fa=fopen("high2.txt","wb");
                if(er==3)
                    fa=fopen("high3.txt","wb");

                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);
                }
                fclose(fa);
            }
            if(scoreint>p[7].scr&&scoreint<p[6].scr )
            {


                int i;
                for(i=9; i>7; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);


                }
                p[7].scr=scoreint;
                strcpy(p[7].name,str);

                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)

                    fa=fopen("high2.txt","wb");
                if(er==3)

                    fa=fopen("high3.txt","wb");



                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }


            if(scoreint>p[6].scr && scoreint<p[5].scr)
            {


                int i;
                for(i=9; i>6; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);


                }
                p[6].scr=scoreint;
                strcpy(p[6].name,str);


                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");


                if(er==3)
                    fa=fopen("high3.txt","wb");


                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }

            if(scoreint>p[5].scr&&scoreint<p[4].scr)
            {

                int i;
                for(i=9; i>5; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);


                }

                p[5].scr=scoreint;
                strcpy(p[5].name,str);
                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");

                if(er==3)
                    fa=fopen("high3.txt","wb");





                for(k=0; k<10; k++)
                {
                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }

            if(scoreint>p[4].scr&&scoreint<p[3].scr)
            {

                int i;
                for(i=9; i>4; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);

                }


                p[4].scr=scoreint;
                strcpy(p[4].name,str);

                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");


                if(er==3)
                    fa=fopen("high3.txt","wb");



                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }


            if(scoreint>p[3].scr&&scoreint<p[2].scr)
            {

                int i;
                for(i=9; i>3; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);


                }


                p[3].scr=scoreint;
                strcpy(p[3].name,str);

                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");
                if(er==3)
                    fa=fopen("high3.txt","wb");







                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }

            if(scoreint>p[2].scr&&scoreint<p[1].scr)
            {

                int i;
                for(i=9; i>2; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);


                }

                p[2].scr=scoreint;
                strcpy(p[2].name,str);

                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");

                if(er==3)
                    fa=fopen("high3.txt","wb");


                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }

            if(scoreint>p[1].scr&&scoreint<p[0].scr)
            {

                int i;
                for(i=9; i>1; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);


                }

                p[1].scr=scoreint;
                strcpy(p[1].name,str);

                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");
                if(er==3)
                    fa=fopen("high3.txt","wb");



                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }

            if(scoreint>p[0].scr)
            {

                int i;
                for(i=9; i>0; i--)
                {
                    p[i].scr=p[i-1].scr;
                    strcpy(p[i].name,p[i-1].name);

                }

                p[0].scr=scoreint;
                strcpy(p[0].name,str);
                if(er==1)
                    fa=fopen("high1.txt","wb");

                if(er==2)
                    fa=fopen("high2.txt","wb");

                if(er==3)
                    fa=fopen("high3.txt","wb");

                for(k=0; k<10; k++)
                {

                    fwrite(&p[k],sizeof(p[k]),1,fa);

                }
                fclose(fa);
            }
        }
    }


    if(mode==10)
    {
        iShowBMP(0,0,"bluewall.bmp");
        iSetColor(255,192,203);
        iFilledEllipse(700,700,200,40,100);
        iSetColor(0,0,0);
        iText(630,690,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

        int k;

        FILE *fg;
        if(eg==1)

            fg=fopen("high1.txt","rb");

        if(eg==2)

            fg=fopen("high2.txt","rb");

        if(eg==3)

            fg=fopen("high3.txt","rb");




        for(k=0; k<10; k++)
        {

            fread(&p[k],sizeof(p[0]),1,fg);
        }
        fclose(fg);
        iSetColor(0,0,0);
        iText(510,560,p[0].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,510,p[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,460,p[2].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,410,p[3].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,360,p[4].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,310,p[5].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,260,p[6].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,210,p[7].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,160,p[8].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(510,110,p[9].name,GLUT_BITMAP_TIMES_ROMAN_24);




        itoa(p[0].scr,scro[0],10);
        itoa(p[1].scr,scro[1],10);
        itoa(p[2].scr,scro[2],10);
        itoa(p[3].scr,scro[3],10);
        itoa(p[4].scr,scro[4],10);
        itoa(p[5].scr,scro[5],10);
        itoa(p[6].scr,scro[6],10);
        itoa(p[7].scr,scro[7],10);
        itoa(p[8].scr,scro[8],10);
        itoa(p[9].scr,scro[9],10);



        iText(800,560,scro[0],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,510,scro[1],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,460,scro[2],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,410,scro[3],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,360,scro[4],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,310,scro[5],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,260,scro[6],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,210,scro[7],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,160,scro[8],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,110,scro[9],GLUT_BITMAP_TIMES_ROMAN_24);


    }

}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

    basket_x=mx;
    if(basket_x<0)
        basket_x=0;

    if(basket_x>1200)
        basket_x=1200;


}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 500 && mx <= 880 && my >= 50 && my <= 175 && mode == 0)
        {
            mode = 1;                          //MENU
        }

    }

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 550 && my <= 610 && mode == 1)
        {
            mode = 2;                           //time
        }

    }


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 120 && my <= 180 && mode == 1)
        {

            if(musicon)
            {

                musicon=0;
                PlaySound(0,0,0);
            }
            else
            {
                musicon=1;
                PlaySound("music.wav",NULL,SND_LOOP|SND_ASYNC);

            }
        }
    }



    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 440 && my <= 500 && mode == 2)
        {
            lifeint=3;
            scoreint=0;
            eggcountint=0;                           //game
            mode =3 ;
            amp=1;
            er=1;
        }

    }

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 330 && my <= 390 && mode == 2)
        {
            lifeint=3;
            scoreint=0;
            eggcountint=0;
            mode = 3;
            amp=2;
            er=2;
        }

    }

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 220 && my <= 280 && mode == 2)
        {
            lifeint=3;
            scoreint=0;
            eggcountint=0;
            mode = 3;
            amp=3;
            er=3;
        }

    }




    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        if(mx>683&&mode==3)
            basket_x+=bspeed;
        if(mx<683&&mode==3)
            basket_x-=bspeed;                          //basket move
    }




    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 440 && my <= 500 && mode == 1)
        {
            mode = 6;                                                        //resume
        }

    }

    if(mx >= 540 && mx <= 840 && my >= 210 && my <= 280 && mode == 4)           //write name
    {
        lev = 1;
    }




    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 330 && my <= 390 && mode == 1)       //high score time
        {
            mode = 12;
        }

    }


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 300 && mx <= 530 && my >= 440 && my <= 500 && mode==12)///////////////////////////////////////
        {
            mode = 10;                                                  //high score
            eg=1;
        }

    }


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 440 && my <= 500 && mode == 12)
        {
            mode = 10;
            eg=2;
        }

    }


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 880 && mx <= 1110 && my >= 440 && my <= 500 && mode==12)
        {
            mode = 10;
            eg=3;
        }
    }


    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 1100 && mx <= 1250 && my >= 210 && my <= 260 && mode==4)
        {
            mode = 1;                                                   //menu from game over

        }
    }

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 590 && mx <= 820 && my >= 225 && my <= 285 &&mode==1 )        //rules
        {
            mode=13;

        }

    }



    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 1100 && mx <= 1300 && my >= 100 && my <= 160&&mode==1 )           //exit
        {
            exit(0);

        }

    }


}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{


    if(key == 'p'||key =='P')
    {
        if(mode==3)

        {


            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
            iPauseTimer(3);
            iPauseTimer(4);
            iPauseTimer(5);
            iPauseTimer(6);
            iPauseTimer(7);
            iPauseTimer(8);
            iPauseTimer(9);

        }
    }

    if(key == 'r'||key=='R')
    {
        if(mode==3)
        {
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
            iResumeTimer(5);
            iResumeTimer(6);
            iResumeTimer(7);
            iResumeTimer(8);
            iResumeTimer(9);

        }
    }





    int i;
    if(mode == 4)
    {
        if(key == '\r')
        {
            lev = 2;
            printf("%s\n", str);
            len = 0;

        }
        else
        {
            str[len] = key;
            len++;

        }
    }




}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key==GLUT_KEY_RIGHT)
    {
        basket_x+=10;
        if(basket_x>1200)
            basket_x=1200;

    }

    if(key==GLUT_KEY_LEFT)
    {
        basket_x-=10;
        if(basket_x<0)
            basket_x=0;
    }





    if(key==GLUT_KEY_LEFT&& mode==2)         //time to menu
    {
        mode=1;

    }

    if(key==GLUT_KEY_LEFT&&mode==12)          //high score time to menu
    {
        mode=1;

    }

    if(key==GLUT_KEY_LEFT&&mode==13)           //rules to menu
    {
        mode=1;

    }


    if(key==GLUT_KEY_LEFT&&mode==10)            //high score to time
    {
        mode=12;

    }

    if(key==GLUT_KEY_F1)                       //save game
    {
        if(mode==3)
            mode=5;

    }


    if(key==GLUT_KEY_F5)                       //music
    {
        if(musicon)
        {

            musicon=0;
            PlaySound(0,0,0);
        }
        else
        {
            musicon=1;
            PlaySound("music.wav",NULL,SND_LOOP|SND_ASYNC);

        }


    }

    if(key==GLUT_KEY_F12)                      //go to menu
    {
        if(mode!=3)
            mode=1;

    }




    if(key == GLUT_KEY_END)                  //exit
    {
        exit(0);
    }

}


int main()
{

    len = 0;
    str[0]= 0;



    iSetTimer(20,egg_ychange0);
    iSetTimer(20,egg_ychange1);
    iSetTimer(20,egg_ychange2);
    iSetTimer(20,egg_ychange3);
    iSetTimer(20,egg_ychange4);


    iSetTimer(30,perk0);
    iSetTimer(30,perk1);
    iSetTimer(30,perk2);
    iSetTimer(30,skull);


    iSetTimer(1000,ti_me);


    if( musicon)
        PlaySound("music.wav",NULL,SND_LOOP|SND_ASYNC);


    iInitialize(1366,768, "CATCH THE EGGS");
    return 0;
}
