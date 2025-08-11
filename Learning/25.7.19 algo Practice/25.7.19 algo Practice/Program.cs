
//public class MedianFinder
//{
//    int count = 0;
//    PriorityQueue<int, int> minHeap;
//    PriorityQueue<int, int> maxHeap;

//    public MedianFinder()
//    {
//        count = 0;
//        minHeap = new PriorityQueue<int, int>(); // 存较大的一半，堆顶是较小数
//        maxHeap = new PriorityQueue<int, int>(Comparer<int>.Create((a,b) => b.CompareTo(a))); // 存较小的一半，堆顶是较大数
//    }

//    public void AddNum(int num)
//    {
//        count++;
//        if (count % 2 == 0)
//        {   // 偶数
//            minHeap.Enqueue(num, num);
//            int tmp = minHeap.Dequeue();
//            maxHeap.Enqueue(tmp, tmp);
//        }
//        else
//        {  // 奇数
//            maxHeap.Enqueue(num, num);
//            int tmp = maxHeap.Dequeue();
//            minHeap.Enqueue(tmp, tmp);
//        }
//    }

//    public double FindMedian()
//    {
//        if (count % 2 == 0)
//        {
//            return (minHeap.Peek() + maxHeap.Peek()) / 2.0;
//        }
//        else
//        {
//            return minHeap.Peek();
//        }
//    }
//}




//public class TreeNode {
//    public int val;
//    public TreeNode left;
//    public TreeNode right;
//    public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
//        this.val = val;
//        this.left = left;
//        this.right = right;
//    }
//}


//public class Solution
//{
//    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
//    {
//        while (true)
//        {
//            if (root.val > p.val && root.val > q.val)
//            {
//                root = root.left;
//            }
//            else if (root.val < p.val && root.val < q.val)
//            {
//                root = root.right;
//            }
//            else
//            {
//                return root;
//            }
//        }
//    }
//}

//public class Solution
//{
//    Dictionary<int, TreeNode> dic = new Dictionary<int, TreeNode>();
//    HashSet<TreeNode> visited = new HashSet<TreeNode>();
//    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
//    {
//        dfs(root);
//        TreeNode tmp;
//        while (p != root)
//        {
//            visited.Add(p);
//            p = dic[p.val];
//        }
//        while (q != root)
//        {
//            if (visited.Contains(q))
//                return q;
//            q = dic[q.val];
//        }
//        return root;
//    }

//    private void dfs(TreeNode root)
//    { 
//        if (root.left != null)
//        {
//            dic[root.left.val] = root;
//            dfs(root.left);
//        }
//        if (root.right != null)
//        {
//            dic[root.right.val] = root;
//            dfs(root.right);
//        }
//    }
//}

//public class TreeNode
//{
//    public int val;
//    public TreeNode left;
//    public TreeNode right;
//    public TreeNode(int x) { val = x; }
//}

//public class Codec
//{
//    public string serialize(TreeNode root)
//    {
//        List<int> preorder = new List<int>();
//        List<int> inorder = new List<int>();
//        dfs_pre(root, preorder);
//        dfs_in(root, inorder);

//        string preStr = string.Join(",", preorder);
//        string inStr = string.Join(",", inorder);
//        return preStr + "|" + inStr;
//    }

//    public TreeNode deserialize(string data)
//    {
//        string[] parts = data.Split('|');
//        if (parts[0] == "" || parts[1] == "") return null;

//        int[] preorder = Array.ConvertAll(parts[0].Split(',', StringSplitOptions.RemoveEmptyEntries), int.Parse);
//        int[] inorder = Array.ConvertAll(parts[1].Split(',', StringSplitOptions.RemoveEmptyEntries), int.Parse);

//        return BuildTree(preorder, inorder);
//    }

//    private void dfs_pre(TreeNode node, List<int> res)
//    {
//        if (node == null) return;
//        res.Add(node.val);
//        dfs_pre(node.left, res);
//        dfs_pre(node.right, res);
//    }

//    private void dfs_in(TreeNode node, List<int> res)
//    {
//        if (node == null) return;
//        dfs_in(node.left, res);
//        res.Add(node.val);
//        dfs_in(node.right, res);
//    }

//    private TreeNode BuildTree(int[] preorder, int[] inorder)
//    {
//        Dictionary<int, int> inMap = new Dictionary<int, int>();
//        for (int i = 0; i < inorder.Length; i++)
//        {
//            inMap[inorder[i]] = i;
//        }
//        return Build(preorder, 0, preorder.Length - 1, inorder, 0, inorder.Length - 1, inMap);
//    }

//    private TreeNode Build(int[] pre, int preStart, int preEnd, int[] ino, int inStart, int inEnd, Dictionary<int, int> inMap)
//    {
//        if (preStart > preEnd || inStart > inEnd) return null;

//        TreeNode root = new TreeNode(pre[preStart]);
//        // 根节点在中序遍历中的位置
//        int inRoot = inMap[root.val];
//        // 中序遍历之前的都是左子树
//        int numsLeft = inRoot - inStart;

//        root.left = Build(pre, preStart + 1, preStart + numsLeft, ino, inStart, inRoot - 1, inMap);
//        root.right = Build(pre, preStart + numsLeft + 1, preEnd, ino, inRoot + 1, inEnd, inMap);
//        return root;
//    }
//}

//using System.Collections.Generic;

//public class TreeNode
//{
//    public int val;
//    public TreeNode left;
//    public TreeNode right;
//    public TreeNode(int x) { val = x; }
//}

//public class Codec
//{
//    int idx = 0;

//    public string serialize(TreeNode root)
//    {
//        if (root == null) return "";
//        return DFS_encode(root);
//    }


//    public TreeNode deserialize(string data)
//    {
//        idx = 0;
//        return BuildTree(data);
//    }


//    private string DFS_encode(TreeNode node)
//    {
//        if (node == null) return "N,";
//        return node.val + "," + DFS_encode(node.left) + DFS_encode(node.right);
//    }
//    private TreeNode BuildTree(string str)
//    {
//        if (idx >= str.Length) return null;
//        if (str[idx] == 'N')
//        {
//            idx += 2; // 跳过 N,
//            return null;
//        }

//        int num = 0;
//        int sign = 1;
//        while (idx < str.Length)
//        {
//            if (str[idx] == ',') break;
//            if (str[idx] == '-') sign = -1;
//            else
//                num = num * 10 + (str[idx] - '0');
//            idx++;
//        }
//        num *= sign;
//        idx++; // 跳过 ,

//        TreeNode node = new TreeNode(num);
//        node.left = BuildTree(str);
//        node.right = BuildTree(str);

//        return node;
//    }
//}


//class Solotion
//{
//    public void QuickSort(int[] arr, int l, int r)
//    {
//        if (l >= r) return;

//        int k = partition(arr, l, r);

//        QuickSort(arr, l, k - 1);
//        QuickSort(arr, k + 1, r);
//    }

//    private int partition(int[] arr, int l, int r)
//    {
//        int i = l, j = r;
//        while (i < j)
//        {
//            while (i < j && arr[l] <= arr[j]) j--;// 首个小于基准数的索引
//            while (i < j && arr[l] >= arr[i]) i++;// 首个大于基准数的索引
//            swap(arr, i, j);
//        }
//        swap(arr, l, i);
//        return i;
//    }

//    private void swap(int[] arr, int i, int j)
//    {
//        int tmp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = tmp;
//    }
//}


//class Solotion
//{
//    public void MergeSort(int[] arr, int l, int r)
//    {
//        if (l >= r) return;

//        int m = (l + r) / 2;
//        MergeSort(arr, l, m);
//        MergeSort(arr, m + 1, r);

//        int idxL = l;
//        int idxR = m + 1;

//        int[] list = new int[r - l + 1];
//        int idx = 0;
//        while (idxL <= m && idxR <= r)
//        {
//            if (arr[idxL] < arr[idxR])
//            {
//                list[idx++] = arr[idxL++];
//            }
//            else
//            {
//                list[idx++] = arr[idxR++];
//            }
//        }
//        while (idxL <= m)
//        {
//            list[idx++] = arr[idxL++];
//        }
//        while (idxR <= r)
//        {
//            list[idx++] = arr[idxR++];
//        }
//        for (int i = l;i <= r; i++)
//        {
//            arr[i] = list[i - l];
//        }
//    }
//}




//public class Solution
//{
//    public int CountTarget(int[] scores, int target)
//    {
//        int idx = FindNum(scores, target, 0, scores.Length - 1);
//        if (idx == -1) return 0;
//        int count = 1;
//        bool Lfinish = false;
//        bool Rfinish = false;
//        for (int i = 1; ; i++)
//        {
//            if (idx + i < scores.Length)
//            {
//                if (scores[idx + i] == target)
//                    count++;
//            }
//            else 
//                Rfinish = true;
//            if (idx - i >= 0)
//            {
//                if (scores[idx - i] == target)
//                    count++;
//            }
//            else
//                Lfinish = true;
//            if (Lfinish && Rfinish) 
//                break;
//        }
//        return count;
//    }

//    private int FindNum(int[] scores, int target, int l, int r)
//    {
//        if (l > r) return -1;
//        int mid = (l + r) / 2;
//        if (scores[mid] == target)
//        {
//            return mid;
//        }
//        else if (scores[mid] > target)
//        {
//            return FindNum(scores, target, l, mid - 1);
//        }
//        else
//        {
//            return FindNum(scores, target, mid + 1, r);
//        }
//    }
//}


//public class Solution
//{
//    public int TakeAttendance(int[] records)
//    {
//        int len = records.Length;
//        int l = 0, r = len - 1;
//        if (records[0] != 0) return 0;
//        if (records[len - 1] == len - 1) return len;
//        while (l <= r)
//        {
//            int mid = l + (r - l) / 2;
//            if (records[mid] == mid)
//                l = mid + 1;
//            else
//                r = mid - 1;
//        }
//        return l;
//    }
//}

//public class Solution
//{
//    public bool FindTargetIn2DPlants(int[][] plants, int target)
//    {
//        for (int i = 0; i < plants.Length; i++)
//        {
//            for (int j = 0; j < plants[i].Length; j++)
//            {
//                if (plants[i][j] == target)
//                    return true;
//            }
//        }
//        return false;
//    }
//}

