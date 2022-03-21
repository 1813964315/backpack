#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;
//********************ȫ�ֱ���****************************
int N;                        		//�����ܸ��� 
int WMAX;                      		//������� 
int cw=0,cp=0;                 		//��ǰ�����ͼ�ֵ
int max_value=0;    	       		//���������ֵ 
double totaltime=0;            		//���㺯��ʱ�� 
int vw[200];            	   		//��λ������ 
int w_v[200][2];    	       		//��ֵ��������
int T[1500][1500];  	       		//��̬�滮��� 
int decrease[200];  	       		//����ݼ����е��±� 
int vector_quantity[200];  	   		//������
int best_results[200];        	 	//���������� 
int left_value;                		//ʣ���ܼ�ֵ�����ݼ�֦ 
string s;                      		//�ļ����ַ��� 
ofstream ofs;                  		//�������������
ifstream ifs;                       //��������������

_LARGE_INTEGER time_start;     		/*��ʼʱ��*/
_LARGE_INTEGER time_over;      		/*����ʱ��*/
double dqFreq;                      /*��ʱ��Ƶ��*/
LARGE_INTEGER f;                    /*��ʱ��Ƶ��*/

//*******************�㷨����******************************
int DP();                           //��̬�滮���KP���� 
int output();                  		//�����������
int Greedy();                  		//̰���㷨���KP����
int KnapSack();                		//������̬�滮�� 
void get_data();       	            //���ļ���ȡ�ò�������
int sort(int choice);          		//����λ������ֵ����
int input(int choice);         		//ѡ�����������ļ�0-9 
void output_result();               //����������д���ļ�
void scatter_diagram();             //����ɢ��ͼ 
void Backtracking(int i);      		//���ݷ����KP���� 
//******************������********************************* 
int main()
{
	int choice; 
	printf(" *******0/1��������********\n\n");
	printf("        1.��̬�滮��       \n");
	printf("        2.̰���㷨         \n");
	printf("        3.�����㷨         \n");
	printf("        4.�ǵ�������       \n");
	printf("        5.����ɢ��ͼ       \n");
	printf("        6.��ȷ��������     \n");
	printf("        7.��������         \n\n"); 
	printf(" **************************\n");
	cout<<"��ѡ���㷨(���������)��"; 
	cin>>choice;
	while(choice!=7)
	{
		switch (choice)
		{
			case 1:
				//ѡ������0-9 
			    input(choice);
				break;
			case 2:
			    input(choice);
				break;
			case 3:
			    input(choice);
				break;
			case 4:
			    input(choice);
				break;
			case 5:
			 	input(choice);
				break;
			case 6:
			 	input(choice);
				break;
			default:
			    printf("����ˣ����������룡\n");
				break;	
	    }
	    printf(" *******0/1��������********\n\n");
		printf("        1.��̬�滮��       \n");
		printf("        2.̰���㷨         \n");
		printf("        3.�����㷨         \n");
		printf("        4.�ǵ�������       \n");
		printf("        5.����ɢ��ͼ       \n");
		printf("        6.��ȷ��������     \n");
		printf("        7.��������         \n\n"); 
		printf(" **************************\n");
	    cout<<"��ѡ���㷨(���������)��"; 
	    cin>>choice;
	}
	return 0;
} 
//0.ѡ�����������ļ�0-9 
int input(int choice)
{
	vector<int> v;
	int choice2;

	printf("---------ѡ���������0-9----------\n\n");
	printf("          0. ��������0            \n");
	printf("          1. ��������1            \n");
	printf("          2. ��������2            \n");
	printf("          3. ��������3            \n");
	printf("          4. ��������4            \n");
	printf("          5. ��������5            \n");
	printf("          6. ��������6            \n");
	printf("          7. ��������7            \n");
	printf("          8. ��������8            \n");
	printf("          9. ��������9            \n");
	printf("          10.�����ϼ��б�         \n\n");
	printf("----------------------------------\n");
	cout<<"��ѡ���������(�򷵻��ϼ�)��";
	cin>>choice2; 
	while(choice2!=10)
	{
		//ÿ�ζ���ն�ά���飬�Ա���Ӱ���´����ݵĲ��� 
    	memset(&w_v[0][0],0,sizeof(w_v));
    	//�ļ���һ������Ϊ���������Լ����������赥���ó�����count������ 
		switch (choice2)
		{
			//���ļ� //ִ���㷨 
			case 0: ifs.open("beibao0.in",ios::in); s="beibao0.in"; get_data(); break;
			case 1: ifs.open("beibao1.in",ios::in); s="beibao1.in"; get_data(); break;
			case 2: ifs.open("beibao2.in",ios::in); s="beibao2.in"; get_data(); break;
			case 3: ifs.open("beibao3.in",ios::in); s="beibao3.in"; get_data(); break;
			case 4: ifs.open("beibao4.in",ios::in); s="beibao4.in"; get_data(); break;
			case 5: ifs.open("beibao5.in",ios::in); s="beibao5.in"; get_data(); break;
			case 6: ifs.open("beibao6.in",ios::in); s="beibao6.in"; get_data(); break;
			case 7: ifs.open("beibao7.in",ios::in); s="beibao7.in"; get_data(); break;
			case 8: ifs.open("beibao8.in",ios::in); s="beibao8.in"; get_data(); break;
			case 9: ifs.open("beibao9.in",ios::in); s="beibao9.in"; get_data(); break;
			default: cout<<"����������������룡"<<endl; break;	
	    }
		QueryPerformanceFrequency(&f);
    	dqFreq=(double)f.QuadPart;
    	QueryPerformanceCounter(&time_start);
    	if(choice==1)
    		DP();
		else if(choice==2)
			Greedy();
		else if(choice==3)
		{
			cw=0,cp=0;
			max_value=0; 
			for(int i=0;i<N;i++)
			{
				left_value+=w_v[i][1];	
			} 
			Backtracking(0);
			for(int i=0;i<N;i++)
			{
				vector_quantity[i]=best_results[i];
			}
			ofs.open("Backtracking.txt",ios::out|ios::app); 
    		output_result();
		}else if(choice==4)
			sort(choice);
		else if(choice==6)
	        break;
		else if(choice==5){
			scatter_diagram(); 	
		}		    
		QueryPerformanceCounter(&time_over);
		cout<<"����ʱ��:"<<((time_over.QuadPart-time_start.QuadPart)/dqFreq)<<"s\n";
		if(choice==1)
			cout<<"�����д��DP.txt�ļ��У�\n";    
		else if(choice==2)
			cout<<"�����д��Greedy.txt�ļ��У�\n"; 
		else if(choice==3)
		 	cout<<"�����д��backtracking.txt�ļ��У�\n";	
		ofs<<"Time:"<<((time_over.QuadPart-time_start.QuadPart)/dqFreq)<<"s\n";
		ofs.close();
		system("pause");
		cout<<"\n��ѡ��������ݣ��򷵻��ϼ�����";
		cin>>choice2; 
	}
	cout<<endl;
	return 0;
} 
//��֪WMAX��N��w_v[N][2]��Ҫ�Ľ���������װ�������� 
//1.��̬�滮���KP���� 
int DP()
{ 
	max_value=KnapSack();
	ofs.open("DP.txt",ios::out|ios::app); 
	output_result();
	return 0;
}
//2.������̬�滮�� 
int KnapSack()
{
	int i=0,j=0;
	int a=0,b=0;
	for(i=0;i<=N;i++)
	{
		T[i][0]=0;
	}
	for(j=0;j<=WMAX;j++)
	{
		T[0][j]=0;
	}
	for(i=1;i<=N;i++)
	{   //�����i�У����е�i�ε��� 
		for(j=1;j<=WMAX;j++)
		{
			//���Ʊ� 
			T[i][j]=T[i-1][j];
			if(j>=w_v[i-1][0] && T[i][j]<w_v[i-1][1]+T[i-1][j-w_v[i-1][0]]) 
		        T[i][j]=w_v[i-1][1]+T[i-1][j-w_v[i-1][0]];
		} 
	}
	for(j=WMAX,i=N;i>=1;i--)
	{   //��װ�뱳������Ʒ 
		if(T[i][j]>T[i-1][j])
		{
			vector_quantity[i]=1;  //����ǰ��ֵ������һ�м�ֵ��˵����ǰ��Ʒ��װ�뱳���� 
			j=j-w_v[i][0];
		}
	}
	//�õ�����ȡ�õ�����ֵ 
	return T[N][WMAX];  
}
//3.̰���㷨���KP���⣨�õ��Ľ���ǽ��ƽ⣬�������Ž⣡������ 
int Greedy()
{
	int choice3=0;
	//ֱ��ʹ���ź�����±����̰��ѡ��
	//��������������Լ������� 
	int k=0,g=0;
	//���¹�0�������´�ʹ�� 
	max_value=0;
	sort(choice3);
	for(int i=0;i<N;i++)
	{
		g=decrease[k];
		if(w_v[g][0]<=WMAX && WMAX>0)
		{
			max_value+=w_v[g][1];  //��ֵ���� 
			WMAX-=w_v[g][0];       //�������� 
			vector_quantity[g]=1; 
		}
		k++;	
	}
	//�����д���ļ� 
	ofs.open("Greedy.txt",ios::out|ios::app); 
	output_result();
	return 0;
}
//4.���ݷ�
void Backtracking(int i)
{
    if(i>=N) //�ݹ�������ж�����
    {   
	    if(cp>max_value)
		{
    	    max_value = cp;                                                 
    	    for(int i=0;i<N;i++)
			{
    	    	best_results[i]=vector_quantity[i];
			}
	    }
        return;
    }
    left_value-=w_v[i][1];
    //�������ӽڵ���У���ֱ������������;
    //�������������ȼ����Ͻ纯�������ж��Ƿ����ȥ
    if(cw+w_v[i][0]<=WMAX )//����Ʒi���뱳��,����������
    {
        cw+=w_v[i][0];       //ͬ�����µ�ǰ����������
        cp+=w_v[i][1];       //ͬ�����µ�ǰ�������ܼ�ֵ
        vector_quantity[i]=1;
        Backtracking(i+1);   //�������������һ��
        cw-=w_v[i][0];       //���ݸ�ԭ
        cp-=w_v[i][1];       //���ݸ�ԭ
    }
    if(cp+left_value>max_value)//������������������������
    	Backtracking(i+1);
    left_value+=w_v[i][1];
}
//5.����λ������ֵ���򣨵ݼ����� 
int sort(int choice)
{
    int index;                  //�±� 
    int k=0,g=0; 
	for(int i=0;i<N;i++)
	{
		decrease[i]=i;
		vector_quantity[i]=0; 
	}
	//ð������
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<N-1-i;j++)
		{
			if(vw[j]<vw[j+1])
			{
				index=vw[j];
				vw[j]=vw[j+1];
				vw[j+1]=index;
				index=decrease[j];
				decrease[j]=decrease[j+1];  //�����±꣬�����ݼ����� 
				decrease[j+1]=index;        //���ʱѭ��������±��õ�decrease�е� 
			}	
		}
	}
	if(choice==4)
	{
		cout<<"�±�����"<<endl;
		for(int m=0;m<N;m++)
		{
			cout<<decrease[m]+1<<" ";
		}
		cout<<endl<<"����λ������ֵ�ݼ�����"<<endl;
		for(int i=0;i<N;i++)
		{
			g=decrease[k];
			cout<<"����"<<g+1<<"  ";
			cout<<w_v[g][0]<<"  "<<w_v[g][1]<<"  ";
	    	printf("%.2f\n",w_v[g][1]/float(w_v[g][0]));	
			k++;	
		}
	} 
	return 0;	
} 
//6.���ļ���ȡ�ò������� 
void get_data()
{
	int count=0;
	int t1;
	int *p=&w_v[0][0];
	if(!ifs.is_open())
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		return;
	}
	//��������
	while(ifs>>t1)
	{   //�����հ׷����� 
		count++;
		if(count==1)
		{
		    WMAX=t1;  //������� 
			cout<<"�������ƣ�"<<WMAX<<"--->"; 
		}else if(count==2)
		{
			N=t1;     //��������
			cout<<"����������"<<N<<endl;  
		}else
		{
			*p=t1;
			p++;	
		}		
	}
	ifs.close();
	output();
}
//7.�����������
int output(){
	for(int i=0;i<N;i++)
	{
		vw[i]=0;
	}
	cout<<"---------------------------"<<endl;
	cout<<"      ����"<<" "<<"��ֵ"<<" "<<"��ֵ/����"<<endl; 
	for(int i=0;i<N;i++)
	{
		cout<<"����"<<i+1<<" "; 
		for(int j=0;j<2;j++)
		{
			cout<<" "<<w_v[i][j]<<"  ";
		}
		printf("%.2f",w_v[i][1]/float(w_v[i][0]));
		vw[i]=w_v[i][1]/float(w_v[i][0]); 
		cout<<endl;
	}
	cout<<"---------------------------"<<endl;
	return 0;
}
//8.����������д���ļ�
void output_result()
{
	ofs<<s<<"      ";
	ofs<<"Max_value:"<<max_value<<"      ";
	cout<<"\n���㷨����õ�����ֵΪ��"<<max_value<<endl;
	ofs<<"solution_vector:{";
	cout<<"������Ϊ��{";
	for(int i=0;i<N;i++)
	{
		if(i==N-1)
		{
			ofs<<vector_quantity[i];
		    cout<<vector_quantity[i];
		}else
		{
			ofs<<vector_quantity[i]<<",";
		    cout<<vector_quantity[i]<<",";
		}
	}
	cout<<"}"<<endl;
	ofs<<"}"<<"      ";
} 
//9.����ɢ��ͼ 
void scatter_diagram()
{
	cout<<"����Ŀ����C++������ʹ�ã��㵥����pythonʵ����ɢ��ͼ����\n";
	cout<<"�����ͬ·���µ�picture�ļ����(�˲��ֹ���������չ)\n";
} 
 





 
