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

NodeptrCN timDonGia(NodeptrCN& list)
{
	double dg;
	cout << "Nhap don gia can nha muon tim kiem: ";
	cin >> dg;
	NodeptrCN p = list;
	NodeptrCN q = NULL;
	while (p != NULL)
	{
		if (p->dataCN.donGia == dg)
		{
			if (q == NULL)
				q = taoNodeCN(p->dataCN);
			else
			{
				themDauCN(q, p->dataCN);
			}
		}
		p = p->nextCN;
	}
	return q;
}

NodeptrNV timNha_DT_DG_MaNhanVien(NodeptrNV& list)
{
	NhanVien x;
	cout << "Nhap ma nhan vien muon tim kiem: ";
	cin.ignore();
	cin.getline(x.maNV, 10);
	NodeptrNV p = list;
	NodeptrNV q = NULL;
	while (p != NULL)
	{
		if (strcmp(p->dataNV.maNV, x.maNV) == 0)
		{
			if (q == NULL)
				q = taoNodeNV(p->dataNV);
			else
			{
				themDauNV(q, p->dataNV);
      }
      p = p->nextNV;
	}
  retunr q;
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

NodeptrNV xoaTenNV(NodeptrNV& list, NodeptrCN& dscn)
{
	cout << setfill(' ') << setw(0);
	NodeptrNV p = list;
	NodeptrNV prev = NULL;
	NodeptrCN q = dscn;
	char ten[30];
	cout << "Nhap ten nhan vien muon xoa: ";
  cin.ignore();
	cin.getline(ten, 30);
	while (p != NULL)
	{
		if (strcmp(p->dataNV.tenNV, ten) == 0)
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

NodeptrNV xoaNha_MaNha_MaNV(NodeptrNV& list, NodeptrCN& dscn)
{
	//cout << setfill(' ') << setw(0);
	NodeptrNV p = list;
	NodeptrCN prev = NULL;
	NodeptrCN q = dscn;
	char manv[10];
	cin.ignore();
	cout << "Nhap ma nhan vien: ";
	cin.getline(manv, 10);
	char macn[10];
	cout << "Nhap ma nha muon xoa: ";
	cin.getline(macn, 10);
	while (p != NULL)
	{
		if (strcmp(p->dataNV.maNV, manv) == 0)
		{
			while (q != NULL)
			{
				if (strcmp(q->dataCN.maNha, macn) == 0)
				{
					if (prev == NULL) {
						prev = dscn;
						dscn = dscn->nextCN;
						delete prev;
						break;
					}
					prev->nextCN = q->nextCN;
					delete q;
					break;
				}
				prev = q;
				q = q->nextCN;
			}
		}
		p = p->nextNV;
	}
	return list;
}