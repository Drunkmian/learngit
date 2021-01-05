#include<iostream>
using namespace std;

//初始化训练样本 
int w1[4][3]={{0,0,0},{1,0,0},{1,0,1},{1,1,0}};
int w2[4][3]={{0,0,1},{0,1,1},{0,1,0},{1,1,1}};

int l=0;//记录W迭代次数 
int t=1;//记录迭代轮数 
int W[100][4]={{-1,-2,-2,0}};
int c=1;//校正参量系数
int X[8][4];//增广向量 

//将训练样本写成增广向量形式 
void Augmented_vector(int a[4][3],int b[4][3])
{
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			X[i][j]=a[i][j];
			X[i][3]=1;
		}
	}
	for(int i=4;i<8;i++){
		for(int j=0;j<3;j++){
			X[i][j]=-b[i-4][j];
			X[i][3]=-1;
		}
	}
/*	for(int i=0;i<8;i++){
		for(int j=0;j<4;j++){
			cout<<X[i][j];
		}
		cout<<endl; 
	}  */	
} 

//判别迭代
void Iteration()
{   
    cout<<"第"<<t<<"轮迭代："<<endl; 
    int flag=0;
    for(int k=0;k<8;k++){
       int s=0;
       for(int j=0;j<4;j++){
       	    s+=W[l][j]*X[k][j];	
        }
       cout<<"W["<<l+1<<"]TX"<<k+1<<"="<<s;	   
	
		if(s>0){
			    cout<<">0,故"<<endl;
				cout<<"W["<<l+2<<"]=W["<<l+1<<"]="; 
                for(int j=0;j<4;j++){
       	            W[l+1][j]=W[l][j];
                    cout<<W[l+1][j]<<" ";
		        }
		        cout<<endl;
        }
	    else{
			    cout<<"<=0,故"<<endl;
				cout<<"W["<<l+2<<"]=W["<<l+1<<"]+c*X["<<k+1<<"]="; 
                for(int j=0;j<4;j++){
       	            W[l+1][j]=W[l][j]+c*X[k][j];
					cout<<W[l+1][j]<<" ";	
            	}
            	cout<<endl;
			 flag++;			
	    	}
	    l++;
    }
    t++;
    if(flag>0)
   	    Iteration();
    else{
    	cout<<"迭代次数："<<t-1<<endl;
   	    cout<<"解向量为"<<endl; 
   	    for(int j=0;j<4;j++){
   	    	cout<<" "<<W[l][j];
		   } 		 
   }   	
} 

int main()
{
   Augmented_vector(w1,w2);
   Iteration();
   return 0; 
}

