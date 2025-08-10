#include<cuda.h>
#include<stdio.h>
int main（int argc, char* argv[]）
//初始化CUDA
cudaError_t status = cudaSuccessi
status = cudaFree（e）；
if （status ！ = cudaSuccess）
printf（“当前电脑的显卡不支持CUDA加速计算！n”）；
return 9
else
printf（“当前电脑的显卡支持CUDA加速计算！n