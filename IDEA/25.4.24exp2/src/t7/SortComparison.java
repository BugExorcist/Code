package t7;

import java.util.Arrays;
import java.util.Random;

// 排序策略接口
interface SortStrategy {
    void sort(int[] array);
    String getAlgorithmName();
}

// 具体排序策略实现
class BubbleSort implements SortStrategy {
    @Override
    public void sort(int[] array) {
        int n = array.length;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (array[j] > array[j+1]) {
                    // 交换元素
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }

    @Override
    public String getAlgorithmName() {
        return "冒泡排序";
    }
}

class QuickSort implements SortStrategy {
    @Override
    public void sort(int[] array) {
        quickSort(array, 0, array.length - 1);
    }

    private void quickSort(int[] array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }

    private int partition(int[] array, int low, int high) {
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                // 交换元素
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // 交换主元
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        return i + 1;
    }

    @Override
    public String getAlgorithmName() {
        return "快速排序";
    }
}

class MergeSort implements SortStrategy {
    @Override
    public void sort(int[] array) {
        mergeSort(array, 0, array.length - 1);
    }

    private void mergeSort(int[] array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }

    private void merge(int[] array, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] L = new int[n1];
        int[] R = new int[n2];

        System.arraycopy(array, left, L, 0, n1);
        System.arraycopy(array, mid + 1, R, 0, n2);

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }

    @Override
    public String getAlgorithmName() {
        return "归并排序";
    }
}

// 排序上下文
class SortContext {
    private SortStrategy strategy;

    public void setStrategy(SortStrategy strategy) {
        this.strategy = strategy;
    }

    public void executeSort(int[] array) {
        long startTime = System.nanoTime();
        strategy.sort(array);
        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000; // 微秒

        System.out.println(strategy.getAlgorithmName() + " 执行时间: " + duration + " 微秒");
    }
}

// 测试类
public class SortComparison {
    public static void main(String[] args) {
        // 准备测试数据
        int[] data = generateRandomArray(10000);
        int[] dataCopy1 = Arrays.copyOf(data, data.length);
        int[] dataCopy2 = Arrays.copyOf(data, data.length);
        int[] dataCopy3 = Arrays.copyOf(data, data.length);

        // 创建排序上下文
        SortContext context = new SortContext();

        // 测试冒泡排序
        context.setStrategy(new BubbleSort());
        context.executeSort(dataCopy1);

        // 测试快速排序
        context.setStrategy(new QuickSort());
        context.executeSort(dataCopy2);

        // 测试归并排序
        context.setStrategy(new MergeSort());
        context.executeSort(dataCopy3);

        // 验证排序结果
        System.out.println("\n验证排序结果是否正确:");
        System.out.println("冒泡排序结果正确: " + isSorted(dataCopy1));
        System.out.println("快速排序结果正确: " + isSorted(dataCopy2));
        System.out.println("归并排序结果正确: " + isSorted(dataCopy3));
    }

    // 生成随机数组
    private static int[] generateRandomArray(int size) {
        int[] array = new int[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(size * 10);
        }
        return array;
    }

    // 验证数组是否已排序
    private static boolean isSorted(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] > array[i + 1]) {
                return false;
            }
        }
        return true;
    }
}