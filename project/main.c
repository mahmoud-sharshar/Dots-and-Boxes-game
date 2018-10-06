#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<string.h>
clock_t t;//clock_t data type of time and t is variable which calculate time but not in seconds
double taken_time=0;//variable in which we store time taken by user in seconds
void printBaord();
int A[50][50]={0};//printed array
void print_rank();
int B[50][50];//array to get number for every dot
void rank(int s,char n[]);
int R[50][50];//to color boxes with color's player
int boxes(int ,int ,int ,int ,int ,int );//function to determine completed boxes
void digits();//function to get number for every dot and print their numbers
int c,s,w,x;//c is the score of player1 , s is the score of player2 and w is score of computer
int row,col,grid;
void player2();//function to make player2 on take his turn
void player1();//function to make player1 on take his turn
void playGAME();//function to play game
void computer();
void playerVSplayer();
void playerVScomputer();
int load();
int valid(char x,char y);

void score();
void Moves();
clock_t t2,t;

void save();

void reset();
int Exit;
 struct{
    char str[100];
    int score;
    int moves;
}player_1,player_2,Computer;
int arr[600];
int ind;
int type[600];
int playe[600];
int box[600];
int redo_index=0;
int redo[600];

int re;
int le;
int load_index=0;
char rank_name[100];

int main()
{
     char p[100];
     again:
         reset();

         Exit=0;
         system("cls");
    printf("\n\n\n\n\n\t\t\t\t\tDOTS AND BOXES \n\n\n");
    printf("\t\t\t\t\t1.start game\n\n\n");
    printf("\t\t\t\t\t2.load game\n\n\n");
    printf("\t\t\t\t\t3.Ranks\n\n\n");
   // printf("\t\t\t\t\t4.About Game\n\n\n");
    printf("\t\t\t\t\t4.Exit\n\n\n");
    scanf("%s",p);
//play game option
    if(strcmp("1",p)==0){ again2:
            system("cls");
            printf("\t\t\t\t\tBeginner\n\n\n\n\t\t\t\t\t2. 2*2\n\n\n\t\t\t\t\t3. 3*3\n\n\n\t\t\t\t\t4. 4*4\n\n\n");
        printf("\n\n\n\n\n\t\t\t\t\tExpert\n\t\t\t\t\t5. 5*5\n\n\n\t\t\t\t\t6. 6*6\n\n\n\t\t\t\t\t7. 7*7\n\n\n\t\t\t\t\t8. 8*8\n\n\n \n\n\n");
        char h[100];
         scanf("%s",&h);
        if(h[0]>'1'&&h[0]<'9')
         {
                grid=h[0]-'0';
                if(grid<2||grid>8)goto again2;
                else{
                        system("cls");
                        playGAME();
                        if(Exit==1)//{ reset();goto again;}
                            {
                               again7:
                            printf("to return to menu press 1\n\n\n ");
                            printf("to exit game press 2 ");
                            char o[10];
                            scanf("%s",o);
                            if(strcmp(o,"1")==0)goto again;
                            else if(strcmp(o,"2")==0){return 0;}
                            else {goto  again7;}
                            }
                        else {
                            again6:
                            printf("to return to menu press 1\n\n\n ");
                            printf("to exit game press 2 ");
                            char o[10];
                            scanf("%s",o);
                            if(strcmp(o,"1")==0)goto again;
                            else if(strcmp(o,"2")==0){return 0;}
                            else {goto  again6;}}}
            }
         else{
            system("cls");
            goto again2;

         }



}
//rank option
else if(strcmp("3",p)==0){
        again3:
system("cls");

    strcpy(rank_name,"none");
    print_rank();

    printf("to return to menu press 1\n\n\n ");
    printf("to exit game press 2 ");
    char o[10];
    scanf("%s",o);
    if(strcmp(o,"1")==0)goto again;
    else if(strcmp(o,"2")==0){
    return 0;}
    else {goto  again3;}

}
//load option
else if(strcmp("2",p)==0)
{
    system("cls");
    printf("for vs computer loads press 1 \n for 1vs1 press 2\n");
char stro[100];
    scanf("%s",&stro);
    if(stro[0]>'0'&&stro[0]<'3')
    {x=stro[0]-'0';
        printf("choose the saved file from 1,2 and 3\n");
    char stri[100];
    scanf("%s",&stri);
    if(stri[0]>'0'&&stri[0]<'4')
    {int le = stri[0]-'0';
        load_index=1;
    load(le);}}

    if(grid==0){load_index=0; goto again;}
    system("cls");
    playGAME();
    again5:
    printf("to return to menu press 1\n\n\n ");
               printf("to exit game press 2 ");
            char o[10];
    scanf("%s",o);
    if(strcmp(o,"1")==0)goto again;
    else if(strcmp(o,"2")==0){
    return 0;}
    else {goto  again5;}



}
//exit option
else if(strcmp("4",p)==0)
    return 0;
else goto again;
return 0;
}
//function to print board with colored boxes after every alternation

