#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

typedef struct NodeCN* NodeptrCN;
struct CanNha {
	char maNha[10];
	double dienTich;
	double donGia;
	char diaChi[50];
	char* maCheck;
};

struct NodeCN {
	CanNha dataCN;
	NodeptrCN nextCN;
};

typedef struct NodeNV* NodeptrNV;
struct NhanVien {
	char maNV[10];
	char tenNV[30];
	char diaChiNV[50];
	NodeCN dscn;
};

struct NodeNV {
	NhanVien dataNV;
	NodeptrNV nextNV;
};

void khoiTaoCN(NodeptrCN& list);
void khoiTaoNV(NodeptrNV& list);
int isEmptyCN(NodeptrCN list);
int isEmptyVN(NodeptrNV list);
void giaiPhongCN(NodeptrCN& list);
void giaiPhongNV(NodeptrNV& list);
NodeptrCN taoNodeCN(CanNha x);;
NodeptrNV taoNodeNV(NhanVien x);
NodeptrCN themDauCN(NodeptrCN& list, CanNha x);
NodeptrNV themDauNV(NodeptrNV& list, NhanVien x);
bool kiemTraTrungMaCN(NodeptrCN& list, char* ma);
bool kiemTraTrungMaNV(NodeptrNV& list, char* ma);
NodeptrCN timDienTich(NodeptrCN& list);