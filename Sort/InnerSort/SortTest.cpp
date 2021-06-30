//
// Created by 晚风吹行舟 on 2021/6/23.
//
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

class Sort {
public:
    virtual void sort(int arr[], int len) = 0;
};

class BubbleSort : public Sort {
public:
    void sort(int arr[], int len) {
        bubbleSort(arr, len);
    }

private:
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

};

class InsertSort : public Sort {
public:
    void sort(int arr[], int len) {
        insertSort1(arr, len);
    }

private:
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
};

class HeapSort : public Sort {
public:
    void sort(int arr[], int len) {
        heapSort(arr, len-1);
    }

private:
    void heapSort(int arr[], int len) {
        // 构建大顶堆
        for (int i = len / 2; i >= 1; i--)
            adjustHeap(arr, i, len);

        // 堆顶元素与末尾元素交换+重新构建大顶堆
        for (int i = len; i > 1; i--) {
            arr[1] = arr[1] + arr[i];
            arr[i] = arr[1] - arr[i];
            arr[1] = arr[1] - arr[i];
            adjustHeap(arr, 1, i - 1);
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

class QuickSort : public Sort {
public:
    void sort(int arr[], int len) {
        quickSort(arr, 0, len - 1);
    }

private:
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


};

class MergeSort : public Sort {
public:
    void sort(int arr[], int len) {
        setArrTmp(len);
        mergeSort(arr, 0, len - 1);
    }

private:
    int *arr_tmp = nullptr;

    void setArrTmp(int n) {
        if (arr_tmp != nullptr)
            delete arr_tmp;
        arr_tmp = new int[n];
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

    void mergeSort(int arr[], int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(low, mid, high, arr);
        }
    }
};

double countTime(Sort *sort, int arr[], int len) {
    clock_t start, end;
    // bubble
    start = clock();
    sort->sort(arr, len);
    end = clock();
    double cost_time = (double) (end - start)*1000/CLOCKS_PER_SEC;
    return cost_time;
}

void initializeArr(int *&arr, int len) {
    arr = new int[len];
    for (int i = 0; i < len; i++)
        arr[i] = i + 1;
}

void shuffleArr(int arr[], int len) {
    if (arr == nullptr) return;
    shuffle(arr, arr + len, default_random_engine(520));
}

double sort(Sort *sort, int arr[], int len) {
    shuffleArr(arr, len);
    return countTime(sort, arr, len);
}

/**
 * 以当前的数据规模为准，分别用下列方法进行排序
 * @堆排序
 * @快速排序
 * @归并排序
 * @插入排序
 * @冒泡排序
 * 每次排序数据是一摸一样的
 * @param len 数据规模
 */
void sortTest(int len) {
    int *arr = nullptr;
    initializeArr(arr, len);
    cout << len << "\t" << sort(new HeapSort(), arr, len) << "\t\t" << sort(new QuickSort(), arr, len) <<
         "\t\t" << sort(new MergeSort(), arr, len)  << endl;
//         << "\t\t" << sort(new BubbleSort(), arr, len) << "\t" << sort(new InsertSort(), arr, len) << endl;
    delete[]arr;
}

int main() {
    int n = 8;
    int *dataNum = new int[n];
    for (int i = 0; i < n; i++)
        dataNum[i] = pow(10, i + 1);
    cout << "scale" << "\t" << "HeapSort" << "\t" << "QuickSort"
         << "\t" << "MergeSort" << "\t" << "BubbleSort" << "\t" << "InsertSort" << endl;
    sortTest(dataNum[0]);
    sortTest(dataNum[1]);
    sortTest(dataNum[2]);
    sortTest(dataNum[3]);
    sortTest(dataNum[4]);
    sortTest(dataNum[5]);
    sortTest(dataNum[6]);
    sortTest(dataNum[7]);


//    int n = 6;
//    int *arr = new int[n];
//    for (int i = 0; i < 6; i++)
//        arr[i] = i+1;
//    shuffle(arr, arr+n, default_random_engine(2));
//    for (int i = 0; i < 6; i++)
//        cout << arr[i];
    return 0;
}



