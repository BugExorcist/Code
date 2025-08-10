package t3;

import java.util.Arrays;

// 目标接口
interface DataOperation {
    void sort(int[] array);
    int search(int[] array, int key);
}

// 被适配的快速排序类
class QuickSort {
    public void quickSort(int[] array) {
        Arrays.sort(array);
    }
}

// 被适配的二分查找类（
class BinarySearch {
    public int binarySearch(int[] array, int key) {
        return Arrays.binarySearch(array, key);
    }
}

// 适配器类
class SortSearchAdapter implements DataOperation {
    private QuickSort quickSort;
    private BinarySearch binarySearch;

    public SortSearchAdapter() {
        this.quickSort = new QuickSort();
        this.binarySearch = new BinarySearch();
    }

    @Override
    public void sort(int[] array) {
        quickSort.quickSort(array);
    }

    @Override
    public int search(int[] array, int key) {
        return binarySearch.binarySearch(array, key);
    }
}

// 使用示例
public class AdapterDemo {
    public static void main(String[] args) {
        // 创建适配器
        DataOperation operation = new SortSearchAdapter();

        int[] data = {5, 2, 9, 1, 5, 6};

        // 使用适配后的接口
        System.out.println("排序前数组: " + Arrays.toString(data));
        operation.sort(data);
        System.out.println("排序后数组: " + Arrays.toString(data));

        int key = 5;
        int result = operation.search(data, key);
        System.out.println("查找 " + key + " 的结果: " + result);
    }
}