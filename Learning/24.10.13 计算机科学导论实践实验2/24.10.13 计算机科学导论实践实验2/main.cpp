//#include <stdio.h>
//#include <stdlib.h>
//#include <cmath>
//#include <windows.h>
//
//double f(double x) {// 待积分函数
//    return 3.0 + 2.345 * x + 0.98372 * x * x + 0.3221 * x * x * x;
//}
//
//int main() {
//    LARGE_INTEGER now, then, fr;// 用于时间记录
//    double estimat = 0.0;// 积分值
//    const int fre = 50000000;// 插样点数量
//    double start = 0.0, end = 1.0;// 积分区间
//
//    QueryPerformanceFrequency(&fr);
//
//    for (int j = 0; j < 10; j++) { // 10种不同插样值
//        int current_fre = fre * (j + 1) / 10;// 动态调整插样点数量
//        double delta = (end - start) / current_fre;// 获取计算的步长
//
//        QueryPerformanceCounter(&now);
//        for (int i = 0; i < current_fre; i++) {// 计算积分
//            estimat += abs(delta * (f(start + i * delta) + f(start + (i + 1) * delta)) / 2);
//        }
//        QueryPerformanceCounter(&then);
//
//        printf("fer: %d samples: Area is %f.\n", current_fre, estimat);// 输出结果
//        printf("CPU耗时：%f毫秒\n", (double)(then.QuadPart - now.QuadPart) * 1000 / (double)(fr.QuadPart));
//
//        estimat = 0.0;
//    }
//
//    system("pause");
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include"mpi.h"


double f(double x) {// 待积分函数
    return 3.0 + 2.345 * x + 0.98372 * x * x + 0.3221 * x * x * x;
}

double Trap(double local_a, double local_b, int local_n, double h) {// 计算积分
    double integral = (f(local_a) + f(local_b)) / 2.0;
    for (int i = 1; i < local_n; i++) {
        integral += f(local_a + i * h);
    }
    integral *= h;
    return integral;
}

int main(int argc, char* argv[]) {
    LARGE_INTEGER now, then, fr;
    int myrank, nprocs;// 进程编号，进程总数
    QueryPerformanceFrequency(&fr);

    double start = 0.0, end = 100.0; // 积分区间

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);// 获取进程编号
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);// 获取进程数

    for (int j = 0; j < 10; j++) { // 10种不同插样值
        int fre = 50000000 * (j + 1) / 10; // 动态调整插样点数量
        double h = (end - start) / fre;
        int local_n = fre / nprocs;// 每个进程的差样点数量
        double local_a = start + myrank * local_n * h;// 计算进程的积分区间
        double local_b = local_a + local_n * h;

        QueryPerformanceCounter(&now);
        double local_int = Trap(local_a, local_b, local_n, h);// 计算进程的积分值
        double total_int;

        if (myrank == 0) {// 若进程的编号是0，则接收其他进程的积分值并计算总积分值
            total_int = local_int;
            double received_int;
            for (int source = 1; source < nprocs; source++) {
                MPI_Recv(&received_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                total_int += received_int;
            }
            QueryPerformanceCounter(&then);
            printf("fer:%d samples: Area from %f to %f = %f\n", fre, start, end, total_int);// 输出结果
            printf("MPI耗时：%f毫秒\n", (double)(then.QuadPart - now.QuadPart) * 1000 / (double)(fr.QuadPart));
        }
        else {
            MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
