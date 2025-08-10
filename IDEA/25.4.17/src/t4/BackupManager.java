package t4;

public class BackupManager {
    private ContactManager contactManager = new ContactManager();
    private MessageManager messageManager = new MessageManager();
    private PhotoManager photoManager = new PhotoManager();
    private MusicManager musicManager = new MusicManager();

    public void performBackup(String targetPath) {
        System.out.println("开始备份");

        contactManager.backup(targetPath);
        messageManager.backup(targetPath);
        photoManager.backup(targetPath);
        musicManager.backup(targetPath);

        System.out.println("备份完成");
    }
}