void printBaord(){
    //color code
    HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
    int i,j;
    int b=taken_time;
     t2=clock()-t;
    taken_time=((double)t2)/CLOCKS_PER_SEC;
    int minutes=b/60;
    int seconds=b%60;
    score();
     Moves();

    if(x==2){

    printf("\n\n\n\t\t\t\t%s\t\t\t\t\t",player_1.str);



    SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
    printf("%s\t",player_2.str );
    SetConsoleTextAttribute(hConSole,saved_attributes);
    printf("\n\n\t\tScore:\t\t  %d\t\t\t\t\t  %d",player_1.score,player_2.score);
    printf("\n\n\t\tMoves:\t\t  %d\t\t\t\t\t  %d",player_1.moves,player_2.moves);
    printf("\n\n\t\tColor:\t\t blue\t\t\t\t\t green");
    printf("\n\n\n\t\t\tTime: %d minutes %d seconds  \n\n",minutes,seconds );

    }
    else {

    SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
    printf("\n\n\n\t\t\t\t%s\t\t\t\t",player_1.str);
    SetConsoleTextAttribute(hConSole,saved_attributes);

    SetConsoleTextAttribute(hConSole,FOREGROUND_RED);
    printf("computer\t");
    SetConsoleTextAttribute(hConSole,saved_attributes);
     printf("\n\n\t\tScore:\t\t  %d\t\t\t\t\t  %d",player_1.score,Computer.score);
    printf("\n\n\t\tMoves:\t\t  %d\t\t\t\t\t  %d",player_1.moves,Computer.moves);
    printf("\n\n\t\tColor:\t\t blue\t\t\t\t\t Red");
    printf("\n\n\n\t\t\t\tTime: %d minutes %d seconds  \n\n",minutes,seconds );}


    for(i=0;i<row;i+=3){
        for(j=0;j<col;j+=4)A[i][j]=254;
    }
    printf("\t\t\t\t");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){

                    if(R[i][j]==1){

    SetConsoleTextAttribute(hConSole,FOREGROUND_INTENSITY);
    printf("%c",A[i][j]);
    SetConsoleTextAttribute(hConSole,saved_attributes); }
                     else if(R[i][j]==2){

    SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
    printf("%c",A[i][j]);
    SetConsoleTextAttribute(hConSole,saved_attributes);}
           else if(R[i][j]==3){

    SetConsoleTextAttribute(hConSole,FOREGROUND_RED);
    printf("%c",A[i][j]);
    SetConsoleTextAttribute(hConSole,saved_attributes);}

            else printf("%c",A[i][j]);
        }
        printf("\n\t\t\t\t");}

    }
    //function to get number for every dot and print their numbers
void digits(){
    int i,j,r=1;printf("\n\n\n\t\t\t");
    for(i=0;i<row;i+=3){
        for(j=0;j<col;j+=4){B[i][j]=r++;
        if(B[i][j]<10){printf("0%d\t",B[i][j]);}
        else printf("%d\t",B[i][j]);}
        printf("\n\n\t\t\t");}}

//function to determine completed boxes , update player score and select color to every box
int boxes(int i,int j,int n,int m,int min,int p){int f=0;
    if(abs(m-n)==1){
    if((A[i][j+2]==196)&&(A[i+3][j+2]==196) &&(A[i+2][j]==179)&&(A[i+2][j+4]== 179)){
            if(A[i+1][j+3]!=219){
        A[i+1][j+1]=A[i+1][j+2]=A[i+1][j+3]=219;
        A[i+2][j+1]=A[i+2][j+2]=A[i+2][j+3]=219;f+=1;
        //next step to color every box with color's player when printed
        if(p==1){R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=1;
        R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=1;}
        else if(p==2){R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=2;
        R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=2;}
        else if(p==3){R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=3;
        R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=3;}
        //step finished
        box[ind-1]=1;
        }}
     if((A[i][j+2]==196)&&(A[i-3][j+2]==196) &&(A[i-1][j]==179)&&(A[i-2][j+4]== 179)){
            if(A[i-1][j+3]!=219){
        A[i-1][j+1]=A[i-1][j+2]=A[i-1][j+3]=219;
        A[i-2][j+1]=A[i-2][j+2]=A[i-2][j+3]=219;f+=1;
        //next step to color every box with color's player when printed
        if(p==1){R[i-1][j+1]=R[i-1][j+2]=R[i-1][j+3]=1;
        R[i-2][j+1]=R[i-2][j+2]=R[i-2][j+3]=1;}
        if(p==2){R[i-1][j+1]=R[i-1][j+2]=R[i-1][j+3]=2;
        R[i-2][j+1]=R[i-2][j+2]=R[i-2][j+3]=2;}
        if(p==3){R[i-1][j+1]=R[i-1][j+2]=R[i-1][j+3]=3;
        R[i-2][j+1]=R[i-2][j+2]=R[i-2][j+3]=3;}
           box[ind-1]=2;
           if(f>1)
            box[ind-1]=5;
            }else  box[ind-1]=2;



            }}
    else if(abs(m-n)==grid+1){

    if((A[i][j+2]==196)&&(A[i+3][j+2]==196) &&(A[i+1][j+4]==179)&&(A[i+2][j+4]== 179)){
            if(A[i+1][j+3]!=219){
            A[i+1][j+1]=A[i+1][j+2]=A[i+1][j+3]=219;
            A[i+2][j+1]=A[i+2][j+2]=A[i+2][j+3]=219;f+=1;
//next step to color every box with color's player when printed
            if(p==1){R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=1;
            R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=1;}
            else if(p==2){R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=2;
            R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=2;}
            else if(p==3){R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=3;
            R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=3;}
if(f>1)
            box[ind]=3;
            else box[ind-1]=3;

    }}
     if((A[i][j-2]==196)&&(A[i+3][j-2]==196) &&(A[i+2][j]==179)&&(A[i+2][j-4]== 179)){
            if(A[i+1][j-3]!=219){
        A[i+1][j-1]=A[i+1][j-2]=A[i+1][j-3]=219;
        A[i+2][j-1]=A[i+2][j-2]=A[i+2][j-3]=219;f+=1;
//next step to color every box with color's player when printed
        if(p==1){R[i+1][j-1]=R[i+1][j-2]=R[i+1][j-3]=1;
        R[i+2][j-1]=R[i+2][j-2]=R[i+2][j-3]=1;}
        else if(p==2){R[i+1][j-1]=R[i+1][j-2]=R[i+1][j-3]=2;
        R[i+2][j-1]=R[i+2][j-2]=R[i+2][j-3]=2;}
        else if(p==3){R[i+1][j-1]=R[i+1][j-2]=R[i+1][j-3]=3;
        R[i+2][j-1]=R[i+2][j-2]=R[i+2][j-3]=3;}
       if(f>1)
            box[ind-1]=6;
            else box[ind-1]=4;
        }}}


                return(f);}
