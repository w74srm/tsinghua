#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct timeNode
{
    vector<int> inTime, outTime;
};
struct carNode
{
    string plate;
    int time;
};

int toSecond(string &s);                 //把时间转换成秒，便于计算
void toStr(int n, string &s, bool flag); //用于时、分、秒的转换
bool cmp(const carNode &a, const carNode &b);
string toHMS(int time); //把秒转成规定格式的时间

unordered_map<string, timeNode> mp; //记录每辆车的原始出入时间信息
vector<carNode> carInfo;            //记录每辆车的停留时间长度
vector<int> carIn, carOut;          //记录配对完成的正确的车辆出入时间

int main()
{
    int N, K;
    string plate, strTime;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        string flag;
        cin >> plate >> strTime >> flag;
        if (flag == "in")
            mp[plate].inTime.push_back(toSecond(strTime));
        else
            mp[plate].outTime.push_back(toSecond(strTime));
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int i = 0, j = 0, time = 0,
            inTimeSize = it->second.inTime.size(),
            outTimeSize = it->second.outTime.size();
        sort(it->second.inTime.begin(), it->second.inTime.end());
        sort(it->second.outTime.begin(), it->second.outTime.end());
        while (i < inTimeSize && j < outTimeSize)
        {
            if (it->second.inTime[i] >= it->second.outTime[j])
            {
                while (j < outTimeSize && it->second.inTime[i] >= it->second.outTime[j])
                {
                    j++;
                }
            }
            else
            {
                while (i < inTimeSize && it->second.inTime[i] < it->second.outTime[j])
                {
                    i++;
                }
                if (i != 0)
                    i--;
                carIn.push_back(it->second.inTime[i]);
                carOut.push_back(it->second.outTime[j]);
                time += it->second.outTime[j] - it->second.inTime[i];
                i++;
                j++;
            }
        }
        carInfo.push_back({it->first, time});
    }
    sort(carIn.begin(), carIn.end());
    sort(carOut.begin(), carOut.end());
    int inIndex = 0, outIndex = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> strTime;
        int tmpTime = toSecond(strTime);
        while (inIndex < carIn.size() && carIn[inIndex] <= tmpTime)
        {
            inIndex++;
        }
        while (outIndex < carOut.size() && carOut[outIndex] <= tmpTime)
        {
            outIndex++;
        }
        printf("%d\n", inIndex - outIndex);
    }
    sort(carInfo.begin(), carInfo.end(), cmp);
    for (int i = 0; i < carInfo.size() && carInfo[i].time == carInfo[0].time; i++)
    {
        cout << carInfo[i].plate << " ";
    }
    cout << toHMS(carInfo[0].time) << endl;
    return 0;
}

bool cmp(const carNode &a, const carNode &b)
{
    return a.time != b.time ? a.time > b.time : a.plate < b.plate;
}

void toStr(int n, string &s, bool flag)
{
    if (n >= 10)
    {
        s.push_back(n / 10 + '0');
        s.push_back(n % 10 + '0');
    }
    else
    {
        s.push_back('0');
        s.push_back(n + '0');
    }
    if (flag)
        s.push_back(':');
}

string toHMS(int time)
{
    string HMS;
    toStr(time / 3600, HMS, true);
    toStr(time % 3600 / 60, HMS, true);
    toStr(time % 3600 % 60, HMS, false);
    return HMS;
}

int toSecond(string &s)
{
    int hour = (s[0] - '0') * 10 + s[1] - '0',
        minute = (s[3] - '0') * 10 + s[4] - '0',
        second = (s[6] - '0') * 10 + s[7] - '0';
    return hour * 3600 + minute * 60 + second;
}