//public class Solution
//{
//    public int InventoryManagement(int[] stock)
//    {
//        int tmp = stock[0];
//        for (int i = 0; i < stock.Length; i++)
//        {
//            if (stock[i] < tmp)
//            {
//                return stock[i];
//            }
//            else
//            {
//                tmp = stock[i];
//            }
//        }
//        return stock[0];
//    }
//}

//public class Solution
//{
//    int result;
//    public int MechanicalAccumulator(int target)
//    {
//        bool x = target > 1 && MechanicalAccumulator(target - 1) > 0;
//        result += target;
//    return result;
//    }
//}


//public class Solution
//{
//    public bool WordPuzzle(char[][] grid, string target)
//    {
//        for (int i = 0; i < grid.Length; i++)
//        {
//            for (int j = 0; j < grid[0].Length; j++)
//            {
//                if (dfs(grid, i, j, target, 0)) return true;
//            }
//        }
//        return false;
//    }

//    private bool dfs(char[][] grid, int i, int j, string target, int idx)
//    {
//        if (i < 0 || i >= grid.Length || j < 0 || j >= grid[0].Length || grid[i][j] != target[idx]) return false;
//        if (idx == target.Length - 1) return true;
//        grid[i][j] = ' ';
//        if (dfs(grid, i, j + 1, target, idx + 1) || 
//            dfs(grid, i, j - 1, target, idx + 1) ||
//            dfs(grid, i + 1, j, target, idx + 1) ||
//            dfs(grid, i - 1, j, target, idx + 1))
//        {
//            return true;
//        }
//        grid[i][j] = target[idx];
//        return false;
//    }
//}

//public class Solution
//{
//    public int InventoryManagement(int[] stock)
//    {
//        Dictionary<int, int> dic = new Dictionary<int, int>();
//        int limit = stock.Length / 2;
//        for (int i =0; i < stock.Length; i++)
//        {
//            if (dic.ContainsKey(stock[i]))
//                dic[stock[i]]++;
//            else
//                dic.Add(stock[i], 1);
//            if (dic[stock[i]] > limit)
//                return stock[i];
//        }
//        return -1;
//    }
//}




//public class Solution
//{
//    bool[,] visited;
//    int m, n, cnt;
//    public int WardrobeFinishing(int m, int n, int cnt)
//    {
//        visited = new bool[m, n];
//        this.m = m; this.n = n; this.cnt = cnt;
//        return dfs(0, 0);
//    }

//    private int dfs(int i, int j)
//    {
//        if (i >= m || j >= n || digt(i) + digt(j) > cnt || visited[i, j]) return 0;
//        visited[i, j] = true;
//        return 1 + dfs(i + 1, j) + dfs(i, j + 1);
//    }

//    private int digt(int n)
//    {
//        int num = 0;
//        while (n > 0)
//        {
//            num += n % 10;
//            n /= 10;
//        }
//        return num;
//    }
//}


//public class TreeNode
//{
//    public int val;
//    public TreeNode left;
//    public TreeNode right;
//    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
//    {
//        this.val = val;
//        this.left = left;
//        this.right = right;
//    }
//}
//public class Solution
//{
//    List<IList<int>> res;
//    List<int> list;
//    int target;
//    public IList<IList<int>> PathTarget(TreeNode root, int target)
//    {
//        this.res = new List<IList<int>>();
//        this.list = new List<int>();
//        this.target = target;
//        dfs(root, 0);
//        return res;
//    }

//    private void dfs(TreeNode root, int count)
//    {
//        if (root == null) return;
//        count += root.val;
//        list.Add(root.val);
//        if (count == target)
//        {
//            if (root.left == null && root.right == null)
//            {
//                res.Add(new List<int>(list));
//            }
//        }
//        dfs(root.left, count);
//        dfs(root.right, count);
//        count -= root.val;
//        list.RemoveAt(list.Count - 1);
//    }
//}



//public class Solution
//{
//    char[] list;
//    HashSet<string> set = new HashSet<string>();
//    public string[] GoodsOrder(string goods)
//    {
//        list = goods.ToCharArray();

//        GetStrint(0);
//        return set.ToArray();
//    }

//    /// <summary>
//    /// 递归固定每一位上的字符
//    /// </summary>
//    /// <param name="idx">当前固定哪一位上的字符</param>
//    private void GetStrint(int idx)
//    {
//        set.Add(new string(list));
//        for (int i = idx + 1; i < list.Length; i++)
//        {
//            Swap(idx, i);
//            GetStrint(idx + 1);
//            Swap(idx, i);
//        }
//    }

//    private void Swap(int num, int idx)
//    {
//        char tmp = list[num];
//        list[num] = list[idx];
//        list[idx] = tmp;
//    }
//}


//using System;
//using System.Collections;
//using System.Collections.Generic;
//using System.Diagnostics.Metrics;
//using System.Net.Security;
//using System.Runtime.CompilerServices;
//using System.Runtime.InteropServices;
//using System.Runtime.Intrinsics.Arm;
//using System.Text;
//using System.Xml.Linq;

//public class TreeNode
//{
//    public int val;
//    public TreeNode left;
//    public TreeNode right;
//    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
//    {
//        this.val = val;
//        this.left = left;
//        this.right = right;
//    }
//}

//public class Solution
//{
//    Dictionary<int, int> dic = new Dictionary<int, int>();
//    public TreeNode DeduceTree(int[] preorder, int[] inorder)
//    {
//        int n = inorder.Length;
//        for (int i = 0; i < n; i++)
//        {
//            dic.Add(inorder[i], i);
//        }
//        return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
//    }

//    private TreeNode buildTree(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd)
//    { 
//        if (preStart > preEnd || inStart > inEnd) return null;

//        // 根节点索引
//        int idx = dic[preorder[preStart]];
//        TreeNode node = new TreeNode(inorder[idx]);
//        // 左子树节点数量
//        int sun_node_num = idx - inStart;

//        node.left = buildTree(preorder, preStart + 1, preStart + sun_node_num, inorder, inStart, idx - 1);
//        node.right = buildTree(preorder, preStart + 1 + sun_node_num, preEnd, inorder, idx + 1, inEnd);

//        return node;
//    }
//}

//public class Solution
//{
//    public bool VerifyTreeOrder(int[] postorder)
//    {
//        // 后序遍历的根节点在最后
//        return Verify(postorder, 0, postorder.Length - 1);
//    }

//    /// <summary>
//    /// 判断节点n的左子树和右子树是否满足二叉搜索树的定义
//    /// </summary>
//    /// <param name="postorder">后序遍历</param>
//    /// <param name="n">当前判断的根节点</param>
//    /// <param name="left">当前树的左边界</param>
//    private bool Verify(int[] postorder, int left, int right)
//    {
//        if (right <= left) return true;
//        int val = postorder[right];
//        int boundary = left;// 边界（右子树的开始）
//        while (boundary < right && postorder[boundary] < val)
//        {
//            boundary++;
//        }
//        for (int i = boundary; i < right; i++)
//        {
//            if (postorder[i] < val)
//            {
//                return false;
//            }
//        }
//        return Verify(postorder, left, boundary - 1) && Verify(postorder, boundary, right - 1);
//    }
//}

//public class Solution
//{
//    public double MyPow(double x, int n)
//    {
//        /*当 n 是 -2147483648 时，-n 仍然是 -2147483648
//         * 因为 int 的范围是 -2147483648 到 2147483647
//         * 无法表示 2147483648
//         */
//        long N = n; // 转换为 long 避免溢出
//        if (N == 0) return 1;
//        if (N < 0)
//        {
//            x = 1 / x;
//            N = -N; 
//        }
//        return N % 2 == 0 ? MyPow(x * x, (int)(N / 2)) : x * MyPow(x * x, (int)(N / 2));
//    }
//}

//public class Solution
//{
//    public int[] CountNumbers(int cnt)
//    {
//        int[] res = new int[(int)Math.Pow(10, cnt) - 1];
//        for (int i = 0; i < (int)(Math.Pow(10, cnt) - 1); i++)
//        {
//            res[i] = i + 1;
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int[] InventoryManagement(int[] stock, int cnt)
//    {
//        if (cnt <= 0 || stock.Length == 0) return new int[0];
//        PriorityQueue<int, int> priorityQueue = new PriorityQueue<int, int>();
//        for (int i = 0; i < stock.Length; i++)
//        {
//            priorityQueue.Enqueue(stock[i], stock[i]);
//        }
//        int[] res = new int[cnt];
//        for (int i = 0; i < cnt; i++)
//        {
//            res[i] = priorityQueue.Dequeue();
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int[] InventoryManagement(int[] stock, int cnt)
//    {
//        if (cnt <= 0 || stock.Length == 0) return new int[0];
//        PriorityQueue<int, int> priorityQueue = new PriorityQueue<int, int>();
//        for (int i = 0; i < stock.Length; i++)
//        {
//            priorityQueue.Enqueue(stock[i], stock[i]);
//        }
//        int[] res = new int[cnt];
//        for (int i = 0; i < cnt; i++)
//        {
//            res[i] = priorityQueue.Dequeue();
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int ReversePairs(int[] record)
//    {
//        int count = 0;
//        for (int i = 0; i < record.Length; i++)
//        {
//            for (int j = i + 1;j < record.Length; j++)
//            {
//                if (record[i] > record[j])
//                {
//                    count++;
//                }
//            }
//        }
//        return count;
//    }
//}

//public class Solution
//{
//    int count;
//    int[] tmp;
//    public int ReversePairs(int[] record)
//    {
//        count = 0;
//        tmp = new int[record.Length];
//        MargeSort(record, 0, record.Length - 1);
//        return count;
//    }

//    private void MargeSort(int[] record, int left, int right)
//    {
//        if (right <= left) return;

//        int mid = left + (right - left) / 2;
//        MargeSort(record, left, mid);
//        MargeSort(record, mid + 1, right);

//        int i = left, j = mid + 1;
//        for (int k = left; k <= right; k++)
//        {
//            tmp[k] = record[k];
//        }
//        for (int k = left; k <= right; k++)
//        {
//            if (i == mid + 1)
//                record[k] = tmp[j++];
//            else if (j == right + 1 || tmp[i] <= tmp[j])
//                record[k] = tmp[i++];
//            else
//            {
//                record[k] = tmp[j++];
//                // 统计逆序对 从i到mid的元素都小于元素j
//                count += mid - i + 1;
//            }
//        }
//    }
//}

//public class Solution
//{
//    public int Fib(int n)
//    {
//        if (n <= 1) return n;
//        long[] dp = new long[n + 1];
//        dp[0] = 0;
//        dp[1] = 1;
//        for (int i = 2; i <= n; i++)
//        {
//            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
//        }
//        return (int)dp[n];
//    }
//}