int play=0;//variable to determine the player who play in every time

//player1 function
void player1(){
            int i,j,a,q=0,b,n,m,min,score;
            char num[100];
            char x,y;
            printf("%s\n",player_1.str);
            printf("\t\t\tenter two dots\n");
            scanf("%s",num);
              if(strcmp(num,"exit")==0)
              {
                  Exit=1;
                  return;
              }
            //to enable player to save game
            if(strcmp(num,"save")==0)
            { printf("put the location of save from 1,2 and 3\n");
            char st[100];
            scanf("%s",&st);
                int l=st[0]-'0';
                  if(l<=3&&l>=1)
                {save(play,l); printf("saved");}
                else{system("cls");
                printBaord();
                digits();}
            }
            if(strcmp(num,"load")==0)
            {printf("put the location of save from 1,2 and 3\n");
            char st[100];
            scanf("%s",&st);
                int l=st[0]-'0';
                  if(l<=3&&l>=1)
                {load_index=1;play=load(l);}
                system("cls");
                printBaord();
                digits();
                return;
            }
            //to enable player to undo last move
            if(strcmp(num,"undo")==0)
            {
            int l;

               play= undo(arr[ind-1]);
                while(play==3)
                {
                    play=undo(arr[ind-1]);
                }
                system("cls");
                printBaord();
                digits();

                return;
            }
            if(strcmp(num,"redo")==0)
            {
            n=redo[redo_index-2];
            m=redo[redo_index-1];
            redo_index=redo_index-2;

            }
            else
            {x=num[0];y=num[1];
            n=valid(x,y);
            if(n==0)
                return;
            else if(n!=0)
            {scanf("%s",num);
        x=num[0];y=num[1];
        m=valid(x,y);
                if(m==0)
                    return;
                    else {
                       for(i=0;i<600;i++)
                        redo[i]=0;
                        redo_index=0;


                    }
            }}
            if(n<m)min=n;
            else min=m;
            system("cls");

            for(i=0;i<row;i+=3){
                for(j=0;j<col;j+=4){
                    if((abs(m-n)==1)&&(min!=(grid+1))&&(min!=(grid+1)*2)&&(min!=(grid+1)*3)&&(min!=(grid+1)*4)&&(min!=(grid+1)*5)&&(min!=(grid+1)*6)&&(min!=(grid+1)*7)&&(min!=(grid+1)*8)&&(min!=(grid+1)*9)){
                        if(B[i][j]==min&&A[i][j+3]!=196){q=1;
                            A[i][j+1]=A[i][j+2]=A[i][j+3]=196;
                            R[i][j+1]=R[i][j+2]=R[i][j+3]=1;
                            a=i;b=j;
                            arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=0;
                            ind=ind+1;
                            }
                        }
                        if(abs(m-n)==(grid+1)){
                            if(B[i][j]==min&&A[i+2][j]!=179){q=1;
                                A[i+1][j]=A[i+2][j]=179;
                                R[i+1][j]=R[i+2][j]=1;
                                a=i;b=j;
                                arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=0;
                            ind=ind+1;
                                }}}}
    if(((abs(m-n)==1&&(min!=(grid+1))&&(min!=(grid+1)*2)&&(min!=(grid+1)*3)&&(min!=(grid+1)*4)&&(min!=(grid+1)*5)&&(min!=(grid+1)*6)&&(min!=(grid+1)*7)&&(min!=(grid+1)*8)&&(min!=(grid+1)*9))||abs(m-n)==(grid+1))&&q==1){
        score=boxes(a,b,n,m,min,1);
        if(score==1){play=0;}
        else if(score==2){play=0;}
        else if(score==0){play=1;}}

        printBaord();
        digits();}


//player2 function
void player2(){
            int i,j,a,q=0,b,min,n,m,score;
            char num[100];
            char x,y;
            printf("%s\n",player_2.str);
            printf("\t\t\tenter two dots\n");
            scanf("%s",num);
             //to enable player to save game
              if(strcmp(num,"exit")==0)
              {
                  Exit=1;
                  return;
              }
            if(strcmp(num,"save")==0)
            { printf("put the location of save from 1,2 and 3\n");
            char st[100];
            scanf("%s",&st);
                int l=st[0]-'0';
                  if(l<=3&&l>=1)
                {save(play,l); printf("saved");}
                else{system("cls");
                printBaord();
                digits();}
            }
            if(strcmp(num,"load")==0)
            {printf("put the location of save from 1,2 and 3\n");
            char st[100];
            scanf("%s",&st);
                int l=st[0]-'0';
                  if(l<=3&&l>=1)
                {load_index=1;play=load(l);}
                system("cls");
                printBaord();
                digits();
                return;
            }
            //to enable player to undo last move
            if(strcmp(num,"undo")==0)
            {
            int l;

                play=undo(arr[ind-1]);
                system("cls");
                printBaord();
                digits();
                return;
            }
            if(strcmp(num,"redo")==0)
            {
            n=redo[redo_index-2];
            m=redo[redo_index-1];
            redo_index=redo_index-2;

            }
            else
            {x=num[0];y=num[1];
            n=valid(x,y);
            if(n==0)
                return;
            else if(n!=0)
            {scanf("%s",num);
        x=num[0];y=num[1];
        m=valid(x,y);
                if(m==0)
                    return;
                    else {
                       for(i=0;i<600;i++)
                        redo[i]=0;
                        redo_index=0;


                    }
            }}

            if(n<m)min=n;
            else min=m;
            system("cls");

            for(i=0;i<row;i+=3){
                for(j=0;j<col;j+=4){
                    if((abs(m-n)==1)&&(min!=(grid+1))&&(min!=(grid+1)*2)&&(min!=(grid+1)*3)&&(min!=(grid+1)*4)&&(min!=(grid+1)*5)&&(min!=(grid+1)*6)&&(min!=(grid+1)*7)&&(min!=(grid+1)*8)&&(min!=(grid+1)*9)){
                        if(B[i][j]==min&&A[i][j+3]!=196){q=1;
                            A[i][j+1]=A[i][j+2]=A[i][j+3]=196;
                              R[i][j+1]=R[i][j+2]=R[i][j+3]=2;
                            a=i;b=j;arr[ind]=min;
                            type[ind]=1;
                             playe[ind]=play;
                            ind=ind+1;


                            }
                        }
                        if(abs(m-n)==(grid+1)){
                            if(B[i][j]==min&&A[i+2][j]!=179){q=1;
                                A[i+1][j]=A[i+2][j]=179;
                                R[i+1][j]=R[i+2][j]=2;
                                a=i;b=j;arr[ind]=min;
                            type[ind]=2;
                             playe[ind]=play;
                            ind=ind+1;

                                }}}}
        if((((abs(m-n)==1)&&(min!=(grid+1))&&(min!=(grid+1)*2)&&(min!=(grid+1)*3)&&(min!=(grid+1)*4)&&(min!=(grid+1)*5)&&(min!=(grid+1)*6)&&(min!=(grid+1)*7)&&(min!=(grid+1)*8)&&(min!=(grid+1)*9))||(abs(m-n)==(grid+1)))&&q==1){
                             score=boxes(a,b,n,m,min,2);
                             if(score==1){play=1;}
                             else if(score==2){play=1;}
                             else if(score==0){play=0;}}
                          printBaord();digits();}
