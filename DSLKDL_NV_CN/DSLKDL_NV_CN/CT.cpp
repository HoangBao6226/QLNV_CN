#include "TV.h"
void main()
{
	NodeptrCN dscn;
	NodeptrNV dsnv;
    int menu;
    do
    {
        cout << endl;
        cout << ("1/ Them thong tin 1 nhan vien vao vi tri chi dinh.") << endl;
        cout << ("2/ Tim cac can nha theo dien tich cua 1 nhan vien phu trach.") << endl;
        cout << ("3/ Tim cac can nha theo don gia cua 1 nhan vien phu trach.") << endl;
        cout << ("4/ Xoa cac nhan vien theo ma.") << endl;
        cout << ("5/ Xoa cac nhan vien theo ten.") << endl;
        cout << ("6/ Xoa can nha theo ma nha.") << endl;
        cout << ("0/ Thoat chuong trinh!!!") << endl;
        cout << ("Nhap lua chon cua ban: ");
        cin >> menu;
        switch (menu)
        {
        case 0:
            return;
        case 1:
        {      
			dsnv = themViTri(dsnv, dscn);
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        { 
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        default:
        {
            cout << ("Chuc nang khong ton tai! Moi nhap lai!");
            break;
        }
        }
        system("pause");
        system("cls");
    } while (menu != 0);
}