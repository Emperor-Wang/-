#include<stdio.h>
#include<iostream> 
#include<string.h>

using namespace std;
class wc{
	
  public: 
    void charnum(char *fname);//-c file字符数 
    void wordnum(char *fname);//-w file单词数 
    void sentencenum(char *fname);//-s file句子数 
    void codenum(char *fname);// -code file代码行 
    void blanknum(char *fname);//-e file空白行 
    void explainationnum(char *fname);//-n file注释行数 
    ~wc(){
    }
    
};
 
void wc::charnum(char *fname){
	 FILE *fp=NULL;
     int c = 0;
     char ch;
     if ((fp = fopen(fname , "r")) == NULL){
     	printf("file read failure.");
     	exit(0);
     }
     ch = fgetc(fp);
     while (ch != EOF){
     	c++;
     	ch = fgetc(fp);
     }
     cout<<"字符数为:"<<c<<endl;
     fclose(fp);
}

void wc::wordnum(char *fname){
	 FILE *fp=NULL;
     int w = 0;
     char ch;
     if ((fp = fopen(fname , "r")) == NULL){
     	printf("file read failure.");
     	exit(0);
     }
     ch=fgetc(fp);
     while(ch!=EOF){
     	 if ((ch>='a'&&ch<='z')||(ch >= 'A'&&ch <='Z') || (ch >= '0'&&ch <= '9'))
     	 {
 	     	while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9') || ch == '-'
			  ||ch=='\''){
  				ch=fgetc(fp);
  			}
  			w++;
  			ch=fgetc(fp);
 	     }
 	     else{
     	 	ch=fgetc(fp);
     	 }
     }
     cout<<"单词数为："<<w<<endl;
     fclose(fp);
}

void wc::sentencenum(char *fname){
	 FILE *fp=NULL;
     int s = 0;
     char ch;
     if ((fp = fopen(fname , "r")) == NULL){
     	printf("file read failure.");
     	exit(0);
     }
     ch=fgetc(fp);
     while(ch!=EOF){
     	if(ch=='.'||ch=='?'||ch=='!'){
	     	s++;
	     	ch=fgetc(fp);
	     }
	     else{
     		ch=fgetc(fp);
     	}
     }
     cout<<"句子数为："<<s<<endl;
     fclose(fp);
}

void wc::codenum(char *fname){
	 FILE *fp=NULL;
     int cl = 0;
     char ch;
     if ((fp = fopen(fname , "r")) == NULL){
     	printf("file read failure.");
     	exit(0);
     }
     ch=fgetc(fp);
     while (ch != EOF)
     {
        if (ch=='\n')
        {
            ch = fgetc(fp);
        }
        else if (ch == '/')
        {
            ch = fgetc(fp);
            if (ch == '/')
            	while (ch != '\n')
                {
                    ch = fgetc(fp);
                }
                ch = fgetc(fp);
        }
        else
        {
			cl++;
            while (ch != '\n'&&ch != '/'&&ch != EOF)
            {
                ch = fgetc(fp);
            }
        }

    }
    cout<<"代码行数为："<<cl<<endl;
    fclose(fp);
}
void wc::blanknum(char*fname){
	FILE *fp=NULL;
     int el=0;
     char ch;
     if ((fp = fopen(fname , "r")) == NULL){
     	printf("file read failure.");
     	exit(0);
     }
     ch=fgetc(fp);
     while (ch!= EOF)
     {
        if (ch=='\n')
        {
            ch = fgetc(fp);
            while (ch=='\n')
            {
                el++;
                ch = fgetc(fp);
            }
        }
        else ch=fgetc(fp); 
    }
    cout<<"空行数为:"<<el<<endl;
    fclose(fp);
 }
    void wc::explainationnum(char*fname){
    	FILE *fp=NULL;
     int nl=0;
     char ch;
     if ((fp = fopen(fname , "r")) == NULL){
     	printf("file read failure.");
     	exit(0);
     }
     ch=fgetc(fp);
     while (ch != EOF)
     {
        if (ch == '/')
        {
            ch = fgetc(fp);
            if (ch == '/')
            	while (ch != '\n')
                {
                    ch = fgetc(fp);
                }
                nl++;
            ch = fgetc(fp);
        }
        else ch=fgetc(fp);
        
    }
    cout<<"注释行数为 ："<<nl<<endl;
    fclose(fp);
}
int main(int argc, char*argv[]){
	wc w;
	FILE *fp;
	while(1){
		if((fp=fopen(argv[2],"r"))==NULL)
           {    
               cout<<"该文件不存在！\n\n"<<endl;
               scanf("%s%s%s",argv[0],argv[1],argv[2]);
               continue;
        }
        
        else if(strcmp(argv[1],"-c")==0){
        	w.charnum(argv[2]);
        }
        else if(strcmp(argv[1],"-w")==0){
        	w.wordnum(argv[2]);
        }
        else if(strcmp(argv[1],"-s")==0){
        	w.sentencenum(argv[2]);
        }
        else if(strcmp(argv[1],"-e")==0){
        	w.blanknum(argv[2]);
        }
        else if(strcmp(argv[1],"-n")==0){
        	w.explainationnum(argv[2]);
        }
        else if(strcmp(argv[1],"-code")==0){
        	w.codenum(argv[2]);
        }
        else if(strcmp(argv[1],"exit")){
        	break;
        }
        else{
        	printf("input cmd wrong");
        }
        cout<<"\n"<<endl;
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	return 0;
}
