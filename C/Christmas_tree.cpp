//First written on Dec 24th for a friend of mine.
//But when I start writing this program, I realized that I was writing it for myself.
//Then four days later I chose to escape her again....
#include<bits/stdc++.h>
#define N 128
const double unit=2.0/128.0;
using namespace std;

int n,i,f[N][N];
struct coord{double x,y;};
coord mid(const coord &a,const coord &b){ return {(a.x+b.x)/2.0,(a.y+b.y)/2.0}; }//返回线段AB的中点
bool up(coord a,coord b,coord test)//判断点test是否在直线AB上方
{
	return test.y>(a.y-b.y)/(a.x-b.x)*(test.x-a.x)+a.y;
}

void fill(int x,coord a,coord b,coord peak)//向三角形ABP填充数字x
{
	int i,j;
	if (peak.y<a.y){
		for (i=0; i<N; i++)
			for (j=0; j<N; j++)
				if (up(a,peak,{unit*i-1,unit*j-1})&&up(b,peak,{unit*i-1,unit*j-1})&&unit*j-1<a.y) f[i][j]=x;
	}
	else{
		for (i=0; i<N; i++)
			for (j=0; j<N; j++)
				if (!up(a,peak,{unit*i-1,unit*j-1})&&!up(b,peak,{unit*i-1,unit*j-1})&&unit*j-1>a.y) f[i][j]=x;
	}
}
void dfs(int depth,int num,coord a,coord b,coord peak,bool upper_tri)//使用迭代的方法构造 谢宾斯基三角形(Sierpinski triangle)
{
	fill(num,a,b,peak);
	if (depth==5) return;

	coord ap=mid(a,peak),bp=mid(b,peak),ab=mid(a,b);
	if (upper_tri)
	{
		dfs(depth+1,num+1,ap,bp,ab,false);
		dfs(depth+1,num,ap,bp,peak,true);
		dfs(depth+1,num,a,ab,ap,true);
		dfs(depth+1,num,ab,b,bp,true);
	}
	else{
		dfs(depth+1,num,ap,bp,ab,true);
		dfs(depth+1,num+1,a,ab,ap,false);
		dfs(depth+1,num+1,ab,b,bp,false);
		dfs(depth+1,num+1,ap,bp,peak,false);
	}
}
int main()
{
	dfs(1,1,{-0.5,-sqrt(3)/6.0},{0.5,-sqrt(3)/6.0},{0,sqrt(1.0/3.0)},true);
	//freopen("tree.txt","w",stdout);
	int i,j;
	for (j=100; j>=88; j--){
		for (i=0; i<N; i++) putchar(" .:i*:"[f[i][j]]);
		putchar('\n');
	}
	for (j=94; j>=79; j--){
		for (i=0; i<N; i++) putchar(" .i+:u"[f[i][j]]);
		putchar('\n');
	}
	for (j=88; j>=47; j--){
		for (i=0; i<N; i++) putchar(" .io*:"[f[i][j]]);
		putchar('\n');
	}
	for (j=10; j; j--){
		for (i=0; i<N/2-3; i++) putchar(' ');
		for (i=N/2-3; i<=N/2+3; i++) putchar('#');
		putchar('\n');
	}
	puts("Merry Christmas, Wang Shuo.");
	system("pause");
}
