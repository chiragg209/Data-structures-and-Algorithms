#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int flag=0;
  
int partition(vector <int> &a, int l, int r){
	int pivot=a[r];
	int i= l-1;
	for(int j=l;j<=r-1;j++){
		if(a[j]<pivot){
			i++;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			flag=1;
		}
	}
	int temp1=a[i+1];
	a[i+1]=a[r];
	a[r]=temp1;
	
	return (i+1);
}
void quicksort(vector <int> &a, int l, int r){
	if(l<r){
		int pi= partition(a,l,r);
		for(int i=0;i<6;i++)	cout<<a[i]<<" ";
		cout<<endl;
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
}
vector <int> randomgenerator(){
	srand(time(0));
	int n=rand()%10;
	
	vector <int> temp;
	for(int i=0;i<n;i++){
		temp.push_back(rand()%1000);
	}
	return temp;
}
int main(){
	int n;
	vector <int> A;
	vector <int> orig;
	int c1=0,c2=0;
	vector <int> B(6); // 8 7 2 5 10 9
	for(int i=0;i<6;i++)	cin>>B[i];
	quicksort(B,0,5);
	for(int i=0;i<6;i++)	cout<<B[i]<<" ";
	cout<<endl;
	
	
	while(!(c1 && c2)){
		flag=0;
		A=randomgenerator();
		orig=A;
		quicksort(A,0,A.size()-1);
		
		if(flag==1 && c1==0){
			cout<<"Testcase1:"<<endl;
			for(int i=0;i<orig.size();i++)
            	cout << A[i] << " ";
    		cout << endl;
			c1=1;
		}else if(flag==0 && c2==0){
			cout<<"Testcase2:"<<endl;
			for(int i=0;i<orig.size();i++)
            	cout << orig[i] << " ";
    		cout << endl;
			c2=1;
		}
	}
	
	return 0;
}
