#include<iostream> 
#include<cmath>

using namespace std;
#define M 10 

//��ʼ��ģʽ����
int X[10][2]= {{0,0},{3,8},{2,2},{1,1},{5,3},{4,8},{6,3},{5,4},{6,4},{7,5}};
float Z[3][2];//���������ڴ�ž������� 
float preZ1[M][2];//�洢��һ�ֵľ������� 
float preZ2[M][2];
float preZ3[M][2];
int k;//�����������ĵ���С���룬��������������Ӧ�������� 
//��ʼ���������� 
int S1[M][2];int s1=0;
int S2[M][2];int s2=0;
int S3[M][2];int s3=0;

float x,y;//�¾����������� 
int turn=0;
//��ʼ���������� 
void ClusterCenter()
{
	for(int i=0;i<3;i++){
	    for(int j=0;j<2;j++){
	    	Z[i][j]=X[i][j];
	     	//cout<<Z[i][j];
		}	
	} 
}

//����㵽ÿ���������ĵ����ֵ 
int Distance(int a[1][2],float b[3][2])
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

//�����µľ�������
void NewClusterCenter(int s,int a[M][2])
{
   int sum1=0,sum2=0;
   for(int i=0;i<s;i++){
       sum1+=a[i][0];
       sum2+=a[i][1];
       //cout<<a[i][0]<<endl;
       //cout<<a[i][1]<<endl;
   } 
   //cout<<sum1<<endl;
   //cout<<sum2<<endl;
   cout<<"��������"<<s<<endl;
   x=(float)sum1/s;
   y=(float)sum2/s;
   cout<<"�¾�����������Ϊ"<<endl; 
   cout<<x<<endl;
   cout<<y<<endl; 
} 

//���� 
void Iteration()
{ 
    s1=0;
    s2=0;
    s3=0;
    cout<<"���ǵ�"<<turn+1<<"�ֵ���"<<endl;
	int flag=0;
	for(int i=0;i<10;i++){
		int temp[1][2];
		for(int j=0;j<2;j++){
			temp[0][j]=X[i][j];
		//   cout<<temp[0][j];
		}
		Distance(temp,Z);
		cout<<"��������";
		if(k==0){
		   for(int j=0;j<2;j++){
		   S1[s1][j]=X[i][j];
		   cout<<S1[s1][j]<<" ";	
		   }
		   s1++;
     	}
		else if(k==1){
		   for(int j=0;j<2;j++){
		   S2[s2][j]=X[i][j];
		   cout<<S2[s2][j]<<" ";			
	       }
		   s2++;		
		}
		else{
		   for(int j=0;j<2;j++){
		   S3[s3][j]=X[i][j];
		   cout<<S3[s3][j]<<" ";		   			
	       }
	       s3++;	
		}
	    cout<<"��������"<<k+1<<"��"<<endl; 
	} 
	//cout<<s1<<" "<<s2<<" "<<s3<<endl; 

/*	for(int i=0;i<s1;i++){
		for(int j=0;j<2;j++){
			cout<<S1[i][j];
		}
		cout<<endl;
	}*/
	cout<<endl;
	cout<<"��һ��";
	NewClusterCenter(s1,S1);
	Z[0][0]=x;
	Z[0][1]=y;
    cout<<endl;
	cout<<"�ڶ���";    
	NewClusterCenter(s2,S2);
	Z[1][0]=x;
	Z[1][1]=y;
	cout<<endl;
	cout<<"������";	
	NewClusterCenter(s3,S3);
	Z[2][0]=x;
	Z[2][1]=y;    
    cout<<endl;

    for(int j=0;j<2;j++){
    	preZ1[turn][j]=Z[0][j];
    	preZ2[turn][j]=Z[1][j];
		preZ3[turn][j]=Z[2][j]; 
	//	cout<<preZ1[turn][j]<<endl;  
	//  cout<<preZ2[turn][j]<<endl;
    //  cout<<preZ3[turn][j]<<endl;	
	}
    

    turn++;
    if(turn==1){
      Iteration();	
	}
    else{	
    
       if(preZ1[turn-1][0]!=preZ1[turn-2][0]||preZ1[turn-1][1]!=preZ1[turn-2][1])
		  {flag++;
		  //cout<<"flag1"<<flag<<endl; 
		  }
       else if(preZ2[turn-1][0]!=preZ2[turn-2][0]||preZ2[turn-1][1]!=preZ2[turn-2][1])
         {flag++;
		 //cout<<"flag2"<<flag<<endl;
		  }
       else if(preZ3[turn-1][0]!=preZ3[turn-2][0]||preZ3[turn-1][1]!=preZ3[turn-2][1])
          {flag++;
		  //cout<<"flag3"<<flag<<endl;
		  }
       else
          flag=0;
         //cout<<"flag"<<flag<<endl; 
       if(flag>0){
       		Iteration();
		   }
       else{
    	  cout<<"���վ������ķֱ�Ϊ��"<<endl; 
	      for(int i=0;i<3;i++){
	      	cout<<"Z"<<i+1<<":("; 
	         for(int j=0;j<2;j++){
	    	 cout<<Z[i][j]<<" "; 
		     }
			cout<<")"<<endl;	
	      }
	      cout<<"�����������ڵ�һ��"; 
	      for(int i=0;i<s1;i++){
	      	cout<<"("; 
	      	for(int j=0;j<2;j++){
	      		cout<<S1[i][j]<<" ";
			  }
			cout<<")"; 
		  }
		  cout<<endl;
		  cout<<"�����������ڵڶ���"; 
	      for(int i=0;i<s2;i++){
	      	cout<<"("; 
	      	for(int j=0;j<2;j++){
	      		cout<<S2[i][j]<<" ";
			  }
			cout<<")";
		  }
		  cout<<endl;
		  cout<<"�����������ڵ�����"; 
	      for(int i=0;i<s3;i++){
	      	cout<<"("; 
	      	for(int j=0;j<2;j++){
	      		cout<<S3[i][j]<<" ";
			  }
			cout<<")";
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





