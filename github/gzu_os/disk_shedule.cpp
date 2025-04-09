#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int n; //进程数
constexpr int N = 200; //盘面的柱面数

typedef struct process{
    string p_name; //进程名
    vector<int> disk_ids; //进程访问磁道号
    vector<bool> visit;   //柱面是否已访问，true为已访问
    vector<int> v; //磁道访问序列
    int seek_len; //寻道长度
    double avg_seek_len; //平均寻道长度
} process;

void init_process_table(process *& pro)
{
    cout << "进程数: " << endl;
    cin >> n;
   
    pro = new process[n]; 
    cout << "输入对应进程名和对应磁盘访问序列" << endl;
    string p_str, p;
    getchar();
  
    for (int i = 0; i < n; ++i)
    {
        getline(cin, p_str);
        stringstream ss(p_str);
        int j = 0;
        while (ss >> p)
        {
            if(j == 0){
                pro[i].p_name = p, j++;
            } 
            else 
            {
                pro[i].disk_ids.push_back(stoi(p));
                pro[i].visit.push_back(false);
            } 
        }
        pro[i].seek_len = 0;     
    }
}

void print_process_table(process* p)
{
    for (int i = 0; i < n; ++i)
    {
        cout << p[i].p_name << ' ';
        for (int j = 0; j < p[i].disk_ids.size(); ++j)
        {
            cout << p[i].disk_ids[j] << ' ';
        }
        cout << endl;
    }
}

void print_process_table(process p)
{
    
    cout << p.p_name << setw(15);
    
    cout << p.seek_len << setw(15);
    cout << p.avg_seek_len << setw(15);
    for (int i = 0; i < p.v.size(); ++i)
    {  
         cout << p.v[i] << ' ';
    }
    cout << endl;
}
/*
判断访问序列的柱面和磁盘柱面是否命中
*/
bool is_find_disk(process& p, int disk_index)
{
    for (int i = 0; i < p.disk_ids.size(); ++i)
    {
        if ( !p.visit[i] && p.disk_ids[i] == disk_index)
        {
            p.visit[i] = true;
            p.v.push_back(p.disk_ids[i]);
            return true;
        }

    }
    return false;  
}

/*
cur_index 当前磁头位置，返回下一个最近位置。
*/
int find_next_pos(process& p, int cur_index)
{
    int latest_next_index, ttmp = INT_MAX;
    int j = 0;
    for (int i = 0; i < p.disk_ids.size(); ++i)
    {
        if (!p.visit[i])
        {
            int tmp = abs(cur_index - p.disk_ids[i]);
            
            if (tmp < ttmp) 
            {
                latest_next_index = p.disk_ids[i];
                ttmp = tmp;
                j = i;
            }
        }
       
    }
    p.v.push_back(latest_next_index);
    p.visit[j] = true;

    return latest_next_index;
}

/*
电梯算法，磁臂从磁盘的一端开始，
向另一端移动；在移过每个柱面时，
处理请求。当到达磁盘的另一端时，
磁头移动方向反转，并继续处理,方向：右->左->右
*/
void SCAN(process& p, int disk_index)
{

    vector<int> tmp(p.disk_ids);
    // int tmp_disk_index = disk_index;
    sort(tmp.begin(), tmp.end());
    //int min_index = N;

    //求寻道长度
    // for (int i = 0; i < tmp.size(); ++i)
    // {
    //     if (tmp[i] >= tmp_disk_index)
    //     {
    //         min_index = min(i, min_index);
    //         p.seek_len += tmp[i] - tmp_disk_index;
    //         tmp_disk_index = tmp[i];
    //     }
    // }
    // if (min_index >= 1)
    // {
    //     p.seek_len += N - tmp[tmp.size() - 1] - 1;
    //     for (int i = 0; i < min_index - 1; ++i)
    //     {
    //         p.seek_len += tmp[i + 1] - tmp[i];
    //     }
    //     p.seek_len += N - tmp[min_index - 1] - 1;
    // }
    if (tmp[0] < disk_index) 
    {
        p.seek_len += N - 1 - disk_index;
        p.seek_len += N - 1 - tmp[0];
    }
    else {
        p.seek_len += tmp[tmp.size() - 1] - disk_index;
    }
    p.avg_seek_len = p.seek_len*1.0 / p.disk_ids.size();

    int len = p.visit.size();
    while(len)
    {
        for (int i = disk_index; i <= N && len >= 0; i++)
        {
            if (is_find_disk(p, i))
            {
                len--;
            }    
        }
        
        for (int i = N; i >= 0 && len >= 0; i--)
        {
             if (is_find_disk(p, i))
            {
                len--;
            }
        }
    }
}
/*
最短寻道优先算法，每次找到距离当前磁头距离最小的下一个柱面
*/
void SSTF(process& p, int disk_index)
{
    int len = p.visit.size();
    int tmp = disk_index;
    while(len)
    {
        tmp = disk_index;
        disk_index = find_next_pos(p, disk_index);
        p.seek_len += abs(tmp - disk_index);
        len--;
    }
    p.avg_seek_len = p.seek_len * 1.0 / p.disk_ids.size();
}

void SCAN_schedule(process* p)
{
    int disk_index;
    cout << "请输入磁头开始位置(柱面号大小为：0~199): ";
    cin >> disk_index;
    cout << "进程名" << setw(15) << "寻道长度" << setw(15) << "平均寻道长度" << setw(20) << "磁道访问序号" <<endl;
    for (int i = 0; i < n; ++i)
    {
        SCAN(p[i], disk_index);
        print_process_table(p[i]);
    }
}

void SSTF_schedule(process* p)
{
    int disk_index;
    cout << "请输入磁头开始位置(柱面号大小为：0~199): ";
    cin >> disk_index;
    cout << "进程名" << setw(15) << "寻道长度" << setw(15) << "平均寻道长度" << setw(20) << "磁道访问序号" <<endl;
    for (int i = 0; i < n; ++i)
    {
        SSTF(p[i], disk_index);
        print_process_table(p[i]);
    }
}
void disk_schedule(process* p)
{
    cout << "\t 1. SCAN 算法" << endl;
    cout << "\t 2. SSTF 算法" << endl;

    cout << "选择算法：";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        SCAN_schedule(p);
    }
    else if (choice == 2)
    {
        SSTF_schedule(p);
    }
}

int main()
{
    process* p = nullptr;

    init_process_table(p);
    
    disk_schedule(p);

    return 0;
}


