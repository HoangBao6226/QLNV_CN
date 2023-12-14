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

NodeptrNV xoaMaNV(NodeptrNV& list, NodeptrCN& dscn)
{
	cout << setfill(' ') << setw(0);
	NodeptrNV p = list;
	NodeptrNV prev = NULL;
	NodeptrCN q = dscn;
	char ma[10];
	cin.ignore();
	cout << "Nhap ma nhan vien muon xoa: ";
	cin.getline(ma, 10);
	while (p != NULL)
	{
		if (strcmp(p->dataNV.maNV, ma) == 0)
		{
			while (q != NULL)
			{
				if(q->dataCN.maCheck == p->dataNV.maNV && p->nextNV != NULL)
					q->dataCN.maCheck = p->nextNV->dataNV.maNV;
				else if(q->dataCN.maCheck == p->dataNV.maNV && p->nextNV == NULL)
					q->dataCN.maCheck = prev->dataNV.maNV;
				q = q->nextCN;
			}
			if (prev == NULL) {
				prev = list;
				list = list->nextNV;
				delete prev;
				break;
			}
			prev->nextNV = p->nextNV;
			delete p;
			break;
		}
		prev = p;
		p = p->nextNV;
	}
	return list;
}