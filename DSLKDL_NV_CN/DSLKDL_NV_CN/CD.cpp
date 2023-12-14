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

void nhapDSCN(NodeptrCN& list, char* ma)
{
	CanNha x;
	x.maCheck = ma;
	do {
		cout << "Nhap ma can nha (nhan Enter de thoat): ";
		cin.getline(x.maNha, 10);
		while (kiemTraTrungMaCN(list, x.maNha))
		{
			cout << "Ma nha bi trung!" << endl;
			cout << "Moi nhap lai ma can nha: ";
			cin.getline(x.maNha, 10);
		}
		if (strcmp(x.maNha, "") == 0)
			break;
		cout << "Nhap dien tich can nha: ";
		cin >> x.dienTich;
		cout << "Nhap don gia can nha: ";
		cin >> x.donGia;
		cout << "Nhap dia chi nha: ";
		cin.ignore();
		cin.getline(x.diaChi, 50);
		themDauCN(list, x);
	} while (true);
}

void nhapDSNV(NodeptrNV& list, NodeptrCN& dscn)
{
	NhanVien x;
	int count = 0;
	do {
		cout << "Nhap ma nhan vien (nhan Enter de thoat): ";
		cin.getline(x.maNV, 10);
		while (kiemTraTrungMaNV(list, x.maNV))
		{
			cout << "Ma nhan vien bi trung!" << endl;
			cout << "Moi nhap lai ma nhan vien: ";
			cin.getline(x.maNV, 10);
		}
		if (strcmp(x.maNV, "") == 0)
			break;
		cout << "Nhap ten nhan vien: ";
		cin.getline(x.tenNV, 30);
		cout << "Nhap dia chi nhan vien: ";
		cin.getline(x.diaChiNV, 50);
		themDauNV(list, x);
		count++;
	} while (true);
	NodeptrNV p = list;
	for (int i = 1; i <= count; i++)
	{
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');
		cout << "Nhap danh sach can nha cua nhan vien " << p->dataNV.maNV <<" phu trach : "<< endl;
		cout << setfill('-');
		cout << setw(60) << "-" << endl;
		cout << setfill(' ');
		nhapDSCN(dscn, p->dataNV.maNV);
		p = p->nextNV;
	}
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
	if (vt == 1)
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
		dem++;
		if (dem == (vt - 1))
			break;
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

void xuatDSCN(NodeptrCN list, char* ma)
{
	cout << setw(20) << left << list->dataCN.maNha << "|";
	cout << setw(20) << left << list->dataCN.dienTich << "|";
	cout << setw(15) << left << list->dataCN.donGia << "|";
	cout << setw(20) << left << list->dataCN.diaChi << endl;
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
  
NodeptrCN timDienTich(NodeptrCN& list)
{
	double dt;
	cout << "Nhap dien tich can nha muon tim kiem: ";
	cin >> dt;
  NodeptrCN p = list;
	NodeptrCN q = NULL;
	while (p != NULL)
	{
    if (p->dataCN.dienTich == dt)
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
