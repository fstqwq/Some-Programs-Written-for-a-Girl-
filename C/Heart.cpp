//First written on Dec 8th, 2018, the day after I met her.
//Reproduced and optimized on Jan 16th, 2019.
#include<bits/stdc++.h>
#define N 120
using namespace std;

const double differential=5e-4;//��dx,dy,dz����0.0005
const double unit=0.025;
const double origin=-1.5;//��(-1.5,-1.5)Ϊ��ԭ�㡱

int n,r,c,i,j,len,f[N][N/2];

inline double sqr(const double &x){return x*x;}//x^2
inline double cube(const double &x){return x*x*x;}//x^3
inline double F(double x,double y,double z){return cube(x*x+y*y*9.0/4+z*z-1)-x*x*cube(z)-y*y*cube(z)*9.0/80;}//F(x,y,z)<=0�Ĳ����γ�������

inline double surfaceY(double x,double z){//�ҵ�(x,z)������ƽ���϶�Ӧ��y>0�����꣬��û���򷵻�0
    double y;
    for (y=1; y>0; y-=differential)
        if (F(x,y,z)<=0) return y;
    return 0;
}
int main()
{
    //freopen("heart.txt","w",stdout);

    for (i=0; i<N; i++)
        for (j=0; j<N/2; j++){
            double x=origin + i*unit , z=origin + j*unit*2;
            double y=surfaceY(x,z);
            if (y==0) {f[i][j]=-1; continue;}

            double gy=1e-2;//���ڹ�����ƽ����xOzƽ��ģ����������������y��û�����塣������Ҫһ��gy����������
            double gx=surfaceY(x+gy,z) - y;
            double gz=surfaceY(x,z+gy) - y;
            double dist=1/sqrt(sqr(gx) + sqr(gy) + sqr(gz));
            f[i][j]=2.4*(gx-gz + gy)*dist+2.4;//���������xOzƽ���ϵ�ͶӰ��б����-1,��z=-x+C

            if (x>=1.1) f[i][j]=1;//����finite difference���㷨�������Ҳഹֱ�����̫���������֮
        }
    for (j=N/2-1; j>=0; j--){
        for (i=0; i<N; i++)
            putchar(" .:-=+*#%"[f[i][j]+1]);
        cout<<endl;
    }
    system("pause");
	return 0;
}
