package t4;

public class Main {
    public static void main(String[] args) {
        BackupManager backupManager = new BackupManager();
        String targetPath = "目标路径"; // 假设目标路径为SD卡上的backup文件夹

        backupManager.performBackup(targetPath);
    }
}