package t10;

// 策略接口
interface GameDifficultyStrategy {
    void playGame();
}

// 初级难度具体策略
class EasyDifficulty implements GameDifficultyStrategy {
    @Override
    public void playGame() {
        System.out.println("以简单模式进行游戏：敌人反应迟缓且可预测。");
    }
}

// 中级难度具体策略
class MediumDifficulty implements GameDifficultyStrategy {
    @Override
    public void playGame() {
        System.out.println("以中等模式进行游戏：敌人的反应速度适中。");
    }
}

// 高级难度具体策略
class HardDifficulty implements GameDifficultyStrategy {
    @Override
    public void playGame() {
        System.out.println("以困难模式进行游戏：敌人行动迅速且难以预测。");
    }
}

// 环境类
class GameEnvironment {
    private GameDifficultyStrategy strategy;

    public void setStrategy(GameDifficultyStrategy strategy) {
        this.strategy = strategy;
    }

    public void play() {
        if (strategy != null) {
            strategy.playGame();
        } else {
            System.out.println("请先选择一个难度等级。");
        }
    }
}

// 测试代码
public class Main {
    public static void main(String[] args) {
        GameEnvironment game = new GameEnvironment();

        // 设置并玩游戏在不同难度下
        game.setStrategy(new EasyDifficulty());
        game.play();

        game.setStrategy(new MediumDifficulty());
        game.play();

        game.setStrategy(new HardDifficulty());
        game.play();
    }
}