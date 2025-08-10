// 获取所有代码块
let codes = document.qurySeleectorAll("code");
// x循环遍历所有代码快
codes.forEach(c =>
    {
        // 设置代码块可以编辑，从而实现可复制
        c.contentEditable = "true";
    }
);