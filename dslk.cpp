// danh sách liên kết đơn 
typedef int item; //kieu cac phan tu dinh nghia la item
typedef struct Node //Xay dung mot Node trong danh sach
{
    item Data; //Du lieu co kieu item
    Node *next; //Truong next la con tro, tro den 1 Node tiep theo
};
typedef Node *List; //List la mot danh sach cac Node
//Khởi tạo danh sách rỗng
void Init (List &L) // &L lay dia chi cua danh sach ngay khi truyen vao ham
{
    L=NULL; //Cho L tro den NULL
}
//Kiểm tra danh sách rỗng hay không
int Isempty (List L)
{
    return (L==NULL);
}
//Tính độ dài danh sách
int len (List L) 
{
    Node *P=L; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        i++; //tang bien dem
        P=P->next; //cho P tro den Node tiep theo
    }
    return i; //tra lai so Node cua l
}
//Tạo 1 Node trong danh sách
Node *Make_Node (Node *P, item x) //tao 1 Node P chua thong tin la x 
{
    P = (Node *) malloc (sizeof (Node)); //Cap phat vung nho cho P
    P->next = NULL; //Cho truong Next tro den NULL
    P->Data = x; //Ghi du lieu vao Data
    return P; 
}
//Chèn Node P vào vị trí đầu tiên
void Insert_first (List &L, item x)  //Chen x vao vi tri dau tien trong danh sach
{
    Node *P; 
    P = Make_Node(P,x); //tao 1 Node P
    P->next = L; //Cho P tro den L
    L = P; //L tro ve P
}
//Chèn Node P vào vị trí k trong danh sách
void Insert_k (List &L, item x, int k) //chen x vao vi tri k trong danh sach
{
    Node *P, *Q = L; 
    int i=1;
    if (k<1 || k> len(L)+1) printf("Vi tri chen khong hop le !"); //kiem tra dieu kien
    else
    {
        P = Make_Node(P,x); //tao 1 Node P
        if (k == 1) Insert_first(L,x); //chen vao vi tri dau tien
        else //chen vao k != 1
        {
            while (Q != NULL && i != k-1) //duyet den vi tri k-1
            {
                i++;
                Q = Q->next;
            }
            P->next = Q->next; 
            Q->next = P;
        }
    }
}
//Tìm phần tử co giá trị x trong danh sách
int Search (List L, item x) //tim x trong danh sach
{
    Node *P=L; 
    int i=1;
    while (P != NULL && P->Data != x) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    if (P != NULL) return i; //tra ve vi tri tim thay
    else return 0; //khong tim thay
}
//Xóa phần tử ở vị trí đầu tiên
void Del_frist (List &L, item &x) //Xoa phan tu dau tien
{
    x = L->Data; //lay gia tri ra neu can dung
    L = L->next; //Cho L tro den Node thu 2 trong danh sach
}
//Xóa phần tư ở vị trí k
void Del_k (List &L, item &x, int k) //Xoa Node k trong danh sach
{
    Node *P=L;
    int i=1;
    if (k<1 || k>len(L)) printf("Vi tri xoa khong hop le !"); //kiem tra dieu kien
    else
    {
        if (k==1) Del_frist(L,x); //xoa vi tri dau tien
        else //xoa vi tri k != 1
        {
            while (P != NULL && i != k-1) //duyet den vi tri k-1
            {
                P=P->next;
                i++;
            }
            P->next = P->next->next; //cho P tro sang Node ke tiep vi tri k
        }
    }
}
//del_x 
void Del_x (List &L, item x) //xoa phan tu x trong danh sach
{
    while (Search(L,x)) Del_k (L,x,Search(L,x)); //trong khi van tim thay x thi van xoa
}
//input out put
void Input (List &L) //nhap danh sach
{
    int i=0; 
    item x;
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Insert_k(L,x,len(L)+1);
    } while(x != 0); //nhap 0 de ket thuc
}
 
void Output (List L) //xuat danh sach
{
    Node *P=L;
    while (P != NULL)
    {
        printf("%5d",P->Data);
        P = P->next;
    }
    printf("\n");
}


int main()
{
    List L;
    Init(L);
    Input(L);
    Output(L);
 
    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra DS rong");
    printf("\n2: Do dai DS");
    printf("\n3: Chen phan tu x vao vi tri k trong DS");
    printf("\n4: Tim mot phan tu trong DS");
    printf("\n5: Xoa phan tu tai vi tri k");
    printf("\n6: XOa phan tu x trong DS");
    printf("\n7: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
    switch (lua_chon)
    {
        case 1:
        {
            if (Isempty(L)) printf("DS rong !");
            else printf ("DS khong rong !");
            break;
        }
        case 2: printf ("Do dai DS la: %d.",len(L));break;
        case 3:
        {
            item x;
            int k;
            printf ("Nhap phan tu can chen vao DS: ");
            scanf("%d",&x);
            printf ("Nhap vi tri can chen: ");
            scanf ("%d",&k);
            Insert_k (L,x,k);
            printf ("DS sau khi chen:\n");
            Output(L);
            break;
        }
        case 4:
        {
            item x;
            printf ("Moi ban nhap vao phan tu can tim: ");
            scanf("%d",&x);
            int k=Search(L,x);
            if (k) printf ("Tim thay %d trong DS tai vi tri thu: %d",x,k);
            else printf ("Khong tim thay %d trong danh sach !",x);
            break;
        }
        case 5:
        {
            int k;
            item x;
            printf ("Nhap vi tri can xoa: ");
            scanf ("%d",&k);
            Del_k (L,x,k);
            printf ("DS sau khi xoa:\n");
            Output(L);
            break;
        }
        case 6:
        {
            item x;
            printf ("Nhap phan tu can xoa: ");
            scanf ("%d",&x);
            Del_x (L,x);
            printf ("DS sau khi xoa:\n");
            Output(L);
            break;
        }
        case 7: break;
    }
    }while (lua_chon !=7);
    return 0;
}