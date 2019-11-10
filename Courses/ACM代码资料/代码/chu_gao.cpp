#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#define max 100000
using namespace std;
char s[max],ss[max];    
int a[max],b[max],c[max];
char arr[max],cha[max];
int compare(char *a,char *b) {
	int len1,len2,i;
    len1 = strlen(a);         
    len2 = strlen(b);         
    if(len1 < len2) {
    	return -1;
	} else if(len1 > len2) {
		return 1;
	} else {
        if(strcmp(a,b) == 0) {
        	return 0;
		} else { 
            for(i = 0; i < len1;i++) { 
                if(a[i] > b[i]) {
                	return 1;
				} 
                if(a[i]<b[i]) {
                	return -1;
				} 
            }
            return 0;
        }
    }
}
int judge(char *ch) {
    int i, k;
    k = strlen(ch);
    for(i = 0;i < k;i++) 
        if(ch[i] != '0') {
        	return 0;
		} 
    return 1;
}
void Sub(char *a1,char *b1) {
    int lena, lenb, i, j, k, flag;
    lena = strlen(a1);
    lenb = strlen(b1);
    if(compare(a1,b1)>=0) {
        for(i = 0;i < lena;i++)  a[i] = a1[lena - 1 - i] - '0';
        for(i = 0;i < lenb;i++)  b[i] = b1[lenb - 1 - i] - '0';
        flag = 0;
    } else {
        for(i = 0;i < lenb;i++) a[i] = b1[lenb - 1 - i] - '0';
        for(i = 0;i < lena;i++) b[i] = a1[lena - 1 - i] - '0';
        flag = 1;
    }
    k = lena > lenb ? lena : lenb;
    for(i = 0;i < k;i++) {
        if(a[i] < b[i]) {
            a[i+1]--;
            c[i] = a[i] - b[i] + 10; 
        } else {
        	c[i]=a[i]-b[i];	
		}  
    }
    while(!c[i-1]) { 
		k--;
		i--;
	}
    if(!flag) { 
        for(i = 0;i < k;i++) {
            if(!i && !c[k-i-1]) {
            	continue;
			}          
            cha[i]=c[k-i-1]+'0'; 
        } 
    } else { 
        cha[0]='-'; 
        for(i = 1;i <= k;i++) {
            if(i == 1 && !c[k-i]) {
            	continue;
			}
            cha[i] = c[k-i] + '0';
        }
    }
    if(judge(cha)) {
    	strcpy(cha,"0");
	}     
}
void chu_gao() {
    char a[1000],b[1000],t[1000];
    int lens,lent,i,j,k,flag=0;
    memset(arr,0,sizeof(arr));
    if(compare(s,ss) < 0) {
    	strcpy(arr,s);
	} else if(!compare(s,ss)) {
		cha[0] = '1';
	} else { 
        j = lent = 0; lens = strlen(s); 
        memset(b,0,sizeof(b)); 
        memset(t,0,sizeof(t));
        for(i = 0;i < lens;i++) {
            b[j++] = s[i]; 
            flag = 0;
            while(compare(b,ss)>=0) {
                Sub(b,ss);
                strcpy(b,cha);
                memset(cha,0,sizeof(cha));
                t[lent]++;
                flag = 1;            
            }
            if(flag) {
            	t[lent] += '0';
			} else {
				t[lent] = '0';
			}                  
            if(!strcmp(b,"0")) {
            	j = 0;
			} else {
				j=strlen(b);
			}
            lent++; 
        }
        k = 0;
        for(i = 0;i<lent;i++) {
        	if(t[i] != '0') {
        		break;
			}
		}
        for(j = i;j < lent;j++) {
        	cha[k++] = t[j];
		}
        strcpy(arr,b); 
    }
    if(judge(cha)) {
    	strcpy(cha,"0");
	}
    if(judge(arr)) {
    	strcpy(arr,"0");
	}  
}
int main() {
    scanf("%s%s",s,ss); 
    if(judge(ss)) {
    	cout<<"0不能作除数"<<endl;
	} else { 
        chu_gao();     
        if(!judge(arr))
            printf("%s / %s=%s......%s\n\n",s,ss,cha,arr);
        else 
            printf("%s / %s=%s\n\n",s,ss,cha);   
    } 
    return 0;
} 