//public class Solution
//{
//    public int TrainWays(int num)
//    {
//        if (num <= 1) return 1;
//        long[] dp = new long[num + 1];
//        dp[0] = 1;
//        dp[1] = 1;
//        for (int i = 2; i <= num; i++)
//        {
//            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
//        }
//        return (int)dp[num];
//    }
//}

//public class Solution
//{
//    public int MaxSales(int[] sales)
//    {
//        int res = sales[0];
//        for (int j = 1; j < sales.Length; j++)
//        {
//            sales[j] = Math.Max(sales[j], sales[j] + sales[j - 1]);
//            res = Math.Max(res, sales[j]);
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int BestTiming(int[] prices)
//    {
//        if (prices.Length <= 1) return 0;
//        int minNum = prices[0];
//        int best = 0;
//        for (int i = 1; i <  prices.Length; i++)
//        {
//            int v = prices[i] - minNum;
//            minNum = Math.Min(minNum, prices[i]);
//            best = Math.Max(best, v);
//        }
//        return best;
//    }
//}

//public class Solution
//{
//    public int JewelleryValue(int[][] frame)
//    {
//        int[] dp = new int[frame[0].Length];

//        for (int i = 0; i < frame.Length; i++)
//        {
//            dp[0] = frame[i][0] + dp[0];
//            for (int j = 1; j < frame[i].Length; j++)
//            {
//                dp[j] = frame[i][j] + Math.Max(dp[j], dp[j - 1]);
//            }
//        }
//        return dp[frame[0].Length - 1];
//    }
//}

//public class Solution
//{
//    public int CrackNumber(int ciphertext)
//    {
//        char[] arr = ciphertext.ToString().ToArray();
//        if (arr.Length <= 1) return 1;
//        int[] dp = new int[ciphertext.ToString().Length + 1];
//        dp[0] = 1;
//        dp[1] = 1;
//        for (int i = 1; i < arr.Length; i++)
//        {
//            if (arr[i] - '0' + (arr[i - 1] - '0') * 10 <= 25 && arr[i - 1] != '0')
//                dp[i + 1] = dp[i] + dp[i - 1];
//            else
//                dp[i + 1] = dp[i];
//        }
//        return dp[arr.Length];
//    }
//}

//public class Solution
//{
//    public int DismantlingAction(string arr)
//    {
//        int n = arr.Length, max = 1;
//        if (n <= 1) return n;
//        int[] dp = new int[n];
//        Dictionary<char, int> dic = new Dictionary<char, int>();
//        dp[0] = 1;
//        dic.Add(arr[0], 0);
//        for(int i = 1; i < n; i++)
//        {
//            if (dic.ContainsKey(arr[i]))
//            {
//                if (dp[i - 1] > i - dic[arr[i]] - 1)
//                    dp[i] = i - dic[arr[i]];
//                else
//                    dp[i] = dp[i - 1] + 1;
//                dic[arr[i]] = i;
//            }
//            else
//            {
//                dp[i] = dp[i - 1] + 1;
//                dic.Add(arr[i], i);
//            }
//            max = Math.Max(max, dp[i]);
//        }
//        return max;
//    }
//}


//public class Solution
//{
//    public int NthUglyNumber(int n)
//    {
//        int[] dp = new int[n];
//        dp[0] = 1;
//        int a = 0, b = 0, c = 0;
//        for (int i = 1; i < n; i++)
//        {
//            dp[i] = Math.Min(dp[a] * 2, Math.Min(dp[b] * 3, dp[c] * 5));
//            if (dp[a] * 2 == dp[i]) a++;
//            if (dp[b] * 3 == dp[i]) b++;
//            if (dp[c] * 5 == dp[i]) c++;
//        }
//        return dp[n - 1];
//    }
//}


//public class Solution
//{
//    public double[] StatisticsProbability(int num)
//    {
//        double[] dp = new double[6];
//        Array.Fill(dp, 1.0 / 6);
//        for (int i = 2; i <= num; i++)
//        {
//            double[] tmp = new double[i * 5 + 1];
//            for (int j = 0; j < (i - 1) * 5 + 1; j++)
//            {
//                for (int k = 0; k < 6; k++)
//                {
//                    tmp[j + k] += dp[j] / 6.0;
//                }
//            }
//            dp = tmp;
//        }
//        return dp;
//    }
//}

//public class Solution
//{
//    public bool ArticleMatch(string s, string p)
//    {
//        int a = s.Length + 1, b = p.Length + 1;
//        bool[,] dp = new bool[a,b];
//        dp[0, 0] = true;
//        for (int i = 2; i < b; i += 2)
//        {
//            if (p[i - 1] == '*' && dp[0, i - 2])
//                dp[0, i] = true;
//        }
//        for (int i = 1; i < a; i++)
//        {
//            for (int j = 1; j < b; j++)
//            {
//                if (p[j - 1] == '*')
//                {
//                    if (dp[i, j - 2] || (dp[i - 1, j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')))
//                        dp[i, j] = true;
//                }
//                else
//                {
//                    if (dp[i - 1, j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
//                        dp[i, j] = true;
//                }
//            }
//        }
//        return dp[a - 1, b - 1];
//    }
//}

//public class Solution
//{
//    public bool CheckDynasty(int[] places)
//    {
//        int count = 0;
//        int num = 0;
//        Array.Sort(places);
//        for(int i = 0; i < 5; i++)
//        {
//            if (places[i] == 0)
//                count++;
//            else
//            {
//                if (num == 0)
//                    num = places[i];
//                else if (places[i] <= num)
//                    return false;
//                else
//                {
//                    count -= places[i] - num - 1;
//                }
//                num = places[i];
//            }
//        }
//        return count >= 0;
//    }
//}

//public class Solution
//{
//    public string CrackPassword(int[] password)
//    {
//        string[] list = new string[password.Length];
//        for (int i = 0; i < password.Length; i++)
//        {
//            list[i] = password[i].ToString();
//        }
//        Array.Sort(list, (x, y) => ((x + y).CompareTo(y + x)));
//        return string.Join("", list);
//    }
//}

//public class Solution
//{
//    public int CuttingBamboo(int bamboo_len)
//    {
//        if (bamboo_len <= 3) return bamboo_len - 1;
//        long count = 1;
//        while (bamboo_len > 4)
//        {
//            bamboo_len -= 3;
//            count = (count * 3) % 1000000007;
//        }
//        count = (count * bamboo_len) % 1000000007;
//        return (int)count;
//    }
//}

//public class Solution
//{
//    public int HammingWeight(uint n)
//    {
//        int res = 0;
//        while (n > 0)
//        {
//            if ((n & 1) == 1)
//                res++;
//            n >>= 1;
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int EncryptionCalculate(int dataA, int dataB)
//    {   // 分别计算无进位和与进位 直到进位为0
//        return dataB == 0 ? dataA : EncryptionCalculate(dataA ^ dataB, (dataA & dataB) << 1);
//    }
//}

//public class Solution
//{
//    public int[] SockCollocation(int[] sockets)
//    {
//        int num = 0;
//        for (int i = 0; i < sockets.Length; i++)
//        {
//            num ^= sockets[i];
//        }
//        int m = 1;
//        while (true)
//        {
//            if ((num & m) == m)
//                break;
//            m <<= 1;
//        }
//        int a = 0;
//        int b = 0;
//        for (int i = 0; i < sockets.Length; i++)
//        {
//            if ((m & sockets[i]) == m) a ^= sockets[i];
//            else b ^= sockets[i];
//        }
//        return new int[] { a, b };
//    }
//}

//public class Solution
//{
//    public int TrainingPlan(int[] actions)
//    {
//        int[] count = new int[32];
//        for (int i = 0; i < actions.Length; i++)
//        {
//            for (int j = 0; j < 32; j++)
//            {
//                count[j] += actions[i] & 1;
//                actions[i] >>= 1;
//                count[j] %= 3;
//            }
//        }
//        int res = 0;
//        for (int i = 31; i >= 0; i--)
//        {
//            res <<= 1;
//            res |= count[i];
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int[] TwoSum(int[] price, int target)
//    {
//        Dictionary<int, int> dic = new Dictionary<int, int>();
//        for (int i = 0; i < price.Length; i++)
//        {
//            if (dic.ContainsKey(target - price[i]))
//            {
//                return new int[] { price[i], target - price[i] };
//            }
//            else
//            {
//                dic[price[i]] = i;
//            }
//        }
//        return new int[] { -1, -1 };
//    }
//}

//public class Solution
//{
//    public int DigitOneInNumber(int num)
//    {
//        int digit = 1, res = 0;
//        int high = num / 10, cur = num % 10, low = 0;
//        while (high > 0 || cur > 0)
//        {
//            if (cur == 0) res += high * digit;
//            else if (cur == 1) res += high * digit + (low + 1);
//            else res += (high + 1) * digit;

//            low += cur * digit;
//            cur  = high % 10;
//            high /= 10;
//            digit *= 10;
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int FindKthNumber(int k)
//    {
//        int digit = 1;
//        int limit = (int)(9 * digit * Math.Pow(10, digit - 1));
//        while (k > limit)
//        {
//            k -= limit;
//            digit++;
//            limit = (int)(9 * digit * Math.Pow(10, digit - 1));
//        }
//        int wei = k % digit;
//        int no = k / digit;
//        int num;
//        if (wei == 0)
//            num = (int)(Math.Pow(10, digit - 1) + no - 1);
//        else
//        {
//            num = (int)(Math.Pow(10, digit - 1) + no);
//            for (int i = 0; i < digit - wei; i++)
//                num /= 10;
//        }
//        return num % 10;
//    }
//}

//public class Solution
//{
//    public int IceBreakingGame(int num, int target)
//    {
//        int x = 0;
//        for (int i = 2; i <= num; i++)
//        {
//            x = (x + target) % i;
//        }
//        return x;
//    }
//}

//public class Solution
//{
//    public IList<IList<string>> GroupAnagrams(string[] strs)
//    {
//        Dictionary<string, List<string>> dic = new Dictionary<string, List<string>>();
//        foreach (string str in strs)
//        {
//            char[] cha = str.ToCharArray();
//            Array.Sort(cha);
//            string key =  new string(cha);
//            List<string> strings = dic.TryGetValue(key, out List<string> list) ? list : new List<string>();
//            strings.Add(str);
//            dic[key] = strings;
//        }
//        return new List<IList<string>>(dic.Values);
//    }
//}

