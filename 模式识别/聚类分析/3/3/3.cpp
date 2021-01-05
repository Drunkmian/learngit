#include<iostream> 
#include<cmath>

using namespace std;
#define M 10 

//初始化模式样本
int X[10][2]= {{0,0},{3,8},{2,2},{1,1},{5,3},{4,8},{6,3},{5,4},{6,4},{7,5}};
int Z[3][2];//该数组用于存放聚类中心 
int k;//求出与聚类中心的最小距离，将该样本分至相应聚类中心 
//初始化三个聚类 
int S1[M][2];int s1=0;
int S2[M][2];int s2=0;
int S3[M][2];int s3=0;

int x,y;//新聚类中心坐标 
//初始化聚类中心 
void ClusterCenter()
{
	for(int i=0;i<3;i++){
	    for(int j=0;j<2;j++){
	    	Z[i][j]=X[i][j];
		}	
	}
}

//计算点到每个聚类中心的最大值 
int Distance(int a[1][2],int b[3][2])
{   
	//float dmin;
  	float d[3];
  	for(k=0;k<3;k++){
  		d[k]=sqrt((a[0][0]-b[k][0])*(a[0][0]-b[k][0])+(a[0][1]-b[k][1])*(a[0][1]-b[k][1])); 
	}
  	
	if((d[0] <= d[1]) && (d[0] <= d[2]))
    //    dmin=d[0];
        k=0;
    else if ((d[1] <= d[0]) && (d[1] <= d[2]))
    //    dmin=d[1];
        k=1;
    else
    //    dmin=d[2];
        k=2;
    return k;
} 

//计算新的聚类中心
void NewClusterCenter(int s,int a[M][2])
{
   int sum1,sum2;
   for(int i=0;i<=s;i++){
       sum1+=a[i][0];
       sum2+=a[i][1];
   } 
   x=(1/(s+1))*sum1;
   y=(1/(s+1))*sum2;
} 

//迭代 
void Iteration()
{ 
	int flag;
	for(int i=0;i<10;i++){
		int temp[1][2];
		temp[0][1]=X[i][2];
		Distance(X,Z);
		if(k==0){
		   for(int j=0;j<2;j++){
		   S1[s1][j]=X[i][j];
		   s1++;	
		   }
     	}
		else if(k==1){
		   for(int j=0;j<2;j++){
		   S2[s2][j]=X[i][j];
		   s2++;			
	       }		
		}
		else
		   for(int j=0;j<2;j++){
		   S3[s3][j]=X[i][j];
		   s3++;			
	       }		   
	} 
	NewClusterCenter(s1,S1);
	Z[0][0]=x;
	Z[0][1]=y;
	NewClusterCenter(s2,S2);
	Z[1][0]=x;
	Z[1][1]=y;
	NewClusterCenter(s3,S3);
	Z[2][0]=x;
	Z[2][1]=y;    
    
    if(Z[0][0]!=Z[1][0]||Z[0][0]!=Z[2][0]||Z[1][0]!=Z[2][0])
       flag++;
    else if(Z[0][1]!=Z[1][1]||Z[0][1]!=Z[2][1]||Z[1][1]!=Z[2][1])
       flag++;
    else
       flag=0;
       
    if(flag>0)
    Iteration();
    else{
    	cout<<"聚类中心为"<<endl; 
	    for(int i=0;i<3;i++){
	      for(int j=0;j<2;j++){
	    	cout<<Z[i][j]<<" "; 
		  }	
	    }
    }
} 

int main()
{
	ClusterCenter();
	Iteration();
	return 0;
}