//function to organize the game
void playGAME(){
row=3*grid+1;
    col=4*grid+1;

        t=clock();

   if(load_index==0)
    again3:
{printf("\n\n\n\n\t\t\t\t\tplayer VS computer   press 1\n\n\n\n");
   printf("\n\n\t\t\t\t\tplayer VS another player  press 2\n");
   char v[10];
   scanf("%s",&v);
   if(strcmp("1",v)!=0&&strcmp("2",v)!=0){system("cls");goto again3;}
   else{
        if(strcmp("1",v)==0)x=1;
         else if(strcmp("2",v)==0)x=2;

   system("cls");}}
   system("cls");
     t=clock();
if(x==2){
         playerVSplayer();if(Exit==1)return;
         }


else if(x==1){
         playerVScomputer();
         if(Exit==1)return;}}

//strategy of computer
int d=1;//global
void computer(){
    int i,j,a,b,min,n,m,q=0,score;
    /*if(redo_index!=0)
    {
        if(d==1)d+=3;
        else d--;
    }*/
    //to check if it can make box or not
    for(i=0;i<row;i+=3){
        for(j=0;j<col;j+=4){
            if(B[i][j]!=(grid+1)&&B[i][j]!=(grid+1)*2&&B[i][j]!=(grid+1)*3&&B[i][j]!=(grid+1)*4&&B[i][j]!=(grid+1)*5&&B[i][j]!=(grid+1)*6&&B[i][j]!=(grid+1)*7&&B[i][j]!=(grid+1)*8&&B[i][j]!=(grid+1)*9){
            if(A[i][j+1]==196&&A[i+1][j]==179&&A[i+1][j+4]==179&&A[i+3][j+1]!=196){
                A[i+3][j+1]=A[i+3][j+2]=A[i+3][j+3]=196;
                R[i+3][j+1]=R[i+3][j+2]=R[i+3][j+3]=3;
                min=n=B[i+3][j];m=B[i+3][j+4];a=i+3;b=j;
                q=1;
                arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=3;
                            ind=ind+1;
                break;}
            else if(A[i+3][j+1]==196&&A[i+1][j]==179&&A[i+1][j+4]==179&&A[i][j+3]!=196){
                 A[i][j+1]=A[i][j+2]=A[i][j+3]=196;
                 R[i][j+1]=R[i][j+2]=R[i][j+3]=3;
                min=n=B[i][j];m=B[i][j+4];a=i;b=j;
                q=1;
                arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=3;
                            ind=ind+1;

                break;}
            else if(A[i+3][j+1]==196&&A[i][j+1]==196&&A[i+1][j+4]==179&&A[i+2][j]!=179){
                A[i+1][j]=A[i+2][j]=179;R[i+1][j]=R[i+2][j]=3;
                min=n=B[i][j];m=B[i+3][j];a=i;b=j;
                q=1;
                arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;

                break;}
            else if(A[i+3][j+1]==196&&A[i][j+1]==196&&A[i+1][j]==179&&A[i+2][j+4]!=179){
                A[i+1][j+4]=A[i+2][j+4]=179;R[i+1][j+4]=R[i+2][j+4]=3;
                min=n=B[i][j+4];m=B[i+3][j+4];a=i;b=j+4;
                q=1;
                arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;

                break;}}}
                if(q==1)break;}
        //to show if there is no line in every empty box
    if(q==0){
        for(i=0;i<row;i+=3){
        for(j=0;j<col;j+=4){
        if(B[i][j]!=(grid+1)&&B[i][j]!=(grid+1)*2&&B[i][j]!=(grid+1)*3&&B[i][j]!=(grid+1)*4&&B[i][j]!=(grid+1)*5&&B[i][j]!=(grid+1)*6&&B[i][j]!=(grid+1)*7&&B[i][j]!=(grid+1)*8&&B[i][j]!=(grid+1)*9){
        if(A[i][j+1]!=196&&A[i+1][j]!=179&&A[i+1][j+4]!=179&&A[i+3][j+1]!=196){
            if(d==1){
           A[i+1][j]=A[i+2][j]=179;R[i+1][j]=R[i+2][j]=3;
            min=n=B[i][j];m=B[i+3][j];a=i;b=j;q=1;d++;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;


            break;}
            else if(d==2){
            A[i+1][j+4]=A[i+2][j+4]=179;R[i+1][j+4]=R[i+2][j+4]=3;
            min=n=B[i][j+4];m=B[i+3][j+4];a=i;b=j;
            q=1;d++;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
            else if(d==3){
            A[i][j+1]=A[i][j+2]=A[i][j+3]=196;R[i][j+1]=R[i][j+2]=R[i][j+3]=3;
            min=n=B[i][j];m=B[i][j+4];a=i;b=j;
            q=1;d++;
            arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
            else if(d==4){
           A[i+3][j+1]=A[i+3][j+2]=A[i+3][j+3]=196;
           R[i+3][j+1]=R[i+3][j+2]=R[i+3][j+3]=3;
            min=n=B[i+3][j];m=B[i+3][j+4];a=i+3;b=j;q=1;d-=3;
            arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=3;
                            ind=ind+1;

            break;}}}}
            if(q==1)break;}}
    //to show if there is one line in every empty box
    if(q==0){
        for(i=0;i<row;i+=3){
        for(j=0;j<col;j+=4){
        if(B[i][j]!=(grid+1)&&B[i][j]!=(grid+1)*2&&B[i][j]!=(grid+1)*3&&B[i][j]!=(grid+1)*4&&B[i][j]!=(grid+1)*5&&B[i][j]!=(grid+1)*6&&B[i][j]!=(grid+1)*7&&B[i][j]!=(grid+1)*8&&B[i][j]!=(grid+1)*9){
        if(A[i][j+1]==196&&A[i+1][j]!=179&&A[i+1][j+4]!=179&&A[i+3][j+1]!=196){
           A[i+1][j]=A[i+2][j]=179;
           R[i+1][j]=R[i+2][j]=3;
            min=n=B[i][j];m=B[i+3][j];a=i;b=j;q=1;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
        else if(A[i][j+1]!=196&&A[i+1][j]==179&&A[i+1][j+4]!=179&&A[i+3][j+1]!=196){
            A[i+1][j+4]=A[i+2][j+4]=179;
            R[i+1][j+4]=R[i+2][j+4]=3;
            min=n=B[i][j+4];m=B[i+3][j+4];a=i;b=j;
            q=1;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
        else if(A[i][j+1]!=196&&A[i+1][j]!=179&&A[i+1][j+4]==179&&A[i+3][j+1]!=196){
            A[i+1][j]=A[i+2][j]=179;
            R[i+1][j]=R[i+2][j]=3;
            min=n=B[i][j];m=B[i+3][j];a=i;b=j;
            q=1;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
        else if(A[i][j+1]!=196&&A[i+1][j]!=179&&A[i+1][j+4]!=179&&A[i+3][j+1]==196){
           A[i+1][j]=A[i+2][j]=179;
           R[i+1][j]=R[i+2][j]=3;
            min=n=B[i][j];m=B[i+3][j];a=i;b=j;q=1;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}}}
            if(q==1)break;}}
    //if there is two lines in every empty box
    if(q==0){
        for(i=0;i<row;i+=3){
        for(j=0;j<col;j+=4){
        if(B[i][j]!=(grid+1)&&B[i][j]!=(grid+1)*2&&B[i][j]!=(grid+1)*3&&B[i][j]!=(grid+1)*4&&B[i][j]!=(grid+1)*5&&B[i][j]!=(grid+1)*6&&B[i][j]!=(grid+1)*7&&B[i][j]!=(grid+1)*8&&B[i][j]!=(grid+1)*9){
            if(A[i][j+1]==196&&A[i+1][j]!=179&&A[i+1][j+4]==179&&A[i+3][j+1]!=196){
           A[i+1][j]=A[i+2][j]=179;
           R[i+1][j]=R[i+2][j]=3;
            min=n=B[i][j];m=B[i+3][j];a=i;b=j;q=1;

            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
            else if(A[i][j+1]==196&&A[i+1][j]==179&&A[i+1][j+4]!=179&&A[i+3][j+1]!=196){
            A[i+1][j+4]=A[i+2][j+4]=179;
            R[i+1][j+4]=R[i+2][j+4]=3;
            min=n=B[i][j+4];m=B[i+3][j+4];a=i;b=j;
            q=1;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
            else if(A[i][j+1]==196&&A[i+1][j]!=179&&A[i+1][j+4]!=179&&A[i+3][j+1]==196){
            A[i+1][j]=A[i+2][j]=179;
            R[i+1][j]=R[i+2][j]=3;
            min=n=B[i][j];m=B[i+3][j];a=i;b=j;
            q=1;
            arr[ind]=min;
                            type[ind]=2;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
            else if(A[i][j+1]!=196&&A[i+1][j]==179&&A[i+1][j+4]==179&&A[i+3][j+1]!=196){
           A[i][j+1]=A[i][j+2]=A[i][j+3]=196;
            R[i][j+1]=R[i][j+2]=R[i][j+3]=3;
            min=n=B[i][j];m=B[i][j+4];a=i;b=j;q=1;
            arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
            else if(A[i][j+1]!=196&&A[i+1][j]!=179&&A[i+1][j+4]==179&&A[i+3][j+1]==196){
           A[i][j+1]=A[i][j+2]=A[i][j+3]=196;
           R[i][j+1]=R[i][j+2]=R[i][j+3]=3;
            min=n=B[i][j];m=B[i][j+4];a=i;b=j;q=1;
            arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=3;
                            ind=ind+1;
            break;}
            else if(A[i][j+1]!=196&&A[i+1][j]==179&&A[i+1][j+4]!=179&&A[i+3][j+1]==196){
           A[i][j+1]=A[i][j+2]=A[i][j+3]=196;
           R[i][j+1]=R[i][j+2]=R[i][j+3]=3;
            min=n=B[i][j];m=B[i][j+4];a=i;b=j;q=1;
            arr[ind]=min;
                            type[ind]=1;
                            playe[ind]=3;
                            ind=ind+1;
            break;}}}
        if(q==1)break;}}
        system("cls");

        if(abs(m-n)==1||abs(m-n)==(grid+1)){
            score=boxes(a,b,n,m,min,3);
            if(score!=0){play=1;}

            else if(score==0){play=0;}}

printBaord();digits();}
//function to check number from user valid or not
int valid(char x,char y){
    int n,m,k=0;
    if(x<'9'&&x>='0'){
        if(y>='0'&&y<='9'){
            n=x-'0';
            m=y-'0';
            k=n*10+m;}}
            if(k>(grid+1)*(grid+1))k=0;
    return k;
}
//function to make player plays against another
void playerVSplayer(){
    int i;//char play_name[100];
   if(load_index==0){printf("\n\n\n\t\t\t\t\tenter the name of player 1 one\n");
scanf("%s",player_1.str);
//strcpy(player_1.str,play_name);
printf("\n\t\t\t\t\tenter the name of player 2 two\n");
scanf("%s",player_2.str);}//strcpy(player_2.str,play_name);}
system("cls");
  t=clock();
printBaord();digits();

for(i=0;;i++){
if(Exit==1)return;

    if(play==0){
        player1();
    }
    else if(play==1){
        player2();
    }if(player_1.score+player_2.score==grid*grid)break;
}
if(player_1.score>player_2.score){printf("\n\n\t\t\t%s win\n",player_1.str);rank(player_1.score,player_1.str);print_rank();
}
else if(player_1.score<player_2.score){printf("\n\n\t\t\t%s win\n",player_2.str);rank(player_2.score,player_2.str);print_rank();
}
else if(player_2.score==player_1.score)printf("\n\n\t\t\tdraw\n");

}

//function to make player plays against computer
void playerVScomputer(){
    int i;//char play_name[100];
if(load_index==0){printf("\n\n\n\n\n\n\t\t\t\t\tenter the name of player \n");
scanf("%s",player_1.str);}//strcpy(player_1.str,play_name);}
system("cls");
int grid2=grid;
printBaord();digits();
for(i=0;;i++){
if(Exit==1)return;
    grid=grid2;
    if(play==0){
        player1();
    }
    else if(play==1){
        computer();
    }

    else {player1();}
    if(Computer.score+player_1.score==grid*grid)break;
}
if(Computer.score<player_1.score){printf("\n\n\t\t\t%s win\n",player_1.str);rank(player_1.score,player_1.str);print_rank();
}
else if(Computer.score>player_1.score)printf("\n\n\t\t\tcomputer win\n");
else if(Computer.score==player_1.score)printf("\n\n\t\t\tdraw\n");
}



void save(int play,int l){
if(x==2)
{if(l==1)
{int j,i;
FILE *f5;
    f5 = fopen("a1.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f5, "%d\n",A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R1.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f9, "%d\n",R[i][j]);}
 fclose(f9);

FILE *f10;
    f10 = fopen("all1.txt","w");
        fprintf(f10, "%d\n%d\n%s\n%s",play,grid,player_1.str,player_2.str);
 fclose(f10);}
if(l==2)
{int j,i;
FILE *f5;
    f5 = fopen("a2.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f5, "%d\n",A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R2.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f9, "%d\n",R[i][j]);}
 fclose(f9);

FILE *f10;
    f10 = fopen("all2.txt","w");
fprintf(f10, "%d\n%d\n%s\n%s",play,grid,player_1.str,player_2.str); fclose(f10);}
if(l==3)
{int j,i;
FILE *f5;
    f5 = fopen("a3.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f5, "%d\n",A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R3.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f9, "%d\n",R[i][j]);}
 fclose(f9);

FILE *f10;
    f10 = fopen("all3.txt","w");
        fprintf(f10, "%d\n%d\n%s\n%s",play,grid,player_1.str,player_2.str);
 fclose(f10);}}
 if(x==1)
 {
     if(l==1)
{int j,i;
FILE *f5;
    f5 = fopen("a4.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f5, "%d\n",A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R4.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f9, "%d\n",R[i][j]);}
 fclose(f9);

FILE *f10;
    f10 = fopen("all4.txt","w");
        fprintf(f10, "%d\n%d\n%s\n%s",play,grid,player_1.str,player_2.str);
 fclose(f10);}
if(l==2)
{int j,i;
FILE *f5;
    f5 = fopen("a5.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f5, "%d\n",A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R5.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f9, "%d\n",R[i][j]);}
 fclose(f9);

FILE *f10;
    f10 = fopen("all5.txt","w");
        fprintf(f10, "%d\n%d\n%s\n%s",play,grid,player_1.str,player_2.str);
 fclose(f10);}
if(l==3)
{int j,i;
FILE *f5;
    f5 = fopen("a6.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f5, "%d\n",A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R6.txt","w");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fprintf(f9, "%d\n",R[i][j]);}
 fclose(f9);

FILE *f10;
    f10 = fopen("all6.txt","w");
        fprintf(f10, "%d\n%d\n%s\n%s",play,grid,player_1.str,player_2.str);
 fclose(f10);}}}


int load(int l){
  if(x==2)
{if (l==1)
{int j,i;
FILE *f10;
    f10 = fopen("all1.txt","r");
        fscanf(f10, "%d\n%d\n%s\n%s",&play,&grid,&player_1.str,&player_2.str);
 fclose(f10);
 if(load_index==1)
 {
    row=3*grid+1;
    col=4*grid+1;
 }
FILE *f5;
    f5 = fopen("a1.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f5, "%d\n",&A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R1.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f9, "%d\n",&R[i][j]);}
 fclose(f9);

}
if (l==2)
{int j,i;
FILE *f10;
    f10 = fopen("all2.txt","r");
        fscanf(f10, "%d\n%d\n%s\n%s",&play,&grid,&player_1.str,&player_2.str);
 fclose(f10);
 if(load_index==1)
 {
    row=3*grid+1;
    col=4*grid+1;
 }
FILE *f5;
    f5 = fopen("a2.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f5, "%d\n",&A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R2.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f9, "%d\n",&R[i][j]);}
 fclose(f9);}
if (l==3)
{int j,i;
FILE *f10;
    f10 = fopen("all3.txt","r");
        fscanf(f10, "%d\n%d\n%s\n%s",&play,&grid,&player_1.str,&player_2.str);
 fclose(f10);
 if(load_index==1)
 {
    row=3*grid+1;
    col=4*grid+1;
 }
FILE *f5;
    f5 = fopen("a3.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f5, "%d\n",&A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R3.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f9, "%d\n",&R[i][j]);}
 fclose(f9);}
}
else if(x==1)
 {if (l==1)
{int j,i;
FILE *f10;
    f10 = fopen("all4.txt","r");
        fscanf(f10, "%d\n%d\n%s\n%s",&play,&grid,&player_1.str,&player_2.str);
 fclose(f10);
 if(load_index==1)
 {
    row=3*grid+1;
    col=4*grid+1;
 }
FILE *f5;
    f5 = fopen("a4.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f5, "%d\n",&A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R4.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f9, "%d\n",&R[i][j]);}
 fclose(f9);}
if (l==2)
{int j,i;
FILE *f10;
    f10 = fopen("all5.txt","r");
        fscanf(f10, "%d\n%d\n%s\n%s",&play,&grid,&player_1.str,&player_2.str);
 fclose(f10);
 if(load_index==1)
 {
    row=3*grid+1;
    col=4*grid+1;
 }
FILE *f5;
    f5 = fopen("a5.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f5, "%d\n",&A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R5.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f9, "%d\n",&R[i][j]);}
 fclose(f9);}
if (l==3)
{int j,i;
FILE *f10;
    f10 = fopen("all6.txt","r");
        fscanf(f10, "%d\n%d\n%s\n%s",&play,&grid,&player_1.str,&player_2.str);
 fclose(f10);
 if(load_index==1)
 {
    row=3*grid+1;
    col=4*grid+1;
 }
FILE *f5;
    f5 = fopen("a6.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f5, "%d\n",&A[i][j]);}
 fclose(f5);
FILE *f9;
    f9 = fopen("R6.txt","r");
for(i=0;i<row;i++)
        {for (j=0;j<col;j++)
        fscanf(f9, "%d\n",&R[i][j]);}
 fclose(f9);}}

return play;
}
int undo(int min){int i,j,a,b;
if(type[ind-1]==1)
{for(i=0;i<row;i+=3){
                for(j=0;j<col;j+=4){

                        if(B[i][j]==min&&A[i][j+3]==196){
                            A[i][j+1]=A[i][j+2]=A[i][j+3]=0;
                            R[i][j+1]=R[i][j+2]=R[i][j+3]=0;
                            ind=ind-1;
                            a=i;b=j;
                            if(playe[ind]!=3)
                            {redo[redo_index]=min;
                            redo[redo_index+1]=min+1;
                            redo_index=redo_index+2;}
                            break;
                           }}}}
else if(type[ind-1]==2)
{for(i=0;i<row;i+=3){
                for(j=0;j<col;j+=4){

                        if(B[i][j]==min){
                            A[i+1][j]=A[i+2][j]=0;
                                R[i+1][j]=R[i+2][j]=0;
                            ind=ind-1;
                            a=i;b=j;
                            if(playe[ind]!=3)
                            {redo[redo_index]=min;
                            redo[redo_index+1]=min+grid+1;
                            redo_index=redo_index+2;}
                            break;
                           }}}}
int boxe=ind;int f=0;

 if (box[boxe]!=0)
 {

  i=a;
 j=b;
      if(box[boxe]==1)
     {A[i+1][j+1]=A[i+1][j+2]=A[i+1][j+3]=0;
         A[i+2][j+1]=A[i+2][j+2]=A[i+2][j+3]=0;
         R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=0;
         R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=0;
         box[boxe]=0;

         }
    else if(box[boxe]==2)

     {A[i-1][j+1]=A[i-1][j+2]=A[i-1][j+3]=0;
         A[i-2][j+1]=A[i-2][j+2]=A[i-2][j+3]=0;
         R[i-1][j+1]=R[i-1][j+2]=R[i-1][j+3]=0;
         R[i-2][j+1]=R[i-2][j+2]=R[i-2][j+3]=0;
                  box[boxe]=0;

     }

      else if(box[boxe]==3)
      {A[i+1][j+1]=A[i+1][j+2]=A[i+1][j+3]=0;
          A[i+2][j+1]=A[i+2][j+2]=A[i+2][j+3]=0;
          R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=0;
          R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=0;
          box[boxe]=0;

      }
    else if(box[boxe]==4)

     {A[i+1][j-1]=A[i+1][j-2]=A[i+1][j-3]=0;
         A[i+2][j-1]=A[i+2][j-2]=A[i+2][j-3]=0;
         R[i+1][j-1]=R[i+1][j-2]=R[i+1][j-3]=0;
         R[i+2][j-1]=R[i+2][j-2]=R[i+2][j-3]=0;
                  box[boxe]=0;

         }
         else if (box[boxe]==5)
         {
             A[i+1][j+1]=A[i+1][j+2]=A[i+1][j+3]=0;
         A[i+2][j+1]=A[i+2][j+2]=A[i+2][j+3]=0;
         A[i-1][j+1]=A[i-1][j+2]=A[i-1][j+3]=0;
         A[i-2][j+1]=A[i-2][j+2]=A[i-2][j+3]=0;
         R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=0;
         R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=0;
         R[i-1][j+1]=R[i-1][j+2]=R[i-1][j+3]=0;
         R[i-2][j+1]=R[i-2][j+2]=R[i-2][j+3]=0;
                  box[boxe]=0;


         }
         else if(box[boxe]==6)
         {
             A[i+1][j+1]=A[i+1][j+2]=A[i+1][j+3]=0;
          A[i+2][j+1]=A[i+2][j+2]=A[i+2][j+3]=0;
          A[i+1][j-1]=A[i+1][j-2]=A[i+1][j-3]=0;
         A[i+2][j-1]=A[i+2][j-2]=A[i+2][j-3]=0;
         R[i+1][j+1]=R[i+1][j+2]=R[i+1][j+3]=0;
          R[i+2][j+1]=R[i+2][j+2]=R[i+2][j+3]=0;
          R[i+1][j-1]=R[i+1][j-2]=R[i+1][j-3]=0;
         R[i+2][j-1]=R[i+2][j-2]=R[i+2][j-3]=0;
                  box[boxe]=0;

         }

 }

return playe[ind];

}



void score()
{
    int i,j;
    player_1.score=0;
    player_2.score=0;
    Computer.score=0;
     for(i=0;i<row;i+=3){
                for(j=0;j<col;j+=4){
        if(B[i][j]!=(grid+1)&&B[i][j]!=(grid+1)*2&&B[i][j]!=(grid+1)*3&&B[i][j]!=(grid+1)*4&&B[i][j]!=(grid+1)*5&&B[i][j]!=(grid+1)*6&&B[i][j]!=(grid+1)*7&&B[i][j]!=(grid+1)*8&&B[i][j]!=(grid+1)*9){
                if(B[i][j]!=(1+grid*(grid+1))&&B[i][j]!=(2+grid*(grid+1))&&B[i][j]!=(3+grid*(grid+1))&&B[i][j]!=(4+grid*(grid+1))&&B[i][j]!=(5+grid*(grid+1))&&B[i][j]!=(6+grid*(grid+1))&&B[i][j]!=(7+grid*(grid+1))&&B[i][j]!=(8+grid*(grid+1))&&B[i][j]!=(9+grid*(grid+1))){
                            if(R[i+1][j+1]==1)player_1.score++;
                            else if(R[i+1][j+1]==2)player_2.score++;
                            else if(R[i+1][j+1]==3)Computer.score++;}
                }}
            }
}
void Moves()
{
    int i,j;
    player_1.moves=0;
    player_2.moves=0;
    Computer.moves=0;
     for(i=0;i<row;i+=3){
                for(j=0;j<col;j+=4){
        if(B[i][j]!=(grid+1)&&B[i][j]!=(grid+1)*2&&B[i][j]!=(grid+1)*3&&B[i][j]!=(grid+1)*4&&B[i][j]!=(grid+1)*5&&B[i][j]!=(grid+1)*6&&B[i][j]!=(grid+1)*7&&B[i][j]!=(grid+1)*8){
                //horizontal
        if(R[i][j+1]==1)player_1.moves+=1;
        else if(R[i][j+1]==2)player_2.moves+=1;
        else if(R[i][j+1]==3)Computer.moves+=1;}
        //vertical
        if(B[i][j]!=(1+grid*(grid+1))&&B[i][j]!=(2+grid*(grid+1))&&B[i][j]!=(3+grid*(grid+1))&&B[i][j]!=(4+grid*(grid+1))&&B[i][j]!=(5+grid*(grid+1))&&B[i][j]!=(6+grid*(grid+1))&&B[i][j]!=(7+grid*(grid+1))&&B[i][j]!=(8+grid*(grid+1))&&B[i][j]!=(9+grid*(grid+1))){
        if(R[i+1][j]==1)player_1.moves+=1;
        else if(R[i+1][j]==2)player_2.moves+=1;
        else if(R[i+1][j]==3)Computer.moves+=1;}
                }
            }
}

void reset()
{
    int i,j;
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
        A[i][j]=R[i][j]=0;

        ind=0;
        }}
        for(i=0;i<600;i++){
             type[i]=0;
        playe[i]=0;
        arr[i]=0;
        }
        play=0;
        player_1.moves=player_1.score=0;
        player_2.moves=player_2.score=0;
        Computer.moves=Computer.score=0;
        row=col=grid=0;

}






typedef struct{
    char name[40];
    int score;
}list_rank;
//function to register ranks of top 10 players
void rank(int s,char n[])
{int i;int q=0;

    strcpy(rank_name,n);
    list_rank store[10];

// to read file of rank
        FILE *Rank;
        Rank=fopen("rank.txt","r");
        for(i=0;i<10;i++){
        fscanf(Rank,"%s : %d",&store[i].name,&store[i].score);

         }
        fclose(Rank);
        //to check if player name is exit before or not
for(i=0;i<10;i++){
    if(strcmp(n,store[i].name)==0){
       strcpy(store[i].name,"player");
       store[i].score=0;

    }
}
//to compare player name with other names in rank if player name is not exit before
  int c;
    char m[20];

  for(i=0;i<10;i++){

    if(s>store[i].score)
    {
        c=store[i].score;
        store[i].score=s;
        s=c;
        strcpy(m,store[i].name);
        strcpy(store[i].name,n);
        strcpy(n,m);}
  }
  //to rewrite rank with new updates
   FILE *Rank1;
        Rank1=fopen("rank.txt","w");
        for(i=0;i<10;i++){
        fprintf(Rank1,"%s : %d\n",store[i].name,store[i].score);}
        fclose(Rank1);


}
//function to print ranks of top 10 players
void print_rank()
{   HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
    int i;
    list_rank store[10];
    FILE *Rank;
        Rank=fopen("rank.txt","r");
        printf("\n\n\t\t\t\t\tTOP 10 PLAYERS\n\n\n\n");
        for(i=0;i<10;i++){
 fscanf(Rank,"%s : %d",&store[i].name,&store[i].score);
                    if(strcmp(store[i].name,rank_name)==0)
                        {

                                SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
                                printf("\t\t\t[%d]  %s : %d\n\n",i+1, store[i].name,store[i].score);
                                SetConsoleTextAttribute(hConSole,saved_attributes);}
                    else {
                        printf("\t\t\t[%d]  %s : %d\n\n",i+1, store[i].name,store[i].score);}}
                        fclose(Rank);
}