//public class Solution
//{
//    public class Pair
//    {
//        public int first;
//        public int second;
//        public Pair(int first, int second)
//        {
//            this.first = first;
//            this.second = second;
//        }
//    }
//    public int LongestConsecutive(int[] nums)
//    {
//        Dictionary<int, Pair> dic = new Dictionary<int, Pair>();
//        int maxLength = 0;
//        foreach (int num in nums)
//        {
//            Pair pair;
//            if (dic.ContainsKey(num))
//                continue;
//            else
//            {
//                int l = num, r = num;
//                if (dic.ContainsKey(num - 1)) l = dic[num - 1].first;
//                if (dic.ContainsKey(num + 1)) r = dic[num + 1].second;
//                pair = new Pair(l, r);
//                dic[r] = pair;
//                dic[l] = pair;
//            }
//            dic[num] = pair;
//            maxLength = Math.Max(maxLength, pair.second - pair.first + 1);
//        }
//        return maxLength;
//    }
//}

//public class Solution
//{
//    public void MoveZeroes(int[] nums)
//    {
//        int lastNonZero = 0;

//        for (int i = 0; i < nums.Length; i++)
//        {
//            if (nums[i] != 0)
//            {
//                nums[lastNonZero++] = nums[i];
//            }
//        }

//        for (int i = lastNonZero; i < nums.Length; i++)
//        {
//            nums[i] = 0;
//        }
//    }
//}

//public class Solution
//{
//    public int MaxArea(int[] height)
//    {
//        int l = 0, r = height.Length - 1;
//        int max = 0;
//        while (l < r)
//        {
//            int area = Math.Min(height[l], height[r]) * (r - l);
//            max = Math.Max(max, area);
//            if (height[l] < height[r])
//                l++;
//            else
//                r--;
//        }
//        return max;
//    }
//}

//public class Solution
//{
//    public IList<IList<int>> ThreeSum(int[] nums)
//    {
//        Dictionary<int, List<int>> dic = new Dictionary<int, List<int>>();
//        List<IList<int>> result = new List<IList<int>>();
//        for (int i = 0; i < nums.Length; i++)
//        {
//            List<int> list = dic.TryGetValue(nums[i], out list) ? list : new List<int>();
//            list.Add(i);
//            dic[nums[i]] = list;
//        }
//        for (int i = 0; i < nums.Length; i++)
//        {
//            for (int j = i + 1; j < nums.Length; j++)
//            {
//                int target = -nums[i] - nums[j];
//                if (!dic.TryGetValue(target, out List<int> list)) continue;
//                else
//                {
//                    foreach (var idx in list)
//                    {
//                        if (idx < j) continue;
//                        List<int> values = new List<int>() { nums[i], nums[j], nums[idx] };
//                        values.Sort();
//                        result.Add(values);
//                        break;
//                    }
//                }
//            }
//        }
//        return result;
//    }
//}


//public class Solution
//{
//    public IList<IList<int>> ThreeSum(int[] nums)
//    {
//        IList<IList<int>> result = new List<IList<int>>();
//        Array.Sort(nums); // 先排序

//        for (int i = 0; i < nums.Length - 2; i++)
//        {
//            if (i > 0 && nums[i] == nums[i - 1]) // 跳过重复的i
//                continue;
//            int left = i + 1;
//            int right = nums.Length - 1;
//            int target = -nums[i];
//            while (left < right)
//            {
//                int sum = nums[left] + nums[right];
//                if (sum == target)
//                {
//                    result.Add(new List<int> { nums[i], nums[left], nums[right] });
//                    // 跳过重复的left和right
//                    while (left < right && nums[left] == nums[left + 1]) left++;
//                    while (left < right && nums[right] == nums[right - 1]) right--;
//                    left++;
//                    right--;
//                }
//                else if (sum < target) left++;
//                else right--;
//            }
//        }
//        return result;
//    }
//}

//public class Solution
//{
//    public int Trap(int[] height)
//    {
//        int n = height.Length;
//        if (n == 0) return 0;
//        int[] leftMax = new int[n];
//        leftMax[0] = height[0];
//        for (int i = 1; i < n; ++i)
//            leftMax[i] = Math.Max(leftMax[i - 1], height[i]);
//        int[] rightMax = new int[n];
//        rightMax[n - 1] = height[n - 1];
//        for (int i = n - 2; i >= 0; --i)
//            rightMax[i] = Math.Max(rightMax[i + 1], height[i]);
//        int ans = 0;
//        for (int i = 0; i < n; ++i)
//            ans += Math.Min(leftMax[i], rightMax[i]) - height[i];
//        return ans;
//    }
//}


//public class Solution
//{
//    public int LengthOfLongestSubstring(string s)
//    {
//        Dictionary<char, int> dic = new Dictionary<char, int>();
//        int max = 0, curLength = 0, cutIdx = 0;
//        for (int i = 0; i < s.Length; i++)
//        {
//            if (!dic.ContainsKey(s[i]))
//            {
//                curLength++;
//                max = Math.Max(max, curLength);
//                dic.Add(s[i], i);
//            }
//            else
//            {
//                cutIdx = Math.Max(cutIdx, dic[s[i]]);
//                curLength = i - cutIdx;
//                max = Math.Max(max, curLength);
//                dic[s[i]] = i;
//            }
//        }
//        return max;
//    }
//}


//public class Solution
//{
//    public IList<int> FindAnagrams(string s, string p)
//    {
//        if (s.Length < p.Length) return new List<int>();
//        List<int> result = new List<int>();
//        char[] arr1 = s.ToCharArray();
//        char[] arr2 = p.ToCharArray();
//        int[] arr1count = new int[26];
//        int[] arr2count = new int[26];
//        int len = arr2.Length;
//        for (int i = 0; i < len; i++)
//        {
//            arr2count[arr2[i] - 'a']++;
//            if (i == len - 1) continue;
//            arr1count[arr1[i] - 'a']++;
//        }
//        for (int i = len - 1; i < arr1.Length; i++)
//        {
//            arr1count[arr1[i] - 'a']++;
//            if (yiyang(arr1count, arr2count))
//                result.Add(i - len + 1);
//            arr1count[arr1[i - len + 1] - 'a']--;
//        }
//        return result;
//    }

//    private bool yiyang(int[] tmp, int[] arr2)
//    {
//        for (int i = 0; i < 26; i++)
//        {
//            if (tmp[i] != arr2[i])
//                return false;
//        }
//        return true;
//    }
//}

//public class Solution
//{
//    public int SubarraySum(int[] nums, int k)
//    {
//        Dictionary<int, int> dic = new Dictionary<int, int>();
//        dic.Add(0, 1);
//        int num = 0, result = 0;
//        for (int i = 0; i < nums.Length; i++)
//        {
//            num += nums[i];
//            if (dic.ContainsKey(num - k))
//            {
//                result += dic[num - k];
//            }
//            if (dic.ContainsKey(num))
//            {
//                dic[num]++;
//            }
//            else
//            {
//                dic.Add(num, 1);
//            }
//        }
//        return result;
//    }
//}

// 解题关键是每次移动窗口，不知道被移除的数字是不是当前的最大数字，所以维护第一第二大的数字
// 如果最大的数字被移除了，则将第二大的数字作为新的最大数字
//public class Solution
//{
//    public int[] MaxSlidingWindow(int[] nums, int k)
//    {
//        LinkedList<int> list = new LinkedList<int>();
//        int[] res = new int[nums.Length - k + 1];

//        for (int i = 0; i < k; i++)// 初始化窗口
//        {
//            while (list.Count > 0 && nums[i] > list.Last.Value)
//                list.RemoveLast();
//            list.AddLast(nums[i]);
//        }
//        res[0] = list.First.Value;
//        for (int i = k; i < nums.Length ; i++)
//        {
//            // 移动窗口
//            if (nums[i - k] == list.First.Value)
//                list.RemoveFirst();
//            while (list.Count > 0 && nums[i] > list.Last.Value)
//                list.RemoveLast();
//            list.AddLast(nums[i]);
//            res[i - k + 1] = list.First.Value;
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public string MinWindow(string s, string t)
//    {
//        if (string.IsNullOrEmpty(s) || string.IsNullOrEmpty(t) || t.Length > s.Length)
//            return "";

//        Dictionary<char, int> need = new Dictionary<char, int>();
//        Dictionary<char, int> window = new Dictionary<char, int>();
//        for (int i = 0; i < t.Length; i++)
//        {
//            if (!need.ContainsKey(t[i])) need[t[i]] = 0;
//            need[t[i]]++;
//        }

//        int l = 0, r = 0;
//        int valid = 0;// 用来记录窗口中匹配的字符个数
//        int start = 0, minLen = int.MaxValue;

//        while (r < s.Length)
//        {
//            char c = s[r++];

//            if (need.ContainsKey(c))
//            { 
//                if (!window.ContainsKey(c)) window[c] = 0;
//                window[c]++;
//                if (window[c] == need[c]) valid++;
//            }
//            while (valid == need.Count) //  窗口中匹配的字符个数等于t中字符个数时，开始收缩窗口
//            { 
//                if (minLen > r - l)// 更新返回字符串范围
//                {
//                    minLen = r - l;
//                    start = l;
//                }
//                char d = s[l++];// 收缩窗口被删除的字符
//                if (need.ContainsKey(d))
//                {
//                    window[d]--;
//                    if (window[d] < need[d]) valid--;
//                }
//            }
//        }

//        return minLen == int.MaxValue ? "" : s.Substring(start, minLen); ;
//    }
//}

//public class Solution
//{
//    public int MinSubArrayLen(int target, int[] nums)
//    {
//        int res = 0;
//        int l = 0, r = 0;
//        int count = nums[l];
//        while (r < nums.Length)
//        {
//            if (count >= target)
//                if (res == 0 || res > r - l + 1)
//                    res = r - l + 1;
//            if (count < target)
//            {
//                r++;
//                if (r < nums.Length)
//                    count += nums[r];
//            }
//            else
//            {
//                count -= nums[l];
//                l++;
//            }
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int MaxSubArray(int[] nums)
//    {
//        int len = nums.Length;
//        int max = nums[0];
//        for (int i = 1; i < len; i++)
//        {
//            nums[i] = Math.Max(nums[i - 1] + nums[i], nums[i]);
//            max = Math.Max(max, nums[i]);
//        }
//        return max;
//    }
//}


