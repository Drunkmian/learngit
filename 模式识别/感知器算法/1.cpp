#include<iostream> 
using namespace std;
#define M 100 
int w[8][3]={{0,0,0}, {1,0,0}, {1,0,1}, {1,1,0}, {0,0,1}, {0,1,1}, {0,1,0}, {1,1,1}}; 
float W[M][4]={{-1,-2,-2,0}}; int X[8][4]; //��¼��������
 int m=0; //��¼ W �����
 int k=0; //��¼�������� 
 void Pre(int a[4][3])
  { for(int i=0;i<8;i++){
   for(int j=0;j<3;j++){ 
   if(i<4){ X[i][j]=a[i][j]; X[i][3]=1; }
   else{X[i][j]=-a[i][j]; X[i][3]=-1; 
   } 
   } 
   }
    }
	void Judge() { 
	int c=1; //У������ϵ�� 
	int error=0; //�����־ 
	cout<<"��"<<k+1<<"�ֵ���:"<<endl;
	 for(int i=0;i<8;i++) { 
	 int sum=0; 
	 for(int j=0;j<4;j++){ 
	 sum+=W[m][j]*X[i][j]; 
	 }
	 cout<<"W["<<m+1<<"]Tx"<<i+1<<"="<<sum<<endl; 
	 if(sum>0){ cout<<"W["<<m+2<<"]=(";
     for(int j=0;j<4;j++){ W[m+1][j]=W[m][j];
	  cout<<W[m+1][j]<<" "; }cout<<")"; }
	  else{cout<<"W["<<m+2<<"]=("; 
	  for(int j=0;j<4;j++){
	   W[m+1][j]=W[m][j]+c*X[i][j]; 
	   cout<<W[m+1][j]<<" "; 
	   }
	   cout<<")"; 
	   error++;
	    }
		m++; 
		cout<<endl; 
		}cout<<endl; 
		k++;
		 if(error>0) Judge(); 
		 else { cout<<"��������Ϊ��"<<k<<endl;
		  cout<<"������Ϊ��" <<"("; 
		  for(int j=0;j<4;j++) { 
		  cout<<W[m][j]<<" "; }
		  cout<<")"; } 
		  }
		  
int main() 
{ Pre(w); 
Judge(); 
return 0; } 
