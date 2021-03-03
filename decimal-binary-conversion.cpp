#include <iostream>
#include <cmath>
using namespace std;

void Ten2Two(unsigned int n,int* arr)//十转二
{
    for(int i=0;i<32;i++)
    {
        if(n-pow(2,31-i)>=0){
            arr[i]=1;
            n=n-pow(2,31-i);
        }
        else
            arr[i]=0;
    }
}

unsigned int Two2Ten(int* arr)//二转十
{
    unsigned int n=0;
    for(int i=0;i<32;i++)
    {
        n+=arr[i]*pow(2,31-i);
    }
    return n;
}

void Two2Eig(int* t,int* ei)//二转八
{
    for(int i=0;i<11;i++)
    {
        if(i==0)
            ei[i]=t[i]*2+t[i+1];
        else
            ei[i]=t[3*i-1]*4+t[3*i]*2+t[3*i+1];
    }
}

void Eig2Two(int *ei,int* t)//八转二
{
    for(int i=0;i<11;i++)
    {
        int n=ei[i];
        if(i==0){
            for(int j=0;j<2;j++){
                if(n-pow(2,1-j)>=0){
                    t[j]=1;
                    n=n-pow(2,1-j);
                }
                else
                    t[j]=0;
            }
        }
        else
            for(int j=0;j<3;j++){
                if(n-pow(2,2-j)>=0){
                    t[3*i-1+j]=1;
                    n=n-pow(2,2-j);
                }
                else
                    t[3*i-1+j]=0;
                
            }
    }
}

void Hex2Two(int* h,int* t)//十六转二
{
    for(int i=0;i<8;i++)
    {
        int n=h[i];
        for(int j=0;j<4;j++){
            if(n-pow(2,3-j)>=0){
                t[4*i+j]=1;
                n=n-pow(2,3-j);
            }
            else
                t[4*i+j]=0;
            }
    }
}

void Two2Hex(int* t,int* h)//二转十六
{
    for(int i=0;i<8;i++)
    {
        h[i]=t[4*i]*8+t[4*i+1]*4+t[4*i+2]*2+t[4*i+3];
    }
}

