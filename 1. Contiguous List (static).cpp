/*
线性表的基本操作：
InitList(&L)            //初始化表
DestroyList(&L)         //销毁链表
ListInsert(&L, i, e)    //插入操作
ListDelete(&L, i, &e)   //删除操作
LocateElem(L, e)        //按值查找操作
GetElem(L, i)           //按位查找操作
Length(L)               //求表长
PrintList(L)            //输出操作
Empty(L)                //判空操作
*/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int ElemType;

#define MaxSize 50                      //定义线性表的最大长度
typedef struct {
    int data[MaxSize];                  //顺序表的元素
    int length;                         //顺序表的当前长度
} SqList;                               //顺序表的类型定义

void Interface() {
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*exit---------------------------------0*" << endl;
    cout << "*insert-------------------------------1*" << endl;
    cout << "*delete-------------------------------2*" << endl;
    cout << "*locate-------------------------------3*" << endl;
    cout << "*get----------------------------------4*" << endl;
    cout << "*length-------------------------------5*" << endl;
    cout << "*print--------------------------------6*" << endl;
    cout << "*empty--------------------------------7*" << endl;
    cout << "*interface----------------------------8*" << endl;
    cout << "****************************************" << endl;
    cout << "Tips: The maximum length of the contiguous list is 50." << endl;
}

void InitList(SqList &L) {
    for(int i = 0 ; i < L.length; i++)
        L.data[i] = 0;
    L.length = 0;
}

bool ListInsert(SqList &L, int i, ElemType e) {
    if(i < 1 || i > L.length + 1)       //判断 i 的范围是否有效
        return false;
    if(L.length >= MaxSize)             //当前存储空间已满，不能插入
        return false;
    for(int j = L.length; j >= i; j--)  //将第 i 个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;                  //在位置 i 处放入 e
    L.length++;                         //线性表长度加 1
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if(i < 1 || i > L.length)           //判断 i 的范围是否有效
        return false;
    e = L.data[i - 1];                  //将被删除的元素赋给 e
    for(int j = i; j < L.length; j++)   //将第 i 个位置后的元素前移
        L.data[j - 1] = L.data[j];      //线性表长度减 1
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e) {
    for(int i = 0; i < L.length; i++)
        if(L.data[i] == e)
            return i + 1;               //下标为 i 的元素等于 e，返回其位序 i + 1
    return 0;                           //退出循环，说明查找失败
}

ElemType GetElem(SqList L, int i) {
    if(i < 1 || i > L.length)           //判断 i 的范围是否有效
        return 0;
    return L.data[i - 1];               //返回对应位置的值
}

int Length(SqList L) {
    return L.length;                    //返回表长
}

bool Empty(SqList L) {
    if(!L.length)
        cout << "The contiguous list is empty" << endl;
    return !L.length;   //当前长度为 0 时，返回表空
}

void PrintList(SqList L) {
    if(Empty(L));
    for(int i = 0; i < L.length; i++){
        if(i)
            cout << " " << L.data[i];
        else
            cout << L.data[i];
    } 
}

void PrintSeparator() {
    cout << "----------------------------------------" << endl;
}

void operate(SqList &L) {
    int index, location;
    ElemType element, e = -1;
    while(true) {
        cout << endl << "Enter the operation numbers from 0 to 8" << endl;
        cin >> index;
        switch(index) {
            case 0 :
                cout << "Bye!" << endl;
                system("pause");
                return;
                break;
            case 1 :
                cout << "Input location" << endl;
                cin >> location;
                cout << "Input element" << endl;
                cin >> element;
                ListInsert(L, location, element) ? cout << "Insert succeeded" << endl : cout << "Incorrect input! The correct range is 1 to " << Length(L) + 1 << endl;
                PrintSeparator();
                break;
            case 2 :
                cout << "Input location" << endl;
                cin >> location;
                if(ListDelete(L, location, e))
                    cout << "The element being deleted is " << e << endl;
                else
                    cout << "Delete failed" << endl;
                PrintSeparator();
                break;
            case 3 :
                cout << "Enter the element you want to find" << endl;
                cin >> element;
                LocateElem(L, element) == 0 ? cout << "Not found" << endl : cout << "The location of the element to be found is " << LocateElem(L, element) << endl;
                PrintSeparator();
                break;
            case 4 :
                cout << "Enter the location you want to find" << endl;
                cin >> location;
                if(!GetElem(L, location)) {
                    if(Empty(L));
                    else
                        cout << "Incorrect input! The correct range is 1 to " << Length(L) << endl;
                }
                else
                    cout << "The element is " << GetElem(L, location) << endl;
                PrintSeparator();
                break;
            case 5 :
                cout << "The length of contiguous list is " << Length(L) << endl;
                PrintSeparator();
                break;
            case 6 :
                if(!Empty(L)) {
                    cout << endl << "The elements in the current contiguous list" << endl;
                    PrintList(L);
                    cout << endl;
                }
                PrintSeparator();
                break;
            case 7 :
                if(!Empty(L))
                    cout << "The contiguous list is not empty" << endl;
                PrintSeparator();
                break;
            case 8 :
                Interface();
                break;
            default:
                cout << "Invalid operation" << endl;
                PrintSeparator();
                break;
        }
    }
}

int main() {
    SqList L;
    InitList(L);
    Interface();
    operate(L);
    return 0;
}