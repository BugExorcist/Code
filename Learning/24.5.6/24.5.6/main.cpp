#include <bits/stdc++.h>
using namespace std;

struct pcb {
	int pid, ppid, priority;//进程ID 父进程ID 优先级
    int reach_time;//进入时间
    int run_time;//运行时间
    int end_time;//结束时间
};

struct pnode {
    pcb* node;     // 指向pcb
    pnode* sub;    // 指向第一个子进程
    pnode* brother; // 指向下一个兄弟节点
    pnode* next;   // 指向下一个进程节点
};

pnode* plink = nullptr;  //指向进程链表的头节点

int createpc(int ID, int PID, int Pri) {
    pnode* p, * pp;
    bool isfindPID = false;

    pnode* p1 = new pnode;
    p1->node = new pcb;
    p1->node->pid = ID;
    p1->node->ppid = PID;
    p1->node->priority = Pri;
    p1->brother = nullptr;
    p1->next = nullptr;
    p1->sub = nullptr;

    if (plink == nullptr) {
        plink = p1;

        return 1;
    }

    if (ID == PID) {//进程没有父进程
        for (p = plink; p->next; p = p->next);//循环结束时p是链表末尾
        p->next = p1;
        return 0;
    }

    pp = plink;//pp用来标记父进程
    for (p = plink; p; p =  p->next) {
        if (p->node->pid == ID) {
            cout << ID << "已经存在！\n";
            return -1;
        }
        if (p->node->pid == PID) {//找到父进程
            isfindPID = true;
            pp = p;
        }
    }
    if (!isfindPID) {
        cout << ID << "没有找到父进程！\n";
        return -2;
    }
    if (!pp->sub) {//当pp(父进程)没有子进程
        pp->sub = p1;
    }
    else {//已经有一个子进程 则更新他的兄弟节点
        for (p = pp->sub; p->brother; p = p->brother);//循环结束时p是兄弟节点链表末尾
            p->brother = p1;
    }

    for (p = plink; p->next; p = p->next);//循环结束时p是链表末尾
    p->next = p1;

    return 0;
}

void showdetail() {
    pnode* p = plink;
    while (p) {
        cout << p->node->pid << "(priority " << p->node->priority << "): ";
        pnode* sub = p->sub;
        while (sub) {
            cout << sub->node->pid << "(priority " << sub->node->priority << ") ";
            sub = sub->brother;
        }
        cout << "\n";
        p = p->next;
    }
    cout << "\n";
}

void revoke(int x) {//撤销ID为x的进程
    //cout << "撤销进程:" << x << "\n";
    pnode* p, * pp, * next, * hode;
    for (p = plink; ; p = p->next) {
        if (p->node->pid == x && p == plink) {//被撤销的是第一个进程
            if (p->sub) {//先处理子进程
                next = p->sub;
                hode = next->brother;
                while (next) {
                    revoke(next->node->pid);
                    next = hode;
                    if (hode) {
                        hode = hode->brother;
                    }
                }
            }
            plink = p->next;
            delete p;
            break;
        }
        else if (p->next->node->pid == x) {
            pp = p->next;
            if (pp->sub) {//先处理子进程
                next = pp->sub;
                hode = next->brother;
                while (next) {
                    revoke(next->node->pid);
                    next = hode;
                    if (hode) {
                        hode = hode->brother;
                    }
                }
            }
            
            p->next = pp->next;
            for (p = plink; ; p = p->next) {
                if (p->sub == pp) {
                    p->sub = pp->brother;
                }
                if (p->brother == pp) {
                    p->brother = pp->brother;
                }
                if (p->next == nullptr) {
                    break;
                }
            }
            delete pp;
        }
        if (p->next == nullptr) {
            break;
        }
    }
    //showdetail();
}



int n;
vector<pcb>v(20);

void menu() {
    cout << "输入进程数：";
    cin >> n;
    cout << "输入进程ID(空格隔开)：";
    for (int i = 0; i < n; i++) {
        cin >> v[i].pid;
    }
    cout << "输入进程优先级(空格隔开)：";
    for (int i = 0; i < n; i++) {
        cin >> v[i].priority;
    }
    cout << "输入进程到达时间(空格隔开)：";
    for (int i = 0; i < n; i++) {
        cin >> v[i].reach_time;
    }
    cout << "输入进程运行时间(空格隔开)：";
    for (int i = 0; i < n; i++) {
        cin >> v[i].run_time;
    }
}

//优先级调度算法(非抢占)
void PR() {
    vector<pcb>ready;
    bool is_running = false;
    int count = 0, countdown = -1;

    cout << "运行过程：\n";
    for (int t = 0; ; t++) {
        cout << t << ":";
        for (int i = 0; i < n; i++) {
            if (v[i].reach_time == t) {
                ready.push_back(v[i]);
                cout << "进程" << v[i].pid << "到达  ";
            }
        }
        if (!is_running && !ready.empty()) {
            sort(ready.begin(), ready.end(), [](pcb a, pcb b) {
                return a.priority < b.priority;
                });
            cout << "进程" << ready.front().pid << "开始运行  ";
            is_running = true;
            countdown = ready[0].run_time + t;
        }
        if (t == countdown) {
            is_running = false;
            cout << "运行完毕";
            for (int i = 0; i < n; i++) {
                if (ready[0].pid == v[i].pid) {
                    v[i].end_time = t;
                }
            }
            ready.erase(ready.begin());
            count++;
        }
        if (count == n)
            break;
        cout << "\n";
    }
    cout << "\n全部运行完毕!\n";
    cout << "进程ID/进入时间/运行时间/结束时间/等待时间/周转时间\n";
    int total_wait = 0, total_turnover = 0;
    for (int i = 0; i < n; i++) {
        cout << v[i].pid << " " << v[i].reach_time << " " << v[i].run_time << " " << v[i].end_time << " " << v[i].end_time - v[i].reach_time - v[i].run_time << " " << v[i].end_time - v[i].reach_time << "\n";
        total_wait += v[i].end_time - v[i].reach_time - v[i].run_time;
        total_turnover += v[i].end_time - v[i].reach_time;
    }
    cout << "平均等待时间：" << (float)total_wait / n << "\n平均周转时间：" << (float)total_turnover / n;
}


void test() {
    createpc(0, 0, 0);
    createpc(1, 0, 1);
    createpc(2, 2, 2);
    createpc(3, 1, 3);
    createpc(4, 2, 4);
    createpc(5, 3, 5);
    createpc(6, 3, 6);
    createpc(7, 7, 7);
    createpc(8, 4, 8);
    createpc(9, 5, 8);

    showdetail();

    revoke(1);

    showdetail();
}

int main() {
    //test();

    menu();
    PR();
    
    return 0;
}