int main(int argc, const char * argv[])
{
    int a[32]={0};//初始化二进制数
    unsigned int n=0;//初始化十进制数
    int eig[11]={0};//初始化八进制数
    int hex[8]={0};//初始化十六进制数
    int flag=0;//初始化标志位，用于标识第一个非零数的出现位置 
    cout<<"1:十进制"<<endl;
    cout<<"2:二进制"<<endl;
    cout<<"3:八进制"<<endl;
    cout<<"4:十六进制"<<endl;
    cout<<"0:退出"<<endl;
    
    int c=-1;
    while(c)
    {
    	cout<<"-----------------------------"<<endl;
        cout<<"请输入进制代码：";
        cin>>c;
        if (cin.fail()||c>4){
        	cin.clear();  //cin.clear()作用是清除cin的错误状态
			cin.ignore(); //cin.ignore()作用是忽略掉缓冲区的内容，直到遇到EOF为止
			c=-1; 
			cout<<"输入错误，请重新输入！"<<endl;
		}
        switch(c){
            case 1:{
                cout<<"请输入十进制数：";
                cin>>n;
                if (cin.fail()){
        			cin.clear();
					cin.ignore();
					cout<<"输入有误或超出无符号int表示范围！"<<endl;
					break;
				}
                Ten2Two(n, a);
                cout<<"二进制为：";
                flag=0;
                for(int i=0;i<32;i++)
                {
                    if(a[i]==1||i==31)
                        flag++;
                    if(flag!=0)
                        cout<<a[i];
                }
                cout<<endl;
                cout<<"八进制为：";
                Two2Eig(a, eig);
                flag=0;
                for(int i=0;i<11;i++)
                {
                    if(eig[i]!=0||i==10)
                        flag++;
                    if(flag!=0)
                        cout<<eig[i];
                }
                cout<<endl;
                Two2Hex(a, hex);
                char s[8]={""};
                for(int i=0;i<8;i++){
                    if(hex[i]<10)
                        s[i]=hex[i]+48;
                    else
                        s[i]=hex[i]+55;
                }
                cout<<"十六进制为：";
                flag=0;
                for(int i=0;i<8;i++)
                {
                    if(s[i]!=48||i==7)
                        flag++;
                    if(flag!=0)
                        cout<<s[i];
                }
                cout<<endl;
                break;
            }
            case 2:{
                cout<<"请输入二进制数：";
                string str;
                cin>>str;
                int len=str.length();//获取字符串长度
                int err=0;
                for(int i=0;i<len;i++)//检查合法性
                {
                    if(str[i]>49||str[i]<48)
                        err++;
                }
                if(err>0){
                    cout<<"输入有误！"<<endl;
                    break;
                }
                if(len>32){
                    cout<<"二进制数长度大于无符号int表示范围，请重新输入！"<<endl;
                    break;
                }
                int des=32-len;
                for(int i=0;i<32;i++){
                    if(i<des)
                        a[i]=0;
                    else
                        a[i]=str[i-des]-48;//将char转换为int
                }
                n=Two2Ten(a);
                cout<<"十进制为："<<n<<endl;
                Two2Eig(a, eig);
                cout<<"八进制为：";
                flag=0;
                for(int i=0;i<11;i++)
                {
                    if(eig[i]!=0||i==10)
                        flag++;
                    if(flag!=0)
                        cout<<eig[i];
                }
                cout<<endl;
                Two2Hex(a, hex);
                char s[8]={""};
                for(int i=0;i<8;i++){
                    if(hex[i]<10)
                        s[i]=hex[i]+48;
                    else
                        s[i]=hex[i]+55;
                }
                cout<<"十六进制为：";
                flag=0;
                for(int i=0;i<8;i++)
                {
                    if(s[i]!=48||i==7)
                        flag++;
                    if(flag!=0)
                        cout<<s[i];
                }
                cout<<endl;
                break;
            }
            case 3:{
                cout<<"请输入八进制数：";
                string str;
                cin>>str;
                int len=str.length();///获取字符串长度
                int err=0;
                for(int i=0;i<len;i++)//检查合法性
                {
                    if(str[i]>55)
                        err++;
                }
                if(err>0){
                    cout<<"输入有误！"<<endl;
                    break;
                }
                if(len>11){
                    cout<<"八进制数长度大于无符号int表示范围，请重新输入！"<<endl;
                    break;
                }
                err=0;
                int des=11-len;
                for(int i=0;i<11;i++){
                    if(i<des)
                        eig[i]=0;
                    else
                        eig[i]=str[i-des]-48;//将char转换为int
                }
                if(eig[0]>3){
                	cout<<"该数大于无符号int表示范围，请重新输入！"<<endl;
                	break; 
				}
                Eig2Two(eig, a);
                cout<<"二进制为：";
                flag=0;
                for(int i=0;i<32;i++)
                {
                    if(a[i]==1||i==31)
                        flag++;
                    if(flag!=0)
                        cout<<a[i];
                }
                cout<<endl;
                n=Two2Ten(a);
                cout<<"十进制为："<<n<<endl;
                Two2Hex(a, hex);
                char s[8]={""};
                for(int i=0;i<8;i++){
                    if(hex[i]<10)
                        s[i]=hex[i]+48;
                    else
                        s[i]=hex[i]+55;
                }
                cout<<"十六进制为：";
                flag=0;
                for(int i=0;i<8;i++)
                {
                    if(s[i]!=48||i==7)
                        flag++;
                    if(flag!=0)
                        cout<<s[i];
                }
                cout<<endl;
                break;
            }
            case 4:{
                cout<<"请输入十六进制数：";
                string str;
                cin>>str;
                int len=str.length();///获取字符串长度
                int err=len;
                int hex[8]={0};
                for(int i=0;i<len;i++)//检查合法性
                {
                    if(str[i]>47&&str[i]<58)
                        err--;
                    if(str[i]>64&&str[i]<71)
                        err--;
                    if(str[i]>96&&str[i]<103)
                    err--;
                }
                if(err>0){
                    cout<<"输入有误！"<<endl;
                    break;
                }
                if(len>8){
                    cout<<"十六进制数长度大于无符号int表示范围，请重新输入！"<<endl;
                    break;
                }
                int des=8-len;
                for(int i=0;i<8;i++){
                    if(i<des)
                        hex[i]=0;
                    else{//将char转换为int
                        if(str[i-des]>96)//判断小写
                            hex[i]=str[i-des]-87;
                        else if(str[i-des]>64)//判断大写
                            hex[i]=str[i-des]-55;
                        else if(str[i-des]>47)//判断数字
                            hex[i]=str[i-des]-48;
                    }
                }
                Hex2Two(hex, a);
                cout<<"二进制为：";
                int flag=0;//标志位，跟踪第一个非零数出现的位置
                for(int i=0;i<32;i++)
                {
                    if(a[i]==1||i==31)
                        flag++;
                    if(flag!=0)
                        cout<<a[i];
                }
                cout<<endl;
                n=Two2Ten(a);
                cout<<"十进制为："<<n<<endl;
                Two2Eig(a, eig);
                cout<<"八进制为：";
                flag=0;
                for(int i=0;i<11;i++)
                {
                    if(eig[i]!=0||i==10)
                        flag++;
                    if(flag!=0)
                        cout<<eig[i];
                }
                cout<<endl;
                break;
            }
        }
    }
    
}
