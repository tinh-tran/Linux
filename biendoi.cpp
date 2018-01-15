#include <iostream>
using namespace std;
 
#define size 6
#define max 10

//nhập vào rows cells 
//int rows,cells
//cout>> cin<<
//
void chuyendoi(int arr[size],int temp[][max],int rows,int cells)
{
        int i = size/rows;
        int j = size/cells;
        cout<<"\n Mảng 2 chiều với " <<i <<" dòng "<< j <<" cột : " ;
        
        int index=0;
        for(int row = 0 ; row<i; row++)
        {
            for(int col = 0; col<j; col++)
            {   
                temp[row][col] = arr[index];
                index++;
            }
        }
    
        cout<<"\n Mảng mới :- \n ";
        for(int row = 0 ; row<i; row++)
        {
            for(int col = 0; col < j; col++)
            {
                cout<<" "<< temp[row][col];
            }
            cout<<"\n ";
        }
  
}

void xuat(int temp[][max],int rows, int cells)
{
		int i = size/rows;
        int j = size/cells;
for(int row=0;row<i;row++)
	{
		for(int col=0;col<j;col++)
		 {
		 cout<<" "<< temp[row][col];
		 }
		 cout<<"\n ";
	} 
}
void XoaCot(int temp[][max],int rows,int cells)
{
	int i = size/rows;
    int j = size/cells;
	int cot;
	 cout <<"Nhập cột cần xoá";
	 cin>> cot; 
for(int row = 0 ; row<i; row++)
 for(int col=cot;col<j-1;col++)
 {
 	temp[row][col]=temp[row][col+1];
 }
 j--;
 xuat(temp,rows,j-1); 
}
void XoaDong(int temp[][max],int rows,int cells)
{
	int i = size/rows;
    int j = size/cells;
 int dong; 
 cout <<"Nhập dòng cần xoá";
 cin>> dong; 
for(int row = dong ; row<i; row++)
    {
    for(int col = 0; col<j; col++)
        {   
		 temp[row][col]=temp[row+1][col];
		}
	}
  i--;
 xuat(temp,rows,cells);
}

 main()
{
	//cấp phát động Cấp phát mảng 10 phần tử kiểu int:
	//int *a = (int *) malloc( 10 * sizeof( int ));
	//int *b = (int *) calloc( 10, sizeof( int ));
    int arr[size] = {1,2,3,4,5,6};
    int temp[max][max];
	int rows,cells;
    cout<<"\n Nhap so cột: ";
    cin>>rows;
	cout<<"\n Nhap so dòng: ";
    cin>>cells;
    
    if(size % rows != 0)
    {
        cout<<"\n Không thể tạo mảng 2 chiều";
    }
	if(size % cells != 0)
	{
		cout<<"\n Không thể tạo mảng 2 chiều";
	}
    else
    {
	chuyendoi(arr,temp,rows,cells);
	}
	XoaDong(temp,rows,cells);
	XoaCot(temp,rows,cells);
	return 0;
}