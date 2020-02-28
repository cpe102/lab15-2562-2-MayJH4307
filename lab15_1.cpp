#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *dPtr,int N,int M){
	double x;
	for(int i =0;i<N*M;i++){
		x = (rand()%101)/100.0;
		*dPtr = x;
		dPtr++;
	}
}

void findRowSum(const double *dPtr,double *result,int N,int M){
	double sum=0;
	for(int i=0;i<N;i++){
		for(int j=0 ;j<M ; j++){
			sum += *dPtr;
			dPtr++;
		}
		*result = sum ;
		result++;
		sum =0;
	}
}

void showData(double *a,int N,int M){
	
	for(int i=0 ;i<N;i++){
		for(int j=0;j<M;j++){
			cout << *a << " ";
			a++;
		}
		cout << endl;
	}
}
