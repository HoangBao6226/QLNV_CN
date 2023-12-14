#include "TV.h"
void main()
{
	NodeptrCN dscn;
	NodeptrNV dsnv;
	xuatDSNV(dsnv, dscn);
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
			xuatDSNV(dsnv, dscn);
            break;
        }
        case 2:
        {
			xuatDSNV(dsnv, dscn);
            break;
        }
        case 3:
        { 
			xuatDSNV(dsnv, dscn);
            break;
        }
        case 4:
        {
			xuatDSNV(dsnv, dscn);
            break;
        }
        case 5:
        {
			xuatDSNV(dsnv, dscn);
            break;
        }
        case 6:
        {
			xuatDSNV(dsnv, dscn);
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
		xuatDSNV(dsnv, dscn);
    } while (menu != 0);
}