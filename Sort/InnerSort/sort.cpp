//
// Created by 晚风吹行舟 on 2021/6/19.
//
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

class Sort {
private:
    // 快速排序的辅助数组
    int *arr_tmp = nullptr;

public:

    void setArrTmp(int n) {
        if (arr_tmp != nullptr)
            delete arr_tmp;
        arr_tmp = new int[n];
    }

    /**
     * 直接插入排序
     * @param arr 待排序数组
     * @param len  数组长度
     */
    void insertSort1(int arr[], int len) {
        for (int i = 1; i < len; i++) {
            int tmp = arr[i];
            int j = i - 1;
            for (; j >= 0; j--) {
                if (tmp < arr[j])
                    // 将当前元素后移一位
                    arr[j + 1] = arr[j];
                else
                    break;
            }
            arr[j + 1] = tmp;
        }
    }

    /**
     * 二分插入排序
     * @param arr 待排序数组
     * @param len 数组长度
     */
    void insertSort2(int arr[], int len) {

    }

    void bubbleSort(int arr[], int len) {
        for (int i = 0; i < len - 1; i++) {
            // 用于记录本趟冒泡排序是否发生
            bool flag = false;
            for (int j = len - 1; j > i; j--) {
                if (arr[j] < arr[j - 1]) {
                    // 前提两个数相加不会溢出
                    arr[j] = arr[j] + arr[j - 1];
                    arr[j - 1] = arr[j] - arr[j - 1];
                    arr[j] = arr[j] - arr[j - 1];
                    flag = true;
                }
            }
            if (flag == false)
                return;
        }
    }

    // 快速排序辅助函数
    int partition(int arr[], int low, int high) {
        int pivot = arr[low];
        while (low < high) {
            while (low < high && arr[high] >= pivot) high--;
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivot) low++;
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }

    /**
     * 快速排序 递归
     * @param arr 待排序数组
     * @param low 起始位置
     * @param high 终止位置
     */
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pos = partition(arr, low, high);
            quickSort(arr, low, pos - 1);
            quickSort(arr, pos + 1, high);
        }
    }

    void merge(int low, int mid, int high, int arr[]) {
        // 移动元素到辅助数组中
        for (int i = low; i <= high; i++)
            arr_tmp[i] = arr[i];
        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high) {
            if (arr_tmp[i] < arr_tmp[j]) {
                arr[low++] = arr_tmp[i++];
            } else {
                arr[low++] = arr_tmp[j++];
            }
        }
        while (i <= mid) arr[low++] = arr_tmp[i++];
        while (j <= high) arr[low++] = arr_tmp[j++];
    }

    void mergeSort(int low, int high, int arr[]) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(low, mid, arr);
            mergeSort(mid + 1, high, arr);
            merge(low, mid, high, arr);
        }
    }

    void heapSort(int arr[], int len) {
        // 构建大顶堆
        for (int i = len/2;i>=1;i--)
            adjustHeap(arr,i,len);

        // 堆顶元素与末尾元素交换+重新构建大顶堆
        for (int i = len;i>1;i--){
            arr[1] = arr[1] + arr[i];
            arr[i] = arr[1] - arr[i];
            arr[1] = arr[1] - arr[i];
            adjustHeap(arr,1,i-1);
        }

    }

    void adjustHeap(int arr[], int start, int len) {
        arr[0] = arr[start];
        // ? 王道视频13:58显示代码中(...;i<=len;....)为什么？
        for (int i = start * 2; i <= len; i *= 2) {
            // 使i指向孩子节点中的最大值
            if (i < len && arr[i] < arr[i + 1]) {
                i++;
            }
            if (arr[0] >= arr[i]) break;
            else {
                arr[start] = arr[i];
                start = i;
            }
        }
        arr[start] = arr[0];
    }


};

class SortTest : public ::testing::Test {

protected:
    Sort sort;
    int arr1[12] = {4, 1, 5, 6, 8, 2, 15, 32, 47, 12, 3, 6};
    int arr2[10] = {13, 15, 21, 3, 41, 25, 31, 10, 5, 12};

protected:
    virtual void SetUp() {

    }
};

TEST_F(SortTest, InsertSort1) {
    sort.insertSort1(arr1, 12);
    ASSERT_EQ(arr1[0], 1);
    ASSERT_EQ(arr1[1], 2);
    ASSERT_EQ(arr1[2], 3);
    ASSERT_EQ(arr1[3], 4);
    ASSERT_EQ(arr1[4], 5);
    ASSERT_EQ(arr1[5], 6);
    ASSERT_EQ(arr1[6], 6);
    ASSERT_EQ(arr1[7], 8);
    ASSERT_EQ(arr1[8], 12);
    ASSERT_EQ(arr1[9], 15);
    ASSERT_EQ(arr1[10], 32);
    ASSERT_EQ(arr1[11], 47);
    sort.insertSort1(arr2, 10);
    ASSERT_EQ(arr2[0], 3);
    ASSERT_EQ(arr2[1], 5);
    ASSERT_EQ(arr2[2], 10);
    ASSERT_EQ(arr2[3], 12);
    ASSERT_EQ(arr2[4], 13);
    ASSERT_EQ(arr2[5], 15);
    ASSERT_EQ(arr2[6], 21);
    ASSERT_EQ(arr2[7], 25);
    ASSERT_EQ(arr2[8], 31);
    ASSERT_EQ(arr2[9], 41);
}