//public class Solution
//{
//    public int[][] Merge(int[][] intervals)
//    {
//        int len = intervals.Length;
//        int[] left = new int[len];
//        int[] right = new int[len];
//        HashSet<string> set = new HashSet<string>();
//        List<int[]> result = new List<int[]>();
//        for (int i = 0; i < len; i++)
//        {
//            left[i] = intervals[i][0];
//            right[i] = intervals[i][1];
//        }
//        for (int i = 0; i < len; i++)
//        {
//            for (int j = i + 1; j < len; j++)
//            {
//                if (left[i] <= right[j] && left[i] >= left[j])
//                {
//                    left[i] = left[j];
//                    right[j] = Math.Max(right[j], right[i]);
//                    right[i] = right[j];
//                }
//                if (right[i] >= left[j] && right[i] <= right[j])
//                {
//                    right[i] = right[j];
//                    left[j] = Math.Min(left[j], left[i]);
//                    left[i] = left[j];
//                }
//            }
//        }
//        for (int i = 0; i < len; i++)
//        {
//            string key = left[i] + "," + right[i];
//            if (set.Add(key)) // 如果添加成功说明没重复
//            {
//                result.Add(new int[] { left[i], right[i] });
//            }
//        }
//        return result.ToArray();
//    }
//}

//public class Solution
//{
//    public int[][] Merge(int[][] intervals)
//    {
//        if (intervals == null || intervals.Length == 0)
//            return new int[0][];

//        // 先按左边界排序
//        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));

//        List<int[]> result = new List<int[]>();
//        int[] current = intervals[0];

//        foreach (int[] interval in intervals)
//        {
//            if (interval[0] <= current[1])
//            {
//                // 有重叠，合并
//                current[1] = Math.Max(current[1], interval[1]);
//            }
//            else
//            {
//                // 无重叠，保存当前，开始新的一段
//                result.Add(current);
//                current = interval;
//            }
//        }
//        // 添加最后一段
//        result.Add(current);

//        return result.ToArray();
//    }
//}


//public class Solution
//{
//    public void Rotate(int[] nums, int k)
//    {
//        solotion2(nums, k);
//    }

//    private void solotion1(int[] nums, int k)
//    {
//        int current = 0, tmp1, tmp2, len = nums.Length, target;
//        int count = 0;// 移动的数字个数
//        int start = 0;
//        while (count < len)
//        {
//            current = start % len;
//            tmp1 = nums[current];
//            do
//            {
//                target = (current + k) % len;
//                tmp2 = nums[target];
//                nums[target] = tmp1;
//                tmp1 = tmp2;
//                current = (current + k) % len;
//                count++;
//            }while (current != start);
//            start++;
//        }
//    }

//    private void solotion2(int[] nums, int k)
//    {

//    }
//}


//public class Solution
//{
//    public int[] ProductExceptSelf(int[] nums)
//    {
//        int len = nums.Length;
//        int[] res = new int[len];
//        int l = 1, r = 1;
//        for (int i = 0; i < len; i++)
//        {
//            res[i] = l;
//            l *= nums[i];
//        }
//        for (int i = len - 1; i >= 0; i--)
//        {
//            res[i] *= r;
//            r *= nums[i];
//        }
//        return res;
//    }
//}

//public class Solution
//{
//    public int FirstMissingPositive(int[] nums)
//    {
//        int i;
//        for (i = 0; i < nums.Length; i++)
//        {
//            while (nums[i] != i + 1 && nums[i] > 0)
//            {
//                if (nums[i] > 0)
//                {
//                    if (nums[i] > nums.Length)
//                        nums[i] = -1;
//                    else
//                    {
//                        int temp = nums[i];
//                        nums[i] = nums[temp - 1];
//                        nums[temp - 1] = temp;
//                        if (nums[i] == nums[temp - 1])
//                            nums[i] = -1;
//                    }
//                }
//                else
//                    nums[i] = -1;
//            }
//        }
//        for (i = 0; i < nums.Length; i++)
//        {
//            if (nums[i] <= 0)
//                return i + 1;
//        }
//        return i + 1;
//    }
//}


//public class Solution
//{
//    public IList<int> SpiralOrder(int[][] matrix)
//    {
//        List<int> res = new List<int>();
//        int left = 0, right = matrix[0].Length - 1, top = 0, bottom = matrix.Length - 1;
//        while (true)
//        {
//            for (int i = left; i <= right; i++)
//            {
//                res.Add(matrix[top][i]);
//            }
//            top++;
//            if (top > bottom) break;
//            for (int i = top; i <= bottom; i++)
//            {
//                res.Add(matrix[i][right]);
//            }
//            right--;
//            if (right < left) break;
//            for (int i = right; i >= left; i--)
//            {
//                res.Add(matrix[bottom][i]);
//            }
//            bottom--;
//            if (bottom < top) break;
//            for (int i = bottom; i >= top; i--)
//            {
//                res.Add(matrix[i][left]);
//            }
//            left++;
//            if (left > right) break;
//        }
//        return res;
//    }
//}


//public class Solution
//{
//    public void Rotate(int[][] matrix)
//    {
//        int n = matrix.Length;
//        int level = 0;
//        int tmp;
//        for (int i = 0; i < n / 2; i++)
//        {
//            for ( int j = 0 + level; j < n - 1 - i; j++)
//            {
//                tmp = matrix[j][n - 1 - level];// 右上 
//                matrix[j][n - 1 - level] = matrix[level][j];// 左上
//                matrix[level][j] = matrix[n - 1 - j][level];//左下
//                matrix[n - 1 - j][level] = matrix[n - 1 - level][n - 1 - j];//右下
//                matrix[n - 1 - level][n - 1 - j] = tmp;
//            }
//            level++;
//        }
//    }
//}

//public class Solution
//{
//    public bool SearchMatrix(int[][] matrix, int target)
//    {
//        int m = matrix.Length, n = matrix[0].Length;
//        int i = 0, j = n - 1;
//        while (i <= m - 1 && j >= 0)
//        {
//            if (matrix[i][j] == target) return true;
//            else if (matrix[i][j] > target) j--;
//            else i++;
//        }
//        return false;
//    }
//}



//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int x) { val = x; }
//}

//public class Solution
//{
//    public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
//    {
//        ListNode A = headA;
//        ListNode B = headB;
//        while (A != B)
//        {
//            A = A == null ? headB : A.next;
//            B = B == null ? headA : B.next;
//        }
//        return A;
//    }
//}

//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int val = 0, ListNode next = null)
//    {
//        this.val = val;
//        this.next = next;
//    }
//}

//public class Solution
//{
//    public ListNode ReverseList(ListNode head)
//    {
//        ListNode A = null;
//        ListNode B = new ListNode();
//        while (head != null)
//        {
//            B = head.next;
//            head.next = A;
//            A = head;
//            head = B;
//        }
//        return A;
//    }
//}

//public class Solution
//{
//    public bool IsPalindrome(ListNode head)
//    {
//        List<int> list = new List<int>();
//        while (head != null)
//        {
//            list.Add(head.val);
//            head = head.next;
//        }
//        for (int i = 0; i < list.Count / 2; i++)
//        {
//            if (list[i] != list[list.Count - 1 - i])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//}

//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int x)
//    {
//        val = x;
//        next = null;
//    }
//}
//public class Solution
//{
//    public bool HasCycle(ListNode head)
//    {
//        if (head == null || head.next == null)
//        {
//            return false;
//        }
//        ListNode slow = head;
//        ListNode fast = head.next;
//        while (slow != fast)
//        {
//            if (fast == null || fast.next == null)
//            {
//                return false;
//            }
//            slow = slow.next;
//            fast = fast.next.next;
//        }
//        return true;
//    }
//}

//public class Solution
//{
//    //public ListNode DetectCycle(ListNode head)
//    //{
//    //    Dictionary<ListNode, ListNode> dic = new Dictionary<ListNode, ListNode>();
//    //    int idx = 0;
//    //    while (head != null)
//    //    {
//    //        if (dic.ContainsKey(head))
//    //            return head;
//    //        else
//    //            dic.Add(head, head);
//    //        head = head.next;
//    //    }
//    //    return null;
//    //}

//    public ListNode DetectCycle(ListNode head)
//    {
//        if (head == null || head.next == null) return null;
//        ListNode slow = head;
//        ListNode fast = head;
//        // 第一阶段：判断是否有环
//        while (fast != null && fast.next != null)
//        {
//            slow = slow.next;
//            fast = fast.next.next;
//            if (slow == fast)
//            {
//                // 第二阶段：找到环的起点
//                fast = head;
//                while (fast != slow)
//                {
//                    fast = fast.next;
//                    slow = slow.next;
//                }
//                return fast;
//            }
//        }
//        return null; // 无环
//    }
//}

//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int val = 0, ListNode next = null)
//    {
//        this.val = val;
//        this.next = next;
//    }
//}

//public class Solution
//{
//    public ListNode MergeTwoLists(ListNode list1, ListNode list2)
//    {
//        if (list1 == null) return list2;
//        else if (list2 == null) return list1;
//        ListNode newhead = new ListNode();
//        ListNode tmp = newhead;
//        while (list1 != null && list2 != null)
//        {
//            if (list1.val < list2.val)
//            {
//                tmp.next = list1;
//                list1 = list1.next;
//            }
//            else
//            {
//                tmp.next = list2;
//                list2 = list2.next;
//            }
//            tmp = tmp.next;
//        }
//        tmp.next = list1 != null ? list1 : list2;
//        return newhead.next;
//    }
//}


//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int val = 0, ListNode next = null)
//    {
//        this.val = val;
//        this.next = next;
//    }
//}

//public class Solution
//{
//    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
//    {
//        bool carry = false;// 进位
//        int sum;
//        ListNode head = new ListNode(), tmp = head;
//        while (l1 != null || l2 != null || carry)// 注意不要忘了进位
//        {
//            sum = 0;
//            if (l1 != null)
//            {
//                sum += l1.val;
//                l1 = l1.next;
//            }
//            if (l2 != null)
//            {
//                sum += l2.val;
//                l2 = l2.next;
//            }
//            if (carry)
//            {
//                sum += 1;
//                carry = false;
//            }
//            if (sum >= 10)
//            {
//                carry = true;
//                sum -= 10;
//            }
//            tmp.next = new ListNode(sum);
//            tmp = tmp.next;
//        }
//        return head.next;
//    }
//}


