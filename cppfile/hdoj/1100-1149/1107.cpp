#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
 
struct node_t {
    int x, y;        // position
    int nl;            // 内力
    int wy;            // 武艺
    int hp;            // 生命
    bool hasFight;
    int d;        // direction: 0:up, down:1
    node_t() {}
    node_t(int xx, int yy, int nnl, int wwy, int hhp, bool h=false, int dd=0) {
        x = xx; y = yy; nl = nnl; wy = wwy;
        hp = hhp; hasFight=h; d = dd;
    }
} ;
 
int map[15][15];
vector<node_t> vnodes[3];    // 0:少林, 1:武当, 2:峨眉
int dir[3][2][2] = {
    { {1, 0}, {-1, 0} },
    { {0, 1}, {-1, 0} },
    { {1, 1}, {-1, -1} }
};
int nn[3];//用来保存每个门派的人数 
int t, n;
 
void init() {//初始化地图还有每个门派 
    memset(map, 0, sizeof(map));
    for (int i=0; i<3; ++i) {
        vnodes[i].clear();
        nn[i] = 0;
    }
}
 
inline bool check(int x, int y) {//如果一个函数很简单，而又要被多次调用，就可以声明为inline，内联函数，可以减少运行时间 
    return x>0 && x<13 && y>0 && y<13;
}
 
int getDPS(int i, int j) {
    double tmp;
    
    if (i == 0) {
        tmp = (0.5*vnodes[i][j].nl + 0.5*vnodes[i][j].wy) * (vnodes[i][j].hp + 10.) / 100.0;//少林派攻击力 
    } else if (i == 1) {
        tmp = (0.8*vnodes[i][j].nl + 0.2*vnodes[i][j].wy) * (vnodes[i][j].hp + 10.) / 100.0;//武当派攻击力 
    } else {
        tmp = (0.2*vnodes[i][j].nl + 0.8*vnodes[i][j].wy) * (vnodes[i][j].hp + 10.) / 100.0;//峨眉派攻击力 
    }
    
    return (int) tmp;
}
 
void fight() {
    int dps0, dps1;//比武的两个人 
    int i, j, k, p;
    int ii, jj, kk;
    int x, y;
    
    for (i=0; i<3; ++i) {
        for (j=0; j<nn[i]; ++j) {
            if (vnodes[i][j].hp>0 && map[vnodes[i][j].x][vnodes[i][j].y]==2 && !vnodes[i][j].hasFight) {
                x = vnodes[i][j].x;
                y = vnodes[i][j].y;
                vnodes[i][j].hasFight = true;//把遍历到的其中一人设为已经打架了 
                for (ii=0; ii<3; ++ii) {//当一个格子里有两个人，如果是同派的就不打架 
                    if (ii == i)
                        continue;
                    for (jj=0; jj<nn[ii]; ++jj) {//如果不是同派的就遍历这个派的所有人，直到找到那个可以打架的格子，把另一个人的打架标示标志为true，表示他们已经打过了，不用再打了 
                        if (vnodes[ii][jj].hp>0 && vnodes[ii][jj].x==x && vnodes[ii][jj].y==y) {
                            dps0 = getDPS(i, j);
                            dps1 = getDPS(ii, jj);
                            vnodes[i][j].hp -= dps1;
                            vnodes[ii][jj].hp -= dps0;
                            vnodes[ii][jj].hasFight = true;
                        }
                    }
                }
            }
        }
    }
}
 
void move() {
    int i, j, k;
    int x, y; 
    
    for (i=0; i<3; ++i) {// 遍历三个门派 
        for (j=0; j<nn[i]; ++j) {//遍历每个门派的每个人 
            vnodes[i][j].hasFight = false;//因为要移动，先把每个人的打架指数改为没有打架 
            x = vnodes[i][j].x; 
            y = vnodes[i][j].y;
            --map[x][y];//把那个人在地图上的位置上的人数减去一； 
            k = vnodes[i][j].d;//把现在那个人的方向给k 
            if (i == 0) {//对于少林派，如果到了地图最边缘就改变横着走的方向 
                if (x == 12) k = 1;
                if (x == 1)  k = 0;
                if (k) {
                    --x;
                } else {
                    ++x;
                }
            } else if (i == 1) {//对于武当派，如果到了地图最边缘就改变纵着走的方向 
                if (y == 12) k = 1;
                if (y == 1)  k = 0;
                if (k) {
                    --y;
                } else {
                    ++y;
                }
            } else {//如果是峨眉派，到了地图边角就改变横着和纵着走的方向，如果刚好在犄角旮旯就不用移动 
                if (x==12 || y==12)
                    k = 1;
                if (x==1 || y==1)
                    k = 0;
                if ((x==1&&y==12) || (x==12 && y==1));
                else {
                    if (k) {
                        --x; --y;
                    } else {
                        ++x; ++y;
                    }
                }
            }
            vnodes[i][j].d = k;//把已经移动过的方向，纵坐标和横坐标给本派弟子,地图上的人数加一 
            vnodes[i][j].x = x;
            vnodes[i][j].y = y;
            ++map[x][y];
        }
    }
}
 
int main() {
    int i, j, k, tmp;
    int x, y, nl, wy, hp;
    char cmd[1];//注意这里必须用字符串接受输入，虽然不知道什么原因，改成%c就错了 
    
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d", &n);
        while (scanf("%s", cmd)!=EOF && (cmd[0]!='0')) {
            scanf("%d %d %d %d %d", &x, &y, &nl, &wy, &hp);
            if (cmd[0] == 'S') j = 0;
            if (cmd[0] == 'W') j = 1;
            if (cmd[0] == 'E') j = 2;
            ++map[x][y];
            vnodes[j].push_back(node_t(x,y,nl,wy,hp));
            ++nn[j];
        }
        while (n--) {
            fight();
            move();
        }
        for (i=0; i<3; ++i) {
            k = 0;
            n = 0;
            for (j=0; j<nn[i]; ++j) {
                if (vnodes[i][j].hp > 0) {//把武力值大于0的本派的人数和武力值都加起来 
                    k += vnodes[i][j].hp;
                    ++n;
                }
            }
            printf("%d %d\n", n, k);
        }
        puts("***");
    }
    
    return 0;
}