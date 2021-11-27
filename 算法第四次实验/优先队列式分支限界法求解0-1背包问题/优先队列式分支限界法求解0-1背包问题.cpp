#include <bits/stdc++.h>
using namespace std;
class Object
{
public:
    int id;                              //第几号物品 
    int weight;                          //该物品的重量 
    int price;                           //该物品的价值 
    float d;                             //计算单位重量价值 
};
class MaxHeapQNode
{
public:
    MaxHeapQNode *parent;
    int lchild;                           //是否为左子节点 
    int upprofit;                         //优先级 
    int profit;                           //价值 
    int weight;                           //重量 
    int lev;                              //第几层 
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
	cout<<"背包容量:"<<c<<endl;
	file1<<"背包容量:"<<c<<endl;
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
int Bound(int i)                      //计算出优先级，当前价值加上背包剩余容量与剩下最大单位重量价值的乘积 
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
    MaxHeapQNode *p = new MaxHeapQNode;                        //将节点加入到最大值堆中更新节点信息 
    p->parent = E;
    p->lchild = ch;
    p->weight = wt;
    p->upprofit = up;
    p->profit = curp;
    p->lev = i + 1;
    q.push(p);
//    cout << "加入点的信息为 " << endl;
//    cout << "p->lev = " << p->lev << " p->upprofit = " << p->upprofit << " p->weight =  " << p->weight << " p->profit =  " << p->profit << endl;
}
void MaxKnapsack()
{
    priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp > q; // 大顶堆     存储各节点信息包括优先级并依据优先级排列找到下一个处理的点 
    MaxHeapQNode *E = NULL;                                            //E存储的是子集树 
    cw = cp = bestp = 0;
    int i = 1;
    int up = Bound(1); //Bound(i)函数计算的是i还未处理时候的上限值
    while(i != n + 1)
    {
        int wt = cw + obj[i].weight;
        if(wt <= c)
        {
            if(bestp < cp + obj[i].price)
                bestp = cp + obj[i].price;
            AddAliveNode(q, E, up, cw + obj[i].weight, cp + obj[i].price, i, 1);
        }
        up = Bound(i + 1); //注意这里 up != up - obj[i].price而且 up >= up - obj[i].price
        if(up >= bestp) //注意这里必须是大于等于
        {
            AddAliveNode(q, E, up, cw, cp, i, 0);
        }
        E = q.top();
        q.pop();                           //  处理下一个要处理的节点 
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
	file1<<"最优装入量为"<<bestp<<endl; 
    printf("最优装入量为 %d\n", bestp);
    file1<<"装入的物品为"<<endl;
    printf("装入的物品为 \n");
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
	cout<<"请选择数据规模"<<endl;
	cout<<"10"<<" "<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	int d;
	cin>>d;
	start=clock();
    InPut(d);
    MaxKnapsack();
    OutPut(d);
    finish=clock();
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
		
	}
	
}

