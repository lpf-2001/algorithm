#include <bits/stdc++.h>
using namespace std;
class Object
{
public:
    int id;                              //�ڼ�����Ʒ 
    int weight;                          //����Ʒ������ 
    int price;                           //����Ʒ�ļ�ֵ 
    float d;                             //���㵥λ������ֵ 
};
class MaxHeapQNode
{
public:
    MaxHeapQNode *parent;
    int lchild;                           //�Ƿ�Ϊ���ӽڵ� 
    int upprofit;                         //���ȼ� 
    int profit;                           //��ֵ 
    int weight;                           //���� 
    int lev;                              //�ڼ��� 
};
struct cmp
{
    bool operator()(MaxHeapQNode *&a, MaxHeapQNode *&b) const
    {
        return a->upprofit < b->upprofit;
    }
};
bool compare(const Object &a, const Object &b)
{
    return a.d >= b.d;
}
int n;
int c;
int cw;
int cp;
int bestp;
Object obj[100000];
int bestx[100000];
void InPut(int d)
{
	ifstream file;
	ofstream file1; 
	if(d==10)
	{
		file.open("10.txt");
		file1.open("10out.txt");
	} 
	else if(d==100)
	{
		file.open("100.txt");
		file1.open("100out.txt");
	} 
	else if(d==1000)
	{
		file.open("1000.txt");
		file1.open("1000out.txt");
	} 
	else if(d==10000)
	{
		file.open("10000.txt");
		file1.open("10000out.txt");
	}
	else if(d==10000)
	{
		file.open("10000.txt");
		file1.open("10000out.txt");
	}
	n=d;
	srand(time(NULL));
	c=rand()%1000;
	cout<<"��������:"<<c<<endl;
	file1<<"��������:"<<c<<endl;
    for(int i = 1; i <= n; ++i)
    {
    	file>>obj[i].weight>>obj[i].price;
    	cout<<obj[i].weight<<" "<<obj[i].price<<endl;
     obj[i].id = i;
     obj[i].d = 1.0 * obj[i].price / obj[i].weight;
    }
 
    sort(obj + 1, obj + n + 1, compare);
//    for(int i = 1; i <= n; ++i)
//        cout << obj[i].d << " ";
//    cout << endl << "InPut Complete" << endl;
}
int Bound(int i)                      //��������ȼ�����ǰ��ֵ���ϱ���ʣ��������ʣ�����λ������ֵ�ĳ˻� 
{
    int tmp_cleft = c - cw;
    int tmp_cp = cp;
    while(tmp_cleft >= obj[i].weight && i <= n)
    {
        tmp_cleft -= obj[i].weight;
        tmp_cp += obj[i].price;
        i++;
    }
    if(i <= n)
    {
        tmp_cp += tmp_cleft * obj[i].d;
    }
    return tmp_cp;
}
void AddAliveNode(priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp> &q, MaxHeapQNode *E, int up, int wt, int curp, int i, int ch)
{
    MaxHeapQNode *p = new MaxHeapQNode;                        //���ڵ���뵽���ֵ���и��½ڵ���Ϣ 
    p->parent = E;
    p->lchild = ch;
    p->weight = wt;
    p->upprofit = up;
    p->profit = curp;
    p->lev = i + 1;
    q.push(p);
//    cout << "��������ϢΪ " << endl;
//    cout << "p->lev = " << p->lev << " p->upprofit = " << p->upprofit << " p->weight =  " << p->weight << " p->profit =  " << p->profit << endl;
}
void MaxKnapsack()
{
    priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp > q; // �󶥶�     �洢���ڵ���Ϣ�������ȼ����������ȼ������ҵ���һ������ĵ� 
    MaxHeapQNode *E = NULL;                                            //E�洢�����Ӽ��� 
    cw = cp = bestp = 0;
    int i = 1;
    int up = Bound(1); //Bound(i)�����������i��δ����ʱ�������ֵ
    while(i != n + 1)
    {
        int wt = cw + obj[i].weight;
        if(wt <= c)
        {
            if(bestp < cp + obj[i].price)
                bestp = cp + obj[i].price;
            AddAliveNode(q, E, up, cw + obj[i].weight, cp + obj[i].price, i, 1);
        }
        up = Bound(i + 1); //ע������ up != up - obj[i].price���� up >= up - obj[i].price
        if(up >= bestp) //ע����������Ǵ��ڵ���
        {
            AddAliveNode(q, E, up, cw, cp, i, 0);
        }
        E = q.top();
        q.pop();                           //  ������һ��Ҫ����Ľڵ� 
        cw = E->weight;
        cp = E->profit;
        up = E->upprofit;
        i = E->lev;
    }
    for(int j = n; j > 0; --j)                        
    {
        bestx[obj[E->lev - 1].id] = E->lchild;
        E = E->parent;
    }
}
void OutPut(int d)
{
	ifstream file;
	ofstream file1; 
	if(d==10)
	{
		file.open("10.txt");
		file1.open("10out.txt",ios::app);
	} 
	else if(d==100)
	{
		file.open("100.txt");
		file1.open("100out.txt",ios::app);
	} 
	else if(d==1000)
	{
		file.open("1000.txt");
		file1.open("1000out.txt",ios::app);
	}
	else if(d==10000)
	{
		file.open("10000.txt");
		file1.open("10000out.txt",ios::app);
	}
	else if(d==100000)
	{
		file.open("100000.txt");
		file1.open("100000out.txt",ios::app);
	}
	file1<<"����װ����Ϊ"<<bestp<<endl; 
    printf("����װ����Ϊ %d\n", bestp);
    file1<<"װ�����ƷΪ"<<endl;
    printf("װ�����ƷΪ \n");
    for(int i = 1; i <= n; ++i)
        if(bestx[i] == 1)
        {
        	printf("%d ", i);
        	file1<<i<<" ";
		}
          
}
int main()
{
	while(1)
	{
	clock_t start,finish;
	cout<<"��ѡ�����ݹ�ģ"<<endl;
	cout<<"10"<<" "<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	int d;
	cin>>d;
	start=clock();
    InPut(d);
    MaxKnapsack();
    OutPut(d);
    finish=clock();
	printf("�����%d���ݹ�ģ�����ʱ��Ϊ��%.2f ms\n",d,(double)(finish-start));
		
	}
	
}

