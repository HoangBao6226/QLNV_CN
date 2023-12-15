#include "TV.h"

void khoiTaoCN(NodeptrCN& list)
{
	list = NULL;
}

void khoiTaoNV(NodeptrNV& list)
{
	list = NULL;
}

int isEmptyCN(NodeptrCN list)
{
	return list == NULL ? 1 : 0;
}

int isEmptyVN(NodeptrNV list)
{
	return list == NULL ? 1 : 0;
}

void giaiPhongCN(NodeptrCN& list)
{
	NodeptrCN p = list;
	while (p != NULL)
	{
		list = list->nextCN;
		delete p;
		p = list;
	}
}

void giaiPhongNV(NodeptrNV& list)
{
	NodeptrNV p = list;
	while (p != NULL)
	{
		list = list->nextNV;
		delete p;
		p = list;
	}
}

NodeptrCN taoNodeCN(CanNha x)
{
	NodeptrCN p;
	p = new NodeCN;
	p->dataCN = x;
	p->nextCN = NULL;
	return p;
}

NodeptrNV taoNodeNV(NhanVien x)
{
	NodeptrNV p;
	p = new NodeNV;
	p->dataNV = x;
	p->nextNV = NULL;
	return p;
}

NodeptrCN themDauCN(NodeptrCN& list, CanNha x)
{
	NodeptrCN p = taoNodeCN(x);
	p->nextCN = list;
	list = p;
	return p;
}

NodeptrNV themDauNV(NodeptrNV& list, NhanVien x)
{
	NodeptrNV p = taoNodeNV(x);
	p->nextNV = list;
	list = p;
	return p;
}

bool kiemTraTrungMaCN(NodeptrCN& list, char* ma)
{
	NodeptrCN p = list;
	while (p != NULL)
	{
		if (strcmp(p->dataCN.maNha, ma) == 0)
			return true;
		p = p->nextCN;
	}
	return false;
}

bool kiemTraTrungMaNV(NodeptrNV& list, char* ma)
{
	NodeptrNV p = list;
	while (p != NULL)
	{
		if (strcmp(p->dataNV.maNV, ma) == 0)
			return true;
		p = p->nextNV;
	}
	return false;
}

NodeptrNV themViTri(NodeptrNV& list, NodeptrCN& dscn)
{
	cout << setfill(' ') << setw(0);
	int vt;
	cout << "Nhap vi tri muon chen them nhan vien: ";
	cin >> vt;
	int dem = 0;
	NhanVien x;
	NodeptrNV p = list;
	NodeptrNV a = new NodeNV;
	cout << "Nhap ma nhan vien: ";
	cin.ignore();
	cin.getline(x.maNV, 10);
	while (kiemTraTrungMaNV(list, x.maNV) || strcmp(x.maNV, "") == 0)
	{
		cout << "Ma nhan vien bi trung!" << endl;
		cout << "Moi nhap lai ma nhan vien: ";
		cin.getline(x.maNV, 10);
	}
	cout << "Nhap ten nhan vien: ";
	cin.getline(x.tenNV, 30);
	cout << "Nhap dia chi nhan vien: ";
	cin.getline(x.diaChiNV, 50);
	a = taoNodeNV(x);
	if (vt == 0)
	{
		a->nextNV = list;
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');
		cout << "Nhap danh sach can nha cua nhan vien " << a->dataNV.maNV << " phu trach : " << endl;
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');
		nhapDSCN(dscn, a->dataNV.maNV);
		return a;
	}
	while (p != NULL)
	{
		if (dem == (vt - 1))
			break;
		dem++;
		p = p->nextNV;
	}
	a->nextNV = p->nextNV;
	p->nextNV = a;
	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');
	cout << "Nhap danh sach can nha cua nhan vien " << a->dataNV.maNV << " phu trach : " << endl;
	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');
	nhapDSCN(dscn, a->dataNV.maNV);
	return list;
}