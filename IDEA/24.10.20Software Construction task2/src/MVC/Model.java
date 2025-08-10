package MVC;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Model {
    private final Random random = new Random();

    public Set<String> generateAdditionProblems(int count) {
        // 生成加法题目
        Set<String> problems = new HashSet<>();
        while (problems.size() < count) {
            int a = random.nextInt(101); // 0-100
            int b = random.nextInt(101 - a); // 确保结果在0-100
            problems.add(a + " + " + b + " = ?");
        }
        return problems;
    }

    public Set<String> generateSubtractionProblems(int count) {
        // 生成减法题目
        Set<String> problems = new HashSet<>();
        while (problems.size() < count) {
            int a = random.nextInt(101); // 0-100
            int b = random.nextInt(a + 1); // 确保a >= b
            problems.add(a + " - " + b + " = ?");
        }
        return problems;
    }

    public Set<String> generateMixedProblems(int count) {
        // 生成加减混合题目
        Set<String> problems = new HashSet<>();
        while (problems.size() < count) {
            if (random.nextBoolean()) {// 50%的概率生成加法题目
                int a = random.nextInt(101);
                int b = random.nextInt(101 - a);
                problems.add(a + " + " + b + " = ?");
            } else {
                int a = random.nextInt(101);
                int b = random.nextInt(a + 1);
                problems.add(a + " - " + b + " = ?");
            }
        }
        return problems;
    }
}
