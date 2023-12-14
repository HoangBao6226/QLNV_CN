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

void xuatDSNV(NodeptrNV list, NodeptrCN dscn)
{
	if (list == NULL)
	{
		cout << "Danh sach nhan vien rong!" << endl;
		return;
	}
	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	cout << setfill(' ');
	cout << setw(5) << left << "STT" << "|";
	cout << setw(20) << left << "Ma nhan vien" << "|";
	cout << setw(20) << left << "Ten nhan vien" << "|";
	cout << setw(25) << left << "Dia chi nhan vien" << "|";
	cout << "Danh sach cac can nha nhan vien nay phu trach:" << endl;
	cout << setfill('*');
	cout << setw(170) << "*" << endl;
	cout << setfill(' ');
	int count = 1;
	while (list != NULL)
	{
		int count2 = 1;
		cout << setw(5) << left << count++ << "|";
		cout << setw(20) << left << list->dataNV.maNV << "|";
		cout << setw(20) << left << list->dataNV.tenNV << "|";
		cout << setw(25) << left << list->dataNV.diaChiNV << "|";
		NodeptrCN p = dscn;
		bool flag = false;
		while (p != NULL)
		{
			if (strcmp(list->dataNV.maNV, p->dataCN.maCheck) == 0)
			{
				if (!flag)
				{
					cout << setw(10) << left << "STT" << "|";
					cout << setw(20) << left << "Ma can nha" << "|";
					cout << setw(20) << left << "Dien tich" << "|";
					cout << setw(15) << left << "Don gia" << "|";
					cout << setw(20) << left << "Dia chi" << endl;
					flag = true;
				}
				if (flag)
				{
					cout << setw(73) << " " << "|";
					cout << setw(10) << left << count2++ << "|";
					xuatDSCN(p, list->dataNV.maNV);
					if (count2 > 1)
					{
						cout << setfill(' ') << setw(70);
					}
				}
			}
			p = p->nextCN;
		}
		if (!flag)
			cout << setw(10) << "Nhan vien nay khong phu trach can nha nao!" << endl;
		list = list->nextNV;
	}
}