//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int val = 0, ListNode next = null)
//    {
//        this.val = val;
//        this.next = next;
//    }
//}
//public class Solution
//{
//    public ListNode RemoveNthFromEnd(ListNode head, int n)
//    {
//        ListNode dumpy = new ListNode();
//        dumpy.next = head;

//        ListNode slow = dumpy;
//        ListNode fast = dumpy;

//        for (int i = 0; i < n; i++)
//        {
//            if (fast == null) return dumpy.next;
//            fast = fast.next;
//        }
//        while (fast.next != null)
//        {
//            fast = fast.next;
//            slow = slow.next;
//        }
//        slow.next = slow.next.next;
//        return dumpy.next;
//    }
//}

//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int val = 0, ListNode next = null)
//    {
//        this.val = val;
//        this.next = next;
//    }
//}

//public class Solution
//{
//    public ListNode SwapPairs(ListNode head)
//    {
//        ListNode dumpy = new ListNode();// 假头节点
//        dumpy.next = head;
//        ListNode tmp = dumpy;// 上一组的尾节点

//        while (head != null && head.next != null)
//        {
//            ListNode first = head;
//            ListNode second = head.next;
//            // 跟新节点
//            tmp.next = second;
//            first.next = second.next;
//            second.next = first;
//            // 移动指针
//            tmp = first;
//            head = first.next;
//        }
//        return dumpy.next;
//    }
//}

//public class Solution
//{
//    public ListNode ReverseKGroup(ListNode head, int k)
//    {
//        ListNode dummy = new ListNode(0);
//        dummy.next = head;

//        ListNode pre = dummy;// 标记上一部分的尾结点
//        ListNode end = dummy;// 标记当前部分的尾结点

//        while (end.next != null)
//        {
//            for (int i = 0; i < k && end != null; i++) end = end.next;
//            if (end == null) break;// 剩余不足k个节点，不需要翻转

//            ListNode start = pre.next;// 当前节点的头节点（翻转后的尾节点）
//            ListNode nextPart = end.next;// 下一部分的头结点
//            // 断开当前待翻转的部分，开始翻转
//            end.next = null;
//            pre.next = reverse(start);
//            // 翻转结束 链接三个部分
//            start.next = nextPart;// 链接当前与下一部分
//            // 重置pre 和 end
//            pre = start;
//            end = pre;
//        }
//        return dummy.next;
//    }
//    // 翻转链表 返回值是反转后的头节点
//    private ListNode reverse(ListNode head)
//    {
//        ListNode pre = null;
//        ListNode curr = head;
//        while (curr != null)
//        {
//            ListNode next = curr.next;
//            curr.next = pre;
//            pre = curr;
//            curr = next;
//        }
//        return pre;
//    }
//}

//public class Node
//{
//    public int val;
//    public Node next;
//    public Node random;

//    public Node(int _val)
//    {
//        val = _val;
//        next = null;
//        random = null;
//    }
//}

//public class Solution
//{
//    public Node CopyRandomList(Node head)
//    {
//        if (head == null)
//            return null;
//        Dictionary<Node, Node> dic = new Dictionary<Node, Node>();
//        Node tmp = head;
//        while (tmp != null)
//        {
//            dic[tmp] = new Node(tmp.val);
//            tmp = tmp.next;
//        }
//        tmp = head;
//        while (tmp != null)
//        {
//            if (tmp.next != null) dic[tmp].next = dic[tmp.next];
//            if (tmp.random != null) dic[tmp].random = dic[tmp.random];
//            tmp = tmp.next;
//        }
//        return dic[head];
//    }
//}

//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int val = 0, ListNode next = null)
//    {
//        this.val = val;
//        this.next = next;
//    }
//}

//public class Solution
//{
//    public ListNode SortList(ListNode head)
//    {
//        if (head == null || head.next == null) return head;
//        ListNode slow = head, fast = head.next;
//        while (fast != null && fast.next != null)
//        {
//            slow = slow.next;// 慢指针记录一半的位置
//            fast = fast.next.next;// 快指针试探结束的位置
//        }
//        // 分割链表
//        ListNode flag = slow.next;
//        slow.next = null;

//        ListNode left = SortList(head);
//        ListNode right = SortList(flag);

//        // 合并有序链表
//        ListNode tmp = new ListNode();
//        ListNode dummy = tmp;
//        while (left != null && right != null)
//        {
//            if (left.val < right.val)
//            {
//                tmp.next = left;
//                left = left.next;
//            }
//            else
//            {
//                tmp.next = right;
//                right = right.next;
//            }
//            tmp = tmp.next;
//        }
//        tmp.next = left == null ? right : left;
//        return dummy.next;
//    }
//}

//public class ListNode
//{
//    public int val;
//    public ListNode next;
//    public ListNode(int val = 0, ListNode next = null)
//    {
//        this.val = val;
//        this.next = next;
//    }
//}

//public class Solution
//{
//    public ListNode MergeKLists(ListNode[] lists)
//    {
//        ListNode dummy = new ListNode();
//        ListNode tmp = dummy;
//        int flag; // 下一次链接节点的索引
//        int val; // 下一次链接节点的值
//        while (true)
//        {
//            flag = -1;
//            val = int.MaxValue;
//            for (int i = 0; i < lists.Length; i++)
//            {
//                if (lists[i] != null)
//                {
//                    if (flag == -1 || lists[i].val < val)
//                    {
//                        flag = i;
//                        val = lists[i].val;
//                    }
//                }
//            }
//            if (flag == -1)
//            {   // 没有满足的节点
//                break;
//            }

//            // 更新链表
//            tmp.next = lists[flag];
//            tmp = tmp.next;
//            lists[flag] = lists[flag].next;
//        }
//        return dummy.next;
//    }
//}

//public class LRUCache
//{
//    // 双向链表表示缓存
//    class MyLinkedList
//    {
//        public int key;
//        public int value;
//        public MyLinkedList? pre;
//        public MyLinkedList? next;
//        public MyLinkedList() { }
//        public MyLinkedList(int key, int value)
//        {
//            this.key = key;
//            this.value = value;
//            pre = null;
//            next = null;
//        }
//    }
//    // 字典用来维护值存储在链表上的位置
//    Dictionary<int, MyLinkedList> dic;
//    int size;
//    int capacity;
//    MyLinkedList head, tail;// 定义头尾假节点可以O(1)访问到双向链表的头尾

//    public LRUCache(int capacity)
//    {
//        size = 0;
//        this.capacity = capacity;
//        dic = new Dictionary<int, MyLinkedList>();
//        head = new MyLinkedList();
//        tail = new MyLinkedList();
//        head.next = tail;
//        tail.pre = head;
//    }

//    public int Get(int key)
//    {
//        dic.TryGetValue(key, out MyLinkedList node);
//        if (node == null) return -1;

//        removeNode(node);
//        addNode(node);
//        return node.value;
//    }

//    public void Put(int key, int value)
//    {
//        dic.TryGetValue(key, out MyLinkedList node);
//        if (node == null)// 缓存中没有该节点
//        {
//            node = new MyLinkedList(key, value);
//            dic[key] = node;
//            addNode(node);
//        }
//        else// 缓存中有该节点
//        {
//            node.value = value;
//            removeNode(node);
//            addNode(node);
//        }
//    }
//    // 添加节点时把节点添加到链表头部
//    private void addNode(MyLinkedList node)
//    {
//        node.pre = head;
//        node.next = head.next;
//        head.next.pre = node;
//        head.next = node;
//        size++;
//        if (size > capacity)// 缓存已满，删除尾节点
//        {
//            dic.Remove(tail.pre.key);
//            removeNode(tail.pre);
//        }
//    }
//    // 删除节点
//    private void removeNode(MyLinkedList node)
//    {
//        node.pre.next = node.next;
//        node.next.pre = node.pre;
//        size--;
//    }
//}

//public class TreeNode
//{
//    public int val;
//    public TreeNode left;
//    public TreeNode right;
//    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
//    {
//        this.val = val;
//        this.left = left;
//        this.right = right;
//    }
//}

//public class Solution
//{
//    List<int> list = new List<int>();
//    public IList<int> InorderTraversal(TreeNode root)
//    {
//        dfs(root);
//        return list;
//    }

//    private void dfs(TreeNode root)
//    {
//        if (root == null) return;
//        dfs(root.left);
//        list.Add(root.val);
//        dfs(root.right);
//    }
//}

//public class Solution
//{
//    int maxHeight = 0;
//    int curHeight = 0;
//    public int MaxDepth(TreeNode root)
//    {
//        dfs(root);
//        return maxHeight;
//    }

//    private void dfs(TreeNode root)
//    {
//        if (root == null) return;
//        curHeight++;
//        maxHeight = Math.Max(maxHeight, curHeight);
//        dfs(root.left);
//        dfs(root.right);
//        curHeight--;
//    }
//}

//public class Solution
//{
//    public TreeNode InvertTree(TreeNode root)
//    {
//        dfs(root);
//        return root;
//    }

//    private void dfs(TreeNode root)
//    {
//        if (root == null) return;
//        TreeNode tmp = root.left;
//        root.left = root.right;
//        root.right = tmp;
//        dfs(root.left);
//        dfs(root.right);

//    }
//}

//public class Solution
//{
//    int ans;
//    public int DiameterOfBinaryTree(TreeNode root)
//    {
//        dfs(root);
//        return ans;
//    }

//    // 返回包含root节点的树直径
//    private int dfs(TreeNode root)
//    {
//        if (root == null) return -1;
//        int l = dfs(root.left) + 1;
//        int r = dfs(root.right) + 1;
//        ans = Math.Max(ans, l + r);
//        return Math.Max(l, r);
//    }
//}


//public class Solution
//{
//    public IList<IList<int>> LevelOrder(TreeNode root)
//    {
//        List<IList<int>> reslut = new List<IList<int>>();
//        if (root == null) return reslut;
//        Queue<TreeNode> queue = new Queue<TreeNode>();
//        queue.Enqueue(root);
//        while (queue.Count > 0)
//        {
//            int size = queue.Count;
//            List<int> list = new List<int>(size);
//            for (int i = 0; i < size; i++)
//            {
//                TreeNode node = queue.Dequeue();
//                list.Add(node.val);
//                if (node.left != null)
//                    queue.Enqueue(node.left);
//                if (node.right != null)
//                    queue.Enqueue(node.right);
//            }
//            reslut.Add(list);
//        }
//        return reslut;
//    }
//}










