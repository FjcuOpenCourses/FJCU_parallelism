// OpenMP Sort.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
using namespace std;

int values[5], final[5];
int i;

void MySleep()
{
    int i_max = 2000, j_max = 200;
    int i, j, s;
    for (i = 0; i < i_max; ++i)
        for (j = 0; j < j_max; ++j)
            s = i + j;
}

void PutinPlace(int src)
{
    int testval, j, rank;
    testval = values[src];
    j = src;
    rank = 0;
    do {
        j = j % 4 + 1;
        if (testval >= values[j]) rank = rank + 1;
        MySleep();
    } while (j != src);
    final[rank] = testval;
}

void to_thread(int num_thread)
{
    omp_set_num_threads(num_thread);
    cout << "執行緒個數： " << num_thread << endl;
#pragma omp parallel for
    for (i = 1; i <= 4; i++)
        PutinPlace(i);
}

int main() 
{
    for (i = 1; i <= 4; i++)
        cin >> values[i];

    clock_t start;
    clock_t interval_4;

    start = clock();
    to_thread(4);  //4 執行緒
    interval_4 = clock() - start;

    double interval_4_sec = interval_4 / (double)CLOCKS_PER_SEC;
    printf("%lf 平行 clock cycles\n", (double)interval_4);
    printf("%lf 平行 seconds elapsed\n", interval_4_sec);

    clock_t interval_1;

    start = clock();
    to_thread(1);  // 1 執行緒, 沒平行
    interval_1 = clock() - start;

    double interval_1_sec = interval_1 / (double)CLOCKS_PER_SEC;

    printf("%lf 沒平行 clock cycles\n", (double)interval_1);
    printf("%lf 沒平行 seconds elapsed\n", interval_1_sec);

    double speedup = interval_1_sec / interval_4_sec;
    double eff = speedup / 4; // 執行緒個數：4
    printf("%lf speedup\n", speedup);
    printf("%lf 使用率\n", eff);

    printf("排序結果：");
    for (i = 1; i <= 4; i++)
        printf("%d", final[i]);

}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
