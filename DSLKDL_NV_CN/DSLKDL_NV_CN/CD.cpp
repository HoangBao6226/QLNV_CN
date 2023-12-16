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

NodeptrNV xoaTenNV(NodeptrNV& list, NodeptrCN& dscn)
{
	char ten[30];
	cout << "Nhap ten nhan vien muon xoa: ";
	cin.ignore();
	cin.getline(ten, 30);
	NodeptrNV prev = NULL;
	NodeptrNV p = list;
	NodeptrCN a = dscn;
	while (p != NULL)
	{
		if (strcmp(p->dataNV.tenNV, ten) == 0)
		{
			while (a != NULL)
			{
				if (a->dataCN.maCheck == p->dataNV.maNV && p->nextNV != NULL)
					a->dataCN.maCheck = p->nextNV->dataNV.maNV;
				else if (a->dataCN.maCheck == p->dataNV.maNV && p->nextNV == NULL)
					a->dataCN.maCheck = prev->dataNV.maNV;
				a = a->nextCN;
			}
			a = dscn;
			NodeptrNV q = p;
			if (p == list)
			{
				list = list->nextNV;
				p = list;
				prev = list;
			}
			else
			{
				prev->nextNV = p->nextNV;
				p = p->nextNV;
			}
			delete	q;
			continue;
		}
		prev = p;
		p = p->nextNV;
	}
	return list;
}