package t5;

// 加密接口
interface Encryptor {
    String encrypt(String data);
}

// 基础加密 - 字母后移6位
class BasicEncryptor implements Encryptor {
    @Override
    public String encrypt(String data) {
        System.out.println("执行基础加密(字母后移6位)");
        StringBuilder result = new StringBuilder();
        for (char c : data.toCharArray()) {
            if (Character.isLetter(c)) {
                char base = Character.isLowerCase(c) ? 'a' : 'A';
                c = (char)(((c - base + 6) % 26) + base);
            }
            result.append(c);
        }
        return result.toString();
    }
}

// 逆向输出加密装饰器
class ReverseEncryptorDecorator implements Encryptor {
    private Encryptor encryptor;

    public ReverseEncryptorDecorator(Encryptor encryptor) {
        this.encryptor = encryptor;
    }

    @Override
    public String encrypt(String data) {
        System.out.println("执行逆向输出加密");
        String encrypted = encryptor.encrypt(data);
        return new StringBuilder(encrypted).reverse().toString();
    }
}

// 求模加密装饰器
class ModuloEncryptorDecorator implements Encryptor {
    private Encryptor encryptor;

    public ModuloEncryptorDecorator(Encryptor encryptor) {
        this.encryptor = encryptor;
    }

    @Override
    public String encrypt(String data) {
        System.out.println("执行求模加密(每位与6求模)");
        String encrypted = encryptor.encrypt(data);
        StringBuilder result = new StringBuilder();
        for (char c : encrypted.toCharArray()) {
            if (Character.isDigit(c)) {
                int num = Character.getNumericValue(c);
                result.append(num % 6);
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }
}

// 客户端使用
public class EncryptionClient {
    public static void main(String[] args) {
        String originalData = "sunnyliu\nyatteRoa\naoRettay\n13452211";
        System.out.println("原始数据:\n" + originalData);

        // 构建多层加密装饰链
        Encryptor encryptor = new BasicEncryptor(); // 基础加密
        encryptor = new ReverseEncryptorDecorator(encryptor); // 添加逆向加密
        encryptor = new ModuloEncryptorDecorator(encryptor); // 添加求模加密

        // 执行多层加密
        String encryptedData = encryptor.encrypt(originalData);
        System.out.println("\n加密后数据:\n" + encryptedData);
    }
}