#include <iostream>
#include <cmath>
using namespace std;

void Ten2Two(unsigned int n,int* arr)//ʮת��
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

unsigned int Two2Ten(int* arr)//��תʮ
{
    unsigned int n=0;
    for(int i=0;i<32;i++)
    {
        n+=arr[i]*pow(2,31-i);
    }
    return n;
}

void Two2Eig(int* t,int* ei)//��ת��
{
    for(int i=0;i<11;i++)
    {
        if(i==0)
            ei[i]=t[i]*2+t[i+1];
        else
            ei[i]=t[3*i-1]*4+t[3*i]*2+t[3*i+1];
    }
}

void Eig2Two(int *ei,int* t)//��ת��
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

void Hex2Two(int* h,int* t)//ʮ��ת��
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

void Two2Hex(int* t,int* h)//��תʮ��
{
    for(int i=0;i<8;i++)
    {
        h[i]=t[4*i]*8+t[4*i+1]*4+t[4*i+2]*2+t[4*i+3];
    }
}

int main(int argc, const char * argv[])
{
    int a[32]={0};//��ʼ����������
    unsigned int n=0;//��ʼ��ʮ������
    int eig[11]={0};//��ʼ���˽�����
    int hex[8]={0};//��ʼ��ʮ��������
    int flag=0;//��ʼ����־λ�����ڱ�ʶ��һ���������ĳ���λ�� 
    cout<<"1:ʮ����"<<endl;
    cout<<"2:������"<<endl;
    cout<<"3:�˽���"<<endl;
    cout<<"4:ʮ������"<<endl;
    cout<<"0:�˳�"<<endl;
    
    int c=-1;
    while(c)
    {
    	cout<<"-----------------------------"<<endl;
        cout<<"��������ƴ��룺";
        cin>>c;
        if (cin.fail()||c>4){
        	cin.clear();  //cin.clear()���������cin�Ĵ���״̬
			cin.ignore(); //cin.ignore()�����Ǻ��Ե������������ݣ�ֱ������EOFΪֹ
			c=-1; 
			cout<<"����������������룡"<<endl;
		}
        switch(c){
            case 1:{
                cout<<"������ʮ��������";
                cin>>n;
                if (cin.fail()){
        			cin.clear();
					cin.ignore();
					cout<<"��������򳬳��޷���int��ʾ��Χ��"<<endl;
					break;
				}
                Ten2Two(n, a);
                cout<<"������Ϊ��";
                flag=0;
                for(int i=0;i<32;i++)
                {
                    if(a[i]==1||i==31)
                        flag++;
                    if(flag!=0)
                        cout<<a[i];
                }
                cout<<endl;
                cout<<"�˽���Ϊ��";
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
                cout<<"ʮ������Ϊ��";
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
                cout<<"���������������";
                string str;
                cin>>str;
                int len=str.length();//��ȡ�ַ�������
                int err=0;
                for(int i=0;i<len;i++)//���Ϸ���
                {
                    if(str[i]>49||str[i]<48)
                        err++;
                }
                if(err>0){
                    cout<<"��������"<<endl;
                    break;
                }
                if(len>32){
                    cout<<"�����������ȴ����޷���int��ʾ��Χ�����������룡"<<endl;
                    break;
                }
                int des=32-len;
                for(int i=0;i<32;i++){
                    if(i<des)
                        a[i]=0;
                    else
                        a[i]=str[i-des]-48;//��charת��Ϊint
                }
                n=Two2Ten(a);
                cout<<"ʮ����Ϊ��"<<n<<endl;
                Two2Eig(a, eig);
                cout<<"�˽���Ϊ��";
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
                cout<<"ʮ������Ϊ��";
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
                cout<<"������˽�������";
                string str;
                cin>>str;
                int len=str.length();///��ȡ�ַ�������
                int err=0;
                for(int i=0;i<len;i++)//���Ϸ���
                {
                    if(str[i]>55)
                        err++;
                }
                if(err>0){
                    cout<<"��������"<<endl;
                    break;
                }
                if(len>11){
                    cout<<"�˽��������ȴ����޷���int��ʾ��Χ�����������룡"<<endl;
                    break;
                }
                err=0;
                int des=11-len;
                for(int i=0;i<11;i++){
                    if(i<des)
                        eig[i]=0;
                    else
                        eig[i]=str[i-des]-48;//��charת��Ϊint
                }
                if(eig[0]>3){
                	cout<<"���������޷���int��ʾ��Χ�����������룡"<<endl;
                	break; 
				}
                Eig2Two(eig, a);
                cout<<"������Ϊ��";
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
                cout<<"ʮ����Ϊ��"<<n<<endl;
                Two2Hex(a, hex);
                char s[8]={""};
                for(int i=0;i<8;i++){
                    if(hex[i]<10)
                        s[i]=hex[i]+48;
                    else
                        s[i]=hex[i]+55;
                }
                cout<<"ʮ������Ϊ��";
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
                cout<<"������ʮ����������";
                string str;
                cin>>str;
                int len=str.length();///��ȡ�ַ�������
                int err=len;
                int hex[8]={0};
                for(int i=0;i<len;i++)//���Ϸ���
                {
                    if(str[i]>47&&str[i]<58)
                        err--;
                    if(str[i]>64&&str[i]<71)
                        err--;
                    if(str[i]>96&&str[i]<103)
                    err--;
                }
                if(err>0){
                    cout<<"��������"<<endl;
                    break;
                }
                if(len>8){
                    cout<<"ʮ�����������ȴ����޷���int��ʾ��Χ�����������룡"<<endl;
                    break;
                }
                int des=8-len;
                for(int i=0;i<8;i++){
                    if(i<des)
                        hex[i]=0;
                    else{//��charת��Ϊint
                        if(str[i-des]>96)//�ж�Сд
                            hex[i]=str[i-des]-87;
                        else if(str[i-des]>64)//�жϴ�д
                            hex[i]=str[i-des]-55;
                        else if(str[i-des]>47)//�ж�����
                            hex[i]=str[i-des]-48;
                    }
                }
                Hex2Two(hex, a);
                cout<<"������Ϊ��";
                int flag=0;//��־λ�����ٵ�һ�����������ֵ�λ��
                for(int i=0;i<32;i++)
                {
                    if(a[i]==1||i==31)
                        flag++;
                    if(flag!=0)
                        cout<<a[i];
                }
                cout<<endl;
                n=Two2Ten(a);
                cout<<"ʮ����Ϊ��"<<n<<endl;
                Two2Eig(a, eig);
                cout<<"�˽���Ϊ��";
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
