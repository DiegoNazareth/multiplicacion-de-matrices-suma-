#include <iostream>

int** crear(int ,int);
void llenar(int **mat,int,int);
void imprimir(int **mat,int ,int );
int** multiplicar(int **mat1,int,int,int **mat2,int,int);
using namespace std;

int main(){
	int ren1,col1,ren2,col2;
	int **mat1,**mat2,**mat3;
	cout<<"Cuantos renglones son de la matriz 1: ";
	cin>>ren1;
	cout<<endl<<"Cuantas columnas son de la matriz 1: ";
	cin>>col1;
	cout<<"Cuantos renglones son de la matriz 2: ";
	cin>>ren2;
	cout<<endl<<"Cuantas columnas son de la matriz 2: ";
	cin>>col2;
	if(col1!=ren2){
		cout<<endl<<"No se puede multiplicar la matriz";
		return 1;
	}else{
		mat1=crear(ren1,col1);
		mat2=crear(ren2,col2);
		cout<<endl<<"Dame los datos matriz 1"<<endl;
		llenar(mat1,ren1,col1);
		cout<<endl<<"Dame los datos matriz 2"<<endl;
		llenar(mat2,ren2,col2);
		cout<<endl<<"Imprimiendo matriz 1";
		imprimir(mat1,ren1,col1);
		cout<<endl<<"Imprimiendo matriz 2";
		imprimir(mat2,ren2,col2);
		cout<<endl<<"Multiplicando matrices";
		mat3=multiplicar(mat1,ren1,col1,mat2,ren2,col2);
		cout<<endl<<"Imprimiendo matriz resultante";
		imprimir(mat3,ren1,col2);
	}
	
	return 0;
}

int** crear(int ren,int col){
	int **mat=new int *[ren];
	for(int i=0;i<ren;i++){
		mat[i]=new int[col];
	}
	return mat;
}

void llenar(int **mat,int ren,int col){
	for(int i=0;i<ren;i++){
		for(int j=0;j<col;j++){
			cout<<"Valor de "<<i<<"x"<<j<<endl;
			cin>>mat[i][j];
		}
	}
}

void imprimir(int **mat,int ren,int col){
	for(int i=0;i<ren;i++){
		cout<<endl;
		for(int j=0;j<col;j++){
			cout<<mat[i][j]<<" ";
		}
	}
}

int** multiplicar(int **mat1,int ren1,int col1,int **mat2,int ren2,int col2){
	int i,j,k,acum;
	int **mat=crear(ren1,col2);
	for(i=0;i<ren1;i++){
		for(j=0;j<col2;j++){
			acum=0;
			for(k=0;k<col1;k++){
				acum+=mat1[i][k]*mat2[k][j];
				mat[i][j]=acum;
			}
		}
	}
	return mat;
}
