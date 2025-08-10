#include <bits/stdc++.h>
using namespace std;

struct pcb {
	int pid, ppid, priority;//����ID ������ID ���ȼ�
    int reach_time;//����ʱ��
    int run_time;//����ʱ��
    int end_time;//����ʱ��
};

struct pnode {
    pcb* node;     // ָ��pcb
    pnode* sub;    // ָ���һ���ӽ���
    pnode* brother; // ָ����һ���ֵܽڵ�
    pnode* next;   // ָ����һ�����̽ڵ�
};

pnode* plink = nullptr;  //ָ����������ͷ�ڵ�

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

    if (ID == PID) {//����û�и�����
        for (p = plink; p->next; p = p->next);//ѭ������ʱp������ĩβ
        p->next = p1;
        return 0;
    }

    pp = plink;//pp������Ǹ�����
    for (p = plink; p; p =  p->next) {
        if (p->node->pid == ID) {
            cout << ID << "�Ѿ����ڣ�\n";
            return -1;
        }
        if (p->node->pid == PID) {//�ҵ�������
            isfindPID = true;
            pp = p;
        }
    }
    if (!isfindPID) {
        cout << ID << "û���ҵ������̣�\n";
        return -2;
    }
    if (!pp->sub) {//��pp(������)û���ӽ���
        pp->sub = p1;
    }
    else {//�Ѿ���һ���ӽ��� ����������ֵܽڵ�
        for (p = pp->sub; p->brother; p = p->brother);//ѭ������ʱp���ֵܽڵ�����ĩβ
            p->brother = p1;
    }

    for (p = plink; p->next; p = p->next);//ѭ������ʱp������ĩβ
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

void revoke(int x) {//����IDΪx�Ľ���
    //cout << "��������:" << x << "\n";
    pnode* p, * pp, * next, * hode;
    for (p = plink; ; p = p->next) {
        if (p->node->pid == x && p == plink) {//���������ǵ�һ������
            if (p->sub) {//�ȴ����ӽ���
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
            if (pp->sub) {//�ȴ����ӽ���
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
    cout << "�����������";
    cin >> n;
    cout << "�������ID(�ո����)��";
    for (int i = 0; i < n; i++) {
        cin >> v[i].pid;
    }
    cout << "����������ȼ�(�ո����)��";
    for (int i = 0; i < n; i++) {
        cin >> v[i].priority;
    }
    cout << "������̵���ʱ��(�ո����)��";
    for (int i = 0; i < n; i++) {
        cin >> v[i].reach_time;
    }
    cout << "�����������ʱ��(�ո����)��";
    for (int i = 0; i < n; i++) {
        cin >> v[i].run_time;
    }
}

//���ȼ������㷨(����ռ)
void PR() {
    vector<pcb>ready;
    bool is_running = false;
    int count = 0, countdown = -1;

    cout << "���й��̣�\n";
    for (int t = 0; ; t++) {
        cout << t << ":";
        for (int i = 0; i < n; i++) {
            if (v[i].reach_time == t) {
                ready.push_back(v[i]);
                cout << "����" << v[i].pid << "����  ";
            }
        }
        if (!is_running && !ready.empty()) {
            sort(ready.begin(), ready.end(), [](pcb a, pcb b) {
                return a.priority < b.priority;
                });
            cout << "����" << ready.front().pid << "��ʼ����  ";
            is_running = true;
            countdown = ready[0].run_time + t;
        }
        if (t == countdown) {
            is_running = false;
            cout << "�������";
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
    cout << "\nȫ���������!\n";
    cout << "����ID/����ʱ��/����ʱ��/����ʱ��/�ȴ�ʱ��/��תʱ��\n";
    int total_wait = 0, total_turnover = 0;
    for (int i = 0; i < n; i++) {
        cout << v[i].pid << " " << v[i].reach_time << " " << v[i].run_time << " " << v[i].end_time << " " << v[i].end_time - v[i].reach_time - v[i].run_time << " " << v[i].end_time - v[i].reach_time << "\n";
        total_wait += v[i].end_time - v[i].reach_time - v[i].run_time;
        total_turnover += v[i].end_time - v[i].reach_time;
    }
    cout << "ƽ���ȴ�ʱ�䣺" << (float)total_wait / n << "\nƽ����תʱ�䣺" << (float)total_turnover / n;
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