TEST_F(SortTest, BubbleSort) {
    sort.bubbleSort(arr1, 12);
    ASSERT_EQ(arr1[0], 1);
    ASSERT_EQ(arr1[1], 2);
    ASSERT_EQ(arr1[2], 3);
    ASSERT_EQ(arr1[3], 4);
    ASSERT_EQ(arr1[4], 5);
    ASSERT_EQ(arr1[5], 6);
    ASSERT_EQ(arr1[6], 6);
    ASSERT_EQ(arr1[7], 8);
    ASSERT_EQ(arr1[8], 12);
    ASSERT_EQ(arr1[9], 15);
    ASSERT_EQ(arr1[10], 32);
    ASSERT_EQ(arr1[11], 47);
    sort.bubbleSort(arr2, 10);
    ASSERT_EQ(arr2[0], 3);
    ASSERT_EQ(arr2[1], 5);
    ASSERT_EQ(arr2[2], 10);
    ASSERT_EQ(arr2[3], 12);
    ASSERT_EQ(arr2[4], 13);
    ASSERT_EQ(arr2[5], 15);
    ASSERT_EQ(arr2[6], 21);
    ASSERT_EQ(arr2[7], 25);
    ASSERT_EQ(arr2[8], 31);
    ASSERT_EQ(arr2[9], 41);
}

TEST_F(SortTest, QuickSort) {
    sort.quickSort(arr1, 0, 11);
    ASSERT_EQ(arr1[0], 1);
    ASSERT_EQ(arr1[1], 2);
    ASSERT_EQ(arr1[2], 3);
    ASSERT_EQ(arr1[3], 4);
    ASSERT_EQ(arr1[4], 5);
    ASSERT_EQ(arr1[5], 6);
    ASSERT_EQ(arr1[6], 6);
    ASSERT_EQ(arr1[7], 8);
    ASSERT_EQ(arr1[8], 12);
    ASSERT_EQ(arr1[9], 15);
    ASSERT_EQ(arr1[10], 32);
    ASSERT_EQ(arr1[11], 47);
    sort.quickSort(arr2, 0, 9);
    ASSERT_EQ(arr2[0], 3);
    ASSERT_EQ(arr2[1], 5);
    ASSERT_EQ(arr2[2], 10);
    ASSERT_EQ(arr2[3], 12);
    ASSERT_EQ(arr2[4], 13);
    ASSERT_EQ(arr2[5], 15);
    ASSERT_EQ(arr2[6], 21);
    ASSERT_EQ(arr2[7], 25);
    ASSERT_EQ(arr2[8], 31);
    ASSERT_EQ(arr2[9], 41);
}

TEST_F(SortTest, MergeSort) {
    sort.setArrTmp(12);
    sort.mergeSort(0, 11, arr1);
    ASSERT_EQ(arr1[0], 1);
    ASSERT_EQ(arr1[1], 2);
    ASSERT_EQ(arr1[2], 3);
    ASSERT_EQ(arr1[3], 4);
    ASSERT_EQ(arr1[4], 5);
    ASSERT_EQ(arr1[5], 6);
    ASSERT_EQ(arr1[6], 6);
    ASSERT_EQ(arr1[7], 8);
    ASSERT_EQ(arr1[8], 12);
    ASSERT_EQ(arr1[9], 15);
    ASSERT_EQ(arr1[10], 32);
    ASSERT_EQ(arr1[11], 47);
    sort.mergeSort(0, 9, arr2);
    ASSERT_EQ(arr2[0], 3);
    ASSERT_EQ(arr2[1], 5);
    ASSERT_EQ(arr2[2], 10);
    ASSERT_EQ(arr2[3], 12);
    ASSERT_EQ(arr2[4], 13);
    ASSERT_EQ(arr2[5], 15);
    ASSERT_EQ(arr2[6], 21);
    ASSERT_EQ(arr2[7], 25);
    ASSERT_EQ(arr2[8], 31);
    ASSERT_EQ(arr2[9], 41);
}

TEST_F(SortTest, heapSort) {
    sort.heapSort(arr1,11);
    ASSERT_EQ(arr1[1], 1);
    ASSERT_EQ(arr1[2], 2);
    ASSERT_EQ(arr1[3], 3);
    ASSERT_EQ(arr1[4], 5);
    ASSERT_EQ(arr1[5], 6);
    ASSERT_EQ(arr1[6], 6);
    ASSERT_EQ(arr1[7], 8);
    ASSERT_EQ(arr1[8], 12);
    ASSERT_EQ(arr1[9], 15);
    ASSERT_EQ(arr1[10], 32);
    ASSERT_EQ(arr1[11], 47);
    sort.heapSort(arr2,9);
    ASSERT_EQ(arr2[1], 3);
    ASSERT_EQ(arr2[2], 5);
    ASSERT_EQ(arr2[3], 10);
    ASSERT_EQ(arr2[4], 12);
    ASSERT_EQ(arr2[5], 15);
    ASSERT_EQ(arr2[6], 21);
    ASSERT_EQ(arr2[7], 25);
    ASSERT_EQ(arr2[8], 31);
    ASSERT_EQ(arr2[9], 41);
}