using System.Security.AccessControl;
using System.Text;
using System.Xml.Linq;

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

//public class Solution
//{
//    public TreeNode SortedArrayToBST(int[] nums)
//    {
//        return dfs(nums, 0, nums.Length - 1);
//    }

//    private TreeNode dfs(int[] nums, int v1, int v2)
//    {
//        if (v1 > v2) return null;
//        int mid = (v1 + v2) / 2;
//        TreeNode root = new TreeNode(nums[mid]);
//        root.left = dfs(nums, v1, mid - 1);
//        root.right = dfs(nums, mid + 1, v2);
//        return root;
//    }
//}

//public class Solution
//{
//    bool flag = false;
//    int val;
//    public bool IsValidBST(TreeNode root)
//    {
//        return dfs(root);
//    }

//    private bool dfs(TreeNode root)
//    {
//        if (root == null) return true;
//        return (dfs(root.left) && check(root.val) && dfs(root.right));
//    }

//    private bool check(int val)
//    {
//        if (!flag)
//        {
//            flag = true;
//            this.val = val;
//            return true;
//        }
//        if (val > this.val)
//        {
//            this.val = val;
//            return true;
//        }    
//        return false;
//    }
//}

//public class Solution
//{
//    int count = 0;
//    int res = int.MinValue;
//    public int KthSmallest(TreeNode root, int k)
//    {
//        dfs(root, k);
//        return res;
//    }

//    private void dfs(TreeNode root, int k)
//    {
//        if (root == null) return;

//        dfs(root.left, k);
//        count++;
//        if (count == k)
//        {
//            res = root.val;
//        }
//        dfs(root.right, k);
//    }
//}

//public class Solution
//{
//    public IList<int> RightSideView(TreeNode root)
//    {
//        List<int> result = new List<int>();
//        Queue<TreeNode> queue = new Queue<TreeNode>();
//        if (root == null) return result;
//        queue.Enqueue(root);
//        while (queue.Count > 0)
//        { 
//            int size = queue.Count;
//            TreeNode node;
//            for (int i = 0; i < size - 1; i++)
//            {
//                node = queue.Dequeue();
//                if (node.left != null)
//                {
//                    queue.Enqueue(node.left);
//                }
//                if (node.right != null)
//                {
//                    queue.Enqueue(node.right);
//                }
//            }
//            node  = queue.Dequeue();
//            result.Add(node.val);
//            if (node.left != null)
//            {
//                queue.Enqueue(node.left);
//            }
//            if (node.right != null)
//            {
//                queue.Enqueue(node.right);
//            }
//        }
//        return result;
//    }
//}

//public class Solution
//{
//public void Flatten(TreeNode root)
//{
//    if (root == null) return;
//    Stack<TreeNode> stack = new Stack<TreeNode>();
//    stack.Push(root);
//    TreeNode pre = null;
//    while (stack.Count > 0)
//    {
//        TreeNode tmp = stack.Pop();
//        if (pre != null)
//        {
//            pre.right = tmp;
//            pre.left = null;
//        }
//        if (tmp.right != null)
//        {
//            stack.Push(tmp.right);
//        }
//        if (tmp.left != null)
//        {
//            stack.Push(tmp.left);
//        }
//        pre = tmp;
//    }
//}
//    public void Flatten(TreeNode root)
//    {
//        if (root == null) return;

//        TreeNode cur = root;
//        while (cur != null)
//        {
//            if (cur.left != null)
//            {
//                TreeNode tmp = cur.left;
//                while (tmp.right != null)
//                {
//                    tmp = tmp.right;
//                }
//                tmp.right = cur.right;
//                cur.right = cur.left;
//                cur.left = null;
//            }
//            cur = cur.right;
//        }
//    }
//}

//public class Solution
//{
//    TreeNode last = null;
//    public void Flatten(TreeNode root)
//    {
//        dfs(root);
//    }

//    private void dfs(TreeNode node)
//    {
//        if (node == null) return;

//        dfs(node.right);
//        dfs(node.left);
//        if (last == null)
//            last = node;
//        else
//        {
//            node.right = last;
//            node.left = null;
//            last = node;
//        }
//    }
//}

//public class Solution
//{
//    Dictionary<int, int> dic = new Dictionary<int, int>();
//    public TreeNode BuildTree(int[] preorder, int[] inorder)
//    {
//        for (int i = 0; i < inorder.Length; i++)
//            dic.Add(inorder[i], i);
//        int n = preorder.Length;
//        return dfs(preorder, 0, n - 1, 0, n - 1);
//    }

//    /// <summary>
//    /// 递归构建二叉树
//    /// </summary>
//    /// <param name="preorder">前序遍历（用于获取根节点的值）</param>
//    /// <param name="preL">当前树的前序遍历左界限</param>
//    /// <param name="preR">当前树的前序遍历右界限</param>
//    /// <param name="inoL">当前树的中序遍历左界限</param>
//    /// <param name="inoR">当前树的中序遍历右界限</param>
//    private TreeNode dfs(int[] preorder, int preL, int preR, int inoL, int inoR)
//    {
//        if (preL > preR) return null;
//        TreeNode root = new TreeNode(preorder[preL]);
//        int leftLength = dic[root.val] - inoL;
//        root.left = dfs(preorder, preL + 1, preL + leftLength, inoL, inoL + leftLength - 1);
//        root.right = dfs(preorder, preL + 1 + leftLength, preR, leftLength + inoL + 1, inoR);
//        return root;
//    }
//}

//public class Solution
//{
//    List<long> list = new List<long>();
//    int size = 0;
//    long target;
//    int res = 0;
//    public int PathSum(TreeNode root, int targetSum)
//    {
//        this.target = targetSum;
//        dfs(root);
//        return res;
//    }

//    private void dfs(TreeNode root)
//    {
//        if (root == null) return;
//        size++;
//        list.Add(0);
//        for (int i = 0; i < size; i++)
//        {
//            list[i] += root.val;
//            if (list[i] == target)
//                res++;
//        }
//        dfs(root.left);
//        dfs(root.right);
//        for (int i = 0; i < size; i++)
//        {
//            list[i] -= root.val;
//        }
//        size--;
//    }
//}


//public class Solution
//{
//    // 用来记录每个节点的父节点
//    Dictionary<int, TreeNode> dic = new Dictionary<int, TreeNode>();
//    // 用来记录已经访问过的节点
//    HashSet<int> set = new HashSet<int>();
//    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
//    {
//        dfs(root);
//        while (p != root)
//        {
//            set.Add(p.val);
//            p = dic[p.val];
//        }
//        while (q != root)
//        {
//            if (set.Contains(q.val))
//            {
//                return q;
//            }
//            q = dic[q.val];
//        }
//        return root;
//    }

//    /// <summary>
//    /// 递归每个节点，记录父节点到字典中
//    /// </summary>
//    private void dfs(TreeNode root)
//    {
//        if (root.left != null)
//        {
//            dic[root.left.val] = root;
//            dfs(root.left);
//        }
//        if (root.right != null)
//        {
//            dic[root.right.val] = root;
//            dfs(root.right);
//        }
//    }
//}


//public class Solution
//{
//    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
//    {
//        // 情况1：如果当前节点就是p或者q，那么当前节点就可能是LCA，返回当前节点作为候选LCD返回
//        // 如果当前节点递归到null 则返回null
//        if (root == null || root == p || root == q) return root;

//        // 情况2: 当前节点不是p或者q，则分别递归左右子树
//        // 返回的结果是LCA的候选节点或或null
//        TreeNode left = LowestCommonAncestor(root.left, p, q);
//        TreeNode right = LowestCommonAncestor(root.right, p, q);

//        // 分支1：当前节点的左右节点都返回了候选LCA 
//        // 说明q和p分别位于当前节点的左右子树中, 当前节点就是LCA 直接返回当前节点
//        if (left != null && right != null) 
//            return root;

//        // 分支2：如果发现只有一侧返回了LCA 说明在之前的递归中已经找到了候选LCA 继续向上传递LCA即可
//        // 分支3：如果left和right都为null，说明q和p不在当前节点的树中, 向上传递null
//        return left ?? right;
//        // 上面的写法等价于：
//        // return left == null ? right : left;
//    }
//}

//public class Solution
//{
//    int res = int.MinValue;
//    public int MaxPathSum(TreeNode root)
//    {
//        dfs(root);
//        return res;
//    }

//    /// <summary>
//    /// 返回包含当前节点的一条链的最大路径和
//    /// </summary>
//    private int dfs(TreeNode root)
//    {
//        if (root == null) return 0 ;
//        // 如果子节点的值为正，那么可以加到当前路径中，否则不带这个节点玩
//        // 逻辑参考力扣53题
//        int left = Math.Max(dfs(root.left), 0);
//        int right = Math.Max(dfs(root.right), 0);
//        // 更新最大值
//        res = Math.Max(res, root.val + left + right);
//        // 返回左侧和右侧中较大的一个加上当前节点的值
//        return Math.Max(root.val + left, root.val + right);
//    }
//}

//public class Solution
//{
//    public int NumIslands(char[][] grid)
//    {
//        int res = 0;
//        for (int i = 0; i < grid.Length; i++)
//        {
//            for (int j = 0; j < grid[i].Length; j++)
//            {
//                if (grid[i][j] == '1')
//                {
//                    dfs(grid, i, j);
//                    res++;
//                }
//            }
//        }
//        return res;
//    }

//    private void dfs(char[][] grid, int i, int j)
//    {
//        if (i < 0 || i >= grid.Length || j < 0 || j >= grid[i].Length || grid[i][j] != '1') return;
//        grid[i][j] = '0';
//        dfs(grid, i + 1, j);
//        dfs(grid, i - 1, j);
//        dfs(grid, i, j + 1);
//        dfs(grid, i, j - 1);
//    }
//}

