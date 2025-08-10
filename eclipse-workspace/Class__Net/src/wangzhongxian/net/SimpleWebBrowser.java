package wangzhongxian.net;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SimpleWebBrowser extends JFrame {
    private JTextField addressBar; // 地址栏
    private JTextArea htmlArea; // HTML显示区域

    public SimpleWebBrowser() {
        setTitle("简单浏览器");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 地址栏
        addressBar = new JTextField("http://xsc.swust.edu.cn/bkyxw/");
        addressBar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                loadPage();
            }
        });

        // 加载页面的按钮
        JButton goButton = new JButton("Go");
        goButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                loadPage();
            }
        });

        // 包含地址栏和加载按钮的面板
        JPanel topPanel = new JPanel(new BorderLayout());
        topPanel.add(addressBar, BorderLayout.CENTER);
        topPanel.add(goButton, BorderLayout.EAST);

        // HTML显示区域
        htmlArea = new JTextArea();
        htmlArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(htmlArea);

        // 包含HTML显示区域的面板
        JPanel bottomPanel = new JPanel(new BorderLayout());
        bottomPanel.add(scrollPane, BorderLayout.CENTER);

        // 主面板
        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.add(topPanel, BorderLayout.NORTH);
        mainPanel.add(bottomPanel, BorderLayout.CENTER);

        add(mainPanel);
        setSize(800, 600);
        setVisible(true);
    }

    private void loadPage() {
        String url = addressBar.getText();

        try {
            // 连接到URL并获取输入流
            URL website = new URL(url);
            URLConnection connection = website.openConnection();
            InputStream inputStream = connection.getInputStream();

            // 将输入流读入字符串
            BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream, "GBK"));
            StringBuilder sb = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line);
                sb.append("\n");
            }
            String html = sb.toString();

            // 将HTML保存到文件
            File file = new File("F:/index.html");
            FileWriter writer = new FileWriter(file);
            writer.write(html);
            writer.close();

            // 在HTML中查找图片并下载
            int imgStart = html.indexOf("<img");
            if (imgStart != -1) {
                int srcStart = html.indexOf("src=\"", imgStart) + 5;
                int srcEnd = html.indexOf("\"", srcStart);
                String imgSrc = html.substring(srcStart, srcEnd);
                
                imgSrc = website + imgSrc;
                
                if (imgSrc.startsWith("http")) {
                    URL imgWebsite = new URL(imgSrc);
                    InputStream imgInputStream = imgWebsite.openStream();
                    File imgFile = new File("F:/3_02.gif");
                    FileOutputStream imgOutputStream = new FileOutputStream(imgFile);
                    byte[] buffer = new byte[1024];
                    int bytesRead;
                    while ((bytesRead = imgInputStream.read(buffer)) != -1) {
                        imgOutputStream.write(buffer, 0, bytesRead);
                    }
                    imgInputStream.close();
                    imgOutputStream.close();
                }
            }

            // 在文本区域中显示HTML源代码
            htmlArea.setText(html);

        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "加载页面出错：" + e.getMessage());
        }
    }

    public static void main(String[] args) {
        new SimpleWebBrowser();
    }
}