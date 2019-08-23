#include<stdio.h>
#include<string.h>
char map[10][10],str1[100],str2[100];
int main(){
while(gets(str1)){
gets(str2);
int len1=strlen(str1);
int len2=strlen(str2);
for(int i=0;i<=len1-1;i++){
if(str1[i]>='1'&&str1[i]<='9'){
if(str1[i-2]!=',')
map[str1[i]-'1'+1][str1[i-1]-'a'+1]=str1[i-2];
else
map[str1[i]-'1'+1][str1[i-1]-'a'+1]='P';
}
}
for(int i=0;i<=len2-1;i++){
if(str2[i]>='1'&&str2[i]<='9'){
if(str2[i-2]!=',')
map[str2[i]-'1'+1][str2[i-1]-'a'+1]=str2[i-2]+32;
else
map[str2[i]-'1'+1][str2[i-1]-'a'+1]='p';
}
}

printf("+---+---+---+---+---+---+---+---+\n");
for(int i=8;i>=1;i--){
printf("|");
for(int j=1;j<=8;j++){
if((i+j)%2==0){
printf(":");
if(map[i][j]) printf("%c",map[i][j]);
else printf(":");
printf(":");
}
else {
printf(".");
if(map[i][j]) printf("%c",map[i][j]);
else printf(".");
printf(".");
}
printf("|");
}
printf("\n");
printf("+---+---+---+---+---+---+---+---+\n");
}
memset(str1,0,sizeof(str1));
memset(str2,0,sizeof(str2));
memset(map,0,sizeof(map));
}
return 0;
}