//public class Solution
//{
//    Queue<int[]> queue = new Queue<int[]>();// 腐烂队列
//    int count = 0;// 幸存橘子数
//    public int OrangesRotting(int[][] grid)
//    {
//        int round = 0;// 回合数
//        for (int i = 0; i < grid.Length; i++)
//        {
//            for (int j = 0; j < grid[i].Length; j++)
//            {
//                if (grid[i][j] == 2)
//                {
//                    queue.Enqueue(new int[] { i, j });
//                }
//                else if (grid[i][j] == 1)
//                {
//                    count++;
//                }
//            }
//        }
//        while (queue.Count > 0 && count > 0)
//        {
//            int size = queue.Count;
//            for (int i = 0; i < size; i++)
//            {
//                int[] kv = queue.Dequeue();
//                ganran(kv[0] + 1, kv[1], grid);
//                ganran(kv[0] - 1, kv[1], grid);
//                ganran(kv[0], kv[1] + 1, grid);
//                ganran(kv[0], kv[1] - 1, grid);
//            }
//            round++;
//        }
//        return count > 0 ? -1 : round;
//    }
//
//    /// <summary>
//    /// 感染橘子
//    /// </summary>
//    private void ganran(int i, int j, int[][] map)
//    {
//        if (i < 0 || i >= map.Length || j < 0 || j >= map[i].Length || map[i][j] != 1) return;
//        map[i][j] = 2;
//        count--;
//        queue.Enqueue(new int[] { i, j });
//    }
//}

//public class Solution
//{
//    HashSet<int> set = new HashSet<int>();
//    HashSet<int> canset = new HashSet<int>();
//    Dictionary<int, List<int>> dic = new Dictionary<int, List<int>>();
//    int numCourses;
//    public bool CanFinish(int numCourses, int[][] prerequisites)
//    {
//        this.numCourses = numCourses;
//        for (int i = 0; i < prerequisites.Length; i++)
//        {
//            if (dic.TryGetValue(prerequisites[i][0], out List<int> list))
//            {
//                list.Add(prerequisites[i][1]);
//            }
//            else
//            {
//                dic.Add(prerequisites[i][0], new List<int>() { prerequisites[i][1] });
//            }
//        }
//        for (int i = 0; i < prerequisites.Length; i++)
//        {
//            if (prerequisites[i][0] >= numCourses) continue;// 这一门不用学
//            else// 要学的
//            {
//                int cur = prerequisites[i][0];
//                set.Clear();
//                if (!checkCanFinish(cur))
//                {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }

//    private bool checkCanFinish(int cur)
//    {
//        bool res = true;
//        if (dic.TryGetValue(cur, out List<int> list))// 有前置课程
//        {
//            foreach (var item in list)
//            {
//                if (canset.Contains(item)) continue;
//                if (item > numCourses) return false;// 没法学
//                if (set.Contains(cur)) return false;// 死循环
//                set.Add(item);
//                res = res && checkCanFinish(item);
//            }
//        }
//        if (res == true) canset.Add(cur);
//        return res;
//    }
//}

//public class Solution
//{
//    List<List<int>> dic;// 被依赖课程
//    int[] count;// 课程的依赖数
//    Queue<int> queue = new Queue<int>();// 当前可学课程（依赖课为0）
//    public bool CanFinish(int numCourses, int[][] prerequisites)
//    {
//        count = new int[numCourses];
//        dic = new List<List<int>>(numCourses);
//        // 初始化 dic，填充 numCourses 个空列表
//        for (int i = 0; i < numCourses; i++)
//        {
//            dic.Add(new List<int>());
//        }

//        for (int i = 0; i < prerequisites.Length; i++)
//        {
//            count[prerequisites[i][0]]++;// 添加依赖数
//            dic[prerequisites[i][1]].Add(prerequisites[i][0]);// 添加被依赖关系
//        }
//        for (int i = 0; i < numCourses; i++)
//        {
//            if (count[i] == 0)// 没有依赖的课
//                queue.Enqueue(i);
//        }
//        int studyFinished = 0;// 学习完成的课程数
//        while (queue.Count > 0)
//        {// 学习当前没有依赖的课，减少别的课的依赖

//            int cur = queue.Dequeue();// 开始学习cur
//            if (dic[cur].Count > 0)// 有别的课依赖cur这门课
//            {
//                foreach (int item in dic[cur])
//                {
//                    count[item]--;// 减少这门课的依赖数
//                    if (count[item] == 0)
//                        queue.Enqueue(item);// 变成没有依赖的课
//                }
//            }
//            studyFinished++;// 学习完cur课程
//        }
//        return studyFinished == numCourses;
//    }
//}

//public class Trie
//{
//    bool isEnd;
//    Trie[] next;

//    public Trie()
//    {
//        this.isEnd = false;
//        this.next = new Trie[26];// 由小写字母组成
//    }

//    public void Insert(string word)
//    {
//        Trie tmp = this;
//        foreach (char c in word)
//        {
//            if (tmp.next[c - 'a'] == null)
//                tmp.next[c - 'a'] = new Trie();
//            tmp = tmp.next[c - 'a'];
//        }
//        tmp.isEnd = true;
//    }

//    public bool Search(string word)
//    {
//        Trie tmp = this;
//        foreach (char c in word)
//        {
//            if (tmp.next[c - 'a'] != null)
//                tmp = tmp.next[c - 'a'];
//            else
//                return false;
//        }
//        return tmp.isEnd;
//    }

//    public bool StartsWith(string prefix)
//    {
//        Trie tmp = this;
//        foreach (char c in prefix)
//        {
//            if (tmp.next[c - 'a'] != null)
//                tmp = tmp.next[c - 'a'];
//            else
//                return false;
//        }
//        return true;
//    }
//}

//public class Solution
//{
//    List<IList<int>> res;
//    List<int> nums;
//    public IList<IList<int>> Permute(int[] nums)
//    {
//        res = new List<IList<int>>();
//        this.nums = new List<int>(nums);
//        DFS(0);
//        return res;
//    }

//    /// <summary>
//    /// 递归固定第x位
//    /// </summary>
//    /// <param name="x">当前固定的位数</param>
//    private void DFS(int x)
//    {
//        if (x == nums.Count - 1)// 当前固定位置为最后一个，结束递归
//        {
//            res.Add(new List<int>(nums));
//            return;
//        }
//        for (int i = x; i < nums.Count; i++)
//        {   // 依次固定第x位的数组 再递归固定下一个位置
//            Swap(x, i);
//            DFS(x + 1);
//            Swap(x, i);
//        }
//    }

//    private void Swap(int x, int i)
//    {
//        int tmp = nums[x];
//        nums[x] = nums[i];
//        nums[i] = tmp;
//    }
//}

//public class Solution
//{
//    List<IList<int>> res = new List<IList<int>>();
//    List<int> path = new List<int>();
//    public IList<IList<int>> Subsets(int[] nums)
//    {
//        dfs(0, nums);
//        return res;
//    }

//    private void dfs(int v, int[] nums)
//    {
//        res.Add(new List<int>(this.path));
//        for (int i = v; i < nums.Length; i++)
//        {
//            path.Add(nums[i]);
//            dfs(i + 1, nums);
//            path.RemoveAt(path.Count - 1);
//        }
//    }
//}

//public class Solution
//{
//    List<string> res = new List<string>();
//    List<char> list = new List<char>();
//    Dictionary<char, string> dic = new Dictionary<char, string>() {
//        {'2', "abc"},
//        {'3', "def"},
//        {'4', "ghi"},
//        {'5', "jkl"},
//        {'6', "mno"},
//        {'7', "pqrs"},
//        {'8', "tuv"},
//        {'9', "wxyz"}
//    };
//    public IList<string> LetterCombinations(string digits)
//    {
//        if (digits.Length == 0) return res;
//        Backtrack(0, digits);
//        return res;
//    }

//    private void Backtrack(int x, string nums)
//    {
//        if (x == nums.Length)
//        {
//            res.Add(new string(list.ToArray()));
//            return;
//        }

//        foreach (char ch in dic[nums[x]])
//        {
//            list.Add(ch);
//            Backtrack(x + 1, nums);
//            list.RemoveAt(list.Count - 1);
//        }
//    }
//}

//public class Solution
//{
//    List<IList<int>> res = new List<IList<int>>();
//    List<int> path = new List<int>();
//    public IList<IList<int>> CombinationSum(int[] candidates, int target)
//    {
//        dfs(candidates, target, 0, 0);
//        return res.ToArray();
//    }

//    private void dfs(int[] nums, int target, int sum, int idx)
//    {
//        if (sum == target)
//        {
//            res.Add(new List<int>(path)); // 找到有效组合
//            return;
//        }

//        for (int i = idx; i < nums.Length; i++)
//        {
//            if(sum + nums[i] > target)// 剪枝
//            {
//                continue;
//            }

//            path.Add(nums[i]);
//            dfs(nums, target, sum + nums[i], i);// 可以重复选择当前数字，所以idx是i，不是i + 1
//            path.RemoveAt(path.Count - 1);
//        }
//    }
//}

//public class Solution
//{
//    List<string> res = new List<string>();
//    List<char> path = new List<char>();
//    public IList<string> GenerateParenthesis(int n)
//    {
//        Backtrack(n, 0, 0, new StringBuilder());
//        return res;
//    }

//    /// <param name="n">括号数</param>
//    /// <param name="open">左括号数</param>
//    /// <param name="close">右括号数</param>
//    private void Backtrack(int n, int open, int close, StringBuilder sb)
//    {
//        if (sb.Length == n * 2)
//        {
//            res.Add(sb.ToString());
//            return;
//        }

//        if (open < n)
//        {
//            sb.Append('(');
//            Backtrack(n, open + 1, close, sb);
//            sb.Remove(sb.Length - 1, 1);
//        }

//        if (close < open)
//        {
//            sb.Append(')');
//            Backtrack(n, open, close + 1, sb);
//            sb.Remove(sb.Length - 1, 1);
//        }
//    }
//}

class Program
{
    static void Main(string[] args)
    {
        TreeNode node1 = new TreeNode(-2);
        TreeNode node2 = new TreeNode();
        TreeNode node3 = new TreeNode(-3);
        node1.left = node2;
        node1.right = node3;

        //ListNode n1 = new ListNode(1);
        //ListNode n2 = new ListNode(2);
        //ListNode n3 = new ListNode(3);
        //ListNode n4 = new ListNode(4);
        //n1.next = n2;
        //n2.next = n3;
        //n3.next = n4;

        Solution solution = new Solution();
        int[] arr = { 1,1 };
        int[] arr2 = { 5, 4, 1, 2 };
        int[][] matrix = { new int[] { 5, 1, 9, 11 }, new int[] { 2, 4, 8, 10 }, new int[] { 13, 3, 6, 7 }, new int[] { 15, 14, 12, 16 } };
        Console.Write(solution.GenerateParenthesis(1));
        Console.WriteLine();


        Console.ReadKey(); // 等待按键退出
    }
}